/*
A. Write a C++ menu-driven program to implement List ADT using a doubly linked list. Maintain proper boundary conditions and follow good coding practices. The List ADT has the following operations,

1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit

What is the time complexity of each of the operations?
*/

#include <stdio.h>
#include <stdlib.h>

class Dlist {
    struct Node {
        int data;
        struct Node *next;
        struct Node *previous;
    };

    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *head;
    struct Node *tail;

    public:
        Dlist() {
            head = NULL;
            tail = NULL;
        }
        void insertbeg(int num);
        void insertend(int num);
        int insertposition(int num ,int pos);
        void deletebeg();
        void deleteend();
        void deletepos(int pos);
        int size();
        int search(int num);
        void display();
        void displayreverse();
};

int main() {
    Dlist l1;
    int choice;
    int num;
    int pos;
    while(1) {

        printf("DOUBLEY LINKED LIST \n");
        printf("\n 1. Insert Beginning \n 2. Insert End \n 3. Insert Position");
        printf("\n 4. Delete Beginning \n 5. Delete End \n 6. Delete Position");
        printf("\n 7. Search \n 8. Display \n 9. Display Reverse \n 10. Reverse Link \n 11. Exit");
        printf("\n Enter the choice ");
        scanf("%d",&choice);


    switch(choice) {
        case 1:
            printf("Enter the number ");
            scanf("%d",&num);
            l1.insertbeg(num);
            break;

        
        case 2:
            printf("Enter the number ");
            scanf("%d",&num);
            l1.insertend(num);
            break;
        
        case 3:
            printf("Enter the number and the position ");
            scanf("%d %d",&num,&pos);
            if(l1.insertposition(num,pos)) {
                printf("\nInserted.");
            }
            else {
                printf("\nCannot insert.");
            }
            break;

        case 4:
            l1.deletebeg();
            break;

        case 5:
            l1.deleteend();
            break;
        
        case 6:
            printf("Enter the position to delete ");
            scanf("%d",&pos);
            l1.deletepos(pos);
            break;

        case 7:
            printf("Enter the number to search ");
            scanf("%d",&num);
            num = l1.search(num);
            printf("%d",num);
            break;
        case 8:
            l1.display();
            break;
        
        case 9:
            l1.displayreverse();
            break;

    }

    }
}

//Getting the size of the doubly linked list.
int Dlist::size() {
    struct Node *temp = head;
    int count = 0;
    if(head == NULL) {
        return 0;
    }

    else {
        while(temp != NULL) {
            count = count + 1;
            temp = temp -> next;
        }
        return count;
    }
}

//Inserting at the beginning of the doubley linked list.
//Time complexity => O(1)
void Dlist::insertbeg(int num) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

    if(head == NULL) {
        newnode -> data = num;
        newnode -> next = head;
        newnode -> previous = NULL;
        head = newnode;   
        tail = newnode;
    }

    else {
        newnode -> data = num;
        newnode -> previous = NULL;
        newnode -> next = head;
        head -> previous = newnode;
        head = newnode;
    }
    

}   

//Inserting at the end of the doubley linked list.
//Time complexity => O(1)
void Dlist::insertend(int num) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

    if(head == NULL) {
        insertbeg(num);
    }

    else {
        newnode -> data = num;
        tail -> next = newnode;
        newnode -> previous = tail;
        newnode -> next = NULL;
        tail = newnode;
    }
}

//Inserting at the position of the doubley linked list.
//Time complexity => O(n)
int Dlist::insertposition(int val, int pos) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (pos == 0 || head == nullptr) {
        insertbeg(val);
    }

    if (newnode == nullptr) {
        return 0;
    }

    newnode->data = val;

    struct Node* temp = head;

    for (int i = 1; i < pos; i++) {

        if (temp == nullptr) {
            return 0;
        }

        temp = temp->next;

    }

    if (temp == nullptr) {
        return 0;
    }

    newnode->next = temp->next;
    newnode->previous = temp;
    
    if (temp->next != nullptr) {
        temp->next->previous = newnode;
    }
    temp->next = newnode;
    return 1;
} 

//Deleting the node at the beginning of the doubley linked list.
//Time complexity => O(1)
void Dlist::deletebeg() {

    if(head == NULL) {
        printf("The list is empty.");
    }

    else if(head -> next == NULL) {
        head = NULL;

    }

    else {
        head = head -> next;
        head -> previous = NULL;
    }
}

//Deleting the node at the end of the doubley linked list.
//Time complexity => O(1)
void Dlist::deleteend() {
    struct Node *temp = tail->previous;

    if(head == NULL) {
        printf("The list is empty.");
    }

    else if(head == tail) {
        deletebeg();
    }

    else {
        temp -> next = NULL;
        tail = temp;
    }
}

//Deleting the node at the given position in the doubley linked list.
//Time complexity => O(n)
void Dlist::deletepos(int pos) {
    int count = 0;
    struct Node *temp = head;
    struct Node *temp2;

    if(pos == 0) {
        deletebeg();
    }

    else if(pos == size() - 1) {
        deleteend();
    }

    else {
        while(count < pos -1) {
            temp = temp -> next;
            count = count + 1;
        }

        if(temp -> next != NULL) {
            temp2 = temp -> next -> next;
            temp -> next = temp2;
            temp2 -> previous = temp;
        
        }

        else {
            deleteend();
        }
 
    }
}

//Search for the value in the doubly linked list.
//Time complexity => O(n)
int Dlist::search(int num) {
    if (head == nullptr) {
        return 0;
    }
    struct Node* temp = head;
    int pos = 0;
    while (temp != nullptr && temp->data != num) {
        temp = temp->next;
        pos++;
    }
    if (temp == nullptr) {
        return 0;
    }
    return pos;
}


//Displaying the data of each nodes in the doubley linked list.
//Time complexity => O(n)
void Dlist::display() {
    struct Node *temp = head;

    if(head == NULL) {
        printf("List empty.");
    }

    else {
        while(temp != NULL) {
            printf("%d\n",temp -> data);
            temp = temp -> next;
        }
    }

}

//Displaying the data of each nodes in reverse in the doubly linked list.
//Time complexity => O(n)
void Dlist::displayreverse() {
    struct Node *temp = tail;
    if(head == NULL) {
        printf("List empty.");
    }

    else {

        while(temp != NULL) {
            printf("%d\n",temp -> data);
            temp = temp -> previous;
        }

    }
}