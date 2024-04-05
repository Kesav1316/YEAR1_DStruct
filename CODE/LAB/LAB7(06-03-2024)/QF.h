/*
Take a string from the user that consists of the '+' symbol. Process the string such that the final string does not include the '+' symbol and the immediate left non-'+' symbol. Select and choose the optimal ADT. Implement the program by including the appropriate header file.
*/
//Stack adt using linked list.
#include<stdio.h>
#include<stdlib.h>

class List {  
    struct node {   
        char data;
        struct node *next;
    };

    int top;
    struct node *head;

    public:
        List() {
            head=NULL;
            top=-1;
        }
        int push(char);
        int pop();
        char popreturn();
        void peek();
        int isempty();
};

//Function to push the num to list.
//Time complexity => O(1)
int List::push(char num) {
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=head;
    head=newnode;
    top++;
    return 1;
}

//Function to pop the element of the list.
//Time complexity => O(1)
int List::pop() {
    if(top==-1) {
        return 0;
    }
    
    struct node *add;
    add=head;
    head=head->next;
    free(add);
    top--;
    return 1;
}

//Function to pop and return character.
//Time complexity => O(1)
char List::popreturn() {
    struct node *add;
    add=head;
    head=head->next;
    char data=add->data;
    free(add);
    top--;
    return data;    
}

//Function to display the peek of the list.
//Time complexity => O(1)
void List::peek() {
    if(top==-1) {
        printf("Stack is empty");
    }

    else {
        printf("%c ", head->data);
    }
}

//Function to check if the list is empty.
//Time complexity => O(1)
int List::isempty() {
    if(top==-1) {
        return 1;
    }
    else {
    return 0;

    }
}    