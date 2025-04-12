#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void){

   DDRD&=~(0xC0);
   DDRB|=0x0F;
   DDRD|=0x0C;
   PORTD&=~(0x0C);
   char a=0x00;
  while(1){
    char u=a%10;
    char d=a/10;
     
    if(PIND&0x80){//aumento
      _delay_ms(100); 
      a=(a+0x01)%100;  
    }

    if(PIND&0x40){//aumento
      _delay_ms(100);
      if(a==0x00){
       a=99;
      } 
      a=(a-0x01);  
    }

     PORTD&=~0x08;
     PORTD|=0x04;
     PORTB=d&0x0F;
     _delay_ms(8);
     PORTD&=~0x04;
     PORTD|=0x08;
     PORTB=u&0x0F;
     _delay_ms(8);
  }
/*
    PORTD&=~(0x08);
    PORTD|=0x04;

    PORTB|=(0x06);
   PORTB &=(0xF6);

   
   
   _delay_ms(1000);

   PORTD&=~(0x04);
   PORTD|=0x08;
   PORTB|=(0x07);
   PORTB&=(0xF7);

  
   _delay_ms(1000);


  }
*/


  return 0;
}
