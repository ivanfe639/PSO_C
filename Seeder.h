/* 
   Nombre: seeder.h
   Autor: Ivan Obregon
   Fecha: 25 de Febrero de 2015
   Descripción: Cabecera de la funcion que genera un vector de numeros aleatorios dentro de un rango
*/
#ifndef functions_matlab_h
#define functions_matlab_h


/*
bnd: matriz de ndx2 que dice el intervalo donde se debe generar el numeor aleatorio
nd: Numero de dimensiones
*salida: es el punturo de salida donde se guardara los numero aleaotorios generados
offset: es la posicion donde guardara los valores aleaotorios generados

*/
//%void Seeder(in d);
void Seeder(double *bnd,int nd, double *salida,int offset);


#endif
