#include "Type.h"
#include "p32xxxx.h"
#include <sys/attribs.h>

static u16 proximity_read(int ch)
{
    AD1CHSbits.CH0SA = ch;          // Select input channel
    AD1CON1bits.SAMP = 1;           // Start sampling
    while(!AD1CON1bits.DONE);       // Wait for conversion to complete
    return ADC1BUF0;                // Read conversion result
}

static void wait_proximity(u16 max_time)
{
	u16 i;
	i = 0;
	while (++i < max_time);
}

u16 proximity_sensor(void) {
	u16 val;

	//LDR	  //5432109876543210
	AD1PCFG = 0b1111111111101111;	// PORTB = Digital; RB4 = analog
	TRISBbits.TRISB4 = 1;			// B4 as input
	AD1CHSbits.CH0SA =  0b0100;     // Channel 0100 input is AN04
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

//		wait_proximity(625000);
	val = proximity_read(4);
	if (val < 350)
		ledmatrix2(0b00000000);
	else if (val < 370)
		ledmatrix2(0b00000100);
	else if (val < 390)
		ledmatrix2(0b00000101);
	else if (val < 410)
		ledmatrix2(0b00001101);
	else if (val < 430)
		ledmatrix2(0b00001111);
	else if (val < 450)
		ledmatrix2(0b00101111);
	else if (val < 470)
		ledmatrix2(0b10101111);
	else if (val < 490)
		ledmatrix2(0b10111111);
	else if (val < 510)
		ledmatrix2(0b11111111);
//	while(i++ < 10000);
	return (val);
}
 