#include <16F887.H>
#include <string.h>
#include <stdio.h>
#Fuses INTRC_IO,NOWDT,PUT,NOPROTECT,NOBROWNOUT,NOMCLR,NOLVP,NOCPD
#USE delay(clock=4000000)
#use rs232(baud=9600, BITS=8, PARITY = N , xmit=PIN_C6,rcv=PIN_C7)

char cadena[10];
char cadena1[]={'e','n','c','i','e','n','d','e',13};
char cadena2[]={'a','p','a','g','a',13};

#int_rda
void serial_isr()
{
printf("\nEscribe palabra: ");
gets(cadena);
}

void main(){
      enable_interrupts(GLOBAL);
      enable_interrupts(INT_RDA);
    
   while(true)
   {
         if(cadena1[0]==cadena[1]&&cadena1[1]==cadena[2]&&cadena1[2]==cadena[3]&&cadena1[3]==cadena[4]&&cadena1[4]==cadena[5]&&cadena1[5]==cadena[6]&&cadena1[6]==cadena[7]&&cadena1[7]==cadena[8]&&cadena1[8]==13)
         {
            output_b(255);
            //delay_ms(500);           
         }
         if(cadena2[0]==cadena[1]&&cadena2[1]==cadena[2]&&cadena2[2]==cadena[3]&&cadena2[3]==cadena[4]&&cadena2[4]==cadena[5])
         {
            output_b(0x00);
         }
   }
}
