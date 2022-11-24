#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"
#include "arrays.c"

int main() {
    float *arr;
    int arrSize, arrSizeResult;

    printf("\nInput array size: ");
    arrSize= inputArraySize();
    arr = malloc(arrSize * sizeof (float));
    inputElements(arr, arrSize);
    arrSizeResult = checkForInteger(arr, arrSize);
    arr = realloc(arr, sizeof(*arr) * arrSizeResult);
    showResult(arr, arrSizeResult);
    free(arr);
    return 0;
}


