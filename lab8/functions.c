#include "functions.h"

void allocation(int argc, char **argv, char **arr){
    for (int i = 0; i < argc; i++){
        *(arr + i) = (char *) malloc(getLength(argv, i) * sizeof(char));
    }
}
void clearMemory(char **arr){
    free(arr);
}
void copyArray(char **firstArr, char **secondArr, int howManyStrings){
    for (int i = 0; i < howManyStrings; i++)
        for (int j = 0; j < getLength(firstArr, i); j++)
            *(*(secondArr + i) + j) = *(*(firstArr + i) + j);
}

void printArray(char **arr, int strAmount)
{
    for (int i = 0; i < strAmount; i++)
        printf("%s\n", *(arr + i));
}

void deleteFirstString(char **arr, int howManyStrings)
{
    for (int i = 0; i < howManyStrings - 1; i++)
        *(arr + i) = *(arr + i + 1);
}

int getLength(char **s, int posOfString){
    int cnt = 0, i = 0;
    while (*(*(s + posOfString) + i) != '\0')
    {
        cnt++;
        i++;
    }
    return cnt + 1;
}

int countWords(char **str, int posOfString){
    int i, flag, cnt;
    for (i = 0, flag = 0, cnt = 0; str[posOfString][i] != '\0'; i++)
    {
        if (str[posOfString][i] == ' ' ||   str[posOfString][i] == '\t')
            flag = 0;
        else
        {
            if (flag == 0)
            {
                cnt++;
                flag = 1;
            }
        }
    }
    return cnt;
}

void merge(char **str, int first, int last)
{
    int mid, start, end, j;
    char **tmpArr = (char**) malloc ((last) * sizeof(char*));
    for (int i = 0; i < first; i++){
        *(tmpArr+i)=*str;
    }

    mid = (first + last) / 2;
    start = first;
    end = mid + 1;

    for (j = first; j <= last; j++)
        if ((start <= mid) && ((end > last) || (countWords(str, start) < countWords(str, end))))
        {
            *(tmpArr + j) = *(str + start);
            start++;
        } else
        {
            *(tmpArr + j) = *(str + end);
            end++;
        }
    for (j = first; j <= last; j++){
        *(str + j) = *(tmpArr + j);
    }
    clearMemory(tmpArr);
}

void mergeSort(char **arr, int first, int last)
{
    if (first < last)
    {
        mergeSort(arr, first, (first + last) / 2);
        mergeSort(arr, (first + last) / 2 + 1, last);
        merge(arr, first, last);
    }
}



