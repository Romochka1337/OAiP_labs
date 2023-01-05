#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void clearMemory(int *arr, int *arrEvens){
    free(arr);
    free(arrEvens);
}
int inputArraySize(){
    int arrSize;
    if(scanf("%d",&arrSize)!= 1 ||arrSize <= 0 || getchar()!='\n'){
        printf("You entered an invalid value, please try again");
        rewind(stdin);
        return inputArraySize();
    }
    else
        rewind(stdin);
    return arrSize;
}

void inputElementsRandomly(int *arr, int arrSize){
    for (int i = 0; i < arrSize; i++) {
        arr[i] = (rand() % 200) -100;
    }
}
void inputElementsManually(int *arr, int arrSize){
    for (int i = 0; i < arrSize; i++) {
        printf("a[%d] = ", i);
        if(scanf("%d",&arr[i])!= 1 || getchar()!='\n'){
            i--;
        }
        rewind(stdin);
    }
}
void inputElementsWorst(int *arr, int arrSize){
    arr[0] = arrSize * 2;
    for (int i = 1; i < arrSize; i++) {
        arr[i] = arr[i-1] - 2;
    }
}
void showResult(int *arr, int arrSize){
    for (int i = 0; i < arrSize; i++) {
        printf("%5d\t", arr[i]);
    }
}

int getEvensArrSize(int *arr, int arrSize){
    int arrEvensSize= 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i]%2 == 0){
            arrEvensSize++;
        }
    }
    return arrEvensSize;
}
void composeEvensArr(int *arr, int *arrEvens, int arrSize){
    int evenCounter = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i]%2 == 0){
            arrEvens[evenCounter] = arr[i];
            evenCounter++;
        }
    }
}

void putIntoInitialArray(int *arr, int *arrEvens,int arrSize){
    int evenCounter = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i]%2 == 0){
            arr[i] = arrEvens[evenCounter];
            evenCounter++;
        }
    }
}

void selectionSort(int *arrEvens, int arrSize){
    int min, temp;
    for (int i = 0; i < arrSize - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < arrSize; j++)
        {
            if (arrEvens[j] < arrEvens[min])
                min = j;
        }
        temp = arrEvens[i];
        arrEvens[i] = arrEvens[min];
        arrEvens[min] = temp;
    }
}
void merge(int *a, int n)
{
    int mid = n / 2; // находим середину сортируемой последовательности
    if (n % 2 == 1)
        mid++;
    int h = 1; // шаг
    // выделяем память под формируемую последовательность
    int *c = (int*)malloc(n * sizeof(int));
    int step;
    while (h < n)
    {
        step = h;
        int i = 0;   // индекс первого пути
        int j = mid; // индекс второго пути
        int k = 0;   // индекс элемента в результирующей последовательности
        while (step <= mid)
        {
            while ((i < step) && (j < n) && (j < (mid + step)))
            { // пока не дошли до конца пути
                // заполняем следующий элемент формируемой последовательности
                // меньшим из двух просматриваемых
                if (a[i] < a[j])
                {
                    c[k] = a[i];
                    i++; k++;
                }
                else {
                    c[k] = a[j];
                    j++; k++;
                }
            }
            while (i < step)
            { // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
                c[k] = a[i];
                i++; k++;
            }
            while ((j < (mid + step)) && (j<n))
            {  // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
                c[k] = a[j];
                j++; k++;
            }
            step = step + h; // переходим к следующему этапу
        }
        h = h * 2;
        // Переносим упорядоченную последовательность (промежуточный вариант) в исходный массив
        for (i = 0; i<n; i++)
            a[i] = c[i];
    }
}
int chooseVariant(){
    int bool;
    printf("\nEnter 1 to fill randomly/ 2 to fill manually / 3 to fill worst variant: ");
    scanf("%d",&bool);
    rewind(stdin);
    return bool;
}
void copyArray(int *arr, int *arr2, int arrSize){
    for(int i =0; i < arrSize; i++){
        arr2[i]=arr[i];
    }
}


