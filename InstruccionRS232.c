#include <16f887.h>
#device adc = 8
#fuses INTRC_IO, NOCPD, NOWDT, PUT, NOPROTECT
#fuses NOBROWNOUT, NOLVP, NODEBUG, NOWRT,NOMCLR
#use delay(clock = 4000000)
#use RS232(Baud = 9600, bits = 8, Parity = N, XMIT = PIN_C6, RCV = PIN_C7)

void main()
{
   while(true)
   {
      Inicio:
      char entrada; 
      int i, j;
      
      printf("\fLado Oscuro");
      printf("\rIntrucciones: Al precionar una tecla ");
      printf("se hara la siguiente accion...\r\rMenu\r");
      printf("k = KIT\rb = BARRA\rp = PARPADEO\r");
      printf("\rINGRESE: ");
      
      entrada = getc();
      
      if(entrada == 'b' || entrada == 'B' || entrada == 'k' || entrada == 'K' || entrada == 'p' || entrada == 'P')
      {
         delay_ms(100);
         printf("\f");
      }
      else
      {
         printf("\r\r%c no pertenece al Menu", entrada);
         delay_ms(1000);
         printf("\f");
      }
      
      if(entrada == 'b' || entrada == 'B')
      {
         printf("\rEn el pic se ve Barra");
         
         while(true)
         {
            for(i=1; i < 128; i*=2)
             {
               output_b(i-1);
               delay_ms(500); 
             }       
             output_b(127);
             delay_ms(500);
             output_b(255);
             delay_ms(500);
             for(j=128; j > 0; j/=2)
             {
               output_b(j-1);
               delay_ms(500);         
             }
             if(kbhit())
               goto Inicio;                        
         }
      }
                  
      if(entrada == 'k' || entrada == 'K')
      {
         printf("\rEn el pic se ve KIT");
         while(true)
         {
             for(i=1; i < 128; i*=2)
             {
               output_b(i);
               delay_ms(500);         
             } 
             for(j=128; j > 0; j/=2)
             {
               output_b(j);
               delay_ms(500);
             } 
             output_b(0);
             if(kbhit())
               goto Inicio; 
         }
      }
      
      if(entrada == 'p' || entrada == 'P')
      {
         printf("\rEn el pic se ve PARPADEO de todos los LED");
         while(true)
         {         
            output_b(255);
            delay_ms(500);
            output_b(0);
            delay_ms(500);
            
            if(kbhit())
               goto Inicio; 
         }         
      }
   }
}
