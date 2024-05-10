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

class List {
    struct node {
        int data;
        struct node *next;
    };
    struct node *head;
    struct node *tail;
    int top;
    public:
        List() {
            head=NULL;
            tail=NULL;
            top=-1;
        }
        int enqueue(int);
        int dequeue();
        int pop();
        int check();
        void peek();
};


//Function to push to the list.
//Time complexity => O(1)
int List::enqueue(int num) {
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;

    if(head!=NULL) {
        tail->next=newnode;
    }

    else {
        head=newnode;
    }

    tail=newnode;  
    top++;
    return 1;
}

//Function to pop of the list.
//Time complexity => O(1)
int List::dequeue() {
    if(head==NULL) {
        return 0;
    }
    
    struct node *add;
    add=head;
    head=add->next;
    free(add);
    top--;
    return 1;
}

//Function to pop queue
//Time complexity => O(1)
int List::pop() {
    struct node *add;
    add=head;
    head=add->next;
    int data=add->data;
    free(add);
    top--;
    return data;
}

//Function to check if the queue is empty
int List::check() {
    if(head==NULL) {
        return 0;
    }
    return 1;
}

//Function to print the peek of the queue.
//Time complexity => O(1)
void List::peek() {
    if(head==NULL) {
        printf("Stack is empty");
    }
    else {
        printf("The value at the top of the List is %d", head->data);
    }
}