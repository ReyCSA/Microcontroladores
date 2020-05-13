#include <16F887.h>
#Fuses NOWDT,PUT,NOPROTECT,NOBROWNOUT,NOMCLR,NOLVP,INTRC_IO,NOCPD
#use delay(clock=4Mhz)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7, parity=n, bits=8) //xmit TX

//variables
int i = 0, j = 0;
int16 a, b, Pulso;
float T, Periodo, F;

#int_EXT
void RB0()
{
   a = get_timer1(); //captura a, primer flanco de subida  
   Pulso = a - b; //primer periodo
   b = a; //segundo flanco
   i = 1; //bandera, indica cuando entra el valor  
}

void main()
{      
   SETUP_TIMER_1(T1_INTERNAL  |T1_DIV_BY_8);//Prescaler = 8
   EXT_INT_EDGE(0,L_TO_H); //interrupcion externa por flanco de subida 
   enable_interrupts(int_ext); //habilita interrupcion por B0   
   enable_interrupts(GLOBAL); //habilita interrupcion global

   while(TRUE)
   {
      //si lee un pulso en B0
      if(i == 1)
      {
         i = 0; //Reinicio la bandera, para una lectura posterior
         
         //Calculamos los periodos 
         T=4.0*8.0/4000000.0;  //Timer1 = (4 * Preescaler) / Clock
         Periodo=T*Pulso; //Periodo
         F=1/Periodo; //Frecuencia 
         
         printf("\rPulsos= %Lu",Pulso);
         printf("   F= %FHz",F);  
         //delay_ms(300);//evita el rebote
         
         /****Prueba Proteus****/
         if(F == 12500)
         {
            if(j == 1)
            {
               output_bit(PIN_C0, 1);
               j = 0;
               printf("    %d", j);
               delay_ms(30);//evita el rebote
            }
            else
            {
               output_bit(PIN_C0, 0);
               j = 1;
               printf("    %d", j);
               delay_ms(30);//evita el rebote
            }
         }
         
         //Si la Frecuencia recibida es de 12Khz
         if(F > 12 && F < 13)
         {
            if(j == 1)
            {
               output_bit(PIN_C0, 1);
               j = 0;
               printf("    %d", j);
               delay_ms(30);//evita el rebote
            }
            else
            {
               output_bit(PIN_C0, 0);
               j = 1;
               printf("    %d", j);
               delay_ms(30);//evita el rebote
            }
         }
         
         //Si la Frecuencia es de 19Khz
         if(F > 19 && F < 20)
         {
            if(j == 1)
            {
               output_bit(PIN_C1, 1);
               j = 0;
               printf("    %d", j);
                delay_ms(30);//evita el rebote
            }
            else
            {
               output_bit(PIN_C1, 0);
               j = 1;
               printf("    %d", j);
                delay_ms(30);//evita el rebote
            }
         }
         
         //Si la Frecuencia es de 32Khz
         if(F > 32 && F < 34)
         {
            if(j == 1)
            {
               output_bit(PIN_C2, 1);
               j = 0;
               printf("    %d", j);
                delay_ms(30);//evita el rebote
            }
            else
            {
               output_bit(PIN_C2, 0);
               j = 1;
               printf("    %d", j);
                delay_ms(30);//evita el rebote
            }
         }
         
         //Reiniciamos la bandera para esperar la siguiente lectura
         if(i == 1)
         {
            i = 0;
         }                 
      }
   }      
}
