#include <stdio.h>

int main (){
    int x, y;
    printf ("Introduzca un entero: ");
    scanf ("%d", &x);           //scanf ("%x", &var); ==> x es el tipo de dato a leer y var es la dirección de variable donde se va a guardar, llevará el &. Incluye un \n al final.
    printf ("Introduzca un segundo entero: ");
    scanf ("%d", &y);
    printf ("\nLos valores introducidos son: %d y %d\n", x, y);
    return 0;
}
