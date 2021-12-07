   // ---------------------------------------------------------------------------------
//
//  ALGORITMIA: IMPLEMENTACION SEGUN BACKTRACKING DE LA SOLUCION DEL PROBLEMA DE
//              DESCOMPONER
//              UN NUMERO N EN M SUMANDOS CON N>=M>0 DE TAL MODO QUE LOS M SUMANDOS
//              SUMEN N Y SU PRODUCTO SEA MAXIMO. SE GENERARAN ADEMAS: TODAS LAS
//              SOLUCIONES FACTIBLES Y LA PRIMERA FACTIBLE.
//
//
//  SESION 3 DE PRACTICAS DE ESQUEMAS ALGORITMICOS
//
//  Fechas: del 29 de noviembre al 3 de diciembre de 2021
//
// ----------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

// prototipos de las funciones backtracking
void DESCOMPONER_BACK_TODAS(int , int , int , int *);
// void DESCOMPONER_BACK_UNA(int , int , int , int *, bool *);
// void DESCOMPONER_BACK_OPTIMA(int , int , int , int *, int *, int *);

// prototipos de las funciones auxiliares que utiliza backtracking: correcto, valor, tratar

// funcion main
int main(){
   int N,M;
   int *x,*x_mejor,v_mejor;
   bool flag;

   do{
      printf ("\nIntroduce el numero a descomponer: ");
      scanf("%d",&N);
   }while(N<=0);

   do{
      printf ("\nIntroduce el numero de sumandos: ");
      scanf("%d",&M);
   }while(M>N);

   //
   // Los vectores x y x_mejor tienen tamaño M
   //

   x=(int*)malloc(M*sizeof(int));
   //x_mejor=(int *)malloc(M*sizeof(int));

   // invocamos a TODAS_LAS_FACTIBLES de BACKTRACKING
   //printf("\n\nTODAS LAS SOLUCIONES FACTIBLES\n");
   //DESCOMPONER_BACK_TODAS(N,M,0,x);

   // invocamos a UNA_FACTIBLE de BACKTRACKING
   //printf("\n\nUNA TUPLA FACTIBLE:\n");
   //flag=true;
   //DESCOMPONER_BACK_UNA(N,M,0,x,&flag);

   // invocamos a OPTIMA de BACKTRACKING
   printf("\n\nSOLUCION OPTIMA:\n");
   v_mejor=INT_MIN;
   DESCOMPONER_BACK_OPTIMA(N,M,0,x,x_mejor,&v_mejor);

   // mostrar la solucion (secuencia de decisiones optima y beneficio maximo)
   tratar(x_mejor,M);
   printf("\t\tEl producto maximo de la descomposicion es: %d\n", v_mejor);

   // liberar memoria
   free(x);
   //free(x_mejor);

   return 0;
}


//
// BACKTRACKING
//

// definiciones de las funciones auxiliares que utiliza backtracking: correcto, valor y tratar
// TAREA A REALIZAR POR EL ALUMNO

/*
   Retornará el sumatorio de los k elementos de x
*/
int suma (int * x, int k) {
   int suma = 0;
   for (int i = 0 ; i<=k ; i++) {
      suma = suma + x[i];
   }
   return suma;
}

/*
   Imprimirá por pantalla el vector x -sucesión de decisiones final-
*/
void tratar (int *x, int n){
    int i;
    printf("\n\t< ");
    for (i=0;i<n;i++){
        printf("%d ",x[i]);
    }
    printf(">");
}
/*
   Retornará el productorio de los elementos de x
*/
int valor (int *x, int m) {
   int productorio = 1;
   for (int i = 0; i<m; i++) {
      productorio = productorio * x[i];
   }
   return productorio;
}

//Descompone el número N en M operandos, siendo su productorio máximo
/*
   N - El número a descomponer
   M - El número de números en los que se descompone N
   k - El nivel del árbol
   x - Sucesión
*/
void DESCOMPONER_BACK_TODAS(int N, int M, int k, int *x){
   // TAREA A REALIZAR POR EL ALUMNO
   x[k] = 0;   //Preparar hermano nivel k
   while (x[k] < N-M+1) { //Mientras haya hermano nivel k
      x[k]=x[k]+1;  //siguiente hermano nivel k
      if (k==M-1 && suma(x,k) == N) {
         tratar (x, M);
      }
      if (k <M-1 && suma(x,k) < N) {
         DESCOMPONER_BACK_TODAS(N, M, k+1, x);
      }
   }
}

void DESCOMPONER_BACK_UNA(int N, int M, int k, int *x, bool *flag){
      // TAREA A REALIZAR POR EL ALUMNO
   x[k] = 0;   //Preparar hermano nivel k
   while (x[k] < N-M+1 && *flag) { //Mientras haya hermano nivel k
      x[k]=x[k]+1;  //siguiente hermano nivel k
      if (k==M-1 && suma(x,k) == N) {
         *flag = false;
         tratar (x, M);
      }
      if (k <M-1 && suma(x,k) < N) {
         DESCOMPONER_BACK_UNA(N, M, k+1, x, flag);
      }
   }
}


//memcpy (x_mejor, x, <ALGO>, n*sizeof(int));

 void DESCOMPONER_BACK_OPTIMA(int N, int M, int k, int *x, int *x_mejor, int *v_mejor){
      // TAREA A REALIZAR POR EL ALUMNO
   int aux;
   x[k] = 0;   //Preparar hermano nivel k
   while (x[k] < N-M+1) { //Mientras haya hermano nivel k
      x[k]=x[k]+1;  //siguiente hermano nivel k
      if (k==M-1 && suma(x,k) == N) {
         aux = valor (x, M);
         if (aux > *v_mejor) {
            *v_mejor = aux;
            memcpy (x_mejor, x, M*sizeof(int));
         }
      }
      if (k <M-1 && suma(x,k) < N) {
         DESCOMPONER_BACK_OPTIMA(N, M, k+1, x, x_mejor, v_mejor);
      }
   }
}
