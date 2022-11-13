#include <stdio.h>

unsigned long long int factorial(unsigned int i) {
    if(i<=1) {
        return 1;
    }
    return i*factorial(i-1);
}

int main(int argc, char *argv[]) {
    
    //DCL04-C: Se declaran tres variables en la misma línea de código , separamos para evitar confusiones
    int i=12;
    int j=3;
    int f=0;

    if(argc==1) {
        printf("Factorial of %d is %lld\n", i, factorial(i));
    }
    else {
        //MSC24-C: Se usa la función deprecada atoi() , cambiamos por strtol()
        j = strtol(argv[1]);
        for(f=0;f<j;f++) {
            printf("Factorial of %d id %lld\n", f, factorial(f));
        }
    }
}

//El codigo sirve para calcular el factorial de i recursivamente
//Ademas de las corregidas , se incumplen las siguientes reglas: INT30-C , DCL00-C , DCL01-C e INT08-C
//La linea que mas consume es la linea 24 , la cual calcula todos los factoriales anteirores y los imprime
