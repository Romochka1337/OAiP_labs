#include <stdio.h>
#include "functions.h"
#include "functions.c"
#include <stdlib.h>


int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("No arguments, restart");
        return 0;
    }
    char **arr = (char **) malloc(argc * (sizeof(char *)));
    allocation(argc, argv, arr);
    copyArray(argv, arr, argc);
    deleteFirstString(arr, argc);
    argc--;
    printf("Initial array::\n");
    printArray(arr, argc);
    mergeSort(arr, 0, argc - 1);
    printf("\nResult array::\n");
    printArray(arr, argc);
    clearMemory(arr);
}
