/*
D. Write a separate C++ menu-driven program to implement Circular Queue ADT using an integer-linked list. Maintain proper boundary conditions and follow good coding practices. The Circular Queue ADT has the following operations,

1. Enqueue
2. Dequeue
3. Peek
4. Exit

What is the time complexity of each of the operations?
*/

#include <stdio.h>
#include <stdlib.h>

class List {
    struct Node {
        int data;
        struct Node *next;
    };

    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *front;
    struct Node *rear;


    public:
        List() {
            front = NULL;
            rear = NULL;
        }
        int insert_beg(int num);
        void del_end();
        void peek();
        void display();
        int size();
        
    

};

int main() {
    List l1;
    int choice;
    int num;
    int pos;
    while(1) {

        printf("\n SINGELY LINKED LIST \n");
        printf("\n 1. Enqueue \n 2. Dequeue \n 3. peek \n 4. Exit \n");;
        printf("\n Enter the choice ");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("Enter the number ");
                scanf("%d",&num);
                if(l1.insert_beg(num)) {
                    printf("\n Inserted successfully.");
                }
                else {
                    printf("\n Insertion unsuccessful.");
                }
                break;
            
            case 2:
                l1.del_end();
                break;

            case 3:
                l1.peek();        
                break;

            case 4:
                return 1;
                break;
            
            case 5:
                l1.display();
                break;
        }
    }


}

//Function to add the element to the queue.
//Time complexity => O(1)
int List::insert_beg(int num) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode -> data = num;
    if(front == NULL) {
        newnode -> next = newnode;
        front = newnode;
        rear = newnode;

    }

    else {
        newnode -> next = front;
        front = newnode;
        rear -> next = front;
    }
    return 1;
}

//Function to delete the element from the queue.
//Time complexity => O(n)
void List::del_end() {
    struct Node *temp = front;
    if(front == NULL) {
        printf("Queue is empty.");
    }
    else {
        if(temp -> next == NULL) {
            front = NULL;
            rear = NULL;
        }
        else {
        while(temp -> next -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = NULL;
        rear = temp;
        free(temp -> next); //Frees the node in the memory address.
        }
    }
}

//Function to show the peek of queue
//Time complexity => O(1)
void List::peek() {
    if(front == NULL) {
        printf("Queue empty.");
    }
    else {
        printf("%d\n",rear -> data);
    }
}

//Function to display the elements of the queue
//Time complexity => O(n)
void List::display() {
    struct Node *temp;
    temp = front;
    if(front == NULL) {
        printf("Queue empty.");
    }
    else {
        while(temp!= NULL) {
            printf("%d ",temp->data);
            temp = temp -> next;
        }
    }
}