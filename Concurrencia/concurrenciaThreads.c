#include <threads.h>
#include <stdio.h>
/*
 *  Crea un hilo y le pasa al hilo hijo la dirección en la que se almacena esa variable, al finalizar el hilo hijo imprime por salida esa variable.
 *  La variable tiene un tiempo de almacenado automatico, si se intenta acceder a la variable una vez que este tiempo se agote, esta se borrara de la memoria
 *  y se producira un acceso invalido a memoria.
*/

int child_Thread(void *val) {
    int *res = (int *)val;
    printf("Result: %d\n", *res);
    return 0;
}

void create_Thread(thrd_t *tid) {

    //La solucion es convertir esta variable a estatica, de esta forma se mantendra almacenada en memoria durante toda la ejecución. 
    static int val = 1;

    if (thrd_success != thrd_create(tid, child_Thread, &val)) {
        /* Handle error */
        print("ERROR: Error en la creacion del hilo");
        return 1;
    }
}

int main(void) {
    thrd_t tid;
    create_Thread(&tid);
    if (thrd_success != thrd_join(tid, NULL)) {
        /* Handle error */
        print("ERROR: Error en el bloqueo del hilo");
        return 1;
    }
    return 0;
}