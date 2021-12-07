#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool iExamPL4B (int ** A, int n, int m, int v, int k);
bool AuxExamPL4B (int ** A, int n, int m, int v, int k);

bool iExamPL4BDebug (int ** A, int n, int m, int v, int k);
bool AuxExamPL4BDebug (int ** A, int n, int m, int v, int k);

bool iExamPL4BIter (int ** A, int n, int m, int v, int k);

void show (int **M , int n, int m);

int main () {

/*
    NOTA: BUG SIN SOLUCIONAR. Si la función debe retornar True (1), no se llega a imprimir el valor por pantalla, parecería que no se retorna nada.
        Bug no atribuido a bucle infinito porque el programa parece llegar a un fin.

        Al ejecutar en cmd: Error: una instrucción hace referencia a una zona de memoria donde no se pudo leer. ==> Error en acceso a valores de matrices (?)
*/

    int idx = 0;

    //Matrix 1 (False)
    int V [] = {8,7,9,0,
                4,7,1,2,
                1,2,1,4};
    int **M;
    M = (int **) malloc (3 * sizeof (int *));
    for (int i = 0; i < 3; i++) {
         M[i] = malloc (4 * sizeof (int));
        for (int j = 0; j < 4 ; j++) {
            M[i][j]=V[idx];
            idx++;
        }
    }


    idx = 0;

    //Matrix 2 (True)
    int V2 [] = {8,7,9,0,
                 4,7,1,2,
                 1,2,1,3};    
    int **M2;
    M2 = (int **) malloc (3 * sizeof (int *));
    for (int i = 0; i < 3; i++) {
         M2[i] = malloc (4 * sizeof (int));
        for (int j = 0; j < 4 ; j++) {
            M2[i][j]=V2[idx];
            idx++;
        }
    }

    int v = 6;
   
    show (M, 3, 4);
    printf("RecurFalse: %d\n", iExamPL4B(M, 3, 4, v, 3));
    printf("IterFalse: %d\n", iExamPL4BIter(M, 3, 4, v, 3));

    show (M2, 3, 4);
    printf("RecurTrue: %d\n", iExamPL4B(M2, 3, 4, v, 3));
    printf("IterTrue: %d\n", iExamPL4BIter (M2, 3, 4, v, 3));


    //Freeing Matrixes
    for (int i = 0 ; i<4; i++) {
        free(M[i]);
    }
    free(M);

    for (int i = 0 ; i<4; i++) {
        free(M2[i]);
    }
    free(M2);

    return 1;
}

bool iExamPL4B (int ** A, int n, int m, int v, int k) {
    if (k==0) {
        return AuxExamPL4B(A, n, m, v, k);
    }
    return iExamPL4B (A, n, m, v, k-1) && AuxExamPL4B(A, n, m, v, k);;
}

/*
El ultimo elem de cada columna es el número de elementos de esa fila inferiores estrictamente a v
*/
bool AuxExamPL4B (int ** A, int n, int m, int v, int k) {
    int conteo = 0;
    for (int j = 0 ; j < m-1 ; j++) {
        if (A[k][j]<v) {
            conteo++;
        }
    }
    return conteo==A[k][m-1];
}

bool iExamPL4BIter (int ** A, int n, int m, int v, int k) {
    int kini = k;
    k = 0;

    bool sol = AuxExamPL4B(A, n, m, v, k);

    while (k < kini && sol) {
        k++;
        sol = sol && AuxExamPL4B(A, n, m, v, k);
    }
    return sol;
}

//Función extra: Muestra matriz de tamaño n m.
void show (int **M , int n, int m) {
    printf("\nShowing Matrix...\n");
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j<m; j++) {
            printf("%d\t",M[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}
