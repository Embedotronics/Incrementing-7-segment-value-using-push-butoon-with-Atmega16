/*
 * push_button.c
 *
 * Created: 24-04-2020 14:56:02
 * Author : Embedotronics
 */ 

# define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	/* Replace with your application code */
	unsigned int digi_val[]={0x40,0xF9,0x24,0x30,0x19,0x12,0x02,0xF8,0x00,0x10};
	unsigned int v1=0;
	DDRA=0x00;
	DDRD=0xff;
	while (1)
	{
		if(PINA==0x01){
			while(PINA==0x01)
			{
				_delay_ms(50);
				PORTD=digi_val[v1];
			}
			v1++;
			
			if(v1==10){
				v1=0;
			}
		}
		
	}
}

