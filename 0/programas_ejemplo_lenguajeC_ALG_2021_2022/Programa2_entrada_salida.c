#include <stdio.h>

int main () {
    int x, y;
    printf ("Introduce un entero: ");
    scanf ("%d", &x);
    //solucion 1
    while (getchar () != '\n');     //Empty input buffer
    //solucion 2
    //fflush(stdin);        //Empty input buffer
    printf ("Introduce un segundo entero: ");
    scanf ("%d", &y);
    printf ("\nLos valores introducidos son: %d y %d\n", x, y);
    return 0;
}
