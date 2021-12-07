#include <stdio.h>

int productoRecur (int a, int b);
int productoIter (int a, int b);

int main () {
    printf("productoRecur (2, 4) = %d\n", productoRecur(2,4));
    printf("productoIter (2, 4) = %d\n", productoIter(2,4));
    return 1;
}

int productoRecur (int a, int b) {
    if (a==0) {
        return 0;
    }
    if (a%2==0) {
        return productoRecur ((int) a/2, 2*b);
    }
    return productoRecur ((int) a/2, 2*b)+b;
}

int productoIter (int a, int b) {
    int aini = a;
    int stack [a/2];
    int idx = 0;

    while (a!=0) {
        stack[idx]=a;       //Guardando en stack
        a=a/2;          //s(a);
        b=b*2;          //s(b);
        idx++;              //Siguiente idx de stack
    }

    int sol = 0;        //triv(x);

    while (a!=aini) {
        idx--;              //Siguiente idx de stack
        a=stack[idx];   //s-1(a);
        b=b/2;          //s-1(b);
        if (a%2!=0) {       //c();
            sol = sol + b;     
        }
    }

    return sol;
}