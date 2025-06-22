#include <stdio.h>

int main() {
    int number, d, sum = 0;

    
    printf("Enter an integer: ");
    scanf("%d", &number);

    
    while (number != 0) {
       
        d = number % 10;

     
        sum += d;

        
        number /= 10;
    }

   
    printf("Sum of digits: %d\n", sum);

    return 0;
}