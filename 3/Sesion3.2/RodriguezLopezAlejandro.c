// --------------------------------------------------------------------------
//
//  ALGORITMIA: IMPLEMENTACION DEL ALGORITMO "MOCHILA 0/1" Y
//
//              DEL ALGORITMO "DESCOMPONER UN NUMERO N EN M SUMANDOS"
//
//
//  SESION 3.2 DE PRACTICAS (ESQUEMAS ALGORITMICOS - PROGRAMACION DINAMICA)
//
//  Fechas: del 19 al 25 de noviembre de 2021
//
// ---------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>

int MOCHILA_programacion_dinamica (int *, int *, int, int);
int DESCOMPONER_programacion_dinamica(int,int);
void show (int**, int, int);

// EMBARCADEROS (OPCIONAL)
//int EMBARCADEROS_programacion_dinamica(int, int **);

int main() {
int n,C,i;
int *P;
int *B;
/*
do{
    printf("Introduce la capacidad de la mochila: ");
    scanf("%d",&C);
} while(C<0);

do{
    printf("\nIntroduce el numero de objetos:  ");
    scanf("%d",&n);
} while(n<0);

// reserva dinamica de memoria para vectores de pesos y beneficios
P=(int *)malloc(n*sizeof(int));
B=(int *)malloc(n*sizeof(int));

printf("\n\nIntroduce los pesos de los %d objetos\n",n);
for (i=1;i<=n;i++){
   do {
    printf("\nPeso[%d]= ", i);
    scanf("%d",&P[i-1]);
   } while(P[i-1]<=0);
}

printf("\n\nIntroduce los beneficios de los %d objetos\n",n);
for (i=1;i<=n;i++){
    do {
        printf("\nBeneficio[%d]= ", i);
        scanf("%d",&B[i-1]);
    } while(B[i-1]<=0);
   }

//
// La funcion MOCHILA_programacion_dinamica recibe:
// - los vectores P y B con los pesos y beneficios de los objetos,
// - el numero de objetos, n, y
// - la capacidad de la mochila, C
//

printf("\n\n\n y el beneficio maximo es:%d\n",MOCHILA_programacion_dinamica(P,B,n,C));
printf("\n\n");
*/
// liberar memoria
free(P);
free(B);

//
// DESCOMPOSICION DE N EN M SUMANDOS
//

int N,M;

do{
    printf("Introduce el numero a descomponer: ");
    scanf("%d",&N);
} while(N<=0);

do{
    printf("\nIntroduce el numero de sumandos en los que se va a descomponer:  ");
    scanf("%d",&M);
} while(M<=0||M>N);

printf("\n\n\n y producto maximo es:%d\n",DESCOMPONER_programacion_dinamica(N,M));
printf("\n\n");



//
// EMBARCADEROS [OPCIONAL]
//

/* int n;
printf("Introduce el numero de embarcaderos: ");
scanf("%d",&n);

// reserva dinámica de memoria para la matriz de costes C
// realizar por el alumno

// lectura de la matriz C de costes
// realizar por el alumno

printf("\n\nEl coste final del recorrido es %d\n",EMBARCADEROS_programacion_dinamica(n,C));
*/

return 0;
}

