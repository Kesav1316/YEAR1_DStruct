/*
A. Write a C++ menu-driven program to implement List ADT using a singly linked list. Maintain proper boundary conditions and follow good coding practices. The List ADT has the following operations,

1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Display Reverse
10. Reverse Link
11. Exit
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
        int insert_beg(int num);
        int insert_end(int num);
        int insert_pos(int num , int pos);
        int del_beg();
        int del_end();
        int del_pos(int pos);
        int search(int num);
        void display();
        void displayreverse();
        int reverselist();
        int link();
        int link2(struct Node *, struct Node *);
        int size();
        
    

};

int main() {
    List l1;
    int choice;
    int num;
    int pos;
    while(1) {

        printf("\n SINGELY LINKED LIST \n");
        printf("\n 1. Insert Beginning \n 2. Insert End \n 3. Insert Position");
        printf("\n 4. Delete Beginning \n 5. Delete End \n 6. Delete Position");
        printf("\n 7. Search \n 8. Display \n 9. Display Reverse \n 10. Reverse Link \n 11. Exit");
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
                printf("Enter the number ");
                scanf("%d",&num);
                if(l1.insert_end(num) == 2) {
                    printf("Inserted ");
                }
                break;

            case 3:
                printf("Enter the number and position to insert ");
                scanf("%d %d",&num,&pos);
                if(l1.insert_pos(num , pos)) {
                    printf("Inserted successfully.");
                } 
                else {
                    printf("Position out of bounds");
                }
        
                break;

            case 4:
                if(l1.del_beg()) {
                    printf("Deleted successfully.");
                }
                else {
                    printf("List is empty.");
                }
                break;
            
            case 5:
                if(l1.del_end()) {
                    printf("Deleted successfully.");
                }
                else {
                    printf("The list is empty.");
                }
                break;
            
            case 6:
                printf("Enter the position ");
                scanf("%d",&pos);
                if(l1.del_pos(pos)) {
                    printf("Deleted successfully.");
                }
                else {
                    printf("The list is empty.");
                }
                break;

            case 7:
                printf("Enter the number ");
                scanf("%d",&num);
                printf("%d in the %d index \n",num,l1.search(num));
                break;

            case 8:
                l1.display();
                break;
            
            case 9:
                l1.displayreverse();
                break;
            
            case(10):
                if(l1.reverselist()) {
                    printf("Successfully reversed.");
                }
                else {
                    printf("The list is empty.");
                }
                break;
            
            case 11:
                return 0;
                break;

            case 12:
                l1.link();
            
            
        }
    }


}

//Getting the size of the singely linked list.
int List::size() {
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

//Inserting at the beginning of the singely linked list.
int List::insert_beg(int num) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode -> data = num;
    newnode -> next = head;
    head = newnode;
    return 1;

}

//Inserting at the end of the singely linked list.
int List::insert_end(int num) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    newnode -> data = num;
    newnode -> next = NULL;
    if(head == NULL) {
        head = newnode;
        return 2;
    }

    else {
        while(temp -> next != NULL) {
            temp = temp -> next;

        }
        temp -> next = newnode;
        return 2;
    }
}

//Inserting at a position in the singely linked list.
int List::insert_pos(int num , int pos) {
    int count = 0;
    struct Node *temp = head;
    struct Node *temp2;
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode -> data = num;

    if(pos > (size())) {
        return 0;    
    }
    else {
        if(head == NULL && pos == 0) {
            insert_beg(num);
        }
        else if(pos == 1) {
            temp = head -> next;
            head -> next = newnode;
            newnode -> next = temp;
            return 1;
        }
        else {
            while(count < pos - 1) {
                temp = temp -> next;
                count++;
        }
        temp2 = temp -> next;
        temp -> next = newnode;
        newnode -> next = temp2; 
        return 1;
        }
    }
}

//Deleting the beginning of the singely linked list.
int List::del_beg() {
    struct Node *temp;
    struct Node *temp2;
    if(head == NULL) {
        printf("The list is empty.");
        return 0;
    }

    else {
        temp2 = head; //temp2 stores the memory address of 0 element
        temp = head -> next; //temp stores the memory of 1 element
        head = temp;
        free(temp2);
        return 1;
    }
}

//Deleting the end of the singely linked list.
int List::del_end() {
    struct Node *temp = head;
    if(head == NULL) {
        return 0;
    }
    else {
        while(temp -> next -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = NULL;
        free(temp -> next); //Frees the node in the memory address.
        return 1;
    }
}

//Deletes the element in that position in the singely linked list.
int List::del_pos(int pos) {
    struct Node *temp = head;
    struct Node *prev = head;
    int count = 0;
    if(head == NULL) {
        return 0;
    }

    else {
        while(count < pos && temp != NULL) {
            prev = temp;
            temp = temp -> next;
            count++;
        }
        prev -> next = temp -> next; //Links previous node to one after the other.
        return 1;
    }
}

//Searching the number in the singely linked list.
int List::search(int num) {
    struct Node *temp = head;
    int count = 0;

    while(temp -> data != num) {
        temp = temp -> next;
        count++;
    }
    return count;


}

//Displaying the data of each nodes in the singely linked list.
void List::display() {
    struct Node *temp = head;
    if(head == NULL) {
        printf("List empty");
    }
    else {
        while(temp != NULL) {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

void List::displayreverse() {
    int arr[100];
    int count = 0;
    struct Node *temp = head;
    if(head == NULL) {
        printf("List empty");
    }

    else {
        while(temp != NULL) {
            arr[count] = temp -> data;
            temp = temp -> next;
            count = count + 1;
        }
    }

    for(int i = count-1 ; i >= 0 ; i--) {
        printf("%d\n",arr[i]);
    }
}

//Method to reverse List in the singely linked list.
int List::reverselist()
{   
    if(head==NULL)
    {
        return 0;
    }
    struct Node *left = head;
    struct Node *temp1;
    struct Node *temp2;
    temp2=left->next;
    while(temp2!=NULL)
	{
	    temp1=left;
        left=temp2;
        temp2=left->next;
        left->next=temp1;
	}
    head->next=NULL;
    head=left;
    
    return 1;
}    

int List::link() {
    struct Node*temp1 = head;
    struct Node*temp2 = head->next;
    return link2(temp1,temp2);
}

int List::link2(struct Node* temp1, struct Node* temp2) {
    struct Node *temp3;
    temp1->next = NULL;
    while(temp2 != NULL) {
        temp3 = temp2 -> next;
        temp2 -> next = temp1;
        temp1 = temp2;
        temp2 = temp3;
        
    }
    head = temp1;
    return 1;

}