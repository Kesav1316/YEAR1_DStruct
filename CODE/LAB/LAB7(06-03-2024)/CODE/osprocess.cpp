//Program to implement queue using linked list
#include<stdio.h>
#include<stdlib.h>
#include"osqfunc.h"



int main()
{   
    queue q;    
    int choice,num,ts,temp;
    printf("Enter size of time slot of CPU:");
    scanf("%d",&ts);
    while(1)    
    {   getchar();
        getchar();
        system("clear"); 
        printf("Enter your choice: \n 1. Insert Process \n2. Execute \n3. Exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case(1):
                printf("Enter time taken by process:");
                scanf("%d",&num);
                q.enqueue(num);
                break;

            case(2):
                if(q.check()==0)
                {
                    printf("No processes to carry out");
                }   
                temp=q.pop();
                if(temp>ts)
                {
                    q.enqueue(temp-ts);
                }
                break;
            case(3):    
                exit(0);
            case(4):
                q.peek();
        }
    }
    return 0;
}                 