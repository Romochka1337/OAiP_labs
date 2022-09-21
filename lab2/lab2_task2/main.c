#include <stdio.h>
int main() {
    int n;
    float b = 0;
    printf("\nInput number N: ");
    scanf("%i", &n);
    if( n != 0){
        for (float i = 1; i <= n; ++i) {
            b += 1 / i;
        }
        printf("\nNumber = %4.2f", b);
    }
    return 0;
}
