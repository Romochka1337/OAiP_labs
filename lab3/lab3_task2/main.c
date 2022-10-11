#include <stdio.h>
int inputArraySize();
void checkForEven(int arr[], int arrSize);
void deleteElements(int arr[],int arrSize, int indexLastEven);
int main() {
    int arrSize;
    arrSize = inputArraySize();
    int arr[100];
    //input values to array
    for(int i = 0; i<arrSize; i++)
    {
        printf("arr[%d] = ", i);
        if(scanf("%d",&arr[i])!= 1){
            i--;
        }
        rewind(stdin);
    }
    checkForEven(arr,arrSize);
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
void checkForEven(int arr[], int arrSize){
    int isThereEven = 0, indexLastEven;
    for (int i = 0; i < arrSize; i++) {
        int num = arr[i];
        num %= 2;
        if((num == 0) && (arr[i] != 0)){
            isThereEven++;
            indexLastEven = i;
        }
    }
    if(isThereEven != 0){
        deleteElements(arr,arrSize, indexLastEven);
    } else{
        printf("\nThere are no even numbers");
    }
}
void deleteElements(int arr[],int arrSize, int indexLastEven){
    for (int i = arrSize; i >= indexLastEven; i--) {
        for (int i = indexLastEven+1; i < arrSize; i++) {
            arr[i]=arr[i+1];
        }
    }
    arrSize = indexLastEven + 1;
    for (int i = 0; i < arrSize; i++) {
        printf("\n%d",arr[i]);
    }
}