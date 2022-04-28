/* 
   Nombre: Chk_Feas.h
   Autor: Ivan Obregon
   Fecha: 27 de Febrero de 2015
   Descripción: funcion que revisa y/o genera unos nuevos valores al vector *X
*/

#include "math.h"
#include "stdlib.h"
#include "stdio.h"
//#include <time.h>

int Chk_Feas(double *X,double *bnd,int res_mode){
int RngOk = 1;
struct timeval time; 
int i;
float blo,bup;
int cifras=100000;

for (i=0; i<2; i++){
  blo=*(bnd+2*i);
  bup=*(bnd+2*i+1);
  gettimeofday(&time,NULL);
  srand((time.tv_usec * 1000));

  if (X[i] < blo || X[i] > bup) {
    RngOk=0;  //Almenos un valor se encuentra por fuera de los rangos
    
    switch(res_mode){
      case 1:
        //X[i] = blo + rand()%(int)((bup-blo)*1000)/1000;
        X[i] = (double)(rand()%(int)((bup-blo)*cifras))/cifras + blo;
	break;

      case 2:
	if (X[i] <= blo){
          X[i] = blo;
        }
	else{
	  X[i] = bup;
	}
      default:
	X[i]=X[i];
    }
  }
}

return RngOk;

}
