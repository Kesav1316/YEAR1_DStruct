#include <stdio.h>
//void ascending(int a[],int n);
//void descending(int a[],int n);

void ascending(int a[],int n) {
    for(int i = 0 ; i < n-1 ; i++) {
        for(int j = 0 ; j < n-1 ; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("SORTED ARRAY \n");
    for(int i = 0;i<n;i++) {
        printf("a[%d] %d \n",i,a[i]);
    }

}

void descending(int a[],int n) {
    for(int i = 0 ; i < n-1 ; i++) {
        for(int j = 0 ; j < n-1 ; j++) {
            if (a[j] < a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for(int i = 0;i<n;i++) {
        printf("SORTED ARRAY \n");
        printf("a[%d] %d \n",i,a[i]);
    }

}

int main() {
    int a[100] = {1};
    int n;
    int i = 0;
    int option = 0;

    while(option != 4) {
    printf("MENU \n 1)INPUTARRAY \n 2)ASCENDING \n 3)DESCENDING \n 4)EXIT \n ");
    printf("Enter the option ");
    scanf("%d",&option);
    switch(option) {
        case 1:
            printf("Enter the size of the array ");
            scanf("%d",&n);
            for(int i = 0;i<n;i++) {
                printf("Enter a[%d]",i);
                scanf("%d",&a[i]);
    
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