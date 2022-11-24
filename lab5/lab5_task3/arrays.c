#include <stdio.h>
#include <stdlib.h>

int inputArraySize(){
    int arrSize;
    if(scanf("%d",&arrSize)!= 1 ||arrSize <= 0 || getchar()!='\n'){
        printf("You entered an invalid value, please try again\n");
        rewind(stdin);
        return inputArraySize();
    }
    else
        rewind(stdin);
    return arrSize;
}
void inputLinesSizes(int *arrLines, int height){
    for (int i = 0; i < height; i++) {
        printf(" a[%d] = ", i);
        if(scanf("%d",&arrLines[i])!= 1 || getchar()!='\n' || arrLines[i] < 0 ){
            printf("You entered an invalid value, please try again\n");
            i--;
        }
        rewind(stdin);
    }
}
void inputElements(int **arr, int *arrLines, int height){
    for (int i = 0; i < height; i++) {
        int weight = arrLines[i];
        arr[i] = malloc(weight * sizeof(int));
        for (int j = 0; j < weight-1; j++) {
            printf("a[%d][%d] = ", i, j);
            if(scanf("%d",&arr[i][j])!= 1 || getchar()!='\n'){
                j--;
            }
            rewind(stdin);
        }
        arr[i][weight-1]=-100;
    }
}
void showArray(int **arr, int *arrLines, int height){
    printf("\n");
    for (int i = 0; i < height; i++){
        int weight = arrLines[i];
        for (int j = 0; j < weight; j++){
            printf("\t%d\t", arr[i][j]);
        }
        printf("\n");
    }
}
void duplicateOdds(int **arr, int *arrLines, int dupI, int dupJ){
    for (int j = arrLines[dupI]-1; j > dupJ; j--) {
        arr[dupI][j] = arr[dupI][j-1];
    }
}
void memoryRealloc(int **arr, int *arrLines, int dupI){
    arr[dupI] = realloc(arr[dupI], arrLines[dupI] * sizeof(int));
}
void getDuplicationIndex(int **arr, int *arrLines, int dupI){
    //get new array sizes and realloc
    int oddNums = 0;
    for (int j = 0; j < arrLines[dupI]; j++) {
        if (arr[dupI][j]%2 != 0){
            oddNums++;
        }
    }
    arrLines[dupI] += oddNums;
    memoryRealloc(arr,arrLines, dupI);
    //get duplication index
    for (int j = 0; j < arrLines[dupI]; j++) {
        if (arr[dupI][j]%2 != 0){
            duplicateOdds(arr,arrLines, dupI, j);
            j++;
        }
    }
}
void getEvenLines(int **arr, int *arrLines, int height){
    for (int i = 0; i < height; i++) {
        getDuplicationIndex(arr, arrLines, i);
        i++;
    }
}
void clearMemory(int **arr, int *arrLines, int n){
    for (int i = 0; i < n; i++){
        free(arr[i]);
    }
    free(arrLines);
}