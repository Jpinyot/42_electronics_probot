#include "Type.h"
#include "p32xxxx.h"
#include <sys/attribs.h>

void	protoboard_buzzer(void)
{
	 __builtin_enable_interrupts();		//enable interrupt globally
	TRISFbits.TRISF1 = 0; //  OUTPUT B3
//	LATFbits.LATF1 = 1;

	//TIMER
	PR2 = 60000;				//T2 period
    TMR2 = 0;					//clear T2 counter
    T2CONbits.ON = 1;			 //T2 = on
    T2CONbits.TCKPS = 0b100;    //TCKPS<2:0> 011 = 1:8 prescale value
    T2CONbits.TGATE = 0;
    IFS0bits.T2IF = 0;       //Reset T2 interrupt flag
    IEC0bits.T2IE = 1;		//ENAVEL interrupts to T2
    IPC2bits.T2IP = 5;		//priority to 5

}

void __ISR(_TIMER_2_VECTOR, IPL5SRS)TP4InterruptT2(void)
{
//	if (LATFbits.LATF1)
//		LATFbits.LATF1 = 0;
//    else
	LATFbits.LATF1 = 1;
	// Reset interrupt flag
    IFS0bits.T2IF = 0;
}