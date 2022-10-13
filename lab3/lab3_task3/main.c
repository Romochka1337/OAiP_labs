#include <stdio.h>
#include <stdlib.h>

int inputArraySize();
void bubbleSort(int num[], int size);
int inputByHandOrRandom();
int main() {
    int arrSize1, arrSize2, newArrSize;
    int arr1[100];
    int arr2[100];
    printf("\nInput first array");
    arrSize1 = inputArraySize();
    //input values to array 1
    if(inputByHandOrRandom() == 1){
        printf("Enter numbers one by one\n");
        for(int i = 0; i<arrSize1; i++)
        {
            printf("arr[%d] = ", i);
            if(scanf("%f",&arr1[i])!= 1 || getchar()!='\n'){
                i--;
            }
            rewind(stdin);
            if((i != 0) && (arr1[i] >= arr1[i-1])){
                i--;
                printf("Array must be filled in descending order\n");
            }
            rewind(stdin);
        }
    } else{
        arr1[0] = ((rand() % 20) -10);
        for (int i = 1; i <arrSize1 ; i++) {
            int newValue = (rand() % 10);
                arr1[i] = arr1[i-1] - newValue;
        }
    }
    for (int i = 0; i < arrSize1; i++) {
        printf(" %d ", arr1[i]);
    }

    printf("\nInput second array");
    arrSize2= inputArraySize();
    //input values to array 2
    if(inputByHandOrRandom() == 1){
        printf("Enter numbers one by one\n");
        for(int i = 0; i<arrSize1; i++)
        {
            printf("arr[%d] = ", i);
            if(scanf("%f",&arr2[i])!= 1 || getchar()!='\n'){
                i--;
            }
            rewind(stdin);
            if((i != 0) && (arr2[i] >= arr2[i-1])){
                i--;
                printf("Array must be filled in descending order\n");
            }
            rewind(stdin);
        }
    } else{
        arr2[0] = ((rand() % 20) -10);
        for (int i = 1; i <arrSize2 ; i++) {
            int newValue = (rand() % 10);
            arr2[i] = arr2[i-1] + newValue;
        }
    }
    for (int i = 0; i < arrSize2; i++) {
        printf(" %d ", arr2[i]);
    }

    //union of arrays
    newArrSize = arrSize1 + arrSize2;
    for (int i = 0; i < arrSize2; ++i) {
        arr1[i+arrSize1] = arr2[i];
    }
    bubbleSort(arr1, newArrSize);
    for (int i = 0; i<newArrSize; i++)
        printf("\n%d ", arr1[i]);
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
void bubbleSort(int num[], int size){
    for (int i = 0; i < size - 1; i++){
        for (int j = (size - 1); j > i; j--){
            if (num[j - 1] < num[j]){
                int temp = num[j - 1];
                num[j - 1] = num[j];
                num[j] = temp;
            }
        }
    }
}
