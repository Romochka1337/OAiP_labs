#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"
#include "arrays.c"
int main() {
    int **arr;
    int height, width;
    int randOrManually;
    printf("Enter height: ");
    height = inputArraySize();
    printf("Enter width: ");
    width = inputArraySize();
    printf("\nEnter 1 to fill randomly/ 2 to fill manually: ");
    randOrManually = chooseVariant();
    arr = (int**)malloc(height * sizeof(int*));
    if(randOrManually == 1){
        inputElementsRandomly(arr, height, width);
    }
    else if(randOrManually == 2){
        inputArrayElements(arr, height, width);
    }
    printf("\nInitial array:");
    showArray(arr, height, width);
    countSums(arr, height, width);

    mergeSort(arr, 0, height-1, width);

    printf("\nResult:");
    showArray(arr, height, width);
    clearMemory(arr, height);
    return 0;
}
