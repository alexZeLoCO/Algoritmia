// ---------------------------------------------------------------------------------
//
// ALGORITMIA: PRACTICA DE DISENIO DE ALGORITMOS RECURSIVOS
//
// Se recoge la implementacion en C del algoritmo recursivo que calcula la
// potencia n-esima de a donde a>=0 y n>=0
//
// Copyright: Raquel Cortina
//
// Fecha: 18 de octubre de 2021
//
// ---------------------------------------------------------------------------------
//
// Completar con las tareas indicadas para el alumno en la sesion 2.1 de practicas
//
//----------------------------------------------------------------------------------


#include <stdio.h>

//
// Prototipos de funciones
//
int POTENCIA(int,int);
int POTENCIA_entresijos(int,int);


// Prototipos de las funciones a realizar por el alumno
// Completar por el alumno
// ...
int potencia_3 (int n);
int potencia_3_entresijos(int n);

int MCD (int a, int b);
int MCD_entresijos (int a, int b);

int factorial (int n);

int numero_cifras (int n);

int suma_cifras (int n);

int semifactorial (int n);

int fibonacci (int n);

int rayuela (int n);

int plano (int x, int y);


//
// Programa principal
//
int main() {
 int n,a,b;

  printf("\t\t CALCULO LA POTENCIA n-ESIMA DE UN NUMERO\n\n");

 // leer la base
 do{
 printf(" Introduce la base a (a>=0): ");
 scanf("%d",&a);
 } while(a<0);

 // leer el exponente
 do{
 printf(" Introduce el exponente n (n>=0): ");
 scanf("%d",&n);
 } while(n<0);

 printf("\n\n");
 printf(" --------\n");
 printf(" POTENCIA\n");
 printf(" --------\n");

 printf(" La potencia %d-esima de %d es: %d \n\n\n", n, a, POTENCIA(a,n));

 printf(" ---------------------------------------------\n");
 printf(" POTENCIA mostrando el funcionamiento interno \n");
 printf(" ---------------------------------------------\n");

 printf(" \n Se muestra el proceso interno: sucesivas llamadas a la funcion, resultado en el caso base y \n");
 printf(" resultados parciales hasta alcanzar el resultado final");

 printf("\n\n\n DESCENSO en la cadena de llamadas ... (se aplica la FUNCION SUCESOR hasta alcanzar caso base)\n\n");

 printf("\n\nLa potencia %d-esima de %d es: %d \n\n", n, a, POTENCIA_entresijos(a,n));


 // Invocacion de las funciones a realizar por el alumno

 // Invocaciones de las funciones potencia_3 y potencia_3_detalles
 // Completar por el alumno
 // ...
  do{
 printf(" Introduce la n de potencia_3 n (n>=0): ");
 scanf("%d",&n);
 } while(n<0);

 printf("La potencia_3 de %d es: %d\n\n\n",n, potencia_3(n));

 printf(" -----------------------------------------------\n");
 printf(" POTENCIA_3 mostrando el funcionamiento interno \n");
 printf(" -----------------------------------------------\n");

 printf("La potencia_3 de %d es: %d\n\n\n",n, potencia_3_entresijos(n));

 // Invocaciones de las funciones MCD y MCD_detalles
 // Completar por el alumno
 // ...
  do{
 printf(" Introduce valor 1 para MCD n (n>0): ");
 scanf("%d",&a);
 } while(a<=0);

  do{
 printf(" Introduce valor 2 para MCD n (n>0): ");
 scanf("%d",&b);
 } while(b<=0);

printf("El MCD de %d y %d es: %d\n\n\n", a,b,MCD(a,b));

 printf(" ----------------------------------------\n");
 printf(" MCD mostrando el funcionamiento interno \n");
 printf(" ----------------------------------------\n");

printf("El MCD de %d y %d es: %d\n\n\n", a,b,MCD_entresijos(a,b));

 // Invocaciones de las funciones: factorial, numero_cifras, suma_cifras, semifactorial, fibonacci, rayuela y plano
 // Completar por el alumno
 // ...

//FACTORIAL
do{
 printf("Introduce valor para factorial (n>=0): ");
 scanf("%d",&n);
 } while(n<0);

printf ("El factorial de %d es: %d\n\n\n",n, factorial(n));

//NUMERO_CIFRAS
do{
 printf("Introduce valor para calcular su numero de cifras (n>=0): ");
 scanf("%d",&n);
 } while(n<0);

printf ("El número de cifras de %d es: %d\n\n\n", n, numero_cifras(n));


//SUMA_CIFRAS
do{
 printf("Introduce valor para calcular su suma de cifras (n>=0): ");
 scanf("%d",&n);
 } while(n<0);

printf ("El sumatorio de las cifras de %d es: %d\n\n\n", n, suma_cifras(n));


//SEMIFACTORIAL
do{
 printf("Introduce valor para calcular su semifactorial (n>=0): ");
 scanf("%d",&n);
 } while(n<0);

 printf("El semifactorial de %d es: %d\n\n\n",n,semifactorial(n));


//FIBONACCI
do{
 printf("Introduce valor para calcular su Fibonacci -supuesto que la serie empieza por 1- (n>=0): ");
 scanf("%d",&n);
 } while(n<0);

printf ("El elemento %d-esimo de la serie de Fibonacci es: %d\n\n\n",n,fibonacci(n));


//RAYUELA
do{
 printf("Introduce valor para calcular el número de formas de llegar a ella en la Rayuela -supuesto que la primera casilla es la 1- (n>0): ");
 scanf("%d",&n);
 } while(n<=0);

 printf ("Hay %d formas de llegar a la casilla %d en la Rayuela\n\n\n",rayuela(n), n);


//PLANO
do{
 printf("Introduce valor para la coordenada x del plano (n>=0): ");
 scanf("%d",&a);
 } while(a<0);

 do{
 printf("Introduce valor para la coordenada y del plano (n>=0): ");
 scanf("%d",&b);
 } while((b<0 && a!=0) || (b<=0 && a==0));

printf ("Hay %d formas de llegar a las coordenadas (%d,%d) del plano.\n\n\n",plano(a,b),a,b);

return 0;
}

