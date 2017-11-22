#include <stdlib.h>;
#include <conio.h>;
#include <stdio.h>;

shared int cierto = 1;
 
 /* Definición de variables compartidas */ 
 shared int bandera[2] = {0,0};   
 shared int turno      = 0; 
 
 while (cierto)
 {
    bandera[proc_id] = cierto;
    while (bandera[1-proc_id] == cierto)
    {
       if (turno == 1-proc_id)
       {
          bandera[proc_id] = 0;
          while (turno == (1-proc_id))  /* espera a que sea su turno de intentar */;
          bandera[proc_id] = 1;
       }
    }
    /* ''Sección crítica'' */
    turno = 1-proc_id;                 /* es el turno del otro proceso */
    bandera[proc_id] = 0;
    /* ''Sección no crítica'' */
 }
 
 
 
 
 //other section
boolean p1_puede_entrar, p2_puede_entrar;
int turno;
 
Proceso1()
{
 while( true )
 {
  [REALIZA_TAREAS_INICIALES]
  p1_puede_entrar = true;
  while( p2_puede_entrar )
  {
   if( turno == 2 )
   {
    p1_puede_entrar = false;
    while( turno == 2 ){}
    p1_puede_entrar = true;
   }
  }
  [REGION_CRITICA]
  turno = 2;
  p1_puede_entrar = false;
  [REALIZA_TAREAS_FINALES]
 }
}
 
Proceso2()
{
 while( true )
 {
  [REALIZA_TAREAS_INICIALES]
  p2_puede_entrar = true;
  while( p1_puede_entrar )
  {
   if( turno == 1 )
   {
    p2_puede_entrar = false;
    while( turno == 1 ){}
    p2_puede_entrar = true;
   }
  }
  [REGION_CRITICA]
  turno = 1;
  p2_puede_entrar = false;
  [REALIZA_TAREAS_FINALES]
 }
}
 
iniciar()
{
 p1_puede_entrar = false;
 p2_puede_entrar = false;
 turno = 1;
 Proceso1();
 Proceso2();
}
