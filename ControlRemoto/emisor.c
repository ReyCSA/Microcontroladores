#include <12F629.h>
#fuses NOWDT,NOPROTECT,NOCPD,NOMCLR,NOPUT,INTRC_IO,NOBROWNOUT
#USE delay(clock=4000000)

int i;

void main()
{ 
   while(true)
   {  
      //Genero una frecuencia de 12Khz
      if(input(PIN_A0) != 1)
      {   
         for(i=1;i<6;i++)
         {
            output_bit(PIN_A2, 1);
            delay_us(9);
            output_bit(PIN_A2, 0);
            delay_us(9);

         }
         output_bit(PIN_A2, 0);
         delay_ms(80); //reposo
      }  
      //Genero una frecuencia de 19K
      if(input(PIN_A1) != 1)
      {   
         for(i=1;i<6;i++)
         {
            output_bit(PIN_A2, 1);
            delay_us(9);
            output_bit(PIN_A2, 0);
            delay_us(9);

         }
         output_bit(PIN_A2, 0);
         delay_ms(50);//reposos
      } 
   }
} 
