//Write a C++ program to find the sum of 'n' integers using only pointers. Maintain proper boundary conditions and follow coding best practices.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *n,*sum,*temp;
    n = (int *)malloc(sizeof(int));
    sum = (int *) malloc(sizeof(int));

    *sum = 0;

    printf("Enter the value of n: ");
    scanf("%d",n);

    if(*n<=0) {
        printf("\nn should be positive\n");
    }
    else {
        printf("Enter the integers: \n");
        while(*n !=0) {
            scanf("%d",temp);
            *sum += *temp;
            *n -= 1;
        }
        printf("The sum is: %d",*sum);
    }

    return 0;
}