#include <stdio.h>
#include <math.h>

int main() {
    int nbr;
    float eps, h0;

    float g = 9.81;

    printf("nbr:");
    scanf("%d", &nbr);

    printf("h0:");
    scanf("%f", &h0);

    printf("eps:");
    scanf("%f", &eps);

    float v = sqrtf(2*h0*g);

    int i;

    for(i = 0; i < nbr; i++){
        v = eps*v;
    }

    float result = (v*v)/(2*g);

    printf("%f", result);

    return 0;
}
