#include <stdio.h>

int main() {
    int a,b,c;
    printf("\nInput a: ");
    scanf("%i", &a);
    printf("Input b: ");
    scanf("%i", &b);
    printf("Input c: ");
    scanf("%i", &c);
    if ((a == b)||(a == c)||(b == c)){
        printf("There are equal numbers");
    } else{
        printf("There are no equal numbers");
    }
    return 0;
}

