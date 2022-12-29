#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "functions.c"

int main() {

    void (*task1)();
    task1 = firstTask;
    void (*task2)();
    task2 = secondTask;
    if (chooseTask() == 1){
        task1();
    } else{
        task2();
    }
    return 0;
}








