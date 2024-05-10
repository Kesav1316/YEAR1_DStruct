#include <stdio.h>
#include <stdlib.h>

class List {
    struct Node {
        int data;
        struct Node *next;
    };

    struct Node *head;

    public:
        List() {
            head = NULL;
        }

    int insertbeg( int );
    int deletebeg(  );
    void display();
    
};

int main() {
    List l1;
    int choice;
    int num;
    while(1) {
        printf("Enter the option 1.INSERT 2.DELETE 3.DISPLAY \n");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("Enter the value of the num ");
                scanf("%d",&num);
                l1.insertbeg(num);
                break;
            
            case 2:
                l1.deletebeg();
                break;
            
            case 3:
                l1.display();

        }
    }
}

int List::insertbeg( int num ) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if(head == NULL) {
        newnode -> data = num;
        newnode -> next = NULL;
        head = newnode;
        return 1;
    }

    else {
        newnode -> data = num;
        newnode -> next = head;
        head = newnode;
        return 1;

    }
}

int List::deletebeg() {
    if (head == NULL) {
        return 0;
    }
    else {
        head = head -> next;
    }
}

void List::display() {
    struct Node *temp = head;
    while(temp != NULL) {
        printf("%d",temp->data);
        temp = temp -> next;
    }
}


