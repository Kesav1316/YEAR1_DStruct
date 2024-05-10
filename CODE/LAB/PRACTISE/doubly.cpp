#include <stdio.h>
#include <stdlib.h>

class List {
    struct Node {
        int data;
        struct Node *previous;
        struct Node *next;
    };

    struct Node *head;
    struct Node *tail;

    public:
        List() {
            head = NULL;
            tail = NULL;
        }
    
    int insertbeg(int );
    int insertend(int );
    int insertpos(int , int );
    int size();
    void display();

};

int main() {
    List l1;
    int choice;
    int num;
    int pos;

    while(1) {
        printf("Enter the choice 1.insertbeg 2.insertend 7.display");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("Enter the number to insert ");
                scanf("%d",&num);
                l1.insertbeg(num);
                break;

            case 2:
                printf("Enter the number to insert ");
                scanf("%d",&num);
                l1.insertend(num);
                break;

            case 3:
                printf("Enter the number and position ");
                scanf("%d %d",&num,&pos);
                l1.insertpos( num , pos );
                break;

            
            case 7:
                l1.display();
                break;

        }

    }
}

int List::insertbeg(int num) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if(head == NULL) {
        newnode -> data = num;
        newnode -> previous = NULL;
        newnode -> next = NULL;

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

int List::insertend(int num) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if(head == NULL) {
        insertbeg(num);
    }

    else {
        newnode -> data = num;
        newnode -> previous = tail;
        newnode -> next = NULL;
        tail -> next = newnode;
        tail = newnode;
    }
}

int List::insertpos( int num , int pos ) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    int count;
    count = 0;
    if(head == NULL && pos == 0) {
        insertbeg(num);
    }

    //else if(head -> next == NULL && pos == 1) {
    //    insertend(num);
    //}

    else if(pos == size()) {
        insertend(num);
    }

    else {
        newnode -> data = num;
        while(temp -> next -> next != NULL && count < pos - 1) {
            temp = temp -> next;
            count = count + 1;
        }
        newnode -> previous = temp;
        newnode -> next = temp -> next;
        temp -> next -> previous = newnode;
        temp -> next = newnode;
    }
}

int List::size() {
    int count;
    count = 0;
    struct Node *temp = head;
    while(temp != NULL) {
        temp = temp -> next;
        count = count + 1;
    }
    return count;
}
void List::display() {
    struct Node *temp = head;

    while(temp != NULL) {
        printf("%d\n",temp->data);
        temp = temp -> next;
    }
}