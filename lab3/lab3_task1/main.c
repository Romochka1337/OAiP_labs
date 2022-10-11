#include <stdio.h>
int inputArraySize();
void minElement(float arr[], int arrSize);
void sumElements(float arr[], int arrSize);
int main() {
    int arrSize;
    arrSize = inputArraySize();
    float arr[100];
    //input values to array
    for(int i = 0; i<arrSize; i++)
    {
        printf("arr[%d] = ", i);
        if(scanf("%f",&arr[i])!= 1){
            i--;
        }
        rewind(stdin);
    }
    minElement(arr, arrSize);
    sumElements(arr, arrSize);
    return 0;
}
int inputArraySize(){
    int arrSize;
    printf("\nInput array size: ");
    if(scanf("%d",&arrSize)!= 1 || arrSize <= 0){
        printf("You entered an invalid value, please try again");
        rewind(stdin);
        return inputArraySize();
    }
    else
        rewind(stdin);
        return arrSize;
}
void minElement(float arr[], int arrSize){
    float minValue = arr[0];
    for (int i = 0; i < arrSize; i++) {
        if(arr[i] < minValue){
            minValue = arr[i];
        }
    }
    printf("Minimal value is %f", minValue);
}
void sumElements(float arr[], int arrSize){
    int amountPosNums = 0,indexFirstNum, indexLastNum;
    float sum = 0;
    for (int i = 0; i < arrSize; i++) {
        if(arr[i] > 0){
            amountPosNums++;
        }
    }
    if (amountPosNums >= 2){
        //find index of first positive number
        for (int i = 0; i < arrSize; i++) {
            if (arr[i] > 0){
                indexFirstNum = i;
                break;
            }
        }
        //find index of last positive number
        for (int i = arrSize-1; i >= 0; i--) {
            if (arr[i] > 0){
                indexLastNum = i;
                break;
            }
        }
        //count sum
        for (int i = indexFirstNum+1; i < indexLastNum; i++) {
            sum+= arr[i];
        }
        printf("\nSum = %f", sum);
    } else{
        printf("\nThere are not enough positive numbers in the array");
    }
}

