
//Program to implement stack using linked list
#include<stdio.h>
#include<stdlib.h>

class LinkList
{  
    private: 

    struct node
    {   
        char data;
        struct node *next;
    };
    int top;
    struct node *head;

    public:
        LinkList()
        {
            head=NULL;
            top=-1;
        }
        int push(char);
        int pop();
        char popreturn();
        void peek();
        int check();
};

//Method to push into stack
int LinkList::push(char num)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=head;
    head=newnode;
    top++;
    return 1;
}

//Method to pop stack
int LinkList::pop()
{
    if(top==-1)
    {
        return 0;
    }
    
    struct node *add;
    add=head;
    head=head->next;
    free(add);
    top--;
    return 1;
}

//Method to pop and return character
char LinkList::popreturn()
{
    struct node *add;
    add=head;
    head=head->next;
    char data=add->data;
    free(add);
    top--;
    return data;    
}

//Method to peek into stack
void LinkList::peek()
{
    if(top==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("%c ", head->data);
    }
}

//Method to check is stack is empty
int LinkList::check()
{
    if(top==-1)
    {
        return 0;
    }
    return 1;
}    