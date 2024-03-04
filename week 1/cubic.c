#include <stdio.h>
#include <math.h>

int main(){
    double a[3], x[3];

    double q, r, d;

    printf("a0:\n");
    scanf("%lf", &a[0]);

    printf("a1:\n");
    scanf("%lf", &a[1]);

    printf("a2:\n");
    scanf("%lf", &a[2]);

    printf("your formula is: x^3 + %f x^2 + %f x + %f", a[2], a[1], a[0]);

    q = (3*a[1] - a[2]*a[2])/9;
    r = (9*a[1]*a[2] - 27*a[0] - 2*a[2]*a[2]*a[2])/54;
    d = q*q*q + r*r;

    if(d < 0){
        double omega = acos(r/ sqrt(-(q*q*q)));
        x[0] = 2*sqrt(-q) * cos(omega/3) - (1/3)*a[2];
        x[1] = 2*sqrt(-q) * cos((omega + 2*M_PI)/3) - (1/3)*a[2];
        x[2] = 2*sqrt(-q) * cos((omega + 4*M_PI)/3) - (1/3)*a[2];
    }

}