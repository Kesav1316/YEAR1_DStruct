#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
class List {
    int arr[SIZE];
    struct Node {
        int data;
        struct Node *next;
    };
    int cur;
    struct Node* head;
    public:
        List() {
            cur = -1;
            head = NULL;
        }

    int insertend( int );
    int insert( int );
    int deletebeg();
    int sort();
    int heap();
    void display();
    
};

int main() {
    List l1;

    while(1) {
        int choice;
        int num;
        printf("1. Insert 2. Delete 3. Display 4. Search 5. Sort 6. Exit");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("Enter the value of nunm ");
                scanf("%d",&num);
                l1.insert(num);
                break;
            
            case 2:
                l1.deletebeg();
                break;

            case 3:
                l1.display();
                break;

            case 5:
                l1.sort();
                break;
        }
    }
    
}

int List::insert(int num) {
    if(cur == SIZE -1) {
        return 0;
    }

    else if(cur == -1) {
        cur = 0;
        arr[cur] = num;
    }

    else {
        cur = cur + 1;
        arr[cur] = num;
        heap();
        return 1;
    }
}

int List::deletebeg() {
    if(cur == -1) {
        return 0;
    }

    else {
        arr[0] = arr[cur];
        cur--;
        heap();
        return 1;

    }
}

int List::insertend(int num) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if(head == NULL) {
        newnode -> data = num;
        newnode -> next = NULL;
        head = newnode;
    }

    else {

        struct Node *temp = head;
        while(temp -> next != NULL) {
            temp = temp -> next;
        }
        newnode -> data = num;
        newnode -> next = NULL;
        temp -> next = newnode;
    }
} 

int List::sort() {

    while(cur != -1) {
        insertend(arr[0]);
        deletebeg();
    }
    struct Node *temp = head;
    while(temp != NULL) {
        printf("%d",temp->data);
        temp = temp -> next;
    }

    return 1;
}
int List::heap() {
    int i;
    i = cur;
    while(i > 0) {
        int parent;
        parent = (i-1)/2;
        if(arr[i] > arr[parent]) {
            int temp;
            temp = arr[i];
            arr[i] = arr[parent];
            arr[parent] = temp;
        }
        i--;
    }
}

void List::display() {
    for( int i = 0 ; i <= cur ; i++ ) {
        printf("%d",arr[i]);
    }
}