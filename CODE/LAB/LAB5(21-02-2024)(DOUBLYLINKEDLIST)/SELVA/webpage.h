#include <stdio.h>
#include <stdlib.h>

class Dlist {
private:
    struct node {
        int data;
        struct node *prev;
        struct node *next;
    };
    int ID = 0;
    struct node *head;
    struct node *tail;
    struct node *current;

public:
    Dlist() {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
    }
    struct node *CreateNode();
    int isempty();
    int newpage();
    int back();
    int front();
    void display();
};

//Function to create a new node.
struct Dlist::node *Dlist::CreateNode() {
    return (struct node *)malloc(sizeof(struct node));
}

//Function to check if the doubly linked list is empty.
int Dlist::isempty() {
    if (head == nullptr) {
        return 1;
    } else {
        return 0;
    }
}

//Function to create a new webpace in the doubly linked list.
int Dlist::newpage() {
    struct node *C_Node = CreateNode();
    C_Node->data = ID;
    ID++;
    C_Node->next = nullptr;
    if (isempty() == 1) {
        C_Node->prev = nullptr;
        head = C_Node;
        tail = C_Node;
        current = C_Node;
    } 
    else {
        C_Node->prev = tail;
        tail->next = C_Node;
        tail = C_Node;
        current = tail;
    }
    return ID - 1;
}

//Function to navigate to the previous webpage in the doubly linked list.
int Dlist::back() {
    if (current != nullptr && current->prev != nullptr) {
        current = current->prev;
        return current->data;
    }
    return -1;
}

//Function to navigate to the next webpage in the doubly linked list.
int Dlist::front() {
    if (current != nullptr && current->next != nullptr) {
        current = current->next;
        return current->data;
    }
    return -1;
}

