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
        int rearlast();
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

        printf("\n STACK ADT \n");
        printf("\n 1.Push \n 2.Pop \n 3.peek \n 4.Exit \n 5.Display.");
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
                    printf("\n Succesful.\n");
                }
                else {
                    printf("\n Stack empty.\n");
                }
                break;

            case 3:
                l1.peek();
                break;

            case 4:
                return 0;

            case 5:
                l1.display();

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

//Function to check if rear is at last.
int queue::rearlast() {
    if(rear == SIZE-1) {
        return 1;
    }
    else {
        return 0;
    }
}

//Function to add the element to the array.
int queue::enqueue(int element) {



    {
    if(isempty()) { 
        front = 0;
        rear = rear + 1;
        arr[rear] = element;
    }

        else if(rearlast()) {
            rear = (rear+1)%SIZE;
            arr[rear] = element;
        }
         else if(rear < front) {
            front = front + 1;
            rear = rear + 1;
            arr[rear] = element;
        } 
        else {
            front = 0;
            rear = rear + 1;
            arr[rear] = element;
        }
        return 1;
    }

}

int queue::dequeue() {
    if(isempty()) {
        return 0;
    }

    else {
        if(front == rear) {
            front = -1;
            rear = -1;
        }
        else if(rear < front) {
            //rear = (rear+1)%SIZE;
            if(front == SIZE - 1) {
                front = 0;
            }
            else {
                front = front + 1;
            }
            
        }
        else {
            front = front + 1;
        }
        return 1;
        
    }
}

void queue::peek() {
    printf("spfmig");
}

//Function to display the elements in the list.
void queue::display() {
    printf("front is %d \n ",front);
    printf("rear is %d \n ",rear);
    if(isempty()) {
        printf("Stack empty.");
    }
    if(rear<=front) {
        for(int i = front;i<SIZE;i++) {
            printf("The number %d\n",arr[i]);
        }
        for(int i = 0;i <= rear;i++) {
            printf("%d \n",arr[i]);
        }

    }
    else {
        int temp2 = front;
        while(temp2 != rear + 1) {
            printf("The no %d\n",arr[temp2]);
            temp2 = temp2 + 1;
        }
    }
}
/*
Works when it do not exceed size
To fix: On adding 6th element it only prints the last added element
*/



