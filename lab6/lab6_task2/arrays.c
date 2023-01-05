#include <stdio.h>
#include <stdlib.h>
int inputArraySize(){
    int arrSize;
    if(scanf("%d",&arrSize)!= 1 ||arrSize <= 0 || getchar()!='\n'){
        printf("You entered an invalid value, please try again: ");
        rewind(stdin);
        return inputArraySize();
    }
    else
        rewind(stdin);
    return arrSize;
}
int chooseVariant(){
    int bool;
    if(scanf("%d",&bool)!= 1 ||bool <= 0 || getchar()!='\n' || bool < 1 || bool > 2){
        printf("You entered an invalid value, please try again: ");
        rewind(stdin);
        return chooseVariant();
    }
    else
        rewind(stdin);
    return bool;
}
void inputElementsRandomly(int **arr, int n, int m){
    for (int i = 0; i < n; i++) {
        arr[i] = (int*)malloc((1 + m) * sizeof(int));
        for (int j = 0; j < m; j++) {
            arr[i][j] = (rand() % 100) -50;
        }
    }
}
void inputArrayElements(int **arr, int n, int m){
    for (int i = 0; i<n; i++)
    {
        arr[i] = (int*)malloc((1 + m) * sizeof(int));
        for (int j = 0; j<m; j++)
        {
            printf("a[%d][%d] = ", i, j);
            if(scanf("%d",&arr[i][j])!= 1 ||arr[i][j] <= 0 || getchar()!='\n'){
                rewind(stdin);
                j--;
            }
        }
    }
}
void showArray(int **arr, int n, int m){
    printf("\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("\t%5d\t", arr[i][j]);
        }
        printf("\n");
    }
}
void clearMemory(int **arr, int height){
    for (int i = 0; i < height; ++i) {
        free(arr[i]);
    }
    free(arr);
}
void countSums(int **arr, int height, int width){
    for (int i = 0; i < height; i++) {
        int count = 0;
        for (int j = 0; j < width; j++) {
            if (arr[i][j]%2 == 0){
                count+=arr[i][j];
            }
        }
        arr[i][width] = count;
    }
}

void mergeSort(int **arr, int left, int right, int width)
{
    if (left == right) return;
    int mid = (left + right) / 2;

    mergeSort(arr, left, mid, width);
    mergeSort(arr, mid + 1, right, width);
    int i = left;
    int j = mid + 1;
    int **tmpArr = (int **) malloc(right * sizeof(int *));
    for (int k = 0; k < left; k++){
        *(tmpArr+k)=*arr;
    }
    for (int step = 0; step < right - left + 1; step++){
        if ((j > right) || ((i <= mid) && (arr[i][width] < arr[j][width]))){
            *(tmpArr + step) = *(arr + i);
            i++;
        } else{
            *(tmpArr + step) = *(arr + j);
            j++;
        }
    }

    for (int step = 0; step < right - left + 1; step++){
        *(arr + left + step) = *(tmpArr + step);
    }
    clearMemory(tmpArr, 0);
}

