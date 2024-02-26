#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXAUTOS 10
#define longitudmax 50

struct Auto {
    char nombre[longitudmax];
    char placas[longitudmax];
    int modelo;
};

struct Estacionamiento {
    struct Auto autos[MAXAUTOS];
    int frente;
    int fin;
    int contador;
};

void inicializarEstacionamiento(struct Estacionamiento *estacionamiento) {
    estacionamiento->frente = -1;
    estacionamiento->fin = -1;
    estacionamiento->contador = 0;
}

int estaLlena(struct Estacionamiento *estacionamiento) {
    return (estacionamiento->contador == MAXAUTOS);
}

int estaVacia(struct Estacionamiento *estacionamiento) {
    return (estacionamiento->contador == 0);
}

void encolar(struct Estacionamiento *estacionamiento, struct Auto *autoNuevo) {
    if (!estaLlena(estacionamiento)) {
        if (estaVacia(estacionamiento)) {
            estacionamiento->frente = 0;
        }
        estacionamiento->fin = (estacionamiento->fin + 1) % MAXAUTOS;
        estacionamiento->autos[estacionamiento->fin] = *autoNuevo;
        estacionamiento->contador++;
        printf("Auto encolado exitosamente.\n");
    } else {
        printf("El estacionamiento está lleno.\n");
    }
}

void desencolar(struct Estacionamiento *estacionamiento) {
    if (!estaVacia(estacionamiento)) {
        printf("Auto desencolado: %s\n", estacionamiento->autos[estacionamiento->frente].nombre);
        estacionamiento->frente = (estacionamiento->frente + 1) % MAXAUTOS;
        estacionamiento->contador--;
        if (estaVacia(estacionamiento)) {
            inicializarEstacionamiento(estacionamiento);
        }
    } else {
        printf("El estacionamiento esta vacio.\n");
    }
}

void imprimirLista(struct Estacionamiento *estacionamiento) {
    if (!estaVacia(estacionamiento)) {
        printf("Lista de autos en el estacionamiento:\n");
        int i = estacionamiento->frente;
        for (int count = 0; count < estacionamiento->contador; count++) {
            printf("Nombre: %s, Placas: %s, Modelo: %d\n", estacionamiento->autos[i].nombre,
                   estacionamiento->autos[i].placas, estacionamiento->autos[i].modelo);
            i = (i + 1) % MAXAUTOS;
        }
    } else {
        printf("El estacionamiento esta vacio.\n");
    }
}

void imprimirPrimerAuto(struct Estacionamiento *estacionamiento) {
    if (!estaVacia(estacionamiento)) {
        printf("Primer auto en el estacionamiento:\n");
        printf("Nombre: %s, Placas: %s, Modelo: %d\n", estacionamiento->autos[estacionamiento->frente].nombre,
               estacionamiento->autos[estacionamiento->frente].placas, estacionamiento->autos[estacionamiento->frente].modelo);
    } else {
        printf("El estacionamiento esta vacio.\n");
    }
}

void imprimirUltimoAuto(struct Estacionamiento *estacionamiento) {
    if (!estaVacia(estacionamiento)) {
        printf("Ultimo auto en el estacionamiento:\n");
        printf("Nombre: %s, Placas: %s, Modelo: %d\n", estacionamiento->autos[estacionamiento->fin].nombre,
               estacionamiento->autos[estacionamiento->fin].placas, estacionamiento->autos[estacionamiento->fin].modelo);
    } else {
        printf("El estacionamiento esta vacio.\n");
    }
}

int main() {
    struct Estacionamiento estacionamiento;
    inicializarEstacionamiento(&estacionamiento);

    int opcion;
    struct Auto autoNuevo;

    do {
        printf("\nMenu:\n");
        printf("1. Agregar auto\n");
        printf("2. Desencolar auto\n");
        printf("3. Mostrar lista de autos\n");
        printf("4. Mostrar primer auto\n");
        printf("5. Mostrar ultimo auto\n");
        printf("0. Salir\n");
        printf("Ingrese su opcion: \n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el nombre del auto:\n");
                scanf("%s", autoNuevo.nombre);
                printf("Ingrese las placas del auto:\n");
                scanf("%s", autoNuevo.placas);
                printf("Ingrese el modelo del auto (numero):\n");
                scanf("%d", &autoNuevo.modelo);
                encolar(&estacionamiento, &autoNuevo);
                break;
            case 2:
                desencolar(&estacionamiento);
                break;
            case 3:
                imprimirLista(&estacionamiento);
                break;
            case 4:
                imprimirPrimerAuto(&estacionamiento);
                break;
            case 5:
                imprimirUltimoAuto(&estacionamiento);
                break;
            case 0:
                printf("Saliendo del programa\n");
                break;
            default:
                printf("Por favor ingrese un numero valido\n");
        }

    } while (opcion != 0);

    return 0;
}
