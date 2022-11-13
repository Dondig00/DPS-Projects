#include <stdio.h>
#include <stddef.h>

const char *p;

char *funcion1(char array[]) {
   //char array[10] = "Mi Cadena"; // DLC30-C: Se inicializa el array de forma local con una direecion , puede generar overflow
   array = "Mi Cadena"; // inicializamos array en la funcion main y le damos el valor en funcion 1
   /* Initialize array */
   return array;
}

void funcion2(void) {
   const char c_str[] = "Todo va bien";
   //DCL30-C. Puede generar que c_str se sobreescriba yo se pierda cuando termine funcion2
   p = c_str;
}

void funcion3(void) {
   printf("%s\n", p);
}

int main(void) {

   char array[10]; 
   p = funcion1(array);
   printf("%s\n", p);
   p = NULL;// Posible solucion vaciarlo
   funcion2();
   funcion3();
   printf("%s\n", p);

   return 0;
}
