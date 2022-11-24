#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"
#include "arrays.c"

int main()
{
    int **arr;
    int *arrLines;
    int height;

    printf("\nInput array height: ");
    height= inputArraySize();
    arrLines = malloc(height * sizeof (int));
    printf("\nInput string lengths:\n");
    inputLinesSizes(arrLines, height);

    arr = malloc(height * sizeof(int*));

    printf("\nInput elements of array:\n");
    inputElements(arr, arrLines, height);
    showArray(arr, arrLines, height);
    getEvenLines(arr, arrLines, height);
    printf("\nResult:\n");
    showArray(arr, arrLines, height);
    clearMemory(arr, arrLines, height);
    return 0;
}









