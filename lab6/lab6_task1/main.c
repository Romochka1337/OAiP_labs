#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
#include "functions.c"
int main() {

    int *arr;
    int *arr2;
    int arrSize;
    int *arrEvens;
    int *arrEvens2;
    int randOrManually;
    printf("\nInput array size: ");
    arrSize = inputArraySize();
    arr = (int *) malloc(sizeof(int) * arrSize);
    arr2 =(int *) malloc(sizeof(int) * arrSize);

    randOrManually = chooseVariant();
    if(randOrManually == 1){
        inputElementsRandomly(arr, arrSize);
    }
    else if(randOrManually == 2){
        inputElementsManually(arr, arrSize);
    } else if (randOrManually == 3){
        inputElementsWorst(arr, arrSize);
    }
    copyArray(arr, arr2, arrSize);
    //show initial array
    printf("\nInitial array:\n");
    showResult(arr,  arrSize);



//merge sort
    int arrEvensSize2 = 0;
    arrEvensSize2 = getEvensArrSize(arr2, arrSize);
    arrEvens2 = (int*) malloc(arrEvensSize2 * sizeof(int));
    composeEvensArr(arr2, arrEvens2, arrSize);

    double time_spendMerge = 0.0;
    clock_t beginMerge = clock();

    merge(arrEvens2, arrEvensSize2);
    clock_t endMerge = clock();
    time_spendMerge +=(double)(endMerge-beginMerge)/CLOCKS_PER_SEC;
    printf("\nВремя выполнения сортировки слиянием: %f секунд", time_spendMerge);
    putIntoInitialArray(arr2, arrEvens2, arrSize);
//    printf("\nResult:\n");
//    showResult(arr2,  arrSize);


    //select sort
    int arrEvensSize = 0;
    arrEvensSize = getEvensArrSize(arr, arrSize);
    arrEvens = (int*) malloc(arrEvensSize * sizeof(int));
    composeEvensArr(arr, arrEvens, arrSize);

    double time_spendSelect = 0.0;
    clock_t beginSelect = clock();
    selectionSort(arrEvens, arrEvensSize);

    clock_t endSelect = clock();
    time_spendSelect +=(double)(endSelect-beginSelect)/CLOCKS_PER_SEC;
    printf("\nВремя выполнения сортировки выбором: %f секунд", time_spendSelect);

    putIntoInitialArray(arr, arrEvens, arrSize);
    printf("\nResult:\n");
    showResult(arr,  arrSize);



    clearMemory(arr, arrEvens);
    clearMemory(arr2, arrEvens2);
    return 0;
}


