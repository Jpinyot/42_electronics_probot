#include "Type.h"
#include "p32xxxx.h"
#include <sys/attribs.h>

#define AVANZA 'A'
#define RETROCEDE 'R'
#define DERECHA 'D'
#define IZQUIERDA 'I'
#define PARAR 'P'
#define EXIT 'X'

void stop_motor(void);

static u8 read_char(void)
{
	u8 caca = 0;
//	LATFbits.LATF1 = 1;
	while (!U2STAbits.URXDA)
	{
		caca;
	} //wait while buffer is full
//	LATFbits.LATF1 = 0;
	return (U2RXREG);
}

void	bluetooth(void)
{

	U2MODE = 0;
	U2MODEbits.BRGH = 0;                // Baud Rate = 9600
	U2BRG = 51;
    U2MODEbits.SIDL = 0;                // Continue operation in SLEEP mode
    U2MODEbits.IREN = 0;                // IrDA is disabled
    U2MODEbits.RTSMD = 1;               // U1RTS pin isn't in Flow Control mode
    U2MODEbits.UEN = 0b00;              // U1TX, U1RX are enabled
    U2MODEbits.WAKE = 1;                // Wake-up enabled
    U2MODEbits.LPBACK = 0;              // Loopback mode is disabled
    U2MODEbits.RXINV = 0;               // U1RX IDLE state is '1'
    U2MODEbits.PDSEL = 0b00;            // 8-bit data, no parity
    U2MODEbits.STSEL = 0;               // 1 stop bit	
    U2STAbits.UTXINV = 0;               // U1TX IDLE state is '1'
	U2STAbits.URXISEL = 0b00;
    U2STAbits.URXEN = 1;                // UART1 receiver is enabled
    U2STAbits.UTXEN = 0;                // UART1 transmitter is enabled
	U2RXREG = 0;
	U2MODEbits.ON = 1;                  // UART1 is enabled

	IFS1bits.U2RXIF = 0;
	IEC1bits.U2RXIE = 1;                // interrupciones
	IPC8bits.U2IP = 4;

	u8 value = 0;
	u8	flag = 0;
	while(1)
	{
		if (PORTEbits.RE7)
			break ;
	}
//	value = read_char();
//	switch (value)
//	{
//		case AVANZA:
//			flag = 1;
//			motor_driver(1, 200000, 0);
//			break;
//		case RETROCEDE:
//			flag = 2;
//			motor_driver(2, 200000, 0);
//			break;
//		case DERECHA:
//			flag = 3;
//			motor_driver(3, 200000, 0);
//			break;
//		case IZQUIERDA:
//			flag = 4;
//			motor_driver(4, 100000, 0);
//			break;
//		case PARAR:
//			flag = 5;
//			stop_motor();
//			break;
//		default:
//			flag = 6;
//			break;
//	}
}

void __ISR(_UART2_VECTOR , IPL4SRS)read_inputs_bluetooth(void)
{
	if (IFS1bits.U2RXIF)
	{
		switch (U2RXREG)
		{
			case AVANZA:
				motor_driver(1, 200000, 0);
				break;
			case RETROCEDE:
				motor_driver(2, 200000, 0);
				break;
			case DERECHA:
				motor_driver(3, 200000, 0);
				break;
			case IZQUIERDA:
				motor_driver(4, 100000, 0);
				break;
		}
		IFS1bits.U2RXIF = 0;
	}

}
//	{
	//	LATFbits.LATF1 = 1;
//		value = read_char();
	//		LATFbits.LATF1 = 0;
	//	if (value)
	//		buzzer(2, 2);
	//	else
	//		LATFbits.LATF1 = 0;

//		if (value == 89 || value == 121)
//		{
//			buzzer(2, 2);
//			break ;
//		}
//		else if (value == 78 || value == 110)
//		{
//			LATDbits.LATD3 = 1;
//		}
		//send_char(value);
//		}
//	}