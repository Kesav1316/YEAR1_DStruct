#include <stdio.h>
#include <stdlib.h>

int main() {
    int *a,*n,*element,*i;
    n = (int *)malloc(sizeof(int));
    element = (int *)malloc(sizeof(int));
    i = (int *)malloc(sizeof(int));
    printf("Enter a element to search ");
    scanf("%d",element);
    for( int i = 0 ; i < size ; i ++ ) {
        if(a[i] == element) {
            printf("ELEMENT FOUND");
            count = 0;
        }
        
    }
    if(count == 1) {
        printf("ELEMENT NOTFOUND");
    }



}
