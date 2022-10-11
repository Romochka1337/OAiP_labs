#include <stdio.h>
int inputArraySize();
void bubbleSort(int num[], int size);
int main() {
    int arrSize1, arrSize2, newArrSize;
    int arr1[100];
    int arr2[100];
    printf("\nInput first array");
    arrSize1 = inputArraySize();
    //input values to array 1
    for(int i = 0; i<arrSize1; i++)
    {
        printf("arr[%d] = ", i);
        if(scanf("%d",&arr1[i])!= 1){
            i--;
        }
        if((i != 0) && (arr1[i] >= arr1[i-1])){
            i--;
            printf("Array must be filled in descending order\n");
        }
        rewind(stdin);
    }
    printf("\nInput second array");
    arrSize2 = inputArraySize();
    //input values to array 2
    for(int i = 0; i<arrSize2; i++)
    {
        printf("arr[%d] = ", i);
        if(scanf("%d",&arr2[i])!= 1){
            i--;
        }
        if((i != 0) && (arr2[i] <= arr2[i-1])){
            printf("Array must be filled in ascending order\n");
        }
        rewind(stdin);
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
    if(scanf("%d",&arrSize)!= 1 || arrSize <= 0){
        printf("You entered an invalid value, please try again");
        rewind(stdin);
        return inputArraySize();
    }
    else
        rewind(stdin);
    return arrSize;
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
