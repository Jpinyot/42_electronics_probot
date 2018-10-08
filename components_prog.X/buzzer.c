#include "Type.h"
#include "p32xxxx.h"
#include <sys/attribs.h>
//u16 PR2_VAL = 2000;
u8 flag = 0;
u8 sound_type = 0;
u8 cnt = 0;

void	buzzer(u8 sound, u8 cycles)
{
	sound_type = sound;
//	 __builtin_enable_interrupts();		//enable interrupt globally
	TRISEbits.TRISE5 = 0; //  OUTPUT B3
	TRISFbits.TRISF1 = 0; //  OUTPUT F1 LED
//	LATFbits.LATF1 = 0;

	//TIMER
	if (sound == 1)
		PR2 = 100;				//T2 period
	else if(sound == 2)
		PR2 = 2000;
    TMR2 = 0;					//clear T2 counter
	IFS0bits.T2IF = 0;       //Reset T2 interrupt flag
    IEC0bits.T2IE = 1;		//ENAVEL interrupts to T2
    IPC2bits.T2IP = 5;		//priority to 5

	//CLOCK
	T2CONbits.ON = 1;			 //T2 = on
//	T2CONbits.TCKPS = 0b100;    //TCKPS<2:0> 011 = 1:8 prescale value


	INTCONbits.MVEC = 1;
	while(1)
	{
		if (flag == cycles)
			break;
	}
	IEC0bits.T2IE = 0;
	T2CONbits.ON = 0;
	flag = 0;
}

void __ISR(_TIMER_2_VECTOR, IPL5SRS)TP4InterruptT2(void)
{
	if (LATFbits.LATF1)
	{
		LATFbits.LATF1 = 0;
		LATEbits.LATE5= 0;
	}
    else
	{
		LATFbits.LATF1 = 1;
		LATEbits.LATE5= 1;
	}
	if (sound_type == 1)
	{
		PR2++;
		if (PR2 > 2000)
		{
			flag++;
			PR2 = 100;
		}
	}
	else if (sound_type == 2)
	{
		PR2--;
		if (PR2 < 100)
		{
			flag++;
			PR2 = 2000;
		}
	}
	// Reset interrupt flag
    IFS0bits.T2IF = 0;
}
