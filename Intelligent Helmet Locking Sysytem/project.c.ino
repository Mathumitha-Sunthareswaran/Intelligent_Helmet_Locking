#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
  DDRB = DDRB | (1<<5);          //declare PORTB5 as output
  DDRD = DDRD & ~(1<<2);         // PB2 ir, PB3 clip 
  DDRD = DDRD & ~(1<<3);        //declare PIND2, and PIND3 as input
  
  while(1)
  {
    if(PIND & 0b00001000)
    {
      _delay_ms(20000);
  while(PIND |= 0b00001000){
          PORTB = PORTB | (1<<5);
          _delay_ms(100);
          PORTB = PORTB & (0<<5);
          _delay_ms(100);
        }
    }
    else
    {
      PORTB = PORTB & (0<<5);
    }
  }
}

void runMode(){
  while(1){
    
  }
}
