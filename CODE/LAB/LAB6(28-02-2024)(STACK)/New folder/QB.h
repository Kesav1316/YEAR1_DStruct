/*
C. Write a C++ menu-driven program to get a string of '(' and ')' parenthesis from the user and check whether they are balanced. Identify the optimal ADT and data structure to solve the mentioned problem. You can consider all previous header files for the solution's implementation. Maintain proper boundary conditions and follow good coding practices. The program has the following operations,

1. Check Balance
2. Exit

The Check Balance operations get a string of open and closed parentheses. Additionally, it displays whether the parenthesis is balanced or not. Explore at least two designs (solutions) before implementing your solution.
What is the time complexity of each solution, and what is the optimal solution? Justify your answer.
*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>

class list{
    private:
        struct node{
            char data;
            struct node* prev;
        };
        struct node* top;
    public:
        list(){
            top=NULL; 
        }
        int push(char);
        char pop(void);
        char peek(void);
        void display(void);
};

//Push elements to the stack.
//Time complexity => O(1).
int list::push(char chr){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        return 0;
    }
    else{
        newnode->data=chr;
        newnode->prev=top;
        top=newnode;
        return 1;
    }
}

//Pop elements from the stack.
//Time complexity => O(1).
char list::pop(void){
    if(top==NULL){
        return '\0';
    }
    else{
        char res = top->data;
        struct node* copy = top;
        top=top->prev;
        free(copy);
        return res;
    }
}

//Display elements in the stack.
//Time complexity => O(n).
void list::display(void){
    if (top==NULL){
        printf("List is empty!");
    }
    else{
        struct node* temp = top;
        while (temp!=NULL){
            printf("%c ",temp->data);
            temp=temp->prev;
        }
    }
}

//Peak of the stack.
//Time complexity => O(1)
char list::peek(void){
    if(top==NULL){
        return '\0';
    }
    else{
        return top->data;
    }
}