#include "Type.h"
#include "p32xxxx.h"
#include <sys/attribs.h>

u8 mode_sel = 0; //1 = grid / 2 = bluetooth
u16 val = 0;
u16 i;

int main(void)
{
	__builtin_enable_interrupts();		//enable interrupt globally
	IFS0bits.INT1IF = 0;
	IEC0bits.INT1IE = 1;
	IPC1bits.INT1IP = 3;
	INTCONbits.INT1EP = 0;
	INTCONbits.MVEC = 1;
	TRISGbits.TRISG9 = 1;
	TRISGbits.TRISG9 = 0;
	TRISGbits.TRISG9 = 1;
	motor_driver(0, 200000, 0);

//	ldr();
//
//	TRISEbits.TRISE6 = 0;	//OUTPUT BLUE
//	TRISEbits.TRISE4 = 0;	//OUTPUT RED
//	TRISEbits.TRISE3 = 0;	//OUTPUT GREEN
////	TRISBbits.TRISB7 = 0;	//OUTPUT GREEN
//
//	while(1)
//	{
//		LATEbits.LATE6 = 1; //BLUE
//		LATEbits.LATE4 = 0; //RED
//		LATEbits.LATE3 = 1; //GREEN
////		LATBbits.LATB11 = 0; //RED
////		LATBbits.LATB12 = 0;//GREEN
////		LATBbits.LATB7 = 1;//GREEN
//	}

	
	while(1)
	{
		modeselector();
	}
}

void __ISR(_EXTERNAL_1_VECTOR , IPL3SRS)read_inputs(void)
{
	if (PORTEbits.RE7)
	{
		modeselector();
		mux_final();
	}
	else
	{
		modeselector();
		bluetooth();
	}
//	bluetooth();
    IFS0bits.INT1IF = 0;
	TRISGbits.TRISG9 = 1;
	TRISGbits.TRISG9 = 0;
	TRISGbits.TRISG9 = 1;
//	IEC0bits.INT1IE = 1;

}