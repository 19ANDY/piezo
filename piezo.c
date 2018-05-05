#include<avr/io.h>
#include<util/delay.h>
#include"adc.c"
#include"uart.c"
#include"uart.h"

void main()
{
DDRB=0xFF;
DDRC=0b0000000;
unsigned int i=0,r;
char receive[10];

//uart_init(UART_BAUD_SELECT(9600,F_CPU));
//sei();

  while(1)
  {
  r=readADC(5);
  //itoa(r,receive,10);
  //uart_puts(receive);
  //uart_puts("\r\n");
  
    if((r>=255)&&((i%2)==0))
    {
	PORTB=0x2E;
	_delay_ms(10000);
    PORTB=0x00;
	i=i+1;
	}
	r=0;
	_delay_ms(30000);
	r=readADC(5);
	
	
	if((r>=255)&&((i%2)!=0))
    {
	PORTB=0x1E;
	_delay_ms(2000);
    PORTB=0x00;
	i=i+1;
	}
	

  
  }
}