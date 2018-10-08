#include "Type.h"
#include "p32xxxx.h"
#include <sys/attribs.h>

#define color1 LATEbits.LATE6 //BLUE
#define color2 LATEbits.LATE4 //RED
#define color3 LATEbits.LATE3 //GREEN

u16 LDR_VALUE[3] = {0, 0, 0};

static int ldr_read(int ch)
{
    AD1CHSbits.CH0SA = ch;          // Select input channel
    AD1CON1bits.SAMP = 1;           // Start sampling
    while(!AD1CON1bits.DONE);       // Wait for conversion to complete
    return ADC1BUF0;                // Read conversion result
}

static void wait_ldr(u16 max_time)
{
	u16 i;
	i = 0;

	while (++i < max_time);
}

u8 ldr(u16 *LDR_CMP) {

	//RGB
	TRISEbits.TRISE6 = 0;	//OUTPUT BLUE
	TRISEbits.TRISE4 = 0;	//OUTPUT RED
	TRISEbits.TRISE3 = 0;	//OUTPUT GREEN

	//LDR
	AD1PCFG = 0b1111110111111111;	// PORTB = Digital; RB9 = analog
	TRISBbits.TRISB9 = 1;			// B9 as input
	AD1CHSbits.CH0SA =  0b1001;     // Channel 1001 input is AN09
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

	//RED
	color1 = 0;
	color2 = 1;
	color3 = 1;
	wait_ldr(6250000);
	LDR_VALUE[0] = ldr_read(9);
	//BLUE
	color1 = 1;
	color2 = 0;
	color3 = 1;
	wait_ldr(6250000);
	LDR_VALUE[1] = ldr_read(9);
	//GREEN
	color1 = 1;
	color2 = 1;
	color3 = 0;
	wait_ldr(6250000);
	LDR_VALUE[2] = ldr_read(9);
	color1 = 1;
	color2 = 1;
	color3 = 1;
	if (LDR_CMP[0] == 0)
	{
		LDR_CMP[0] = LDR_VALUE[0];
		LDR_CMP[1] = LDR_VALUE[1];
		LDR_CMP[2] = LDR_VALUE[2];
	}
	else
	{
		if (LDR_CMP[0] < (LDR_VALUE[0] - LDR_VALUE[0] * 0.1) || LDR_CMP[0] > (LDR_VALUE[0] + LDR_VALUE[0] * 0.1))
			return (0);
		if (LDR_CMP[1] < (LDR_VALUE[1] - LDR_VALUE[1] * 0.1) || LDR_CMP[1] > (LDR_VALUE[1] + LDR_VALUE[1] * 0.1))
			return (0);
		if (LDR_CMP[2] < (LDR_VALUE[2] - LDR_VALUE[2] * 0.1) || LDR_CMP[2] > (LDR_VALUE[2] + LDR_VALUE[2] * 0.1))
			return (0);
	}
	return (1);
}