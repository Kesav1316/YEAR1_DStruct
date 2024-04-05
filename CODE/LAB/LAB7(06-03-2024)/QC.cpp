/*
C. Write a separate C++ menu-driven program to implement Queue ADT using an integer-linked list. Maintain proper boundary conditions and follow good coding practices. The Queue ADT has the following operations,

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
    struct Node *head;


    public:
        List() {
            head = NULL;
        }
        int insert_end(int num);
        void del_beg();
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
                if(l1.insert_end(num)) {
                    printf("\n Inserted successfully.");
                }
                else {
                    printf("\n Insertion unsuccessful.");
                }
                break;
            
            case 2:
                l1.del_beg();
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
//Time complexity => O(n)
int List::insert_end(int num) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    newnode -> data = num;
    newnode -> next = NULL;
    if(head == NULL) {
        head = newnode;
        return 1;
    }

    else {
        while(temp -> next != NULL) {
            temp = temp -> next;

        }
        temp -> next = newnode;
        return 1;
    }
    
}

//Function to delete the element from the queue.
//Time complexity => O(1)
void List::del_beg() {
    struct Node *temp;
    struct Node *temp2;
    if(head == NULL) {
        printf("The list is empty.");
    }

    else {
        temp2 = head;
        temp = head -> next; 
        head = temp;
        free(temp2);
    }
}

//Function to show the peek of queue
//Time complexity => O(1)
void List::peek() {
    if(head == NULL) {
        printf("Queue empty.");
    }
    else {
        printf("%d\n",head -> data);
    }
}

//Function to display the elements of the queue
//Time complexity => O(n)
void List::display() {
    struct Node *temp;
    temp = head;
    if(head == NULL) {
        printf("Queue empty.");
    }
    else {
        while(temp!= NULL) {
            printf("%d ",temp->data);
            temp = temp -> next;
        }
    }
}