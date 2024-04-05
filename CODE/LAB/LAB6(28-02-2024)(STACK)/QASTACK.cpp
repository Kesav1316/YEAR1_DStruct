/*
A. Write a separate C++ menu-driven program to implement stack ADT using a character array of size 5 and a singly linked list. Maintain proper boundary conditions and follow good coding practices. The Stack ADT has the following operations,

1. Push
2. Pop
3. Peek
4. Exit

What is the time complexity of each of the operations? (K4)
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
class stack
{
    char arr[SIZE];
    int top;
    public:
        stack() {
            top = -1;
        }
        int push(char);
        int pop();
        char peak();
        void display();
};

int main() {
    stack l1;
    int choice;
    char element;
    int pos;
    while(1) {

        printf("\n STACK ADT \n");
        printf("\n 1. Push \n 2. Pop \n 3. Peak \n 4. Exit \n");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("Enter the character ");
                scanf(" %c",&element);
                if(l1.push(element)) {
                    printf("\n Inserted successfully.\n");
                }
                else {
                    printf("\n Insertion unsuccessful.\n");
                }
                break;
            
            case 2:
                if(l1.pop()) {
                    printf("\n Succesful.\n");
                }
                else {
                    printf("\n Stack empty.\n");
                }
                break;

            case 3:
                if(!l1.peak()) {
                    printf("\n Stack is empty.\n");
                }

                else {
                    printf("\n %c\n",l1.peak());
                }
                break;

            case 4:
                return 0;

        }
    }

}

//Method to push into stack adt.
//Time complexity => O(1)
int stack::push(char element) {
    if(top == SIZE-1) {
        return 0;
    }
    else if (top == -1) {
        top = 0;
        arr[0] = element;
        return 1;
    }
    else {
        top = top + 1;
        arr[top] = element;
        return 1;
        
    }
}   

//Method to pop the element in stack adt.
//Time complexity => O(1)
int stack::pop() {
    if(top == -1) {
        return 0; 
    }
    else {
        top = top - 1;
        return 1;
    }
}

//Displaying the top of the node.
//Time complexity => O(1)
char stack::peak() {
    if(top == -1) {
        return 0;
    }

    else {
        return arr[top];
    }
}

//Displaying the values of the stack adt.
//Time complexity => O(n)
void stack::display() {
    printf("\nThe contents of the stack are:");
    for(int i=top;i>=0;i--) {   
        printf("%c ",arr[i]);
    }
}
