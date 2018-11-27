/*
 * 
 * Autor: Roberto Martinez
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo {
    int valor;
    struct _nodo *siguiente;
} Nodo;


typedef Nodo *TNodo;
typedef Nodo *Pila;

//creamos la pila que usaremos
void app_pila(Pila *pila, int v) {

    TNodo nuevo;

    nuevo = (TNodo) malloc(sizeof (Nodo));
    nuevo->valor = v;

    nuevo->siguiente = *pila;

    *pila = nuevo;
}

int del_pila(Pila *pila) {
    TNodo nodo;
    int valor;

    nodo = *pila;

    if (!nodo) {
        return 0;
    }

    *pila = nodo->siguiente;

    valor = nodo->valor;

    free(nodo);
    return valor;
}
//funcion para reemplazar un dato
void remplazar(Pila *pila, int viejo, int nuevo) {
    TNodo nodo;
    int encontrado = 0;
    nodo = *pila;

    while (nodo) {
        if (nodo->valor == viejo) {
            encontrado++;
            nodo->valor = nuevo;
        }
        nodo = nodo->siguiente;
    }
    if (encontrado == 0) {
        printf("\nError ...No se Encontro\n");
    }
}

//funcion para mostrar un dato
void mostrar(Pila *pila) {
    TNodo nodo;

    nodo = *pila;

    while (nodo) {
        printf("[%d]", nodo->valor);
        nodo = nodo->siguiente;
    }
    printf("\n");
    printf("\n");
}

int pila_vacia(Pila *pila) {
    return (*pila) ? (1) : (0);
}

int main(int argc, char *argv[]) {

    int op, num, num2;
    Pila nueva_pila = NULL;



// aqui se muestra nuestro menu
    do {
		 printf("==============\n");
        printf("MENU\n");
        printf("==============\n");
        printf("1)INSERTAR\n");
        printf("2)REEMPLAZAR\n");
        printf("3)MOSTRAR\n");
        printf("4)SALIR\n");
printf("\n");

        scanf("%d", &op);
        system("clear");
                switch (op) {
            case 1:
                do {
                    printf("INTRODUCE NUMERO:\n >");
                    scanf("%d", &num);
                    if (num != 0) app_pila(&nueva_pila, num);
                } while (num != 0);
                break;

            case 2:
                if (pila_vacia(&nueva_pila)) {
                    printf("NUMERO A BUSCAR:");
                    scanf("%d", &num);

                    printf("NUMERO A REEMPLAZAR");
                    scanf("%d", &num2);

                    remplazar(&nueva_pila, num, num2);
                } else {
                    printf("PILA VACIA\n");
                }
                break;

            case 3:
                if (pila_vacia(&nueva_pila)) {
                    mostrar(&nueva_pila);
                } else {
                    printf("PILA VACIA\n");
                }
                break;

            case 4:
                exit(EXIT_SUCCESS);
                break;

            default:
                printf("ERROR\n");
                break;
        }
    } while (1);

    return 0;
}

