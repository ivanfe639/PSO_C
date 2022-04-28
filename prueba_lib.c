#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "functions_matlab.h"
#include "Seeder.h"
#include "Chk_Feas.h"

int main(){

int i,j;
double a;
int filas=30;
int colum=2;
int mat[filas][colum],*pmat;
pmat=&mat[0][0];
int myvector[2]={12,24};
int qw[4]={0,1,2,3},*Pqw;
int er[4]={0,0,0,0},*Per;
/*
zeros(filas, colum, pmat);

for (i=0; i<30; i++){
  for (j=0; j<2; j++){

    printf("mat[%i][%i]= %i\n",i,j,*(pmat+i*colum+j));
  }
}
*/
/* 
//prueba Seeder.c
int particulas=10;

const int nd=2;

float bnd[2][2]={{-5,5},{2,3}};
float *pbnd;
float X[particulas][2],*pX;

pbnd=&bnd[0][0];
pX=&X[0][0];


Seeder(pbnd,nd,pX,0);
printf("f_prueba1([%f,%f]) ",*(pX),*(pX+1));
printf("\n");

float q;

q=f_prueba1(*(pX),*(pX+1));
printf("\n %f",q);
*/
/*
// Prueba Chk_Feas.c
float bnd[2][2]={{0,6.2832},{0,6.2832}};
float *pbnd;
float X[2]={1.6545, 2.6532};
pbnd=&bnd[0][0];
int RngOk;
RngOk=Chk_Feas(X,pbnd,1);

printf("RngOk= %i\n",RngOk);
for (j=0; j<2; j++){

    printf("Xnuevo= %f \t",X[j]);
}
*/
Per=&qw[0];

for (j=0; j<4; j++){
    printf("er= %i \n",*(Per+j));

}

}



