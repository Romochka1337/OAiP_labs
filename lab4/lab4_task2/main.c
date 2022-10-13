#include <stdio.h>
#include <stdlib.h>

int inputArraySize();
int inputByHandOrRandom();
int inputArrayManually();
int main() {
    int arrLines, arrColumns, isTherePosNums = 0, arr[100][100];
    printf("\nInput number of lines: ");
    arrLines = inputArraySize();
    printf("\nInput number of columns: ");
    arrColumns = inputArraySize();
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
    //output result
    for (int i = 0; i <arrLines ; i++) {
        for (int j = 0; j < arrColumns; ++j) {
            printf(" %d ", arr[i][j]);
        }
        printf("\n");
    }
    //check for positive numbers
    for (int i = 0; i <arrLines ; i++) {
        for (int j = 0; j < arrColumns; j++) {
            if (arr[i][j] > 0){
                break;
            }
            if (j == arrColumns -1){
                isTherePosNums = -1;
            }
            if (isTherePosNums == -1){
                break;
            }
        }
    }
    if (isTherePosNums < 0){
        printf("\nThere is a line that does not contain positive numbers");
        for (int i = 0; i <arrLines ; i++) {
            for (int j = 0; j < arrColumns; ++j) {
                arr[i][j] = -arr[i][j];
            }
        }
        printf("\n");
    }else{
        printf("\nAll lines contain positive numbers");
    }
    printf("\nResult: \n");
    //output result
    for (int i = 0; i <arrLines ; i++) {
        for (int j = 0; j < arrColumns; ++j) {
            printf(" %d ", arr[i][j]);
        }
        printf("\n");
    }
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