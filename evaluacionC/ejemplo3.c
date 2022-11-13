#include <stdio.h>

extern void f(int i);

void func(int expr) {
    int i=4;    // Sin sacamos ambos fuera se soluciona
    f(i);
    switch (expr) {
        /*int i=4; //DCL41-C, ninguna de las 2 se ejecuta porque se declara i y se llama f antes de el primer case, no se ejecuta
        f(i);*/
        case 0:
            i=17;
        default:
            printf("%d\n", i);
    }
}

int main(void) {
    func(0);
    return 0;
}

/*
 * Si invocamos func con un 0, la función entrará en el caso 0 del switch e imprimirá 17 .
 * 2. El problema se encuentra en las líneas 11 y 12, ya que el código de esas líneas no se va a ejecutar nunca
 * 
*/