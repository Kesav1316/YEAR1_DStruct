//2. Write a C++ menu-driven program to sort an array of numbers in ascending or descending order. After you write the function for sorting, search online and find what type of sorting you have done in your code.
#include <stdio.h>
#include <stdlib.h>

void ascending(int *arr,int *n){
    int *i,*first,*second,*tmp;
    first = (int *)malloc(sizeof(int));
    second = (int *)malloc(sizeof(int));
    tmp = (int *)malloc(sizeof(int));
    for(*first = 0;*first <*n -1;(*first)++){
        for(*second = *first + 1;*second < *n;(*second)++){
            if(*(arr + (*first)) > *(arr + (*second))){
                *tmp = *(arr + (*first)) ;
                *(arr + (*first)) = *(arr + (*second));
                *(arr + (*second)) = *tmp;
            }
        }
    }
    for(*i = 0; *i < *n;(*i)++){
        printf("%d ",*(arr + (*i)));
    }
    printf("\n");
}
void descending(int *arr,int *n){
    int *i,*first,*second,*tmp;
    first = (int *)malloc(sizeof(int));
    second = (int *)malloc(sizeof(int));
    tmp = (int *)malloc(sizeof(int));
    for(*first = 0;*first <*n -1;(*first)++){
        for(*second = *first + 1;*second < *n;(*second)++){
            if(*(arr + (*first)) < *(arr + (*second))){
                *tmp = *(arr + (*first)) ;
                *(arr + (*first)) = *(arr + (*second));
                *(arr + (*second)) = *tmp;
            }
        }
    }
    for(*i = 0; *i < *n;(*i)++){
        printf("%d ",*(arr + (*i)));
    }
}


int main() {
    int option = 0;
    int *a,*n,*i;
    n = (int *)malloc(sizeof(int));
    i = (int *)malloc(sizeof(int));



    while(option != 4) {
    printf("MENU \n 1)INPUTARRAY \n 2)ASCENDING \n 3)DESCENDING \n 4)EXIT \n ");
    printf("Enter the option ");
    scanf("%d",&option);
    switch(option) {
        case 1:
            printf("Enter the size of the array ");
            scanf("%d",n);
            a = (int *)malloc(sizeof(int) * (*n));
            for( *i = 0;*i< *n;(*i)++) {
                printf("Enter a[%d]",*i);
                scanf("%d",a + (*i));
    
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