
#include "Type.h"
#include "p32xxxx.h"
#include <sys/attribs.h>

//u16 LDR[3] = {0, 0, 0};

static void initMux(void)
{
	TRISEbits.TRISE1 = 0; //S0
	TRISEbits.TRISE2 = 0; //S1
	TRISEbits.TRISE0 = 0; //S2
	TRISDbits.TRISD9 = 0; //S3

	TRISDbits.TRISD11 = 0; //GND
	LATDbits.LATD11 = 0;
	
	TRISDbits.TRISD10 = 0; //3.3
	LATDbits.LATD10 = 1; 
}

static void initADC(void)
{
			  //5432109876543210
    AD1PCFG = 0b1111111111110111;             // PORTB = Digital; RB9 = analog
    TRISBbits.TRISB3 = 1;           // Pin set as input
    AD1CON1bits.FORM = 0;           // Integer 16-bit output
    AD1CON1bits.SSRC = 0b111;       // Internal counter ends sampling and starts conversion
    AD1CSSL = 0;                    // No scanning required
    AD1CON2bits.VCFG = 0;           // Internal voltage references
    AD1CON2bits.CSCNA = 0;          // Do not scan inputs
    AD1CON2bits.BUFM = 0;           // Buffer configured as one 16-word buffer
    AD1CON2bits.ALTS = 0;           // Always use MUX A input multiplexer settings
    AD1CON3bits.ADRC = 0;           // Clock derived from PBclock
    AD1CON3bits.ADCS = 0b00111111;  // TAD = 2*TPB
    AD1CON3bits.SAMC = 0b11111;     // 31 TAD auto-sample time
    AD1CON1bits.ON = 1;             // A/D converter module is operating
	//Green light
    TRISFbits.TRISF1 = 0;
	LATFbits.LATF1 = 0;
}

static int ReadADC(int ch, int ix)
{
	LATEbits.LATE1 = (ix >> 0) & 1;
	LATEbits.LATE2 = (ix >> 1) & 1;
	LATEbits.LATE0 = (ix >> 2) & 1;
	LATDbits.LATD9 = (ix >> 3) & 1;

    AD1CHSbits.CH0SA = ch;          // Select input channel
    AD1CON1bits.SAMP = 1;           // Start sampling
    while(!AD1CON1bits.DONE);       // Wait for conversion to complete
    return ADC1BUF0;                // Read conversion result
}

void mux_final(void)
{
//	IEC0bits.INT1IE = 0; checkear con Buzzer
	u16 LDR_CMP[3] = {0, 0, 0};
	u8 ldr_flag = 0;
	int order[16] = {7, 6 , 5, 4, 3, 2, 1, 11, 2, 3, 12, 13, 0, 1, 14, 15};
	int i = 0;

	initADC();
	initMux();
	int value, ord, j=0; //tiene que ser u16 o algo asi?
	while (j++ < 40000);
	while (i < 6)
	{
		j = 0;
		TRISGbits.TRISG9 = 0;

		while (j++ < 1000);
		value = ReadADC(3, order[i]);
		if (value > 350 && value < 390)			//FORWARD
			motor_driver(1, 200000, 0);
		else if (value < 450)					//BACKWARDS /purple
			motor_driver(2, 200000, 0);
		else if (value > 540 && value < 600)	//LEFT		/green
			motor_driver(4, 100000, 0);
		else if (value < 690)					//RIGHT		/blue
			motor_driver(3, 200000, 0);
		else if (value < 750)					//LDR		/yellow
			ldr_flag = 1;	//1,2,3
		else if (value < 840)					//BUZZER	/red
			buzzer(2,2);	//1,2,3
		else if (value < 890)					//gyro		/brown
			gyro();
		else if (value < 950)					//RUMBA		/orange
			rumba();
		else									//STOP
		{
//			value = 1;
//			proximity_test();
			motor_driver(0, 200000, 0);
		}
		if (ldr_flag == 1 && value < 750)
			if (!ldr(LDR_CMP))
				break;
		i++;
	}

}

