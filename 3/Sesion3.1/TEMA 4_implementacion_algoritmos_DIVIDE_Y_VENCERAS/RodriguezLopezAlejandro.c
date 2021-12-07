//
// ALGORITMIA: PRACTICA DE DIVIDE Y VENCERAS
//
// Maximo_vector y Producto_vector
//
// Copyright: Raquel Cortina
//
// Fecha: 11 de noviembre de 2021
//
// --------------------------------------------------------------------------------------------------------------------------------
//
// Programa en el que se pide el tamanio del vector (n>=1), se reserva dinamicamente memoria,
// se leen sus elementos. Los elementos se muestran por pantalla y seguidamente, a traves de las funciones
// MAXIMO_VECTOR y PRODUCTO_VECTOR, que siguen el esquema de divide y venceras, se busca el elemento de mayor
// valor en el vector y se calcula el producto de los elementos del vector respectivamente.
//
// OPCIONAL: Programa en el que se pide el numero de filas y de columnas de la matriz (n,m>=1), se reserva dinamicamente memoria,
// se leen sus elementos. Los elementos se muestran por pantalla y seguidamente, a traves de la funcion
// EXAMEN_RECURSION_NOVIEMBRE_2021, que sigue el esquema de divide y venceras, se resuelve el problema 1 del examen del tema 2:
//
// "Dada una matriz de enteros A[1..n][1..m] siendo n≥1 y m≥1, diseniar una funcion recursiva que retorne cierto si se cumple
// que para cada fila  el numero de ceros que contiene es menor o igual que el numero de ceros que contiene la fila inmediatamente
// siguiente, y falso en caso contrario"
//
//---------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// prototipos de funciones
int lee_vector(int *, int);
int escribe_vector(int *, int);
int maximo_vector_DyV(int *,int,int);
int producto_vector_DyV(int *,int,int);

int lee_vector_reales(float *, int);
int escribe_vector_reales(float *, int);
float media_aritmetica_DyV(float *, int, int);

// PROBLEMA 1 DEL EXAMEN RECURSION NOVIEMBRE 2021

void lee_matriz (int **, int, int);
void escribe_matriz (int **, int, int);
bool EXAMEN_RECURSION_NOVIEMBRE_2021 (int **, int, int, int);
int cuentaCeros (int **, int, int);
int interseccion (int **, int, int);

// programa principal
int main() {
/*
    int n,m,x;
    int *V;
    float *W;

    do{
       printf("\nIntroduce el numero de elementos del vector para obtener el maximo y el producto (>=1): ");
       scanf("%d",&n);} while (n<1);

    // reservar dinamicamente memoria
    V = (int*) malloc(n*sizeof(int));


    lee_vector(V,n);
    escribe_vector (V,n);

    printf("\nEl maximo de los elementos del vector es %d\n\n",maximo_vector_DyV(V,0,n-1));
    printf("\nEl producto de los elementos del vector es %d\n\n",producto_vector_DyV(V,0,n-1));

    do{
       printf("\nIntroduce el numero de elementos del vector para obtener la media aritmetica (>=1): ");
       scanf("%d",&m);} while (m<1);

    // reservar dinamicamente memoria
    W = (float*) malloc(m*sizeof(float));

    lee_vector_reales(W,m);
    escribe_vector_reales(W,m);
    printf("\nLa media aritmetica del vector es: %f\n\n",media_aritmetica_DyV(W,0,m-1));

    //liberar memoria
    free(V);
    free(W);

*/
// PROBLEMA 1 DEL EXAMEN RECURSION NOVIEMBRE 2021

    int n,m;
    printf("Dame el numero de filas: ");
    scanf("%d",&n);
    printf("Dame el numero de columnas: ");
    scanf("%d",&m);

    // definimos una variable de tipo puntero a puntero a int y reservamos memoria para n filas
    int **M = (int**) malloc(n*sizeof(int*));

    //reservamos espacio para las columnas
    for(int i=0;i<n;i++)
            M[i] = (int*) malloc(m*sizeof(int));

    // Leemos la matriz
    lee_matriz (M,n,m);


    printf("\n\nLa matriz introducida es:\n\n");

    // Mostramos el contenido de la matriz
    escribe_matriz (M,n,m);

    //Invocamos a la funcion que comprueba
    if (EXAMEN_RECURSION_NOVIEMBRE_2021(M,0,n-1,m)) printf("Se cumple que cada fila tiene un numero de ceros menor o igual que la fila inmediatamente siguiente\n\n");
    else printf("No se cumple que cada fila tiene un numero de ceros menor o igual que la fila inmediatamente siguiente\n\n");

    // Liberamos el espacio reservado para las columnas
    for (int i=0;i<n;i++) free(M[i]);

    // Liberamos el espacio reservado para las filas
    free(M);

    return 0;
}

