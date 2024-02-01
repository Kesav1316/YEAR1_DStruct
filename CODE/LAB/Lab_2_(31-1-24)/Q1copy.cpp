#include <stdio.h>
#include <stdlib.h>

int main() {
    int *a,*size,*element,*i;
    size = (int *)malloc(sizeof(int));
    element = (int *)malloc(sizeof(int));
    i = (int *)malloc(sizeof(int));
    printf("Enter number of elements ");
    scanf("%d",size);
    a = (int *)malloc(sizeof(int) * (*size));

    for ( *i = 0 ; *i < *size ; (*i)++) {
        printf("Enter %d element",*i + 1);
        scanf("%d",(a + (*i)));
    }
    printf("Enter a element to search ");
    scanf("%d",element);
    for(*i = 0 ; *i < *size ; (*i )++ ) {
        if(*(a + (*i)) == *element) {
            printf("ELEMENT FOUND in %d\n",(*i) + 1);
            return 0;
        }
        
    }
    printf("Element not found\n");



}
