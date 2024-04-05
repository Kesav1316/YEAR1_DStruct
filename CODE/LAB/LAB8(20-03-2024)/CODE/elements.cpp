#include <stdio.h>

int main(){

    int array[] = {4,1,1,2,6,8,3,9,7,5};
    int len = sizeof(array) / sizeof(int);

    int number;
    int lower = 0;
    int upper = 0;
    int flagl=0,flagu=0;

    printf("Enter Number: ");
    scanf("%d", &number);

    for(int i = 0; i < len; i++){

        if(array[i] < number && (lower == 0 || array[i] > lower))
        {
            lower = array[i];
            flagl=1;
        }
        else if(array[i] > number && (upper == 0 || array[i] < upper))
        {
            upper = array[i];
            flagu=1;
        }
    }
     
    if(flagl==0)
    {
    printf("None %d %d", number, upper);
    }

    else if (flagu==0)
    {
       printf(" %d %d None",lower, number); 
    }

    else
    {
        printf(" %d %d %d",lower, number,upper); 
    }
    return 0;
}