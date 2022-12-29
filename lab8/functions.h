#ifndef Functions_H
#define Functions_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void copyArray(char **firstArr, char **secondArr, int howManyStrings);
void printArray(char **arr, int howManyStrings);
void deleteFirstString(char **arr,int howManyStrings);
int getLength(char **s, int posOfString);
void mergeSort(char **arr, int first, int last);
int countWords(char **str, int posOfString);
void allocation(int argc, char **argv, char **arr);
void clearMemory(char **arr);
#endif