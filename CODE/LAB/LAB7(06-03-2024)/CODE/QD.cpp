#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
class queueSLL
{
    private:
    struct node
    {
        int data;
        struct node *next;
    };
    struct node *front;
    struct node *rear;
    public:
    queueSLL()
    {
        front=NULL;
        rear=NULL;
    }
    int enqueue(int);
    int dequeue(void);
    int peek(void);
    void display(void);
    int empty();
};
int main()
{
    int choice;
    int val;
    queueSLL queue;
    while(true)
    {
        printf("\nMENU");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter the choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("\nEnter the value:");
                scanf("%d",&val);
                int s=queue.enqueue(val);
                if(s==0)
                {
                    printf("\nThe queue is full");
                }
                else if(s==1)
                {
                    printf("\nINSERTED SUCCSESSFULLY");
                }
                break;
            }
            case 2:
            {
                int p=queue.dequeue();
                if(p==0)
                {
                    printf("\nThe queue is empty");
                }
                else
                {
                    printf("\nThe dequeued element:%d",p);
                }
                break;
            }
            case 3:
            {
                int s=queue.peek();
                if(s==0)
                {
                    printf("\nThe queue is empty");
                }
                else{
                    printf("\nThe peeked elemt is:%d",s);
                }
                break;
            }
            case 4:
            {
                printf("\nThe elements are:");
                printf("\n");
                queue.display();
                break;
            }
            case 5:
            {
                printf("\nEXITTING");
                return 0;
            }
        }
    }
}
//METHOD TO CHECK THE QUEUE IS EMPTY
int queueSLL::empty()
{
    if(front==NULL && rear==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//METHOD TO ADD AN ELEMENT INTO THE QUEUE
//TIME COMPLEXITY : O(1)
int queueSLL::enqueue(int val)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    if(empty()==1)
    {
        front=rear=newnode;
        rear->next=front;
        return 1;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
        return 1;
    }
}
//METHOD TO REMOVE AN ELEMENT FROM THE QUEUE
//TIME COMPLEXITY : O(1)
int queueSLL::dequeue()
{
    struct node *temp=front;
    if(empty()==1)
    {
        return 0;
    }
    else if(front==rear)
    {
        int b=temp->data;
        front=rear=NULL;
        free(temp);
        return b;
    }
    else
    {
        int b=temp->data;
        front=temp->next;
        free(temp);
        rear->next=front;
        return b;
    }
}
//METHOD TO SEE THE FRONT ELEMENT
//TIME COMPEXITY : O(1) 
int queueSLL::peek()
{
    if(empty()==1)
    {
        return 0;
    }
    else
    {
        int b=front->data;
        return b;
    }
}
//METHOD TO DISPLAY
//TIME COMPLEXITY : O(n)
void queueSLL::display()
{
    struct node *temp=front;
    if(empty()==1)
    {
        printf("[]");
    }
    else
    {
        printf("[");
        while(temp!=rear)
        {
            printf("%d,",temp->data);
            temp=temp->next;
        }
        printf("%d]",temp->data);
    }
}