#include <stdbool.h>
#include <stdio.h>
#include <math.h>

bool isPrime(int num){
    if(num < 2)
        return false;

    if(num != 2 && (num % 2) == 0)
        return false;

    int i;
    for(i = 3; i <= sqrt(num); i += 2){
        if((num % i) == 0)
            return false;
    }

    return true;
}

int main(){
    int num;

    printf("Check if number is prime: \n");
    scanf("%d", &num);

    if(isPrime(num))
        printf("%d is a prime \n", num);
    else
        printf("%d is not a prime \n", num);
}