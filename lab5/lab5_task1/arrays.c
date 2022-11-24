#include <stdio.h>
#include <stdlib.h>

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
void inputElements(float *arr, int arrSize){
    for (int i = 0; i < arrSize; i++) {
        printf("a[%d] = ", i);
        if(scanf("%f",&arr[i])!= 1 || getchar()!='\n'){
            i--;
        }
        rewind(stdin);
    }
}
int checkForInteger(float *arr,int arrSize){
    int num;
    float num2;
    for (int i = 0; i < arrSize; i++) {
        num = arr[i];
        num2 = (float)num;
        if (arr[i] == num2){
            for (int j = i; j < arrSize; j++) {
                arr[j] = arr[j+1];
            }
            i = -1;
            arrSize--;
        }
    }
    return arrSize;
}
void showResult(float *arr, int arrSizeResult){
    printf("\nResult:");
    if (arrSizeResult == 0){
        printf("\nAll elements was removed from array");
    }
    for (int i = 0; i < arrSizeResult; i++) {
        printf("\n%f", arr[i]);
    }
}