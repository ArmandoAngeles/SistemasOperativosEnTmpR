#include <16f627a.h>
#FUSES INTRC_IO
#FUSES NOMCLR
#FUSES NOLVP
#FUSES NOPROTECT

#use delay(clock=4000000)

int prioridad=0;
int tempo=0;

#int_timer0

void timer0(){
   tempo++;
   if (prioridad==1)
      prioridad=0;
   else
      prioridad++;
   set_timer0(0); 
}

#include <lcd.c>

void main(){ 
   set_tris_a(0x00);
   set_tris_b(0x00);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_256|RTCC_8_bit);
   set_timer0(0);
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);


   lcd_init();
   while(TRUE){
      switch (prioridad)
      {
         case 0:
            if (tempo==9)
            {
               output_toggle(PIN_B3);
               tempo=0;
            }
            break;
         case 1:
            lcd_putc("\fEjecutando\nTarea 2");
            break;
         default:
            break;
      }
   } 
}
