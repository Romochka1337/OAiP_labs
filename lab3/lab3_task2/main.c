#include <stdio.h>
#include <stdlib.h>

int inputArraySize();
void checkForEven(int arr[], int arrSize);
void deleteElements(int arr[],int arrSize, int indexLastEven);
int inputByHandOrRandom();
int main() {
    int arrSize;
    arrSize = inputArraySize();
    int arr[100];
    //input values to array
    if(inputByHandOrRandom() == 1){
        printf("Enter numbers one by one\n");
        for(int i = 0; i<arrSize; i++)
        {
            printf("arr[%d] = ", i);
            if(scanf("%d",&arr[i])!= 1 || getchar()!='\n'){
                i--;
            }
            rewind(stdin);
        }
    } else{
        for (int i = 0; i <arrSize ; i++) {
            arr[i] = (rand() % 20) -10;

        }
    }
    for (int i = 0; i < arrSize; i++) {
        printf(" \n%d ", arr[i]);
    }
    printf("\nResult: ");

    checkForEven(arr,arrSize);
    return 0;
}
int inputArraySize(){
    int arrSize;
    printf("\nInput array size: ");
    if(scanf("%d",&arrSize)!= 1 || arrSize <= 0|| arrSize > 100 ||getchar()!='\n'){
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
    if(scanf("%d",&handOrRand)!= 1  || getchar()!='\n'|| ((handOrRand != 1)&&(handOrRand != 2))){
        printf("You entered an invalid value, please try again\n");
        rewind(stdin);
        return (inputByHandOrRandom());
    }
    return handOrRand;
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