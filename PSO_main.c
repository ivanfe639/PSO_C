/* 
   Nombre: PSO_main.h
   Autor: Ivan Obregon
   Fecha: 2 de Marzo de 2015
   Descripción: Algoritmo PSO implementado en C
*/

#include "stdio.h"
#include "stdlib.h"
#include "functions_matlab.h"
#include "Seeder.h"
#include "Chk_Feas.h"
#include <time.h>

/*función para medir el tiempo*/
double timeval_diff(struct timeval *x, struct timeval *y){
	return
	(double)(x->tv_sec + (double)x->tv_usec/1000000) -
	(double)(y->tv_sec + (double)y->tv_usec/1000000);	
	}


int main(){
//%%%%%%%%%%%%%%%%%%%%%%%% Variables de entrada %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
double (*target_function)(double xx,double yy);

//target_function=&bohachevsky;
//target_function=&f_prueba1;
//target_function=&ackley;
//target_function=&rastrigin;
//target_function=&bukin6;
//target_function=&drop;
//target_function=&egg;
//target_function=&holder;
target_function=&schaffer2;

const int particulas=500;   //afecta mas el numero de particulas que el numero de iteraciones
int iteraciones=100;
double w=0.5;
double c1=2.05;
double c2=2.05;
double bnd[2][2]={{-100,100},			//Rango donde actua la funcion *ver el archivo functions_matlab.h
		 						  {-100,100}}; 
int nd=2;
int cifras=100000;
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
double secs;  
int index;
struct timeval tempo,t_ini,t_fin; 
double *pbnd;
pbnd=&bnd[0][0];
int i,j;
double r1,r2;
double V[particulas][2]; //Velocidades
double X[particulas][2],*pX;		//presenteX
double *pPi;
double Z[particulas],*pZ;
double minPi,*pminPi;
double Pg[2];
double Xt[2];
double Yt;
double Zp;
double Yg;
pX=&X[0][0];
pZ=&Z[0];
pminPi=&minPi;

// 1) primer paso defino los valores iniciales de X"presente" y V"velocidades"

gettimeofday(&t_ini,NULL);
for (i=0; i<particulas; i++){
  Seeder(pbnd,nd,pX,i);
  Z[i]=target_function(*(pX+2*i),*(pX+2*i+1));  	//Imagenes de presenteX
}
/*
for (i=0; i<30; i++){
  for (j=0; j<2; j++){
     printf("%lf \t",X[i][j]);
  }
  printf("\n");
}
*/

// 2) Encontrar valores de Pi"pbestx" y Pg"gbest" la mejor posicion de todos

pPi=&X[0][0]; //los mejores valores de X pbestx
index=min(pZ,particulas,pminPi); //Guarda el valor y la posicion del mejor osea el minimo de las imagenes


Pg[0]=X[index][0];
Pg[1]=X[index][1];
printf("Punto de partida  [%lf , %lf] \n",Pg[0],Pg[1]);

for (j=0; j<iteraciones; j++){
  // 3) Actualizar posicion y velocidad 
  for (i=0; i<particulas; i++){
    gettimeofday(&tempo,NULL);
    srand((tempo.tv_usec * 1000));

    r1=(double)(rand()%(int)(cifras))/cifras;
    r2=(double)(rand()%(int)(cifras))/cifras;
    //printf("r1= %lf  r2=%lf\n",r1,r2);

    V[i][0]=w*V[i][0] + c1*r1*(*(pPi+2*i+0)-X[i][0]) + c2*r2*(Pg[0]-X[i][0]);
    V[i][1]=w*V[i][1] + c1*r1*(*(pPi+2*i+1)-X[i][1]) + c2*r2*(Pg[1]-X[i][1]);
    Xt[0]=X[i][0]+V[i][0];
    Xt[1]=X[i][1]+V[i][1];


    // Evalua si el valor está dentro de la frontera

    Chk_Feas(Xt,pbnd,1);

    Yt=target_function(Xt[0],Xt[1]);

    // Evalua si el nuevo valor es mejor para actualizar la posicion de la particula
    if (Z[i]>Yt){
      X[i][0]=Xt[0];
      X[i][1]=Xt[1];
    }
    
    // 4) Obtener el nuevo Pi
    
    Zp=target_function(X[i][0],X[i][1]);
    if (Z[i]>Zp){
      *(pPi+2*i+0)=X[i][0];
      *(pPi+2*i+1)=X[i][1];
      Z[i]=Zp;
    }

    // 5) Obtener el nuevo Pg

    Yg=target_function(Pg[0],Pg[1]);
    if (Yg>Zp){
      Pg[0]=X[i][0];
      Pg[1]=X[i][1];

    }
    
  }
  //printf("Pg's  [%lf , %lf] \n",Pg[0],Pg[1]);
}
gettimeofday(&t_fin,NULL);
printf("La respuesta es el punto: [ %lf , %lf ] y su imagen es %lf",Pg[0],Pg[1],target_function(Pg[0],Pg[1]));

//===============impresion del tiempo de duracion =================
	secs = timeval_diff(&t_fin, &t_ini);
  	printf("\n\n tiempo de duracion %.16g [ms]\n", secs * 1000.0);		//impresión del tiempo total en [ms]

/*
double qwe;
qwe=schaffer2(Pg[0],Pg[1]);
printf("\n valor= %lf \n",qwe);
*/
}

