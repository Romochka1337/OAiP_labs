#include <stdio.h>
#include <stdlib.h>
int inputArraySize();
int inputByHandOrRandom();
int inputArrayManually();
int main() {
    int arrSize, sum = 0, arr[100][100], countIndex;
    printf("\nInput array size: ");
    arrSize = inputArraySize();
    if(inputByHandOrRandom() == 1){
        printf("Enter numbers one by one\n");
        for (int i = 0; i <arrSize ; i++) {
            printf("\nLine number %d\n",i+1);
            for (int j = 0; j < arrSize; ++j) {
                arr[i][j] = inputArrayManually();
            }
        }
    } else{
        for (int i = 0; i <arrSize ; i++) {
            for (int j = 0; j < arrSize; ++j) {
                arr[i][j] = (rand() % 20) -10;
            }
        }
    }
    for (int i = 0; i <arrSize ; i++) {
        for (int j = 0; j < arrSize; ++j) {
            printf(" %d ", arr[i][j]);
        }
        printf("\n");
    }
    //count sum
    countIndex = arrSize / 2 ;

    for (int i = 0; i < countIndex; i++) {
        for (int j = arrSize-1; j >= arrSize - countIndex; j--) {
            sum += arr[i][j];
        }
    }
    printf("\nSum %d", sum);
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