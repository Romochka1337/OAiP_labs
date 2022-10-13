#include <stdio.h>
#include <stdlib.h>
int inputArraySize();
int inputByHandOrRandom();
int inputArrayManually();
void sortColumns(int arr[100][100], int arrLines, int arrColumns, int arrSums[100]);
int main() {
    int arrLines, arrColumns, arrSums[100], arr[100][100];
    printf("\nInput number of lines: ");
    arrLines = inputArraySize();
    printf("\nInput number of columns: ");
    arrColumns = inputArraySize();
    //enter values
    if(inputByHandOrRandom() == 1){
        printf("Enter numbers one by one\n");
        for (int i = 0; i <arrLines ; i++) {
            printf("\nLine number %d\n",i+1);
            for (int j = 0; j < arrColumns; ++j) {
                arr[i][j] = inputArrayManually();
            }
        }
    } else{
        for (int i = 0; i <arrLines ; i++) {
            for (int j = 0; j < arrColumns; ++j) {
                arr[i][j] = (rand() % 20) -10;
            }
        }
    }
    //count sum of elements in columns
    for (int i = 0; i < arrColumns; ++i) {
        arrSums[i] = 0;
        for (int j = 0; j < arrLines; ++j) {
            if ((arr[j][i] < 0)&&(arr[j][i]%2==0)){
                arrSums[i] += -(arr[j][i]);
            }
        }
    }
    //output result array
    for (int i = 0; i <arrLines ; i++) {
        for (int j = 0; j < arrColumns; ++j) {
            printf(" %d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    //out sums
    printf("Performance indicators\n");
    for (int i = 0; i < arrColumns; i++) {
        printf(" %d ",arrSums[i]);
    }
    printf("\n");
    int bool = 1, bool2 = 0;
    while (bool = 1){
        for (int i = 0; i < arrColumns-1; i++) {
            bool2=0;
            if (arrSums[i] > arrSums[i+1]){
                sortColumns(arr,arrLines,arrColumns,arrSums);
                //count sum of elements in columns
                for (int i = 0; i < arrColumns; ++i) {
                    arrSums[i] = 0;
                    for (int j = 0; j < arrLines; ++j) {
                        if ((arr[j][i] < 0)&&(arr[j][i]%2==0)){
                            arrSums[i] += -(arr[j][i]);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < arrColumns-1; i++) {
            if (arrSums[i]>arrSums[i+1]){
                bool2=1;
            }
        }
        if (bool2 == 0){
            bool = 0;
            break;
        }
    }
    printf("\nResult of moving columns\n");
    //output result array
    for (int i = 0; i <arrLines ; i++) {
        for (int j = 0; j < arrColumns; ++j) {
            printf(" %d ", arr[i][j]);
        }
        printf("\n");
    }
    //out sums
    printf("Performance indicators\n");
    for (int i = 0; i < arrColumns; i++) {
        printf(" %d ",arrSums[i]);
    }
    int sumOfElements = 0, isThereNegativeNum = 0;
    for (int i = 0; i < arrLines; i++) {
        for (int j = 0; j < arrColumns; j++) {
            if (arr[i][j] < 0){
                isThereNegativeNum++;
            }
        }
        if (isThereNegativeNum > 0){
            for (int j = 0; j < arrColumns; j++) {
                sumOfElements += arr[i][j];
            }
        }
        isThereNegativeNum = 0;
    }
    printf("\n Sum of elements: %d", sumOfElements);
    return 0;
}
int inputArraySize(){
    int arrSize;
    if(scanf("%d",&arrSize)!= 1 || arrSize <= 0){
        printf("You entered an invalid value, please try again");
        rewind(stdin);
        return inputArraySize();
    }
    else
        rewind(stdin);
    return arrSize;
}
int inputByHandOrRandom(){
    printf("\nEnter 1 if you want to enter the array manually");
    printf("\nEnter 2 if you want a random array\n");
    int handOrRand;
    if(scanf("%d",&handOrRand)!= 1 || ((handOrRand != 1)&&(handOrRand != 2))){
        printf("You entered an invalid value, please try again\n");
        rewind(stdin);
        return (inputByHandOrRandom());
    }
    return handOrRand;
}
int inputArrayManually(){
    int num;
    if(scanf("%d",&num)!= 1){
        printf("You entered an invalid value, please try again");
        rewind(stdin);
        return inputArrayManually();
    }
    else
        rewind(stdin);
    return num;
}
void sortColumns(int arr[100][100], int arrLines, int arrColumns, int arrSums[100]){
        for (int j = 0; j < arrColumns-1; j++) {
            for (int i = 0; i < arrLines; i++) {
                if (arrSums[j] > arrSums[j+1]){
                    int a = arr[i][j];
                    arr[i][j] = arr[i][j+1];
                    arr[i][j+1]=a;
                }
            }
        }
}