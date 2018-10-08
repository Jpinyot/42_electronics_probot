
#include "Type.h"
#include "p32xxxx.h"
#include <sys/attribs.h>

void	gyro()
{
	PR3 = 62500;				//T2 period
	TMR3 = 0;					//clear T2 counter
	IFS0bits.T3IF = 0;       //Reset T2 interrupt flag
    IEC0bits.T3IE = 1;		//ENAVEL interrupts to T2
    IPC3bits.T3IP = 4;		//priority to 5

	//CLOCK
	T3CONbits.ON = 1;			 //T2 = on
	T3CONbits.TCKPS = 0b100;    //TCKPS<2:0> 011 = 1:8 prescale value
		//SET MOTORS------------
	//MOTOR 1 output
	TRISDbits.TRISD4 = 0;	//ENABLE
	LATDbits.LATD4 = 1;		//ENABLE high
	TRISDbits.TRISD5 = 0;
	TRISDbits.TRISD1 = 0;
	//MOTOR 2 output
	TRISDbits.TRISD2 = 0;	//ENABLE
	LATDbits.LATD2 = 1;		//ENABLE high
	TRISDbits.TRISD6 = 0;
	TRISDbits.TRISD3 = 0;

	TRISFbits.TRISF1 = 0;	//ENABLE
	LATFbits.LATF1 = 0;
	//SET MOTORS-----------

	LATDbits.LATD5 = 1;
	LATDbits.LATD1 = 0;

	LATDbits.LATD6 = 0; //MOTOR IZQUIERDO
	LATDbits.LATD3 = 1;
	while(1);
}

void __ISR(_TIMER_3_VECTOR, IPL4SRS)interruptlavadora(void)
{
	LATDbits.LATD5 = LATDbits.LATD5 ? 0 : 1;
	LATDbits.LATD1 = LATDbits.LATD1 ? 0 : 1;
	LATDbits.LATD6 = LATDbits.LATD6 ? 0 : 1;
	LATDbits.LATD3 = LATDbits.LATD3 ? 0 : 1;
	// Reset interrupt flag
    IFS0bits.T3IF = 0;
}