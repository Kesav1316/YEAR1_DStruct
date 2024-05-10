/*
A. Write a separate C++ menu-driven program to implement Hash ADT with Separate Chaining. Maintain proper boundary conditions and follow good coding practices. The Hash ADT has the following operations,

1. Insert
2. Delete
3. Search
4. Exit

What is the time complexity of each of the operations?
*/

#include <stdio.h>
#include <stdlib.h>
#define size 10

class hash {
    struct Node {
        int data;
        struct Node *next;
    };
    struct Node *arr[size];
    void hashdisp(struct Node* head,int i) {
        struct Node *temp = head;

        if(head == NULL)  {
            printf("List empty in %d index\n",i);
        }

        else  {
            printf("Index %d : ",i);
            while(temp != NULL) {
                printf("%d ",temp->data);
                temp=temp->next;
            }
            printf("\n");
        }
    }

    public:
        hash() {
            for(int i=0;i<size;i++) {
                arr[i]=NULL;
            }
        }

        void insert(int);
        void disp();
        int deletion(int);
        int search(int);
};


int main() {
    hash h;
    int choice;
    int num;
    while(1) {

        printf("\n1. Insert \n2. Delete \n3. Search \n4. Exit");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("Enter the number ");
                scanf("%d",&num);
                h.insert(num);
                break;
            
            case 2:
                printf("Enter the number ");
                scanf("%d",&num);
                if(h.deletion(num)) {
                    printf("\n Deleted successfully.");
                }
                else {
                    printf("\n Deletion unsuccessful.");
                }
                break;

            case 3:
                printf("Enter the number ");
                scanf("%d",&num);
                if(h.search(num)) {
                    printf("\n Element exists in hash.");
                }
                else {
                    printf("\n Element does not exist in hash.");
                }            
                break;

            case 4:
                printf("PROGRAM ENDED ");
                return 0;
                break;
            
            case 5:
                h.disp();
                break;
        }
    }
}


//Method to insert into hash. 
//Time complexity => O(n).
void hash::insert(int num) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));  
    newnode->data=num;   
    newnode->next=NULL;
    int target=num%size;
    if(arr[target]==NULL) {
        arr[target]=newnode;  
        printf("Inserted.");
    }
    else {
        struct Node *temp = arr[target];
        int count = 0;
        struct Node *prev = NULL; 
        while(temp != NULL) {
            if(temp->data == num) {
                printf("The number exists.");
                count ++;
                break;
            }
            prev = temp; 
            temp = temp->next;
        }
        if(count !=1) {
            if(temp == NULL) {
                prev->next = newnode;
            }
            else {
                temp->next = newnode;
            }
        }


    }
}

//Method to delete the key in the hash.
//Time complexity => O(n).
int hash::deletion(int num) {
    int target = num % size;
    if(arr[target]==NULL) {
        return 0;      
    }
    if(arr[target]->data==num) {
        struct Node *temp = arr[target];
        arr[target]=arr[target]->next;
        free(temp);
        return 1;      
    }
    
    struct Node *temp = arr[target];
    struct Node *prev = arr[target];
    while(temp != NULL) {
        if(temp->data==num) {
            prev->next=temp->next;
            free(temp);
            return 1;
        }
        prev = temp;
        temp = temp -> next;
    }
    return 0;
}

//Method to search the key in the hash.
//Time complexity => O(n).
int hash::search(int num) {
    int target=num%size;
    if(arr[target]==NULL) {
        return 0;      
    }
    struct Node *temp = arr[target];
    while(temp != NULL) {
        if(temp->data==num) {
            return 1;
        }
        temp = temp -> next;
    }
    return 0;
}

//Method to display
void hash::disp() {
    for(int i=0;i<size;i++) {
        hashdisp(arr[i],i);
    }
}