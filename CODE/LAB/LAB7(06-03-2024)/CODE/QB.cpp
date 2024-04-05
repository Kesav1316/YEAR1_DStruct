#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define size 5
class queuearray
{
    private:
       int i;
       int array[size];
       int front=-1;
       int rear=-1;
    public:
        int empty(void);
        int full(void);
        int enqueue(int);
        int dequeue(void);
        int peek(void);
        void display(void);
};


int main()
{
    int choice;
    int val;
    queuearray queue;
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
int queuearray::empty()
{
    if(front==-1 && rear==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//METHOD TO CHECK THE QUEUE IS FULL
int queuearray::full()
{
    if((rear+1)%size==front)
    {
        return 1;
    }
    return 0;
}
//METHOD TO ADD AN ELEMENT INTO THE QUEUE
//INSERT AT THE END
//TIME COMPLEXITY : O(1)
int queuearray::enqueue(int val)
{
    if(empty()==1)
    {
        array[rear+1]=val;
        front++;
        rear++;
        return 1;
    }
    else if(full()==0)
    {
        array[(rear+1)%size]=val;
        rear=(rear+1)%size;
        return 1;
    }
    else
    {
        return 0;
    }
}
//METHOD TO REMOVE AN ELEMENT FROM THE QUEUE
//DELETE AT THE FRONT
//TIME COMPLEXITY : O(1)
int queuearray::dequeue()
{
    if (empty()==1)
    {
        return 0;
    }
    else if(rear==front)
    {
        int b=array[front];
        rear=-1;
        front=-1;
        return b;
    }
    else
    {
        int b=array[front];
        front=(front+1)%size;
        return b;
    }
}
//METHOD TO SEE THE FRONT ELEMENT
//TIME COMPEXITY : O(1) 
int queuearray::peek()
{
    if(empty()==1)
    {
        return 0;
    }
    else
    {
        return array[front];
    }
}
//METHOD TO DISPLAY
//TIME COMPLEXITY : O(n)
void queuearray::display()
{
    int i=front;
    printf("\n[");
    if(empty()==0)
    {
        while(i!=rear)
        {
            printf("%d,",array[i]);
            i=(i+1)%size;
        }
        printf("%d]",array[i]);
    }
    else
    {
        printf("[]");
    }
}