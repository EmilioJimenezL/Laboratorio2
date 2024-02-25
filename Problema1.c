#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int integerSize = 4;

void insertarIntArray (int[], int, int);
void printIntArray(int*, int);
void deleteIntArray(int *, int);
int * fusionarArraysInt(int *, int *, int, int);

int main()
{
    srand(time(NULL));
    int arr1[5], arr2[5], num, index, menu;
    int * arr1Ptr = &arr1[0];
    int * arr2Ptr = &arr2[0];
    int * selectedPtr;
    printf("Se genero 1 array de 5 elementos\n");
    for (int i = 0; i < sizeof(arr1)/sizeof(arr1[i]); ++i) {
        arr1[i] = 0;
    }
    do {
        printf("Array 1\n");
        printIntArray(arr1Ptr, sizeof(arr1));
        printf("Que operacion desea realizar?\n");
        printf("1) Insertar\n2) Eliminar\n3) Fusionar 2 arreglos\n0) Salir\n");
        scanf("%i", &menu);
        switch (menu) {
            case 1:
                printf("Ingrese el valor que desea insertar:\n");
                scanf("%i", &num);
                printf("Ingrese la posicion en la cual lo desea insertar:\n");
                scanf("%i", &index);
                insertarIntArray(arr1, num, index);
                break;
            case 2:
                printf("Escriba el indice del valor que desea eliminar:\n");
                scanf("%i", &index);
                deleteIntArray(arr1Ptr, index);
                break;
            case 3:
                for (int i = 0; i < sizeof(arr2)/sizeof(arr2[i]); ++i) {
                    arr2[i] = rand()%100+1;
                }
                printf("Se ha generado un segundo array con valores aleatorios:\n");
                printf("Array 2\n");
                printIntArray(arr2Ptr, sizeof(arr2));
                printf("Se han fusionado ambos arrays:\n");
                fusionarArraysInt(arr1Ptr, arr2Ptr, sizeof(arr1), sizeof(arr2));
                break;
            case 0:
                printf("Saliendo del programa...");
                break;
            default:
                break;
        }
    } while (menu != 0);
    return 0;
}
void printIntArray(int *ptr, int memorySize){
    for (int i = 0; i < memorySize/integerSize; ++i) {
        printf("%i ", *ptr);
        ptr++;
    }
    printf("\n");
}
void insertarIntArray (int * ptr, int num, int index){
    *(ptr + index) = num;
}
void deleteIntArray(int * ptr, int index){
    *(ptr + index) = 0;
}
int * fusionarArraysInt(int * ptr1, int * ptr2, int msize1, int msize2){
    int aux;
    int arr1Size = msize1/integerSize;
    int arr2Size = msize2/integerSize;
    int arrFusionSize = arr1Size + arr2Size;
    int arrFusion[arrFusionSize];
    int * ptrFusion = &arrFusion[0];
    for (int i = 0; i < arr1Size; ++i) {
        arrFusion[i] = *(ptr1+i);
        aux = i+1;
    }
    for (int i = aux; i < (arr2Size + aux); ++i) {
        arrFusion[i] = *(ptr2+(i-aux));
    }
    printIntArray(ptrFusion, arrFusionSize*4);
    return ptrFusion;
}