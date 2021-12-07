#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

int potenciaRecursiva(int n, int m);
int potenciaIterativa (int n, int m);

int MCD_Recursivo (int a, int b);
int MCD_Iterativo (int, int);

int tablerosRecursivo (int n, int m);
int tablerosIterativo (int n, int m);

int sumaElementosRecursivo (int V[], int n);
int sumaElementosIterativo (int V[], int n);

bool capicuaRecursivo (int V[], int n, int m);
bool capicuaIterativo (int V[], int n, int m);

bool matrizSimetricaRecursivo (int **M, int n);
bool matrizSimetricaIterativo (int **M, int n);

bool bandaSimetrica (int **M, int n);

void show (int **M, int n);
void showV (int V [], int n);

char* toBoolean (int b);

int main () {

    printf("potenciaRecursiva(2,2) = %d\n", potenciaRecursiva(2,2));
    printf("potenciaIterativa(2,2) = %d\n", potenciaIterativa(2,2));

    printf("MCD_Recursivo(48,96) = %d\n", MCD_Recursivo(48,96));
    printf("MCD_Iterativo(48,96) = %d\n", MCD_Iterativo(48,96));

    printf("tablerosRecursivo(6,3) = %d\n", tablerosRecursivo(6,3));
    printf("tablerosRecursivo(6,3) = %d\n", tablerosIterativo(6,3));
    
    int V [5] = {1,2,3,2,1};
    showV(V, 5);

    printf("sumaElementosRecursivo(V, 5) = %d\n", sumaElementosRecursivo(V, 5));
    printf("sumaElementosIterativo(V, 5) = %d\n", sumaElementosIterativo(V, 5));
    
    printf("capicuaRecursivo (V, 5) = %s\n", toBoolean(capicuaRecursivo(V, 0, 5)));
    printf("capicuaIterativo (V, 5) = %s\n", toBoolean(capicuaIterativo(V, 0, 5)));

    int V2 [4] = {1,2,2,1};
    showV(V2, 4);
   
    printf("capicuaRecursivo (V2, 4) = %s\n", toBoolean(capicuaRecursivo(V2, 0, 4)));
    printf("capicuaRecursivo (V2, 4) = %s\n", toBoolean(capicuaIterativo(V2, 0, 4)));

    int V3 [5] = {1,1,3,2,1};
    showV(V3, 5);

    printf("capicuaRecursivo (V3, 5) = %s\n", toBoolean(capicuaRecursivo(V3, 0, 5)));
    printf("capicuaRecursivo (V3, 5) = %s\n", toBoolean(capicuaIterativo(V3, 0, 5)));

    int V4 [4] = {1,1,2,1};
    showV(V4, 4);

    printf("capicuaRecursivo (V4, 4) = %s\n", toBoolean(capicuaRecursivo(V4, 0, 4)));
    printf("capicuaRecursivo (V4, 4) = %s\n", toBoolean(capicuaIterativo(V4, 0, 4)));
    
    int **M;
    M = (int **) malloc (3 * sizeof (int *));
    for (int i = 0 ; i<3 ; i++) {
        M[i] = malloc (3 * sizeof (int));
    }

    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j<3; j++) {
            M[i][j] = 1;
        }
    }

    show(M,3);

    printf("matrizSimetricaRecurisvo(M, 3) = %s\n", toBoolean(matrizSimetricaRecursivo(M, 3)));
    printf("matrizSimetricaIterativo(M, 3) = %s\n", toBoolean(matrizSimetricaIterativo(M, 3)));

    M[2][1] = 3;

    show(M,3);

    printf("matrizSimetricaRecursivo(M, 3) = %s\n", toBoolean(matrizSimetricaRecursivo(M, 3)));
    printf("matrizSimetricaIterativo(M, 3) = %s\n\n", toBoolean(matrizSimetricaIterativo(M, 3)));

    for (int i = 0 ; i<3; i++) {
        free(M[i]);
    }
    free(M);

    return 0;
}

char* toBoolean (int b) {
    if (b == 0) {
       return "False";
    }
    return "True";
}

void showV (int V[], int n) {
    printf("\n\nShowing Vector...\n");
    for (int i = 0 ; i<n; i++) {
        printf("%d\t",V[i]);
    }
    printf("\n");
}
void show (int **M , int n) {

    printf("\nShowing Matrix...\n");
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j<3; j++) {
            printf("%d\t",M[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

int potenciaRecursiva (int n, int m) {
    if (m==0) {
        return 1;
    }
    return n*potenciaRecursiva(n, m-1);
}

int potenciaIterativa (int n, int m) {
    int p = 0;
    int q = 1;

    while (p!=m) {
        p++;
        q=q*n;
    }

    return q;
}

int MCD_Recursivo (int a, int b) {
    if (a==b) {
        return a;
    }
    if (a>b) {
        return MCD_Recursivo (a-b,b);
    }
    return MCD_Recursivo (a,b-a);
}

int MCD_Iterativo (int a, int b) {
    while (a!=b) {
        if (a>b) {
            a=a-b;
        } else {
            b=b-a;
        }
    }
    return a;
}

int tablerosRecursivo (int n, int m) {
    if (m==1) {
        return pow(n,2);
    }
    return tablerosRecursivo(n-1, m-1);
}

int tablerosIterativo (int n, int m) {
    int ni = n;
    int mi = m;

    while (m>1) {
        n--;
        m--;
    }

    return pow(n,2);
}

int sumaElementosRecursivo (int V [], int n) {
    if (n==1) {
        return V[0];
    }
    return V[n-1]+sumaElementosRecursivo(V, n-1);
}

int sumaElementosIterativo (int V [], int n) {
    int ni = n;

    while (ni>1) {
        ni--;
    }

    int suma = V[ni-1];

    while (ni<n) {
        suma=suma+V[ni];
        ni++;
    }
    return suma;
}

bool capicuaRecursivo (int V [], int n, int m) {
    if (n>=m-1) {
        return true;
    }
    return V[n]==V[m-1] && capicuaRecursivo(V, n+1, m-1);
    
}

bool capicuaIterativo (int V [], int n, int m) {

    int ni = n;
    int mi = m-1;

    while (ni<mi) {
        ni++;
        mi--;
    }

    bool sol = true;

    while (ni>n && mi<m-1) {

        if (V[ni]!=V[mi]) {
            sol = false;
        }

        ni--;
        mi++;
    }
    return sol;
}

bool matrizSimetricaRecursivo (int **M, int n) {
    if (n==0) {
        return true;
    }
    return matrizSimetricaRecursivo(M, n-1) && bandaSimetrica(M, n);
}

bool matrizSimetricaIterativo (int **M, int n) {
    int ni = n;

    while (ni!=0) {
        ni--;
    }

    bool sol = true;

    while (ni<n) {
        ni++;
        if (!bandaSimetrica(M, ni)) {
            sol = false;
        }
    }
    return sol;
}

bool bandaSimetrica (int **M, int n) {
    int i = 0;
    while (i<n-1) {
        i++;
        if (M[i][n-1]!=M[n-1][i]) {
            return false;
        }
    }
    return true;
}
