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
void inputArrayElements(int **arr, int n, int m){
    for (int i = 0; i<n; i++)
    {
        arr[i] = (int*)malloc((1 + m) * sizeof(int));
        for (int j = 0; j<m; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}
void showArray(int **arr, int n, int m){
    printf("\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("\t%d\t", arr[i][j]);
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
void mergeSort(int **arr, int start, int end, int width)
{
    if (start != end) {
        int **mergedArray = (int **) malloc(end * sizeof(int * ));
        int mid = (start + end) / 2;

        mergeSort(arr, start, mid, width);
        mergeSort(arr, mid + 1, end, width);

        int i = start;
        int j = mid + 1;
        int k;
        int diff = end - start;

        for (k = 0 ; k < diff + 1; k++)
            if ((j > end) || ((i <= mid) && (arr[i][width] < arr[j][width]))){
                *(mergedArray + k) = *(arr + i);
                i++;
            }
            else{
                *(mergedArray + k) = *(arr + j);
                j++;
            }
        for (k = 0; k < diff+ 1; k++){
            *(arr + start + k) = *(mergedArray + k);
        }
    }else{
        return;
    }
}



