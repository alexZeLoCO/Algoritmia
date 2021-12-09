#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void dinamica (int ,int ,int**);
void mostrar (int **, int, int);
void backtracking (int, int, int**, int, int*, int*, int*);
bool DyV (int*, int, int);

int main () {

    int c = 5;
    int n = 3;
    int ** a;

    int v [10] = {14,17,
                  5,2,
                  5,8,
                  7,2,
                  15,10};

    a = (int**) malloc (5 * sizeof(int*));
    for (int i = 0; i < 5; i++) {
        a[i] = (int*) malloc (2 * sizeof (int));
    }
    
    int idx = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0 ; j < 2; j++) {
            a[i][j] = v[idx++];
        }
    }
    
    printf("///ALGORITMO DINAMICA///\n");
    dinamica(c, n, a);

    printf("\n\n///ALGORITMO BACKTRACKING///\n");
    int* x;
    x = (int*) malloc (c * sizeof(int));

    int* x_mejor;
    x_mejor = (int *) malloc (c * sizeof(int));

    int v_mejor = 0;

    backtracking(c, n, a, 0, x, x_mejor, &v_mejor);

    for (int i = 0; i<c; i++) {
        printf("%d\t", x_mejor[i]);
    }
    printf("\n");
    

    printf("\n///ALGORITMO DIVIDE Y VENCERAS///\n");
    int vectorF [5] = {3, 7, 12, 3, 4};
    int vectorT [5] = {3, 6, 5, 24, 12};
    printf("Existen al menos 2 elementos consecutivos en el vector tales que uno es el doble del otro: %d\n", DyV(vectorT, 0, 5));
    printf("Existen al menos 2 elementos consecutivos en el vector tales que uno es el doble del otro: %d\n", DyV(vectorF, 0, 5));

}

void mostrar (int ** m , int f, int c) {
    for (int i = 0 ; i < c; i++) {
        printf("\t%d", i);
    }
    for (int i = 0; i < f; i++) {
        printf("\n%d\t", i);
        for (int j = 0; j < c; j++) {
            printf("%d\t", m[i][j]);
        }
    }
}

/**
 * @brief Imprime por pantalla las estructuras de datos del problema presentado.
 * 
 * @param c Número de filas
 * @param n Número de columnas + 1
 * @param a Matriz
 */
void dinamica (int c, int n, int ** a) {
    int * x;        //Secuencia decisiones
    x = (int*) malloc (c+1 * sizeof(int));

    int ** max;
    max = (int**) (malloc ((c+1) * sizeof(int*)));
    for (int i = 0; i<c+1; i++) {
        max[i] = (int*) (malloc ((n+1) * sizeof(int)));
    }

    int ** dec;
    dec = (int**) (malloc ((c+1) * sizeof(int*)));
    for (int i = 0; i<c+1; i++) {
        dec[i] = (int*) (malloc ((n+1) * sizeof(int)));
    }

    //1. Casos triviales
    for (int i = 0; i<n+1; i++) {
        max[0][i] = 0;
        dec[0][i] = 0;
    }

    //2. El resto
    for (int i = 1; i < c+1; i++) {     //Filas
        for (int j = 0; j < n+1; j++) {     //Columnas
            if (j == 0) {
                max[i][j] = max[i-1][j] + a[i-1][1];
                dec[i][j] = 0;
            } else {
                if (max[i-1][j-1] + a[i-1][0] > max[i-1][j] + a[i-1][1]) {
                    max[i][j] = max[i-1][j-1] + a[i-1][0];
                    dec[i][j] = 1;
                } else {
                    max[i][j] = max[i-1][j] + a[i-1][1];
                    dec[i][j] = 0;
                }
                //max[i][j] = (max[i-1][j-1] + a[i-1][0] > max[i-1][j] + a[i-1][1]) ? max[i-1][j-1] + a[i-1][0] : max[i-1][j] + a[i-1][1];
            }   
        }
    }
    printf("Max:\n");
    mostrar(max, c+1, n+1);
    printf("\n\nDec:\n");
    mostrar(dec, c+1, n+1);
}

/**
 * @brief Calcula el sumatorio de un elemento de cada fila, siendo x[i] la columna a sumar de la fila i
 * 
 * @param a Matriz a operar
 * @param c Número de filas
 * @param x Sucesión de decisiones sobre la columna a valorar
 * @return int Sumatorio de un elemento de cada fila
 */
int valor (int** a, int c, int * x) {
    int suma = 0;
    for (int i = 0 ; i < c; i++) {
        suma+=a[i][x[i]];
    }
    return suma;
}

/**
 * @brief Colocará en x_mejor la sucesión de decisiones óptima para el problema presentado
 * 
 * @param c Filas
 * @param n Columnas
 * @param a Matriz
 * @param k 0
 * @param x Sucesión vacía
 * @param x_mejor Sucesión vacía - resultado final
 * @param v_mejor entero vacío
 */
void backtracking (int c, int n, int ** a, int k, int* x, int* x_mejor, int *v_mejor) {
    //preparar recorrido nivel k        x[k] = -1;
    //mientras exista hermano nivel k {  x[k] < 1
    //sig hermano nivel k       ++x[k]
    //si solucion y correcto { tratar }
    //si no solución y correcto { recursividad } }
    //retornar

    int aux;
    x[k]=-1;
    while (x[k]<1){
        x[k]=x[k]+1;
        if (k==c){    //si solución
            aux=valor(a, c, x); // funcion objetivo
            if (aux > *v_mejor){        //si es mejor que el anterior
                *v_mejor=aux;
                //opcion 1
                //for(i=1;i<=n;i++)
                //  x_mejor[i-1]=x[i-1];
                //opcion 2
                //void *memcpy(void *s1, const void *s2, size_t n);
                //memcpy copia los primeros n bytes del area de memoria apuntada por
                //s2 al area de memoria apuntada por s1
                memcpy(x_mejor,x,c*sizeof(int));
            }
        }
            //si no solución y correcto
        if (k<c) {
            backtracking(c, n, a, k+1, x, x_mejor, v_mejor);
        }
    }
}

/**
 * @brief Retornará true si en el vector existen al menos dos elementos consecutivos tales que uno es el doble del otro
 * 
 * @param v Vector a evaluar
 * @param ini Posición inicial del vector a operar (0)
 * @param fin Posición final del vector a operar (longitud)
 * @return true si existen al menos dos elementos consecutivos tales que uno sea el doble del otro
 * @return false no existen ningun par de elementos consecutivos tales que uno sea el doble del otro
 */
bool DyV (int* v, int ini, int fin) {

    if (ini == fin) return false;
    if (ini == 1+fin || fin == 1+ini) return (v[ini] == 2*v[fin] || v[fin] == 2*v[ini]);
    else {
        return (DyV(v,ini,(ini+fin)/2) || DyV(v,(ini+fin)/2+1,fin));
        }
}
