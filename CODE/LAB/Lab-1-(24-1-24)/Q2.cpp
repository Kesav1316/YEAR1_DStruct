#include "Q2.h"

int main() {
    int n1= 1,n2 =1 ,choosen_opt =1;

    while(choosen_opt != 6) {
        printf("\nCALCULATOR \n 1)SET \n 2)ADD \n 3)SUBTRACT \n 4)MULTIPLY \n 5)DIVIDE \n 6)EXIT \n");
        printf("Choose a number: ");
        scanf("%d",&choosen_opt);
        
        switch(choosen_opt) {
            case 1:
                printf("Enter the value of 1st number: ");
                scanf("%d",&n1);

                printf("Enter the value of 2nd number: ");
                scanf("%d",&n2);

            case 2:
                printf("Sum of %d and %d is: %d",n1,n2,add_no(&n1,&n2));
                break;

            case 3:
                printf("Difference Of %d and %d is %d",n1,n2,sub_no(&n1,&n2));
                break;

            case 4:
                printf("Multiplication Of %d and %d is %d",n1,n2,mul_no(&n1,&n2));
                break;

            case 5:
                printf("Division Of %d and %d is %d",n1,n2,div_no(&n1,&n2));
                break;

            case 6:
                printf("APPLICATION CLOSED\n"); 
                break;
        
            default:
                printf("Not available");
                break;
            }
    }
}