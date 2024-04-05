/*
B. Write a C++ menu-driven program to implement List ADT using a singly linked list. You have a gethead() private member function that returns the address of the head value of a list. Maintain proper boundary conditions and follow good coding practices. The List ADT has the following operations,

1. Insert Ascending
2. Merge
3. Display
4. Exit

Option 1 inserts a node so the list is always in ascending order. Option 2 takes two lists as input, and merges two lists into a third list. The third list should also be in ascending order. Convert the file into a header file and include it in a C++ file. The second C++ consists of 3 lists and has the following operations,

1. Insert List1
2. Insert List2
3. Merge into List3
4. Display
5. Exit
*/

#include<stdio.h>
#include<stdlib.h>

class Link {
    struct Node{
        int data;
        struct Node * next;
    };

    struct Node *head;
    struct Node *gethead() {
        return head;
    }

    public:
        Link() {
            head = NULL;
        }
   
    void display();
    int insertascending(int);
    int merge(Link,Link);
};

//Method to display the singely linked list.
void Link::display()
{
    struct Node* temp;
    temp = head;
    
    while(temp!=NULL) {
    printf("%d ",temp->data);
    temp = temp->next;
    }

}

//Method to insert in ascending order in the singely linked list.
int Link::insertascending(int num) {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = num;
    newnode->next = NULL;

    if (head == NULL || num <= head->data) {
      newnode->next = head;
      head=newnode;
    }

    struct Node *prev = head;
    struct Node *curr = head->next;

    while (curr != NULL && num > curr->data) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = newnode;
    newnode->next = curr;

    return 1;
}

//Method to merge two singely linked list.
int Link::merge(Link l1,Link l2) {
    struct Node * temp1;
    struct Node * temp2;
    temp1 = l1.gethead();

    while(temp1!=NULL) {
      insertascending(temp1->data);
      temp1 = temp1->next;
    }

    temp2 = l2.gethead();
    while(temp2!=NULL) {
        insertascending(temp2->data);
        temp2 = temp2->next;
    }
    return 1;

}
