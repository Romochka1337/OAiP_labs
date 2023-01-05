#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "functions.c"

int main() {
    void (*fptr)() = NULL;
    int restart = 1, task;
    while (restart)
    {
        chooseTask(&task);
        if (task == 1)
            fptr = firstTask;
        else
            fptr = secondTask;
        fptr();
        reset(&restart);
    }
    return 0;
}








