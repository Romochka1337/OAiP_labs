#include <stdio.h>
int main() {
    int sumNum = 11, plusNum = 27;
    for (int i = 2; i <= 9; ++i) {
        int firstNum;
        int secondNum = sumNum - i;
        int firstChangedNum, secondChangedNum, fullNum, changedFullNum;
        firstNum = i * 10;
        fullNum = firstNum + secondNum;
        changedFullNum = fullNum + plusNum;
        secondChangedNum = changedFullNum % 10;
        firstChangedNum = (changedFullNum - secondChangedNum) / 10;
        if((i == secondChangedNum)&&(secondNum == firstChangedNum)){
            printf("This number is %i ", fullNum);
        }
    }
    return 0;
}
