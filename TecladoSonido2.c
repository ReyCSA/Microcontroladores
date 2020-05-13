#include <16F627A.H>
#FUSES INTRC_IO,NOBROWNOUT,NOWDT,PUT,NOPROTECT,NOBROWNOUT,NOMCLR,NOLVP,NOCPD
#USE delay(clock=4000000)

void main()
{
   IngresaN:
   int i  = 4, vector[3];

   while(i != 0)
   {   
      //FILA_1:
         output_bit(PIN_A3,1); 
         //COLUMNA:
         if(input(PIN_A0)==1)//No.1
         {
            i = i - 1;
            vector[i] = 1;
               while(input(PIN_A0) != 0)
               {              
                  output_toggle(PIN_B7);
                  delay_ms(1);
               }  
         }
                             
         if(input(PIN_A1)==1)//No.2
         {
            i = i - 1;
            vector[i] = 2;
               while(input(PIN_A1) != 0)
               {
                  output_toggle(PIN_B7);
                  delay_ms(1);     
               }  
         }
            
         if(input(PIN_A5)==1)//No.3
         {
            i = i - 1;
            vector[i] = 3;
               while(input(PIN_A5) != 0)
               {
                  output_toggle(PIN_B7);
                  delay_ms(1);                  
               }  
         } 
         delay_ms(35); 
         output_bit(PIN_A3,0);
         
      //FILA_2:
         output_bit(PIN_A2,1); 
         //COLUMNA:
         if(input(PIN_A0)==1) //No. 4
         {
            i = i - 1;
            vector[i] = 4;
               while(input(PIN_A0) != 0)
               {
                  output_toggle(PIN_B7);
                  delay_ms(1);
               }
         }
                             
         if(input(PIN_A1)==1) //No. 5
         {
            i = i - 1;
            vector[i] = 5;
               while(input(PIN_A1) != 0)
               {
                  output_toggle(PIN_B7);
                  delay_ms(1);                  
               }  
         }
                             
         if(input(PIN_A5)==1) //No. 6
         {
            i = i - 1;
            vector[i] = 6;
               while(input(PIN_A5) != 0)
               {
                  output_toggle(PIN_B7);
                  delay_ms(1);                  
               } 
         }
                              
         delay_ms(35); 
         output_bit(PIN_A2,0);   
         
      //FILA_3:
         output_bit(PIN_A6,1); 
         //COLUMNA:
         if(input(PIN_A0)==1) //No. 7
         {
            i = i - 1;
            vector[i] = 7;
               while(input(PIN_A0) != 0)
               {
                  output_toggle(PIN_B7);
                  delay_ms(1);                  
               }  
         }
                             
         if(input(PIN_A1)==1) //No. 8
         {
            i = i - 1;
            vector[i] = 8;
               while(input(PIN_A1) != 0)
               {
                  output_toggle(PIN_B7);
                  delay_ms(1);                  
               }
         }
                             
         if(input(PIN_A5)==1) //No. 9
         {
            i = i - 1;
            vector[i] = 9;
               while(input(PIN_A5) != 0)
               {
                  output_toggle(PIN_B7);
                  delay_ms(1);                  
               }
         }
            
         delay_ms(35); 
         output_bit(PIN_A6,0); 
         
      //FILA_4:
         output_bit(PIN_A7,1); 
         //COLUMNA:
         if(input(PIN_A0)==1) //No. 10
         {
            i = i - 1;
            vector[i] = 10;
               while(input(PIN_A0) != 0)
               {
                  output_toggle(PIN_B7);
                  delay_ms(1);                  
               } 
         }
                             
         if(input(PIN_A1)==1) //No. 0
         {
            i = i - 1;
            vector[i] = 0;
               while(input(PIN_A1) != 0)
               {
                  output_toggle(PIN_B7);
                  delay_ms(1);                  
               } 
         }
            
         if(input(PIN_A5)==1) //No. 11
         {
            i = i - 1;
            vector[i] = 11;
               while(input(PIN_A5) != 0)
               {
                  output_toggle(PIN_B7);
                  delay_ms(1);                  
               } 
         }
                             
         delay_ms(35); 
         output_bit(PIN_A7,0);   

   } //Fin del While
   if(vector[0] == 5 && vector[1] == 9 && vector[2] == 7 && vector[3] == 2)
   {
      for(int t = 0; t < 2; t++)
      {
         output_b(7);
         delay_ms(500);
         output_b(0);
         delay_ms(500);
      }
         goto IngresaN;
   }
   else
   {
         output_b(112);
         delay_ms(2000);
         output_b(0);
         goto IngresaN;
   }
} //Fin del Programa

