/* 
   Nombre: seeder.h
   Autor: Ivan Obregon
   Fecha: 25 de Febrero de 2015
   Descripción: funcion que genera un vector de numeros aleatorios dentro de un rango
*/

#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include <time.h>

void Seeder(double *bnd, int nd, double *salida,int offset){
int cifras=100000;	//El numero de ceros es para darle mas cifras significativas al numero aleatorio
int i;
double a;
struct timeval time; 
gettimeofday(&time,NULL);
// microsecond has 1 000 000
// Assuming you did not need quite that accuracy
// Also do not assume the system clock has that accuracy.
srand((time.tv_usec * 1000));

for (i=0; i<nd; i++){
  //num=(*(bnd+i*2+1)-*(bnd+i*2))*cifras;
  a=(double)(rand()%(int)((*(bnd+i*2+1)-*(bnd+i*2))*cifras))/cifras+*(bnd+i*2);
  *(salida+i+offset*2)=a;
}

}
