#include <stdio.h>
#include <stdlib.h>

class CList{
    struct Node {
        int data;
        struct Node *next;
    };

    struct Node *head;
    struct Node *tail;
    public:
        CList() {
            head = NULL;
            tail = NULL;
        }
        int insbeg(int num);
        void insend(int num);
        int insert_pos(int num , int pos);
        int del_beg();
        void display();

};


int main() {
    int num;
    int choice;
    int pos;
    CList l1;
    while(1) {
        printf("\n 1. Insert Beginning \n 2. Insert End \n 3. Insert Position");
        printf("\n 4. Delete Beginning \n 5. Delete End \n 6. Delete Position");
        printf("\n 7. Search \n 8. Display \n 9. Display Reverse \n 10. Reverse Link \n 11. Exit");
        printf("\n Enter the choice ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Enter the number ");
                scanf("%d",&num);
                l1.insbeg(num);
                break;
            
            case 2:
                printf("Enter the number ");
                scanf("%d",&num);
                l1.insend(num);  
                break;

            case 3:
                printf("Enter the number and position ");
                scanf("%d",&num);
                l1.insert_pos(num,pos);
                break;
            
            case 4:
                if(l1.del_beg()) {
                    printf("Deleted successfully.");
                }
                else {
                    printf("The list is empty");
                }
            case 8:
                l1.display();
                break;
            

        }
    }

    l1.display();
    
}

//Inserting the number at the beginning of the list.

int CList::insbeg(int num) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode -> data = num;
    if(head == NULL) {
        newnode -> next = newnode;
        head = newnode;
        tail = newnode;

    }

    else {
        newnode -> next = head;
        head = newnode;
        tail -> next = head;
    }
    return 1;
}


//Inserting the number at the end of the list.

void CList::insend(int num) {   
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode -> data = num;
    newnode -> next = head;
    tail -> next = newnode;
    tail = newnode;
}

//Displaying the elements of the list.
//Inserts in pos + 1
int CList::insert_pos(int num , int pos) {
    int count = 0;
    struct Node *temp = head;
    struct Node *temp2;
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode -> data = num;


    if(head == NULL && pos == 0) {
        insbeg(num);
    }
    else if(pos == 1) {
      temp = head -> next;
      head -> next = newnode;
      newnode -> next = temp;
    }
    else {
      while(count < pos - 1) {
        temp = temp -> next;
        count++;
      }
      temp2 = temp -> next;
      temp -> next = newnode;
      newnode -> next = temp2; 
    }
}

int CList::del_beg() {
    if(head == NULL) {
        return 0;
    }
    else {
    head = head -> next; 
    tail -> next = head;
    return 1;
    }
}

void CList::display() {
    struct Node *temp = head;
    while(temp != tail) { //Stops one before the last element in the list.
        printf("%d ",temp -> data);
        temp = temp -> next;
    }
    printf("%d ",temp -> data);

}

