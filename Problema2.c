/* Problema 2. Pilas con arreglos 
 * (2 puntos)
 * Desarrollar un programa en lenguaje C que permita controlar los 
 * autos que entran y salen de unestacionamiento, empleando el marca del auto
 * (string), placas(string) y modelo(int), usando una pila.
 * Utilice un arreglo de estructuras. Los datos de los autos deberán ser ingresados por el 
 * teclado. 
 *
 * El programa debe usar un menú para poder:
 * a) Imprimir el número de autos que se encuentran en el estacionamiento
 * b) Imprimir la lista de los autos (y sus características) que se 
 * encuentran en el estacionamiento en orden.
 * c) Imprimir el primer auto que ha entrado (características).
 * d) Imprimir el último auto que ha entrado (características).
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


typedef struct {
	char *nombre;
	char placas[10];
	int modelo;

} car;


int printEstacionamientoArray(car *[10]);

int main(int argc, char* argv[] ){

	printf("Hello, world!\n");

	car acar = {"hi", "baa", 0};


	car* estacionamiento[10] = {NULL};
	estacionamiento[0] = &acar;

	printf("nnn is %s\n", (*estacionamiento[0]).nombre);

//	estacionamiento[0]
	char* x = "oo";
	//strcpy( (*estacionamiento[0]).marca, x);
//	strcpy( estacionamiento[0]->marca, "oooooo");

//	printf("name is: %s\n", estacionamiento[0]->marca);

	acar.nombre = "oo";
	estacionamiento[0]->nombre="zzz";
	char *name = estacionamiento[0]->nombre;
	strcpy(name, x);
	printf("nnn is %s\n", (*estacionamiento[0]).nombre);
	printf("nnn is %s\n", estacionamiento[0]->nombre);
	printEstacionamientoArray(estacionamiento);


	exit(0);

	for(int i = 0; i < 10; i++){
		char nombre[50];
		char placas[10];
		char modelo_s[10];
		int modelo;

		scanf("%s", nombre);
		scanf("%s", placas);
		scanf("%s", modelo_s);
		//getchar();

		errno = 0;
		// convert string to int
		char *endptr;
		modelo = strtol(modelo_s, &endptr, 10);
		while(*endptr != '\0'){
			printf("Ingrese el Modelo solo como un numero:\t");
			scanf("%s", modelo_s);
			errno = 0;
			modelo = strtol(modelo_s, &endptr, 10);
		}
		
//		strcpy(estacionamiento[i]->marca, marca);
//		strcpy(estacionamiento[i]->placas, placas);
//		estacionamiento[i]->modelo = modelo;

		//printf("[%d] %s,%s,%d\nEND\n", i, marca, placas, modelo);

	}

	printEstacionamientoArray(estacionamiento);

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
