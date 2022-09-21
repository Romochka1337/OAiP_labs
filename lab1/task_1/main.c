#include <stdio.h>
#include <math.h>

int main() {

    float x1, x2, y1, y2;
    printf("\nInput X1: ");
    scanf("%f", &x1);
    printf("Input Y1: ");
    scanf("%f", &y1);
    printf("Input X2: ");
    scanf("%f", &x2);
    printf("Input Y2: ");
    scanf("%f", &y2);
    float distance =sqrtf(((x2 - x1) * (x2 -x1)) + ((y2 - y1)*(y2 - y1)));

    printf("distance = %4.2f \n", distance);
    return 0;
}


