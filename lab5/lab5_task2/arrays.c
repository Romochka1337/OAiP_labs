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
        arr[i] = (int*)malloc(m * sizeof(int));
        for (int j = 0; j<m; j++)
        {
            printf("a[%d][%d] = ", i, j);
            if(scanf("%d",&arr[i][j])!= 1 || getchar()!='\n'){
                j--;
            }
            rewind(stdin);
        }
    }
}
void showArray(int **arr, int n, int m, int size){
    printf("\n");
    for (int i = 0; i < n; i++){
        if (i < size){
            m--;
        }
        for (int j = 0; j < m; j++){
            printf("\t%d\t", arr[i][j]);
        }
        if (i < size){
            m++;
        }
        printf("\n");
    }
}
void removeFromArr(int **arr, int m, int removeI, int removeJ){
    for (int i = removeJ; i < m; i++) {
        arr[removeI][i] = arr[removeI][i+1];
    }
}
int getIndexForRemove(int **arr, int n, int m){
    int size;
    size = (n < m) ? n : m;
    for (int i = 0; i < size; i++) {
        removeFromArr(arr,m, i ,m-i-1);
    }
    return size;
}
void memoryRealloc(int **arr, int m, int size){
    m--;
    for (int i = 0; i < size; i++) {
        arr = realloc(arr, (m) * sizeof(int));
    }
}
void clearMemory(int **arr, int n){
    for (int i = 0; i < n; i++){
        free(arr[i]);
    }
}