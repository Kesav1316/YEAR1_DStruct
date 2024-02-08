// Write a C++ menu-driven program to sort an array of numbers in ascending or descending order. After you write the function for sorting, search online and find what type of sorting you have done in your code.
//BUBBLE SORT IS USED
#include <stdio.h>
#include <stdlib.h>

void ascending(int *a,int *n) {
    int i,j,*tmp;
    tmp = (int *)malloc(sizeof(int));
    for( i = 0 ; i < *n-1 ; i++) {
        for( j = 0 ; j < *n-1 ; j++) {
            if ( *(a + j) > *(a + j + 1)) {
                *tmp = *(a + j);
                *(a + j) = *(a + (j + 1));
                *(a + (j + 1)) = *tmp;
            }
        }
    }
    printf("SORTED ARRAY \n");
    for(i = 0;i<*n;i++) {
        printf("a[%d] %d \n",i,*(a + i));
    }

}

void descending(int *a,int *n) {
    int i,j,*tmp;
    tmp = (int *)malloc(sizeof(int));
    for( i = 0 ; i < *n-1 ; i++) {
        for( j = 0 ; j < *n-1 ; j++) {
            if ( *(a + (j)) < *(a + (j + 1))) {
                *tmp = *(a + j);
                *(a + j) = *(a + (j + 1));
                *(a + (j + 1)) = *tmp;
            }
        }
    }
    printf("SORTED ARRAY \n");
    for(i = 0;i<*n;(i)++) {
        printf("a[%d] %d \n",i,*(a + i));
    }

}

int main() {
    int option = 0;
    int i,*a,*n;
    n = (int *)malloc(sizeof(int));



    while(option != 4) {
    printf("MENU \n 1)INPUTARRAY \n 2)ASCENDING \n 3)DESCENDING \n 4)EXIT \n ");
    printf("Enter the option ");
    scanf("%d",&option);
    switch(option) {
        case 1:
            printf("Enter the size of the array ");
            scanf("%d",n);
            a = (int *)malloc(sizeof(int));
            for( i = 0;i< *n;i++) {
                printf("Enter a[%d]",i);
                scanf("%d",a + i);
    
            }
            break;
        
        case 2:
            ascending(a,n);
            break;

        case 3:
            descending(a,n);
            break;

        case 4:
            printf("PROGRAM ENDED");
            break;

        default:
            break;


    }

    }







}