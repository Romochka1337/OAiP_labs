#include "functions.h"
//int chooseTask(){
//    int choose;
//    printf("\nВведите номер задания (1 или 2): ");
//    if(scanf("%d",&choose)!= 1 ||choose <= 0 || getchar()!='\n' || ((choose!=1)&&(choose!=2))){
//        printf("Вы ввели неправильное значение, попробуйте снова");
//        rewind(stdin);
//        return chooseTask();
//    }
//    else
//        rewind(stdin);
//    return choose;
//}
void firstTask(){
    char *str = (char*)calloc(1024, sizeof(char));
    printf("Введите строку:");
    inputStr(&str);
    if (checkStrForNull(str) == 1){
        printf("\nОшибка. Вы ввели пустую строку\n");
        free(str);
        firstTask();
    } else{
        int wordsAmount = count_word(str);
        int *firstLettersArr;
        int *lastLettersArr;
        int *repeatsCountArr;
        firstLettersArr = (int *)malloc(wordsAmount * sizeof(int));
        lastLettersArr = (int *)malloc(wordsAmount * sizeof(int));
        repeatsCountArr = (int *)malloc(wordsAmount * sizeof(int));
        findWords(str, wordsAmount, firstLettersArr, lastLettersArr);
        wordForCompare(str, wordsAmount, firstLettersArr, lastLettersArr, repeatsCountArr);
        int repeatsMax = 0;
        for (int i = 0; i < wordsAmount; i++) {
            if (repeatsCountArr[i] == 1){
                repeatsCountArr[i] = repeatsCountArr[i]-1;
            }
            if (repeatsCountArr[i] > repeatsMax){
                repeatsMax = repeatsCountArr[i];
            }
        }
        int maxRepWordFirstLetter;
        int maxRepWordLastLetter;
        int checkForSeveralMax = 0;
        for (int i = 0; i < wordsAmount; i++) {
            if (repeatsMax == repeatsCountArr[i]){
                maxRepWordFirstLetter = firstLettersArr[i];
                maxRepWordLastLetter = lastLettersArr[i];
            }

        }
        for (int i = 0; i < wordsAmount; i++){
            if ((repeatsMax == repeatsCountArr[i]) && (compareWords(str, maxRepWordFirstLetter, maxRepWordLastLetter, firstLettersArr[i], lastLettersArr[i]) == 0)){
                checkForSeveralMax = 1;
                break;
            }
        }
        if (checkForSeveralMax == 0){
            printf("\nСамое частое слово это: ");
            for (int i = maxRepWordFirstLetter; i < maxRepWordLastLetter; i++){
                printf("%c", str[i]);
            }
        }else{
            printf("\nЗдесь нет самого частого слова");
        }
        free(str);
        free(firstLettersArr);
        free(lastLettersArr);
        free(repeatsCountArr);
    }
}
int checkStrForNull(char* str){
    int i=0;
    int isThereSymbol = 0;
    while (str[i]!='\0'){
        if ((str[i] != ' ')&&(str[i] != '\t')){
            isThereSymbol++;
        }
        i++;
    }
    return isThereSymbol;
}
void secondTask(){
    char *s= (char*)calloc(1024, sizeof(char));
    char *s0= (char*)calloc(1024, sizeof(char));
    printf("\nВведите строку s:\n");
    inputStr(&s);
    if (checkStrForNull(s) == 1){
        printf("\nОшибка. Вы ввели пустую строку\n");
        free(s);
        secondTask();
    } else{
        printf("\nВведите строку s0:\n");
        inputStr(&s0);
        if (checkStrForNull(s0) == 1){
            printf("\nОшибка. Вы ввели пустую строку\n");
            free(s);
            free(s0);
            secondTask();
        } else{
            char symbol;
            inputSymbol(&symbol);
            allocation(s, s0, symbol);
            printf("\nИтоговая строка:\n");
            fputs(s, stdout);
            free(s);
            free(s0);
        }
    }
}
void allocation(char* s, char* s0, char symbol){
    int wordsAmountS = count_word(s);
    int *firstLettersArrS;
    int *lastLettersArrS;
    firstLettersArrS = (int *)malloc(wordsAmountS * sizeof(int));
    lastLettersArrS = (int *)malloc(wordsAmountS * sizeof(int));
    findWords(s, wordsAmountS, firstLettersArrS, lastLettersArrS);
    int wordsAmountS0 = count_word(s0);
    int *firstLettersArrS0;
    int *lastLettersArrS0;
    firstLettersArrS0 = (int *)malloc(wordsAmountS0 * sizeof(int));
    lastLettersArrS0 = (int *)malloc(wordsAmountS0 * sizeof(int));
    findWords(s0, wordsAmountS0, firstLettersArrS0, lastLettersArrS0);
    findWordsForDelete(s, s0, symbol, wordsAmountS, firstLettersArrS, lastLettersArrS, wordsAmountS0, firstLettersArrS0, lastLettersArrS0);

    free(firstLettersArrS);
    free(lastLettersArrS);
    free(firstLettersArrS0);
    free(lastLettersArrS0);
}
void wordForCompare(char* str, int wordsAmount, int *firstLettersArr, int *lastLettersArr, int *repeatsCountArr){
    int firstWordFirstLetter;
    int firstWordLastLetter;
    int secondWordFirstLetter;
    int secondWordLastLetter;
    for (int i = 0; i < wordsAmount; i++){
        firstWordFirstLetter=firstLettersArr[i];
        firstWordLastLetter=lastLettersArr[i];
        int counter=0;
        for (int j = 0; j < wordsAmount; j++) {
            secondWordFirstLetter= firstLettersArr[j];
            secondWordLastLetter= lastLettersArr[j];
            counter += compareWords(str, firstWordFirstLetter, firstWordLastLetter, secondWordFirstLetter, secondWordLastLetter);
        }
        repeatsCountArr[i] = counter;
    }
}

