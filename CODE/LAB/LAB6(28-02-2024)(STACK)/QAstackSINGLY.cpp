#include <stdio.h>
#include <stdlib.h>

class list {
    struct Node {
        int data;
        struct Node *next;
    };

    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *head;


    public:
        list() {
            head = NULL;
        }
        int push(char);
        int pop();
        void peak();
        void display();
        

};

int main() {
    list l1;
    int choice;
    char element;
    int pos;
    while(1) {

        printf("\n list ADT \n");
        printf("\n 1. Push \n 2. Pop \n 3. Peak \n 4. Exit \n");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("Enter the character ");
                scanf(" %c",&element);
                if(l1.push(element)) {
                    printf("\n Inserted successfully.\n");
                }
                else {
                    printf("\n Insertion unsuccessful.\n");
                }
                break;
            
            case 2:
                if(l1.pop()) {
                    printf("\n Succesful.\n");
                }
                else {
                    printf("\n Stack empty.\n");
                }
                break;

            case 3:
                l1.peak();
                break;  

            case 4:
                return 1;


        }
    }

}

//Pushing the element into the singly linked list.
//Time complexity => O(1)
int list::push(char element) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode -> data = element;
    newnode -> next = head;
    head = newnode;
    return 1;

}

//Popping the element from the singly linked list.
//Time complexity => O(1)
int list::pop() {
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

//Displaying the top of the singly linked list.
//Time complexity => O(1)
void list::peak() {
    if(head == NULL) {
        printf("Stack is empty.\n");
    }
    else {
        printf("%c",head->data);
    }
}

//Displaying the data of each nodes in singly linked list.
//Time complexity => O(n)
void list::display() {
    struct Node *temp = head;
    if(head == NULL) {
        printf("list empty");
    }
    else {
        while(temp != NULL) {
            printf("\n %c \n",temp->data);
            temp=temp->next;
        }
    }
}
