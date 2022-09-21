#include <stdio.h>
int cycle(int N);
int fib(int i);
int countIndex(int F);
int main() {
    int N, F, f1, f2;
    printf("\nInput number F: ");
    scanf("%i", &F);
    N = countIndex(F);
    f1 = N -1;
    f2 = N + 1;
    printf("\nFk-1 number= %i",cycle(f1));
    printf("\nFk+1 number= %i",cycle(f2));
    return 0;
}
int cycle(int N){
    int fNum;
    for(int i = 1;i <= N; ++i)
    {
        fNum = fib(i);
    }
    return fNum;
}
int countIndex(int F){
    for (int i = 1; i <= F; ++i) {
        int fibNum = fib(i);
        if(fibNum == F){
            return i;
        }
        if(fibNum > F){
            break;
        }
    }
}
int fib(int i)
{
    if(i < 1) return 0;
    if(i == 1) return 1;
    return fib(i-1) + fib(i - 2);
}
