/* 
   Nombre: Functions_matlab.c
   Autor: Ivan Obregon
   Fecha: 25 de Febrero de 2015
   Descripción: Funciones generales utilizadas en matlab y recopilacion de funciones de prueba
*/
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

/*************************
Recordar cómo se forman las matrices:

*puntero: Tiene la posición de memoria de un vector, si se quiere implementar una matriz, lo que se hace es lo siguiente:

matriz[m][n]

*puntero será una matriz de una sola fila con m*n elementos, sin embargo, solo tendrá un sentido para recorrer la misma

for(k=0;k<n;k++){
  for(i=0;i<m;i++){
    *(puntero+i+k*m)=Valor; //Este valor será el asignado a la matriz[i][k]
  }
}
  
Sin embargo, el puntero puede hacer referencia a tal matriz para efectos de visualización, de la siguiente manera:
puntero=&matriz[0][0]
La anterior línea se puede colocar en cuanto se define la matriz[m][n], el puntero simplemente apunta a tal matriz



**************************/

void zeros(int m, int n,double *p_zeros){
int i,j;
for(i=0;i<m;i++){
  for(j=0;j<n;j++){
   *(p_zeros+i*n+j)=0;
  }
}
}

//Generación de matriz m*n de unos
void ones(int m, int n,int *p_one){
int i,j;
for(i=0;i<m;i++){
  for(j=0;j<n;j++){
   *(p_one+i*n+j)=1;
  }
}
}

/*
m: Tamaño de la población
n: Tamaño de bits del individuo
*dist: Vector de distancias (Error del individuo en general)
*temp_mag: Error medio cuadrático por población
*/
//Validación del error medio cuadrático
void error_rms(int m, int n,double *dist,double *temp_mag){
int i,j;double mag[m];
for(i=0;i<m;i++){
  mag[i]=0;
  for(j=0;j<n;j++){
    mag[i]=mag[i]+pow(*(dist+i*n+j),2);
  }
  *(temp_mag+i)=sqrt(mag[i]/m);
}
}

//Saca el mínimo de un vector (*vector) y retorna el índice dónde es mínimo, además, el minimo con el puntero *min
int min(double *vector, int m,double *min){
int k,index=0;double minimo;
minimo=*(vector);
for (k=1;k<m;k++){
  if (*(vector+k)<minimo){
    minimo=*(vector+k);
    index=k;
  }
}
*min=minimo;
return index;
}

//Saca el máximo de un vector (*vector) y retorna el índice dónde es máximo, además, el máximo con el puntero *max
int max(double *vector,int m,double *max){
int k,index=0;double maximo;
maximo=*vector;
for (k=1;k<m;k++){
  if (*(vector+k)>maximo){
    maximo=*(vector+k);
    index=k;
  }
}
*max=maximo;
return index;

}

//Generación de Función de prueba Ackley
double ackley(double xx,double yy)
{
    int i;
    int n_dimentions = 2;
    double a, b, c;
    double sum1=0, sum2=0, term1, term2, z;

    a = 20;
    b = 0.2;
    c = 2* M_PI;

    sum1=pow(xx,2) + pow(yy,2);
    sum2=cos(c*xx) + cos(c*yy);
 
    term1 = -a * exp(-b*sqrt(sum1/n_dimentions));
    term2 = -exp(sum2/n_dimentions);

    z = term1 + term2 + a + exp(1);

    return z;
}

double f_prueba1(double xx,double yy){
  double z;

  z=10*sin(10*sqrt((pow(xx,2)) + (pow(yy,2))))*exp(-sqrt((pow(xx+1,2)) + (pow(yy-1,2))));
  return z;
}

double bohachevsky(double xx,double yy){

    double term1, term2, term3, term4, z;

    term1 = pow(xx,2);
    term2 = 2*pow(yy,2);
    term3 = -0.3 * cos(3*M_PI*xx);
    term4 = -0.4 * cos(4*M_PI*yy);
    z = term1 + term2 + term3 + term4 + 0.7;
    return z;
}

double rastrigin(double xx,double yy)
{
    int i;
    int n_dimentions = 2;
    double sum, z;
    
		sum=pow(xx,2) - 10*cos(2*M_PI*xx) + pow(yy,2) - 10*cos(2*M_PI*yy);
    z= 10*n_dimentions + sum;
    return z;
}

double bukin6(double xx,double yy)
{
    double term1, term2, z;
    
		term1 = 100 * sqrt(fabs(yy - 0.01*pow(xx,2)));	
    term2 = 0.01 * fabs(xx+10);

    z= term1 + term2;

    return z;
}

double drop(double xx,double yy)
{
    double frac1, frac2, z;
    
		frac1 = 1 + cos(12*sqrt(pow(xx,2)+pow(yy,2)));
		frac2 = 0.5*(pow(xx,2) + pow(yy,2)) + 2;

    z= -frac1/frac2;

    return z;
}

double egg(double xx,double yy)
{
    double term1, term2, z;
    
		term1 = -(yy+47)*sin(sqrt(fabs(yy+(xx/2)+47)));
		term2 = -xx*sin(sqrt(fabs(xx-(yy+47))));

    z= term1 + term2;

    return z;
}

double holder(double xx,double yy)
{
    double fact1, fact2, z;
    
		fact1=sin(xx)*cos(yy);
		fact2=exp(fabs(1-(sqrt(pow(xx,2)+pow(yy,2)))/(M_PI)));

    z= -fabs(fact1*fact2);

    return z;
}

double schaffer2(double xx,double yy)
{
    double fact1, fact2, z;
    
		fact1=pow((sin(pow(xx,2)-pow(yy,2))),2) - 0.5;
		fact2=pow((1 + 0.001*(pow(xx,2)+pow(yy,2))),2);

    z= 0.5 + fact1/fact2;

    return z;
}























