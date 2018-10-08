#include "Type.h"
#include "p32xxxx.h"
#include <sys/attribs.h>


static void led_on(u16 value)
{
	if (value > 100)
	{
		LATFbits.LATF1 = 1;

	}
	else
	{
		LATFbits.LATF1 = 0;
		LATDbits.LATD1 = 0;
	}
}

void real_mux(void)
{
	//modulo adc
	u16 value = 0;
	AD1PCFG = 0b1111110111111111;             // PORTB = Digital; RB9 = analog
	AD1CON1 = 0x0000;             // SAMP bit = 0 ends sampling
	AD1CON1bits.ASAM = 1;
	AD1CON1bits.SSRC = 0b111;
// and starts converting
	AD1CHSbits.CH0SA = 0b1001;


	AD1CSSL = 0;
	AD1CON3 = 0x0002;             // Manual Sample, TAD = internal 6 TPB
	AD1CON2 = 0;
	AD1CON1SET = 0x8000;          // turn on the ADC

	//pines para el mux
	TRISGbits.TRISG9 = 0; //S0
	TRISGbits.TRISG8 = 0; //S1
	TRISGbits.TRISG7 = 0; //S2
	TRISGbits.TRISG6 = 0; //S3


    //PREPARANDO SALIDAS LED
    TRISFbits.TRISF1 = 0;
    TRISDbits.TRISD2 = 0;
    TRISDbits.TRISD3 = 0;
    TRISDbits.TRISD1 = 0;
    TRISDbits.TRISD4 = 0;

    LATFbits.LATF1 = 0;
    LATDbits.LATD2 = 1;
    LATDbits.LATD3 = 1;
    LATDbits.LATD1 = 1;
    LATDbits.LATD4 = 1;

	while (1)                     // repeat continuously
	{
		LATGbits.LATG9 = 1;
		LATGbits.LATG8 = 1;
		LATGbits.LATG7 = 1;
		LATGbits.LATG6 = 0;
		AD1CON1CLR = 0x0002;        // start Converting
		while (!(AD1CON1 & 0x0001));// conversion done?
		value = ADC1BUF0;        // yes then get ADC value

		led_on(value);
	}
}