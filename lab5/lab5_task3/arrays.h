#ifndef LAB5_TASK3_ARRAYS_H
#define LAB5_TASK3_ARRAYS_H
#endif //LAB5_TASK3_ARRAYS_H
#include <stdio.h>
#include <stdlib.h>
int inputArraySize();
void inputElements(int **arr,int *arrLines, int height);
void showArray(int **arr, int *arrLines, int height);
void getEvenLines(int **arr, int *arrLines, int height);
void getDuplicationIndex(int **arr, int *arrLines, int dupI);
void memoryRealloc(int **arr,int *arrLines,  int index);
void duplicateOdds(int **arr, int *arrLines, int dupI, int dupJ);
void inputLinesSizes(int *arrLines, int height);
void clearMemory(int **arr, int *arrLines, int n);
