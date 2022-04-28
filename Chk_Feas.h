/* 
   Nombre: seeder.h
   Autor: Ivan Obregon
   Fecha: 25 de Febrero de 2015
   Descripción: Cabecera de la funcion que revisa y/o genera unos nuevos valores al vector
*/
#ifndef Chk_feas_h
#define Chk_feas_h


/* Chk_Feas
*X: El vector de dos posiciones a comprobar si esta dentro del rango (VECTOR)
*bnd: El puntero de la matriz de frontera (PUNTERO)
res_mode: El tipo de correccion, 1 para generar un numero aleatorio dentro y 2 para acercarlo a la frontera (ENTERO)
*/
int Chk_Feas(double *X,double *bnd,int res_mode);

#endif
