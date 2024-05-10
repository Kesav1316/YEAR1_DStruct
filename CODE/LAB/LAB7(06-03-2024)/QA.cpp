/*
A. Write a separate C++ menu-driven program to implement Queue ADT using an integer array of size 5. Maintain proper boundary conditions and follow good coding practices. The Queue ADT has the following operations,

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
        int enqueue(int);
        int dequeue();
        void peek();
        void display();
};

int main() {
    queue l1;
    int choice;
    int element;
    int pos;
    while(1) {

        printf("\n Queue \n");
        printf("\n 1.Enqueue \n 2.Dequeue \n 3.Peek \n 4.Exit \n");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("Enter the numbers ");
                scanf(" %d",&element);
                if(l1.enqueue(element)) {
                    printf("\n Inserted successfully.\n");
                }
                else {
                    printf("\n Insertion unsuccessful.\n");
                }
                break;
            
            case 2:
                if(l1.dequeue()) {
                    printf("\n Dequeue Succesful.\n");
                }
                else {
                    printf("\n Queue empty.\n");
                }
                break;

            case 3:
                l1.peek();
                break;

            case 4:
                printf("PROGRAM ENDED\n");
                return 0;

        }
    }

}

//Function to check if the queue is full.
//Time complexity => O(1)
int queue::isfull() {
    if(rear == SIZE -1) {
        return 1;
    }
    else {
        return 0;
    }
}

//Function to check if the queue is empty.
//Time complexity => O(1)
int queue::isempty() {
    if(front == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

//Function to add the element to the queue.
//Time complexity => O(1)
int queue::enqueue(int element) {
    if(isfull()) {
        return 0;
    }
    else {
        if(isempty()) {
            front = 0;
            rear = 0;
            arr[0] = element;
        }
        else {
            rear = rear + 1;
            arr[rear] = element;
        }
        return 1;

    }
}

//Function to pop the element from the queue.
//Time complexity => O(1)
int queue::dequeue() {
    if(isempty()) {
        return 0;
    }

    else {
        if(front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = front + 1;
        }
        return 1;
        
    }
}

//Function to display the peek value in the queue.
//Time complexity => O(1)
void queue::peek() {
    if(isempty()) {
        printf("Stack empty.");
    }
    else {
        printf("The peek is %d\n",arr[front]);
    }

}

//Function to display the elements in the queue.
//Time complexity => O(n)
void queue::display() {
    if(isempty()) {
        printf("Stack empty.");
    }
    else {
        int temp2 = front;
        while(temp2 != rear + 1) {
            printf("The number %d\n",arr[temp2]);
            temp2 = temp2 + 1;
        }
    }
}