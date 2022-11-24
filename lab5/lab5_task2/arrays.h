#include <stdio.h>
#include <stdlib.h>
int inputArraySize();
void inputArrayElements(int **arr, int n, int m);
void showArray(int **arr, int n, int m, int size);
void removeFromArr(int **arr, int m, int removeI, int removeJ);
int getIndexForRemove(int **arr, int n, int m);
void memoryRealloc(int **arr, int m, int size);
void clearMemory(int **arr, int n);
