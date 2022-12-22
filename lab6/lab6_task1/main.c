#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int inputArraySize();
void showResult(int *arr, int arrSize);
void inputElementsManually(int *arr, int arrSize);
void inputElementsRandomly(int *arr, int arrSize);
void inputElementsWorst(int *arr, int arrSize);
int getEvensArrSize(int *arr, int arrSize);
void composeEvensArr(int *arr, int *arrEvens, int arrSize);
int chooseVariant();
void selectionSort(int *arrEvens, int arrSize);
void bubbleSort(int *arrEvens, int arrSize);
void putIntoInitialArray(int *arr, int *arrEvens, int arrSize);
void clearMemory(int *arr, int *arrEvens);
int main() {
    double time_spend = 0.0;
    clock_t begin = clock();
    int *arr;
    int arrSize;
    int *arrEvens;
    int randOrManually;
    printf("\nInput array size: ");
    arrSize = inputArraySize();
    arr = (int *) malloc(sizeof(int) * arrSize);

    randOrManually = chooseVariant();

    if(randOrManually == 1){
        inputElementsRandomly(arr, arrSize);
    }
    else if(randOrManually == 2){
    inputElementsManually(arr, arrSize);
    } else if (randOrManually == 3){
        inputElementsWorst(arr, arrSize);
    }

    showResult(arr,  arrSize);

    int arrEvensSize = 0;
    arrEvensSize = getEvensArrSize(arr, arrSize);

    arrEvens = (int*) malloc(arrEvensSize * sizeof(int));
    composeEvensArr(arr, arrEvens, arrSize);

    //select sort
    selectionSort(arrEvens, arrEvensSize);

    //buble sort
//    bubbleSort(arrEvens, arrEvensSize);

    putIntoInitialArray(arr, arrEvens, arrSize);

    showResult(arr,  arrSize);

    clock_t end = clock();
    time_spend +=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("\nВремя выполнения программы: %f секунд", time_spend);
    clearMemory(arr, arrEvens);
    return 0;
}
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
    printf("\nResult:\t");
    for (int i = 0; i < arrSize; i++) {
        printf("%d\t", arr[i]);
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
void bubbleSort(int *arrEvens, int arrSize){
    for (int i = 0; i < arrSize - 1; i++)
    {
        for (int j = (arrSize - 1); j > i; j--)
        {
            if (arrEvens[j - 1] > arrEvens[j])
            {
                int temp = arrEvens[j - 1];
                arrEvens[j - 1] = arrEvens[j];
                arrEvens[j] = temp;
            }
        }
    }
}
int chooseVariant(){
    int bool;
    printf("\nEnter 1 to fill randomly/ 2 to fill manually / 3 to fill worst variant: ");
    scanf("%d",&bool);
    rewind(stdin);
    return bool;
}

