#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[] = {1,2,3,4,5,6,7,8,9,10};;
    int size = sizeof(a)/sizeof(int);
    int element;
    int count = 1;
    printf("Enter a element to search ");
    scanf("%d",&element);
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
