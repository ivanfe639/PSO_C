/* 
   Nombre: functions_matlab.h
   Autor: Ivan Obregon
   Fecha: 25 de Febrero de 2015
   Descripción: Cabecera de las funciones generales utilizadas en matlab y recopilacion de funciones de prueba
   !!!Fijarse en el tipo de variable de cada funcion eg. int,float,double, etc.
*/
#ifndef functions_matlab_h
#define functions_matlab_h

/*
Función ones
Esta función genera una matriz m*n casillas con valores de 1

Entradas
m: Número de filas
n: Número de columnas
*p_one: puntero a matriz de unos

Esta función no arroja salidas, sin embargo el resultado se evidencia en el puntero *p_one
*/
void ones(int m, int n,int *p_one);

/*
Funcion Zeros
Genera una matrizde m*n cuyos valores son ceros (0)
m: Numero de filas 
n: Numero de columnas
*p_zeros: puntero deonde se almacenara la salida
*/
void zeros(int m, int n,double *p_zeros);

/*
Función error_rms
Esta función sirve para realizar la validación del error medio cuadrático

Entradas
m: Tamaño de la población
n: Tamaño de bits del individuo
*dist: Vector de distancias (Error del individuo en general)
*temp_mag: Error medio cuadrático por población

La salida de esta función se evidencia en el puntero *temp_mag
*/
void error_rms(int m, int n,double *dist,double *temp_mag);

/*Función min
Esta función evalúa el mínimo de un vector (*vector) y retorna el índice dónde es mínimo, además, el mínimo con el puntero *min

Entradas
*vector: Arreglo a evaluar cuál es su menor valor
m: Longitud del vector a evaluar
*min: Mínimo valor encontrado

Salidas
Entero con el índice en dónde se ubica el menor valor en el vector
*/
int min(double *vector, int m,double *min);



/*Función max
Esta función evalúa el máximo de un vector (*vector) y retorna el índice dónde es máximo, además, el máximo con el puntero *max

Entradas
*vector: Arreglo a evaluar cuál es su mayor valor
m: Longitud del vector a evaluar
*max: Máximo valor encontrado

Salidas
Entero con el índice en dónde se ubica el mayor valor en el vector
*/
int max(double *vector,int m,double *max);



/*Función genMaskXor
Esta función genera una matriz binaria a partir de un umbral mut_rate (entre 0 y 1) y con el resultado de esta matriz se realiza un xor con el vector de población (*popu)

Entradas
m: Longitud de las filas de la matriz de población
n: Longitud de las columnas de la matriz de población
mut_rate: Rata máxima de mutación
*popu: Arreglo para calcular la matriz de la nueva población

Salidas
La función no tiene salidas, sin embargo el resultado se aloja en la matriz de población *popu
*/
void genMaskXor(int m, int n, double mut_rate, int *popu);


/*Función genMask
Esta función genera una matriz binaria a partir de un umbral (entre 0 y 1) y da como resultado una matriz aleatoria de 1s y 0s

Entradas
m: Longitud de las filas de la matriz de población
n: Longitud de las columnas de la matriz de población
umbral: Límite máximo para el cual se generará un 1 en la matriz
*mask: Arreglo para calcular la matriz máscara
sign: Signo de "mayor que" (>) y "menor que" (<) para generar la máscara

Salidas
La función no tiene salidas, sin embargo el resultado se aloja en la matriz de población *mask
*/
void genMask(int m, int n, double umbral,int *mask,char sign);


/*Función ackley
======================================================
Minimo de la funcion en el punto [0,0] valor 0    ||_\\
Valores de entrada X y Y entre [-32.768 , 32.768] || // 
======================================================

Entradas
xx: El valor del punto en x.
yy: El valor del punto en y.
Salidas
La salida es el cálculo de la funcion Ackley.
*/
double ackley(double xx,double yy);

/*Funcion de prueba #1

===========================================================================
Minimo de la funcion en el punto [-1.214745,1.214745] valor -7.344226  ||_\\
Valores de entrada X y Y entre [-10,10]                                || // 
===========================================================================

Entradas:
xx: El valor del punto en x.
yy: El valor del punto en y.

Salidas:
z: valor de la imagen en el punto (x,y).

*/
double f_prueba1(double xx,double yy);

/*Funcion Bohachevsky

======================================================
Minimo de la funcion en el punto [0,0] valor 0    ||_\\
Valores de entrada X y Y entre [-100 , 100]       || // 
======================================================

Entradas:
xx: El valor del punto en x.
yy: El valor del punto en y.

Salidas:
z: valor de la imagen en el punto (x,y).

*/
double bohachevsky(double xx,double yy);

/*Funcion Rastrigin
	
=====================================================
Minimo de la funcion en el punto [0,0] valor 0   ||_\\
Valores de entrada X y Y entre [-5.12 , 5.12]  	 || // 
=====================================================
Entradas:
xx: El valor del punto en x.
yy: El valor del punto en y.

Salidas:
z: valor de la imagen en el punto (x,y).

*/
double rastrigin(double xx,double yy);

/*Funcion Bukin N°6

=============================================================
Minimo de la funcion en el punto [-10,1] valor 0   		    ||_\\
Valores de entrada X entre [-15 , -5] y Y entre[-3 , 3]   || // 
=============================================================
Entradas:
xx: El valor del punto en x.
yy: El valor del punto en y.

Salidas:
z: valor de la imagen en el punto (x,y).

*/
double bukin6(double xx,double yy);

/*Funcion Drop-Wave 

====================================================
Minimo de la funcion en el punto [0,0] valor -1  ||_\\
Valores de entrada X y Y entre [-5.12 , 5.12]    || // 
====================================================
Entradas:
xx: El valor del punto en x.
yy: El valor del punto en y.

Salidas:
z: valor de la imagen en el punto (x,y).

*/
double drop(double xx,double yy);

/*Funcion Egg-Holder 

====================================================================
Minimo de la funcion en el punto [512,404.2319] valor -959.6407  ||_\\
Valores de entrada X y Y entre [-512 , 512] 									   || // 
====================================================================
Entradas:
xx: El valor del punto en x.
yy: El valor del punto en y.

Salidas:
z: valor de la imagen en el punto (x,y).

*/
double egg(double xx,double yy);


/*Funcion Holder Table

=========================================================================
Minimo de la funcion en el punto [±8.05502,±9.66459] valor -19.2085  ||_\\
Valores de entrada X y Y entre [-10 , 10]       									   || // 
========================================================================
Entradas:
xx: El valor del punto en x.
yy: El valor del punto en y.

Salidas:
z: valor de la imagen en el punto (x,y).

*/
double holder(double xx,double yy);


/*Funcion Schaffer N°2

=======================================================
Minimo de la funcion en el punto [ 0 , 0 ] valor 0  ||_\\
Valores de entrada X y Y entre [-100 , 100]         || // 
=======================================================
Entradas:
xx: El valor del punto en x.
yy: El valor del punto en y.

Salidas:
z: valor de la imagen en el punto (x,y).

*/
double schaffer2(double xx,double yy);


#endif

