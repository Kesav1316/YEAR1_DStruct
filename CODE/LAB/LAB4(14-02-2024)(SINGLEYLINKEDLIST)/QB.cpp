/*
B. Write a C++ menu-driven program to implement List ADT using a singly linked list. You have a gethead() private member function that returns the address of the head value of a list. Maintain proper boundary conditions and follow good coding practices. The List ADT has the following operations,

1. Insert Ascending
2. Merge
3. Display
4. Exit

Option 1 inserts a node so the list is always in ascending order. Option 2 takes two lists as input, and merges two lists into a third list. The third list should also be in ascending order. Convert the file into a header file and include it in a C++ file. The second C++ consists of 3 lists and has the following operations,

1. Insert List1
2. Insert List2
3. Merge into List3
4. Display
5. Exit
*/
#include<stdio.h>
#include<stdlib.h>
#include"insertion.h"

int main() {
    Link l1,l2,l3;
    int n1,n2,option;

    while(1) {
        printf("\n Enter the option\n1.INSERT NUMBER IN LIST 1\n2.INSERT NUMBER IN LIST 2\n3.MERGE LISTS\n4.DISPLAY\n5.EXIT \n");
        scanf("%d",&option);
        switch(option) {

            case 1:
                printf("\n Enter the number to enter");
                scanf("%d",&n1);
        
                l1.insertascending(n1);
                printf("\n Inserted.");
                break;

            case 2:
                printf("\n Enter the number to enter");
                scanf("%d",&n2);

                l2.insertascending(n2);
                printf("\n Inserted");
                break;

            case 3:
                l3.merge(l1,l2);    
                printf("\n Merged both list.");
                break;

            case 4:
                printf("\n LIST 1: ");
                l1.display();

                printf("\n LIST 2: ");
                l2.display();

                printf("\nLIST 3: ");
                l3.display();
                break;  

            case 5:
                exit(0);
                break;

            default:
                printf("\n Enter a valid option.");
                break;

    }
    }

}