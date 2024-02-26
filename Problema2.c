/*
 * Estructuras de datos - LIS 2032-01
 * Nombres Completos:
 * Emilio Ivan Jimenez Lopez
 * Hector Alejandro Canizales Peña
 * Brandon Yahir Castro Ramos
 * Descripción breve del programa:
 * */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef struct {
	char *nombre;
	char *placas;
	int modelo;

} car;

int popFromEstacionamientoStack(car *estacionamiento[10], int *top);
int addToEstacionamientoStack(car *estacionamiento[10], int *top, char *nombre, char *placas, int modelo);
int printEstacionamientoStack(car *estacionamiento[10], int top);
int printEstacionamientoArray(car *[10]);

int main(int argc, char* argv[] ){

	car* estacionamiento[10] = {NULL};
	// estacionamiento_top shall be an available index number 
	int estacionamiento_top = 0;

	while(1){
		printf("Utilice el menu para manejar el estacionamiento\n");
		printf("1) Imprimir stack del estacionamiento.\n");
		printf("2) Anadir o editar el stack del estacionamiento.\n");
		printf("3) Remover del stack del estacionamiento.\n");
		printf("0) Salir.\n");

		int input_i;

		scanf("%i", &input_i);
		getchar();
		//printf("the char received is %c\n", x);

		switch(input_i){
			case 1:
				printEstacionamientoStack(estacionamiento, estacionamiento_top);

				break;
			case 2:
				int go_back = 0;
				while(!go_back){

					char input_c;

					printf("Seleccione una opcion:\n");
					printf("a) Anadir nuevo carro.\n");
					printf("c) Cambiar datos de un carro.\n");
					printf("0) Go back.\n");

					scanf("%c", &input_c);
					getchar();
					//printf("input_c is %c\n", input_c);

					switch(input_c){
						case 'a':
							//int arreglo_insertar_valor(int* numbers, int length, int value, int index, int* usados_length){
							//

							if(estacionamiento_top == 10){
								printf("Estacionamiento LLENO");
								break;
							}

							char *nombre = malloc(51);
							char *placas = malloc(11);
							char modelo_s[10];
							int modelo;

							printf("Ingrese el nombre del carro (max 50 chars):\t");
							scanf("%s", nombre);
							printf("Ingrese las placas del carro (max 10 chars):\t");
							scanf("%s", placas);
							printf("Ingrese el modelo del carro (solo numeros):\t");
							scanf("%s", modelo_s);

							errno = 0;
							// convert string to int
							char *endptr;

							// convert string to int base 10
							modelo = strtol(modelo_s, &endptr, 10);
							while(*endptr != '\0'){
								printf("Ingrese el Modelo solo como un numero:\t");
								scanf("%s", modelo_s);
								errno = 0;
								// convert string to int base 10
								modelo = strtol(modelo_s, &endptr, 10);
							}


							addToEstacionamientoStack(estacionamiento, &estacionamiento_top, nombre, placas, modelo);
							printf("Carro: [%s] anadido a numero\n", placas, estacionamiento_top);
							printEstacionamientoStack(estacionamiento, estacionamiento_top);

							break;
						case 'c':

							int numero;
							{

								errno = 0;
								// convert string to int
								char *endptr;

								char numero_s[11];
								printf("Ingrese el numero de carro que quiere modificar: ");
								scanf("%s", numero_s);

								// convert string to int base 10
								numero = strtol(numero_s, &endptr, 10);
								while(*endptr != '\0'){
									printf("Ingrese el numero de nuevo:\t");
									scanf("%s", numero_s);
									errno = 0;
									// convert string to int base 10
									numero = strtol(numero_s, &endptr, 10);
								}

							}

							printf("Numero is: %d\n", numero); 

							if(numero <= estacionamiento_top){


								free(estacionamiento[numero-1]->nombre);
								free(estacionamiento[numero-1]->placas);

								char *nombre = malloc(51);
								char *placas = malloc(11);
								char modelo_s[10];
								int modelo;

								printf("Ingrese el nombre del carro (max 50 chars):\t");
								scanf("%s", nombre);
								printf("Ingrese las placas del carro (max 10 chars):\t");
								scanf("%s", placas);
								printf("Ingrese el modelo del carro (solo numeros):\t");
								scanf("%s", modelo_s);

								errno = 0;
								// convert string to int
								char *endptr;

								// convert string to int base 10
								modelo = strtol(modelo_s, &endptr, 10);
								while(*endptr != '\0'){
									printf("Ingrese el Modelo solo como un numero:\t");
									scanf("%s", modelo_s);
									errno = 0;
									// convert string to int base 10
									modelo = strtol(modelo_s, &endptr, 10);
								}

								estacionamiento[numero-1]->nombre = nombre;
								estacionamiento[numero-1]->placas = placas;
								estacionamiento[numero-1]->modelo= modelo;

							} else {
								printf("Numero de carro incorrecto. Intente nuevamente.\n");
							}

							printEstacionamientoStack(estacionamiento, estacionamiento_top);

							break;
						default:
							printf("Going back... [ENTER]\n");
							go_back = 1;
							break;
					}

					getchar();

				}

				break;
			case 3:

				popFromEstacionamientoStack(estacionamiento, &estacionamiento_top);
				printEstacionamientoStack(estacionamiento, estacionamiento_top);
				
				//getchar();

				break;
			default:
				printf("Exiting...\n");
				exit(0);

		}

	}
	printEstacionamientoArray(estacionamiento);
	return 0;
}

int popFromEstacionamientoStack(car *estacionamiento[10], int *top){
	if(*top == 0){
		printf("Estacionamiento VACIO\n");
		return 1;
	}

	int i = *top - 1;
	printf("Carro saliendo...\n");
	printf("#%d: %s, %s, %d\n", *top, estacionamiento[i]->nombre, estacionamiento[i]->placas, estacionamiento[i]->modelo);

	free(estacionamiento[i]->nombre);
	free(estacionamiento[i]->placas);
	free(estacionamiento[i]);

	*top = *top - 1;

	return 0;
}

int addToEstacionamientoStack(car *estacionamiento[10], int *top, char *nombre, char *placas, int modelo){
	if(*top == 10){
		printf("Stack is full!\n");
		return 1;
	}
	if(estacionamiento[*top] == NULL){
		estacionamiento[*top] = malloc(sizeof(car));
	}
	estacionamiento[*top]->nombre = nombre;
	estacionamiento[*top]->placas = placas;
	estacionamiento[*top]->modelo = modelo;
	*top = *top + 1;

	return 0;
}

int printEstacionamientoStack(car *estacionamiento[10], int top){
	if(top == 0){
		printf("Estacionamiento VACIO\n");
	}
	for(int i = 0; i < top; i++){
			printf("#%d: %s, %s, %d\n", i+1, estacionamiento[i]->nombre, estacionamiento[i]->placas, estacionamiento[i]->modelo);
	}

	return 0;
}

int printEstacionamientoArray(car *estacionamiento[10]){
	
	for(int i = 0; i < 10; i++){
		if(estacionamiento[i] != NULL){
			printf("[%d]: %s, %s, %d\n", i, estacionamiento[i]->nombre, estacionamiento[i]->placas, estacionamiento[i]->modelo);
		}
	}
	

	return 0;

}