void show (int**M, int n, int m) {
        int i,j,aux;
    printf("\t");
    for (int k=0; k<m;k++) {
        printf("%d\t",k);
    }
    printf("\n\n");
    for (i=0;i<n;i++)
    {
        printf("%d\t",i);
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

int MOCHILA_programacion_dinamica (int *P, int *B, int n, int C){
int **Bmax;
int **Dec;
int *X;

n=n+1;
C=C+1;
// reserva dinamica de memoria para X, esto es, el vector de decisiones
// realizar por el alumno
X=(int *)malloc(n*sizeof(int));


// reserva dinamica de memoria de las matrices Bmax y Dec
// realizar por el alumno
Bmax=(int **)malloc(n*sizeof(int*));
for (int i = 0; i < n ; i++) {
    Bmax[i]=(int *)malloc(C*sizeof(int));
}

Dec=(int **)malloc(n*sizeof(int*));
for (int i = 0; i < n ; i++) {
    Dec[i]=(int *)malloc(C*sizeof(int));
}


// inicializar las matrices con los resultados de los problemas triviales
// realizar por el alumno
for (int c=0; c<C; c++) {
    Bmax [0][c] = 0;
    Dec  [0][c] = 0;
}

// rellenar las matrices por filas en sentido ascendente
// realizar por el alumno
for (int j=1; j<n ; j++) {
    for (int c=0; c<C; c++) {
        if (c<P[j-1]) {
            Bmax[j][c] = Bmax[j-1][c];
            Dec [j][c] = 0;
        } else {
            if (Bmax[j-1][c]>=Bmax[j-1][c-P[j-1]]+B[j-1]) {
                Bmax [j][c] = Bmax [j-1][c];
                Dec[j][c] = 0;
            } else {
                Bmax[j][c] = Bmax[j-1][c-P[j-1]]+B[j-1];
                Dec [j][c] = 1;
            }
        }
    }
}

printf("\nDec\n");
show (Dec, n, C);
printf("Bmax\n");
show (Bmax, n, C);

// solucion
// realizar por el alumno

int j = n;
int c = C;
j--;
c--;

while (j>0) {
    X[j-1] = Dec [j][c];
    c = c - X[j-1] * P[j-1];
    j--;
}
// mostrar por pantalla la secuencia de decisiones optima
// realizar por el alumno
for (int i = 0; i<n-1; i++) {
    printf("x%d: %d\t",i, X[i]);
}
printf("\n");


// liberar memoria
// realizar por el alumno
int BM = Bmax[n-1][C-1];

for (int i = 0; i<n; i++) {
    free(Dec[i]);
    free(Bmax[i]);
}
free(Dec);
free(Bmax);

// retornar el beneficio maximo
// realizar por el alumno
return BM;
}


int DESCOMPONER_programacion_dinamica(int N, int M){
int **Pmax;
int **Dec;
int *S;

M++;
N++;

// reserva dinamica de memoria para Sumandos, esto es, el vector de decisiones
// realizar por el alumno
S=(int *)malloc(M*sizeof(int));


// reserva dinamica de memoria de las matrices Pmax y Dec
// realizar por el alumno
Pmax=(int **)malloc(N*sizeof(int*));
for (int i = 0; i < N ; i++) {
    Pmax[i]=(int *)malloc(M*sizeof(int));
}

Dec=(int **)malloc(N*sizeof(int*));
for (int i = 0; i < N ; i++) {
    Dec[i]=(int *)malloc(M*sizeof(int));
}


// inicializar las matrices con los resultados de los problemas triviales
// realizar por el alumno
for (int i = 1; i<M; i++) {
    Pmax[1][i]=i;
    Dec [1][i]=i;
}



// rellenar las matrices por filas en sentido ascendente
// realizar por el alumno
for (int j = 2; j < M; j++) {
    for (int n = j; n < N; n++) {
        Pmax[j][n] = 1;
        for (int Sj=0; Sj < n-j+1 ; Sj++) {
            int p = Pmax[j-1][n-Sj]*Sj;
            if (p>=Pmax[j][n]) {
                Pmax[j][n] = p;
                Dec[j][n] = Sj;
            }
        }
    }
}

printf("Dec:\n");
show(Dec,  N, M);
printf("Pmax:\n");
show(Pmax, N, M);

// solucion
// realizar por el alumno


// mostrar por pantalla la secuencia de decisiones optima
// realizar por el alumno


// liberar memoria
// realizar por el alumno


// retornar el producto maximo
// realizar por el alumno
}




// [OPCIONAL]
/*
int embarcaderos_programacion_dinamica(int n, int **C){
// realizar por el alumno
}
*/