//
// Definiciones de funciones
//

// Funcion para leer las componentes del vector
int lee_vector(int *V, int n){
    for (int i=0;i<n;i++) {
        printf("\nDame el valor de la componente %d: ",i+1);
    scanf("%d",V+i);
    }
    return 0;
}

// Funcion para escribir las componentes del vector
int escribe_vector(int *V, int n){
    printf("\nEl vector introducido es: [ ");
    for (int i=0;i<n;i++) {
        printf("%d ",*(V+i));
    }
    printf("]\n");
    return 0;
}

int lee_vector_reales(float *V, int n){
    for (int i=0;i<n;i++) {
        printf("\nDame el valor de la componente %d: ",i+1);
    scanf("%f",V+i);
    }
    return 0;
}

int escribe_vector_reales(float *V, int n){
    printf("\nEl vector introducido es: [ ");
    for (int i=0;i<n;i++) {
        printf("%f ",*(V+i));
    }
    printf("]\n");
    return 0;
}


void lee_matriz (int **M, int n, int m){
    int i,j;
    for (i=0;i<n;i++)
        for (j=0;j<m;j++){
            printf("Dame el elemento [%d,%d] :  ",i+1,j+1);
            scanf("%d",&M[i][j]);
            // otra opcion
            //scanf("%d",M[i]+j);
            // y otra opcion
            //scanf("%d",*(M+i)+j);
        }
    }

void escribe_matriz (int **M, int n, int m){
    int i,j,aux;
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++){
            printf("%d\t",M[i][j]);
            // otra opcion
            //printf("%d\t",*(M[i]+j));
            // y otra opcion
            //printf("%d\t",*(*(M+i)+j));
        };
    printf("\n\n");
    }
}


// Funcion que proporciona el maximo del vector siguiendo el esquema de Divide y Venceras
int maximo_vector_DyV(int *V, int inicio, int fin){
int m, max1, max2;

if (inicio == 1 || inicio == fin) return ((V[inicio] > V[fin]) ? V[inicio] : V[fin]);
else {
      // dividir
      m=(inicio+fin)/2;

      // resolver
      max1=maximo_vector_DyV(V,inicio,m);
      max2=maximo_vector_DyV(V,m+1,fin);

      // combinar
      return ((max1 > max2) ? max1 : max2);
      // completar por el alumno
    }
}

// Funcion que proporciona el producto de los elementos del vector siguiendo el esquema de Divide y Venceras
int producto_vector_DyV(int *V, int inicio, int fin){
int m, mul1, mul2;

if (inicio == fin) return V[inicio];
else {
      // dividir
      m=(inicio+fin)/2;

      // resolver
      mul1=producto_vector_DyV(V,inicio,m);
      mul2=producto_vector_DyV(V,m+1,fin);

      // combinar
      return mul1*mul2;
      // completar por el alumno
    }
}

//WIP
float media_aritmetica_DyV (float *V, int inicio, int fin) {
    int m;
    float sum1, sum2;
    printf("\tCalling: %d, %d\n",inicio, fin);

if (inicio == fin) return V[inicio];
else {
      // dividir
      m=(inicio+fin)/2;

      // resolver
      sum1=media_aritmetica_DyV(V,inicio,m);
      printf("Sum1: %f\n", sum1);
      sum2=media_aritmetica_DyV(V,m+1,fin);
      printf("Sum2: %f\n", sum2);

      // combinar
      printf("\tBacking: %f / %d\n",(sum1+sum2)*(fin-inicio)+V[fin], fin-inicio+1);
      return ((sum1+sum2)*(fin-inicio)+V[fin]) / (fin-inicio+1);
      // completar por el alumno
    }
}


// Funcion que soluciona el problema 1 del examen del tema 2, siguiendo el esquema de Divide y Venceras
bool EXAMEN_RECURSION_NOVIEMBRE_2021(int **M, int inicio_filas, int fin_filas, int m){
    if (fin_filas == inicio_filas) return true;
    int k=(fin_filas+inicio_filas)/2;

    bool b1 = EXAMEN_RECURSION_NOVIEMBRE_2021(M, inicio_filas, k, m);
    bool b2 = EXAMEN_RECURSION_NOVIEMBRE_2021(M, k+1, fin_filas, m);

    return b1 && b2 && interseccion(M, k, m);
}

int interseccion (int **M, int k, int m) {
        int f1, f2;

    for (int i=0; i<m-1; i++){
        if (M[k][i]==0) {
            f1++;
        }
        if (M[k+1][i]==0) {
            f2++;
        }
    }
    return f1<=f2;
}
