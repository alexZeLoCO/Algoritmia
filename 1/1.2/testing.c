#include <stdio.h>
#include <stdlib.h>

int rellena(int **, int);
int imprime (int **, int);

# define TALLA 10

int main () {
    int **Matriz=NULL;

    Matriz = (int **) malloc (TALLA * sizeof (int*));
    for (int j=0; j<TALLA; j++) {
        Matriz[j] = (int *) malloc (TALLA * sizeof (int));
    }

    rellena(Matriz, TALLA);

    imprime(Matriz, TALLA);

    //imprime (Matriz, TALLA+1);      ==>       Error 3221225477

    for (int j=0; j<TALLA; j++) {
        free (Matriz[j]);
    }
    free(Matriz);

}

int rellena(int **M, int n){
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {   
            M[i][j]=0;
        }
    }
    return 0;
}

int imprime (int **M, int n){
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {   
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    return 0;
}
