/* Imagine a class with a 'n' number of students. Their integer roll numbers are stored in an array in ascending order. There are gaps in the roll number series.  Now, get a roll number from the user and search whether it is present in the array. If present, return the array index + 1. Follow the below approach for searching,
1) Compare the roll number with the middle element.
  1.1) If present -> return index + 1
  1.2) Otherwise check if the roll number to be searched is bigger than the number in the current index.
      1.2.1) If so, set the current location as the starting point and repeat 1 (array search size reduces by 1/2)
      1.2.2) otherwise, set the current location as the ending point and repeat 1 (array search size reduces by 1/2)
       1.2.3) If there are no more elements to be searched, then return that the roll number is not present in the array.
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int *arr,*n,*search,*i;
    n = (int *)malloc(sizeof(int));
    search = (int *)malloc(sizeof(int));
    i = (int *)malloc(sizeof(int));
    printf("Enter the size of the array ");
    scanf("%d",n);
    arr = (int *)malloc(sizeof(int) * (*n));
    for(*i  = 0 ; *i<*n ; (*i)++){
        printf("Enter the number in arr[%d] ",(*i) + 1);
        scanf("%d",(arr + (*i)));
    }
    printf("Enter the number to search ");
    scanf("%d",search);
    for(*i = 0 ; *i < *n ; (*i)++){
        if(*(arr + (*i)) == *search){
            printf("Element is at %d position\n",*i + 1);
            return 0;
        }
    }
    printf("Element not found \n");
    return 0;

}