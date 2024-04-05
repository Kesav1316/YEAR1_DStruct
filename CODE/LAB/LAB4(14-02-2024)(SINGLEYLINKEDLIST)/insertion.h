#include<stdio.h>
#include<stdlib.h>

class Link {
    struct Node{
        int data;
        struct Node * next;
    };
    struct Node * head;
    struct Node * gethead() {
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

//Method to display the elements in the singely linked list.
void Link::display() {
    struct Node* temp;
    temp = head;

    while(temp!=NULL){
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
