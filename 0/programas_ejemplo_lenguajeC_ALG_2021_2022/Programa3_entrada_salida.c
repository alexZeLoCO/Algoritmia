#include <stdio.h>

int main () {
    int x;
    char c;
    printf ("Introduce un entero: ");
    scanf ("%d", &x);
    fflush (stdin);         //Empty input buffer - Test by removing line
    printf ("Introduce un caracter: ");
    scanf ("%c", &c);
    printf ("Los valores introducidos son: %d y %c\n", x, c);
    return 0;
}
