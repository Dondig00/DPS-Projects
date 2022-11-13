#include <stdlib.h>

struct flexArrayStruct {
    int num; 
    //int data[1]; //DCL38-C ASIGNA un tamaño fijo al array. si fuese mayor saltaria un overflow
    int data[]; //Lo podemos solucionar volviendo el array dinamico
};


//Crea un puntero que almacenara una estructura del tipo flexArrayStruct. Por ello debemos reservar memoria para la estructura, el numero entero y el tamaño de array 
void func(size_t array_size){
    /*Space is allocated for de struct*/
    struct flexArrayStruct *structP = (struct flexArrayStruct *) malloc(sizeof(struct flexArrayStruct) + sizeof(int) * (array_size-1));
    
    if (structP == NULL) {
        /*ERROR*/
    }
    /* Asigna al campo num de la estructura el tamaño del array */
   structP->num = array_size;

   /*
    * Access data[] as if it has been allocated
    * as data[array_size]
   */
   for (size_t i = 0; i < array_size; ++i) {
      structP->data[i] = 1;//DCL38
   }
}

int main(void) {
   func(5);
   return 0;
}

