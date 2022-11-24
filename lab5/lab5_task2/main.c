#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"
#include "arrays.c"

int main()
{
    int **arr;
    int n, m, size = 0;
    printf("Enter the number of lines: ");
    n = inputArraySize();
    printf("Enter number of columns: ");
    m = inputArraySize();
    arr = (int**)malloc(n * sizeof(int*));
    inputArrayElements(arr, n, m);
    showArray(arr, n, m, size);
    size = getIndexForRemove(arr, n ,m);
    printf("\nResult:");
    memoryRealloc(arr, m, size);
    showArray(arr, n, m, size);
    clearMemory(arr, n);
    return 0;
}


