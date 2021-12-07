// ----------------------------------------------------------------------------
//
// Implementacion en C del algoritmo dar_la_vuelta
//
// ALGORITMIA: PRACTICA DE ANALISIS DE ALGORITMOS
//
// Copyright: Raquel Cortina
// Fecha: 1 de setiembre de 2019
//
// Programa para medir los tiempos de ejecucion de la implementacion en C
//
// ------------------------------------------------------------------------------------------
//
// La libreria time.h ofrece una funcion para medir tiempos. Su nombre es clock.
//
// clock_t clock(void);
//
// Esta funcion devuelve el tiempo empleado por el procesador (en tics de reloj)
// hasta el punto en el que se efectua la llamada a la funcion clock. Para determinar
// el tiempo en segundos, el valor retornado por la funci�n clock debe ser dividido
// por el valor de la macro CLOCKS_PER_SEC.
//
// La libreria stdlib.h ofrece la funcion rand que selecciona un numero al azar. Si queremos
// un numero aleatorio entre un rango personalizado, por ejemplo entre 0 y 1000, utilizaremos
// el operador modulo (%) del siguiente modo:
//
// rand()%1000
//
// ------------------------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fijamos el numero de tallas a medir
# define NUM_TALLAS 12

// Fijamos el numero de repeticiones
# define REPETICIONES 100

// Prototipos de funciones
int rellena(int *, int);
int dar_la_vuelta(int *, int);

// Funcion principal
int main()
{
 int i,j;
 clock_t tiempo_inicial, tiempo_final;

 // Se declara un vector de NUM_TALLAS que son las que vamos a medir
 int talla[NUM_TALLAS]={1000,2000,3000,4000,5000,6000,7000,8000,9000,10000, 11000,12000};

 // Mostramos la cabecera de la tabla en la que figuraran tallas vs. tiempos
 printf("\n\nDAR LA VUELTA A UN VECTOR\n\n");
 printf("Tiempo empleado:\n\n\n");
 printf("\t\tTalla\t\tTiempo\n\n");
 printf("\t\t-----\t\t------\n\n");



 // Bucle que recorre las diferentes tallas a medir
 for (i=0;i<NUM_TALLAS;i++)
     {
     // Reservamos memoria para talla[i] enteros
     int *V=(int *) malloc (talla[i] * sizeof(int));

     // Rellenado de un vector de talla[i]
     rellena(V,talla[i]);

     // Llamada a la funcion clock antes de la franja de codigo a medir
     tiempo_inicial=clock();

     // Bucle para repetir el experimento
     for (j=1;j<=REPETICIONES;j++)
         // Invocacion de la funcion a medir
         dar_la_vuelta(V, talla[i]);

     // Llamada a la funcion clock despues de la franja de codigo a medir
     tiempo_final=clock();

     // Liberamos el espacio reservado para el vector
     free(V);

     // Mostramos la talla medida y el tiempo empleado (tiempo medido/repeticiones)
     printf("\t\t%d\t\t%f\n", talla[i],(tiempo_final-tiempo_inicial) /(double)CLOCKS_PER_SEC / REPETICIONES);
     }
  return 0;
}

// Funcion que rellena el vector
int rellena(int *V, int talla)
{
    int i;
    for (i=1;i<=talla;i++)
        V[i-1]=rand()%1000;
    return 0;
}

// Funcion que da la vuelta al vector
int dar_la_vuelta(int *V,int talla)
{
    for (unsigned int i=0; i<talla-1; i++) {
        for (unsigned int j=0; j<talla-1; j++) {
            unsigned int aux = V[j];
            V[j] = V[j+1];
            V[j+1] = aux;
        }
    }
    return 0;
}
