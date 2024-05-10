//program to implement cpu timeslot
#include<stdio.h>
#include<stdlib.h>
#define timeslot 25
class queue
{
  
  struct node 
  {
    
    int data;
    struct node *next;
   
  };
    struct node *front;
    struct node *rear;
  
  public:
  queue()
  {
   front=NULL;
   rear=NULL;
   
  }
  int enqueue(int num);
  int dequeue();
  
};

//Method to insert an element in the queue
int queue::enqueue(int num)
{
  struct node *newnode=(struct node *)malloc(sizeof(struct node));
  if(front==NULL)
  {
    newnode->data=num;
    newnode->next=newnode;
    front=newnode;
    rear=newnode;
    return 1;
  }
  else
  {
    newnode->data=num;
    newnode->next=front;
    rear->next=newnode;
    rear=newnode;
    return 1;
  }
}

// Method to delete an element from the queue
int queue:: dequeue()
{
  
  if(front==NULL)
  {
    return 0;
  }
  else
  {
    if(front->data-timeslot<=0)
    {
      if(front==rear)
      {
        front=NULL;
        rear=NULL;
        return 1;
      }
      else
      {
        struct node *temp=front;
        front=front->next;
        rear->next=front;
        free(temp);
        temp=NULL;
        return 1;
      }
      
    }
    else
    {
      int time;
      time=front->data-timeslot;
      if(front==rear)
      {
        front=NULL;
        rear=NULL;
      }
      else
      {
        struct node *temp=front;
        front=front->next;
        rear->next=front;
        free(temp);
        temp=NULL;
      }
      enqueue(time);
      return 1;
    }
  }
}
