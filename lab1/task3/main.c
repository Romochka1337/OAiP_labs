#include <stdio.h>
#include <math.h>

float averageGeometric(float a, float b, float c);
float averageArithmetic(float a, float b, float c, float notNullCounter);
float countAfterNullCheck(float a, float b, float c);

int main() {
    float a,b,c;
    printf("\nInput a: ");
    scanf("%f", &a);
    printf("Input b: ");
    scanf("%f", &b);
    printf("Input c: ");
    scanf("%f", &c);
    printf("\n%f", countAfterNullCheck(a,b,c));
    return 0;
}
float countAfterNullCheck(float a, float b, float c){
    if((a == 0)||( b == 0)||(c == 0)){
        float notNullCounter = 0;
        if(a != 0)
            notNullCounter++;
        if(b != 0)
            notNullCounter++;
        if(c != 0)
            notNullCounter++;
        if ( notNullCounter == 0)
            return 0;
        return averageArithmetic(a, b, c, notNullCounter);
    }else{
        return averageGeometric(a,b,c);
    }
}
float averageGeometric(float a, float b, float c){
    float result = cbrt(a * b * c) ;
    return result;
}
float averageArithmetic(float a, float b, float c, float notNullCounter){
    float result = (a + b + c) / notNullCounter;
    return result;
}
