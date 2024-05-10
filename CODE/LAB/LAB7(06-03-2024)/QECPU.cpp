#include<stdio.h>
#include<stdlib.h>
#include"QE.h"
int main()
{
    queue q1;
    int choice;
    char i;
    while(1)
    
    {
        printf("\n1) Insert");
        printf("\n2) Execute");
        printf("\n3) Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        getchar();
        switch (choice)
        {
            case 1:
                int num1;
                printf("Enter the number to insert:");
                scanf("%d",&num1);
                if(q1.enqueue(num1))
                {
                printf("Element is inserted successfully");
                }
                else
                {
                printf("Operation failed!");
                }
                break;

            case 2:
                if(q1.dequeue())
                {
                printf("Element is removed successfully");
                }
                else
                {
                printf("The queue is empty!");
                }
                break;
          
            case 3:
                printf("PROGRAM ENDED");
                return 0;
        }
    }
}
