/*
B. Write a separate C++ menu-driven program to implement Circular Queue ADT using an integer array of size 5. Maintain proper boundary conditions and follow good coding practices. The Circular Queue ADT has the following operations,

1. Enqueue
2. Dequeue
3. Peek
4. Exit

What is the time complexity of each of the operations?
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
class queue {
    int arr[SIZE];
    int front;
    int rear;
    public:
        queue() {
            front = -1;
            rear = -1;
        }
        int isfull();
        int isempty();
        void enqueue(int);
        void dequeue();
        void peek();
        void display();
};

int main() {
    queue l1;
    int choice;
    int num;
    int pos;
    while(1) {

        printf("\n CIRCULAR QUEUE \n");
        printf("\n 1.Push \n 2.Pop \n 3.peek \n 4.Exit \n");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("Enter the numbers ");
                scanf(" %d",&num);
                l1.enqueue(num);
                break;
            
            case 2:
                l1.dequeue();
                break;

            case 3:
                l1.peek();
                break;

            case 4:
                printf("PROGRAM ENDED\n");
                return 0;

            case 5:
                l1.display();

        }
    }

}

//Function to check if the queue is full.
//Time complexity => O(1)
int queue::isfull() {
    if((rear+1)%SIZE == front) {
        return 1;
    }
    else {
        return 0;
    }
}

//Function to check if the queue is empty.
//Time complexity => O(1)
int queue::isempty() {
    if(front == -1 && rear == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

//Function to add the element to the queue.
//Time complexity => O(1)
void queue::enqueue(int num) {

    if(isempty()) {
        arr[rear+1]=num;
        front++;
        rear++;
        printf("Inserted Successfully");
    }

    else if(isfull()==0) {
        arr[(rear+1)%SIZE]=num;
        rear=(rear+1)%SIZE;
        printf("Inserted Successfully");
    }

    else {
        printf("Not Inserted");
    }
}

//Function to delete the element from the queue.
//Time complexity => O(1)
void queue::dequeue() {
    if (isempty()) {
        printf("Queue Empty.");
    }

    else if(rear==front) {
        int b=arr[front];
        rear=-1;
        front=-1;
        printf("DEQUEUED");
    }

    else {
        int b=arr[front];
        front=(front+1)%SIZE;
        printf("DEQUEUED");
    }

}

//Function to print the peek of the queue.
//Time complexity => O(1)
void queue::peek() {
    if(isempty()) {
        printf("Queue Empty.");
    }

    else {
        printf("The peek is %d",arr[front]);
    }
}

//Function to display the elements in the queue.
//Time complexity => O(n)
void queue::display() {
    int i=front;
    if(isempty()==0)
    {
        while(i!=rear)
        {
            printf("%d,",arr[i]);
            i=(i+1)%SIZE;
        }
        printf("%d",arr[i]);
    }
    else
    {
        printf("Queue Empty.");
    }
}



