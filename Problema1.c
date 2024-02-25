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
    int arr1[5], arr2[5], num, index;
    int *arr1Ptr = &arr1[0];
    int * arr2Ptr = &arr2[0];
    printf("Se generaron 2 arrays de 5 elementos con numeros aleatorios\n");
    for (int i = 0; i < sizeof(arr1)/sizeof(arr1[i]); ++i) {
        arr1[i] = (rand()%100)+1;
        arr2[i] = (rand()%100)+1;
    }
    printf("Array 1\n");
    printIntArray(arr1Ptr, sizeof(arr1));
    printf("Array 2\n");
    printIntArray(arr2Ptr, sizeof(arr2));
    num = (rand()%100)+1;
    index = rand()%sizeof(arr1)/sizeof(arr1[0]);
    printf("\nSe insertara el numero generado aleatoriamente (%i) en la posicion aleatoria (%i) del arreglo 1\n", num, index);
    insertarIntArray(arr1Ptr, num, index);
    printf("Array 1:\n");
    printIntArray(arr1Ptr, sizeof(arr1));
    index = rand()%sizeof(arr1)/sizeof(arr1[0]);
    printf("\nSe eliminara un numero de la posicion aleatoria (%i) del arreglo 2", index);
    deleteIntArray(arr2Ptr, index);
    printf("\nArray 2:\n");
    printIntArray(arr2Ptr, sizeof(arr2));
    printf("\nSe fusionaran los dos arreglos modificados\n");
    int * ptr3 = fusionarArraysInt(arr1Ptr, arr2Ptr, sizeof(arr1), sizeof(arr2));
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
    int * ptrFusion = &arrFusion;
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