//
// Definiciones de funciones
//

// Potencia
int   POTENCIA(int a, int n){
  if (n==0) return 1;
  else return POTENCIA(a,n-1)*a;
}

// Potencia_detalles
int POTENCIA_entresijos(int a, int n){
int p;
if (n==0){
        printf("\tpotencia(%d,%d)\n\n",a,n);
        p=1;
        printf("\n\n CASO BASE y su resultado\n\n");
        printf("\tpotencia(%d,%d) ---> resultado = %d\n\n",a,n,p);
        printf("\n\n ASCENSO en la cadena de llamadas ... (se aplica la FUNCION de COMBINACION hasta alcanzar la llamada inicial)\n\n");
        return p;
        }
else{
    printf("\tpotencia(%d,%d)\n",a,n);
    p=POTENCIA_entresijos(a,n-1)*a;
    printf("\tpotencia(%d,%d) ---> resultado = %d\n",a,n,p);
    return p;
    }
}


//
// Definicion de las funciones a realizar por el alumno
//

// Potencia_3
// Completar por el alumno
// ...

int potencia_3 (int n) {
    if (n==0) {
        return 1;
    }  
    if (n==1) {
        return 3;
    }
    return 2*potencia_3(n-1)+3*potencia_3(n-2);
}

// Potencia_3_entresijos
// Completar por el alumno
// ...
int potencia_3_entresijos (int n) {
    if (n<=1) {
        printf("\tpotencia_3(%d)\n\n",n);
        printf("\n\nCASO BASE y su resultado\n\n");
        if (n==0) {
            int p=1;
            printf("\tpotencia_3(%d) ---> resultado = %d\n\n",n,p);
            printf("\n\nASCENSO en la cadena de llamadas ... ( se aplica la FUNCIÓN de COMBINACIÓN hasta alcanzar la llamada inicial)\n\n");
            return p;
        }  
        if (n==1) {
            int p=3;
            printf("\tpotencia_3(%d) ---> resultado = %d\n\n",n,p);
            printf("\n\nASCENSO en la cadena de llamadas ... ( se aplica la FUNCIÓN de COMBINACIÓN hasta alcanzar la llamada inicial)\n\n");
            return p;
        }
    }
    printf("\tpotencia_3(%d)\n",n);
    int p = 2*potencia_3(n-1)+3*potencia_3(n-2);
    printf("\tpotencia_3(%d) ---> resultado = %d\n",n,p);
    return p;
}

// MCD
// Completar por el alumno
// ...
int MCD (int a, int b) {
    if (a==b) {
        return a;
    }
    if (a>b) {
        return MCD (a-b,b);
    }
    return MCD (a,b-a);
}

// MCD_entresijos
// Completar por el alumno
// ...
int MCD_entresijos (int a, int b) {
    if (a==b) {
        printf("\tMCD(%d,%d)\n\n",a,b);
        printf("\n\nCASO BASE y su resultado\n\n");
        printf("\tMCD(%d,%d) ---> resultado = %d\n\n",a,b,a);
        printf("\n\nASCENSO en la cadena de llamadas ... ( se aplica la FUNCIÓN de COMBINACIÓN hasta alcanzar la llamada inicial)\n\n");
        return a;
    }

    int p;
    printf("\nMCD(%d,%d)\n",a,b);

    if (a>b) {
        p = MCD (a-b,b);
    } else {
        p = MCD (a,b-a);
    }

    printf("\nMCD(%d,%d) ---> resultado = %d\n",a,b,p);
    return p;
}

// factorial
// Completar por el alumno
// ...
int factorial (int n) {
    if (n==0) { return 1;}
    return factorial (n-1)*n;
}

// numero_cifras
// Completar por el alumno
// ...
int numero_cifras (int n) {
    if (n==0) {
        return 0;       //No quedan cifras
    }
    return numero_cifras ((int) n/10) + 1;  //Reducción de una cifra y actualización contador
}

// suma_cifras
// Completar por el alumno
// ...
int suma_cifras (int n) {
    if (n==0) {
        return n;       //No quedan cifras
    }
    return suma_cifras (n/10) + n%10;   //Reducción cifra y actualización sumatorio con cifra
}

// semifactorial
// Completar por el alumno
// ...
int semifactorial (int n) {
    if (n==0 || n==1) {
        return 1;       //Ultimos 2 valores posibles
    }
    return semifactorial(n-2)*n;        //Reducción en 2 de valor
}

// fibonacci
// Completar por el alumno
// ...
// 0 1 1 2 3
int fibonacci (int n) {
    if (n==0 || n==1) {
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

// rayuela
// Completar por el alumno
// ...
//  1    2   3   4   5   6   7
//  1    2   3   5
int rayuela (int n) {
    if (n==1 || n==2) {
        return n;
    }
    return rayuela(n-1)+rayuela(n-2);
}

// plano
// Completar por el alumno
// ...
int plano (int x, int y) {
    if (x==0 || y==0) {     //Si (en ejes) { Solo 1 forma de llegar }
        return 1;
    }
    return plano (x-1, y) + plano (x, y-1);     //Reducción de cada coordenada en 1
}