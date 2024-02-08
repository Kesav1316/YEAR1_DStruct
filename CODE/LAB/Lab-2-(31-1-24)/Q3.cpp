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

void ascending(int *a,int *n) {
    int i,j,*tmp;
    tmp = (int *)malloc(sizeof(int));
    for( i = 0 ; i < *n-1 ; (i)++) {
        for( j = 0 ; j < *n-1 ; (j)++) {
            if ( *(a + (j)) > *(a + (j + 1))) {
                *tmp = *(a + (j));
                *(a + (j)) = *(a + (j + 1));
                *(a + (j + 1)) = *tmp;
            }
        }
    }
}

int *search(int *array,int *n,int *find){
    int begg,end,*mid;
    begg = 0;
    end = *n;
    while(begg <= end){
        *mid = (int)((begg + end) /2);
        if(*(array + *mid) == *find){
            printf("ROLL NUMBER FOUND IN %d\n",*mid + 1);
            return mid;
        }
        else {
            if(*(array + *mid) < *find){
                begg = *mid  + 1;
            }else{
                end = *mid - 1;
            }
        }
    }
    printf("ROLL NUMBER NOT FOUND\n");
    return mid;
}


int main(){
    int i,*n,*a,*rollno;
    n = (int *)malloc(sizeof(int));

    printf("Enter the number of students : ");
    scanf("%d",n);

    rollno = (int *)malloc(sizeof(int));
    a = (int *)malloc(sizeof(int) * (*n));

    for( i = 0; i<*n ; i++ ) {
        printf("ENTER ROLL NUMBER %d ",i + 1);
        scanf("%d",(a + i)); 
    }
    ascending(a,n);


    printf("\nENTER ROLL NUMBER TO SEARCH: ");
    scanf("%d",rollno);
    search(a,n,rollno);
    return 0;

}