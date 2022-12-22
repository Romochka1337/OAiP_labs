#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"
#include "arrays.c"
int main() {
    int **arr;
    int height, width;
    printf("Enter height: ");
    height = inputArraySize();
    printf("Enter width: ");
    width = inputArraySize();

    arr = (int**)malloc(height * sizeof(int*));
    inputArrayElements(arr, height, width);
    showArray(arr, height, width);
    countSums(arr, height, width);

    mergeSort(arr, 0, height-1, width);


    showArray(arr, height, width);
    clearMemory(arr, height);
    return 0;
}
