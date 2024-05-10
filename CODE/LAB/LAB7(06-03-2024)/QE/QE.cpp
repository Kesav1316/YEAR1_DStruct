/*
An operating system allocates a fixed time slot CPU time for processes using a round-robin scheduling algorithm. The fixed time slot will be initialized before the start of the menu-driven program. Implement the round-robin scheduling algorithm using the circular List ADT. Implement the program by including the appropriate header file. It consists of the following operations.

1. Insert Process
2. Execute
3. Exit

The "Insert Process" will get an integer time from the user and add it to the List.

The "Execute" operation will execute a deList operation and subtract the fixed time from the process. If the processing time falls below 0 then the process is considered to have completed its execution, otherwise, the remaining time after subtraction is enListd back into the circular ADT.

What is the time complexity of each of the operations?
*/
#include<stdio.h>
#include<stdlib.h>
#include"QE.h"


int main()
{   
    List q;    
    int choice,num,ts,temp;
    printf("Enter size of time slot of CPU:");
    scanf("%d",&ts);
    while(1) {  
        printf("Enter your choice: \n 1.Insert Process \n2. Execute \n3. Exit");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Enter time taken by process:");
                scanf("%d",&num);
                q.enqueue(num);
                break;

            case 2:
                if(q.check()==0) {
                    printf("No processes to carry out");
                }   

                temp=q.pop();
                if(temp>ts) {
                    q.enqueue(temp-ts);
                }
                break;
            case 3:    
                return 0;
        }
    }
    return 0;
}                 