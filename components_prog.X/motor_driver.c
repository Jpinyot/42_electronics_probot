
#include "Type.h"
#include "p32xxxx.h"
#include <sys/attribs.h>

//https://www.rakeshmondal.info/dc-motor-control-introhttps://www.rakeshmondal.info/dc-motor-control-intro

static void	set_motors(void)
{
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
}

void stop_motor(void)
{
	LATDbits.LATD5 = 0;
	LATDbits.LATD1 = 0;
	LATDbits.LATD6 = 0;
	LATDbits.LATD3 = 0;
}

static void wait_motor(s32 cycles, u8 prox)
{
	u8 stop = 0;
	
	while(cycles)
	{
		if ((prox == 1) && !(cycles % 1000))
		{
			if (proximity_sensor() > 500)
			{
				stop = 1;
				break;
			}
		}
		cycles--;
	}
	if (stop == 1)
	{
		stop_motor();
		LATFbits.LATF1 = 1;
		buzzer(1,1);
	}
}

static void	go_forward()
{
	LATDbits.LATD5 = 1;
	LATDbits.LATD1 = 0;

	LATDbits.LATD6 = 1; //MOTOR IZQUIERDO
	LATDbits.LATD3 = 0;

	//Set Timer
	T2CONbits.TCKPS = 2; // TImer 2 prescaler n = 4
	PR2 =1999;
	TMR2 = 0;

	//MOTOR DERECHO
	OC5CONbits.OCM= 0b110; //PWM without fault pin
	OC5RS = 900;
	OC5R = 1000;	//OCxR When PWM drops to low
//	MOTOR IZQUIERDO
	OC3CONbits.OCM= 0b110;
	OC3RS = 2000;
	OC3R = 1000;

	T2CONbits.ON = 1;		//Turn ON Timer2
	OC5CONbits.ON = 1;		//Turn ON OC5
	OC3CONbits.ON = 1;		//Turn ON OC3
	
	wait_motor(200000, 1);
}

static void	go_backwards(void)
{
	LATDbits.LATD5 = 0;
	LATDbits.LATD1 = 1;

	LATDbits.LATD6 = 0;
	LATDbits.LATD3 = 1;

	//Set Timer
	T2CONbits.TCKPS = 2; // TImer 2 prescaler n = 4
	PR2 =1999;
	TMR2 = 0;

	//MOTOR 1
	OC5CONbits.OCM= 0b110; //PWM without fault pin
	OC5RS = 900;
	OC5R = 1000;	//OCxR When PWM drops to low
//	MOTOR 2
	OC3CONbits.OCM= 0b110;
	OC3RS = 2000;
	OC3R = 1000;

	T2CONbits.ON = 1;		//Turn ON Timer2
	OC5CONbits.ON = 1;		//Turn ON OC5
	OC3CONbits.ON = 1;		//Turn ON OC3

	wait_motor(400000, 0);
}

static void	turn_right(void)
{
	LATDbits.LATD5 = 0;
	LATDbits.LATD1 = 1;
	//M2
	LATDbits.LATD6 = 1;
	LATDbits.LATD3 = 0;

	T2CONbits.TCKPS = 2; // TImer 2 prescaler n = 4
	PR2 =1999;
	TMR2 = 0;

	//MOTOR 1
	OC5CONbits.OCM= 0b110; //PWM without fault pin
	OC5RS = 900;
	OC5R = 1000;	//OCxR When PWM drops to low

	OC3CONbits.OCM= 0b110;
	OC3RS = 2000;
	OC3R = 1000;

	T2CONbits.ON = 1;		//Turn ON Timer2
	OC3CONbits.ON = 1;		//Turn ON OC3

	wait_motor(17000, 1);
}
static void	turn_left(void)
{

	//M1 //pegatina
	LATDbits.LATD5 = 1;
	LATDbits.LATD1 = 0;

	LATDbits.LATD6 = 0;
	LATDbits.LATD3 = 1;

	//Set Timer
	T2CONbits.TCKPS = 2; // TImer 2 prescaler n = 4
	PR2 =1999;
	TMR2 = 0;

	OC3CONbits.OCM= 0b110;
	OC3RS = 2000;
	OC3R = 1000;

	//MOTOR 1
	OC5CONbits.OCM= 0b110; //PWM without fault pin
	OC5RS = 900;
	OC5R = 1000;	//OCxR When PWM drops to low

	T2CONbits.ON = 1;		//Turn ON Timer2
	OC5CONbits.ON = 1;		//Turn ON OC5

	wait_motor(30000, 1);
}

void	motor_driver(int direction, s32 time, s16 speed)
{
	TRISFbits.TRISF1 = 0;
	LATFbits.LATF1 = 0;
	set_motors();
	if (direction == 0)
		stop_motor();
	else if (direction == 1)
		go_forward();
	else if (direction == 2)
		go_backwards();
	else if (direction == 3)
		turn_right();
	else if (direction == 4)
		turn_left();
	stop_motor();
}