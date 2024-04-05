//Program to implement queue using linked list
#include<stdio.h>
#include<stdlib.h>

class queue
{
    struct node
    {
        int data;
        struct node *next;
    };
    struct node *head;
    struct node *tail;
    int top;

    public:
        queue()
        {
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


//Method to push into queue
int queue::enqueue(int num)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    if(head!=NULL)
    {
        tail->next=newnode;
    }
    else
    {
        head=newnode;
    }
    tail=newnode;  

    top++;
    return 1;
}

//Method to dequeue
int queue::dequeue()
{
    if(head==NULL)
    {
        return 0;
    }
    
    struct node *add;
    add=head;
    head=add->next;
    free(add);
    top--;
    return 1;
}

//Method to pop queue
int queue::pop()
{
    struct node *add;
    add=head;
    head=add->next;
    int data=add->data;
    free(add);
    top--;
    return data;
}

//Method to check if queue is empty
int queue::check()
{
    if(head==NULL)
    {
        return 0;
    }
    return 1;
}

//Method to peek into queue
void queue::peek()
{
    if(head==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("The value at the top of the queue is %d", head->data);
    }
}