#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//Prot de funciones
bool iExamPL4B (int ** A, int n, int m, int v, int k);
bool iExamPL4BIter (int ** A, int n, int m, int v, int k);

bool AuxExamPL4B (int ** A, int n, int m, int v, int k);
//Prot de funciones opcionales
void show (int ** M, int n, int m);
char* toBool (int b);
bool equal (bool a, bool b);

//Main
int main () {

  int V [] = {8,7,9,0,
              4,7,1,2,
              1,2,1,4};
  int idx = 0;

  int ** M;
  M = (int **) malloc (3 * sizeof (int *));   //FALSE
  for (int i = 0; i < 3; i++) {
       M[i] = malloc (4 * sizeof (int));
      for (int j = 0; j < 4 ; j++) {
          M[i][j]=V[idx];
          idx++;
      }
  }

  int V2 [] = {8,7,9,0,
              4,7,1,2,
              1,2,1,3};
  idx = 0;

  int ** M2;
  M2 = (int **) malloc (3 * sizeof (int *));    //TRUE
  for (int i = 0; i < 3; i++) {
       M2[i] = malloc (4 * sizeof (int));
      for (int j = 0; j < 4 ; j++) {
          M2[i][j]=V2[idx];
          idx++;
      }
  }

  show (M, 3, 4);
  printf("Recursiva: %s\n", toBool(iExamPL4B(M, 2, 3, 6, 2)));
  printf("Iterativa: %s\n", toBool(iExamPL4BIter(M, 2, 3, 6, 2)));
  printf("Concluyente: %s\n",toBool(equal(iExamPL4B(M, 2, 3, 6, 2), iExamPL4BIter(M, 2, 3, 6, 2))));

  show (M2, 3, 4);
  printf("Recursiva: %s\n", toBool(iExamPL4B(M2, 2, 3, 6, 2)));
  printf("Iterativa: %s\n", toBool(iExamPL4BIter(M2, 2, 3, 6, 2)));
  printf("Concluyente: %s\n",toBool(equal(iExamPL4B(M2, 2, 3, 6, 2), iExamPL4BIter(M2, 2, 3, 6, 2))));

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

//Def de funciones
/*
  caso
      k=1 ==> retorna AuxExamPL4B(A, n, m, v, k);
      k>1 ==> retorna iExamPL4B(A, n, m, v, k-1) AND AuxExamPL4B(A, n, m, v, k);
  fincaso
*/

bool iExamPL4B (int ** A, int n, int m, int v, int k) {   //Llamada inicial (k=n);
  if (k==0) {
    return AuxExamPL4B (A, n, m , v, k);
  }
  return iExamPL4B (A, n, m, v, k-1) && AuxExamPL4B (A, n, m, v, k);
}

bool AuxExamPL4B (int ** A, int n, int m, int v, int k) {
  int contador = 0;
  for (int i = 0; i<m; i++) {
    if (A[k][i]<v) {
      contador++;
    }
  }
  return contador == A[k][m];
}

bool iExamPL4BIter (int ** A, int n, int m, int v, int k) {
  int kini = k;
/*
  while (k!=0) {
    k--;
  }
  */
  k=0;

  bool sol = AuxExamPL4B (A, n, m , v, k);

  while (k!=kini) {
    k++;
    sol = sol && AuxExamPL4B (A, n, m, v, k);
  }

  return sol;
}

//Def de funciones opcionales
void show (int ** M, int n, int m) {
  printf("\nMatrix...\n");
  for (int i = 0; i<n; i++) {
    for (int j = 0; j<m; j++) {
      printf("%d\t",M[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

char* toBool (int n) {
  if (n==0) {
    return "False";
  }
  return "True";
}

bool equal (bool a, bool b) {
  return a==b;
}