int compareWords(char* str, int firstWordFirstLetter, int firstWordLastLetter, int secondWordFirstLetter, int secondWordLastLetter){
    int firstLength = firstWordLastLetter-firstWordFirstLetter;
    int secondLength= secondWordLastLetter - secondWordFirstLetter;
    if (firstLength!=secondLength){
        return 0;
    } else{
        for (int i = 0; i < firstLength; i++) {
            if (str[firstWordFirstLetter+i] != str[secondWordFirstLetter+i]) {
                return 0;
            }
        }
        return 1;
    }
}

void inputStr(char** str)
{
    do
    {
        fgets(*str, 1024, stdin);
        rewind(stdin);
    } while (strLength(*str) < 1 && getchar() != '\0');
    char *mas = (char*)realloc(*str, (strLength(*str) + 2) * sizeof(char));
    if (mas != NULL)
        *str = mas;
}
int strLength(char* str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i + 1;
}
void findWords(char* str, int wordsAmount, int *firstLettersArr, int *lastLettersArr){
    int i=0;
    for (int j = 0; j < wordsAmount; j++) {
        while (str[i] != '\0'){
            if (str[i] != '\t' && str[i] != ' '){
                firstLettersArr[j] = i;
                break;
            }
            i++;
        }
        while (str[i] != '\0'){
            if (str[i] == '\t' || str[i] == ' '|| str[i+1] == '\0'){
                lastLettersArr[j] = i;
                break;
            }
            i++;
        }
    }

}
int count_word(char* str)
{
    int i, flag, cnt;
    for (i = 0, flag = 0, cnt = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' || str[i] == ',' || str[i] == '.' || str[i] == '-'|| str[i] == '\t')
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
void inputSymbol(char* a)
{
    printf("Введите символ:");
    while (scanf("%c", a) != 1 || getchar() != '\n' || *a ==' '|| *a =='\t')
    {
        printf("Ошибка.Попробуй снова:\n");
        rewind(stdin);
    }
}

void findWordsForDelete(char* s,char* s0,char symbol,int wordsAmountS,int *firstLettersArrS,int *lastLettersArrS,int wordsAmountS0,int *firstLettersArrS0,int *lastLettersArrS0){
    for (int i = 0; i < wordsAmountS; i++) {
        if (s[firstLettersArrS[i]] == symbol){
            if (compare(s, s0, i, wordsAmountS0, firstLettersArrS, lastLettersArrS, firstLettersArrS0, lastLettersArrS0) == 0){
                delete(s, firstLettersArrS[i], lastLettersArrS[i]);
                allocation(s, s0, symbol);
            }
        }
    }

}

int compare(char* s, char* s0, int sWord, int wordsAmountS0, int *firstLettersArrS, int *lastLettersArrS, int *firstLettersArrS0, int *lastLettersArrS0){
    for (int i = 0; i < wordsAmountS0; i++) {
        if (compareTwoWords(s, s0, sWord, i, firstLettersArrS, lastLettersArrS, firstLettersArrS0, lastLettersArrS0) == 1){
            return 1;
        }
    }
    return 0;
}

int compareTwoWords(char* s, char* s0, int sWord, int s0Word, int *firstLettersArrS, int *lastLettersArrS, int *firstLettersArrS0, int *lastLettersArrS0){
    int diffS, diffS0;
    diffS = lastLettersArrS[sWord] - firstLettersArrS[sWord];
    diffS0 = lastLettersArrS0[s0Word] - firstLettersArrS0[s0Word];
    if (diffS != diffS0){
        return 0;
    } else{
        for (int i = 0; i < diffS; i++) {
            if (s[firstLettersArrS[sWord]+i] != s0[firstLettersArrS0[s0Word]+i]){
                return 0;
            }
        }
        return 1;
    }
}

void delete(char* str, int deleteStart, int deleteEnd){
    int length=0;
    int diff= deleteEnd-deleteStart;
    while (str[length] != '\0'){
        length++;
    }
    length--;
    printf("\n");

    for (int i = 0; i < diff; i++) {
        for (int j = deleteStart; j < length; j++) {
            str[j] = str[j+1];
        }
    }
    int newLength = strLength(str) - diff;
    str = realloc(str, newLength);
}
void reset(int *reset)
{
    printf("\nВыполнить программу ещё раз?(да-1, нет-0):\n");
    while (scanf("%d", reset) != 1 || *reset != 1 && *reset != 0 || getchar() != '\n')
    {
        printf("Ошибка! Попробуйте снова\n");
        rewind(stdin);
    }
}

void chooseTask(int *choice)
{
    printf("\nВыберите номер задания: 1 или 2:\n");
    while (scanf("%d", choice) != 1 || *choice != 1 && *choice != 2 || getchar() != '\n')
    {
        printf("Ошибка! Попробуйте снова\n");
        rewind(stdin);
    }
    printf("Задание %d:\n", *choice);
}