/*
C. Write a separate C++ menu-driven program to implement Graph ADT with an adjacency matrix. Maintain proper boundary conditions and follow good coding practices. The Graph ADT has the following operations,

1. Insert
2. Delete
3. Search
4. Display
5. Exit

What is the time complexity of each of the operations?
*/

#include<stdio.h>
#include<stdlib.h>
#define size 5
class hash {
    struct node {
        int data;
        struct node *next;
    };
    int cur;
    struct node *adjacencylist[size];
    struct node *head;
    public:
        hash() {
            for (int i=0;i<size;i++) {
                adjacencylist[i]=NULL;
            }
            cur=0;
        }
        int insert (int u,int v);
        void display();
        int search(int v);
        int del(int v);
};

int main() {
    hash h1;
    int choice;
    while(1) {
        printf("\n1) Insert");
        printf("\n2) Delete");
        printf("\n3) Search");
        printf("\n4) Display");
        printf("\n5) Exit");
        printf("\n Enter your choice ");
        scanf("%d",&choice);
        
        switch (choice) {
            case 1:
                int v11,v12;
                printf("Enter the vertex 1:");
                scanf("%d",&v11);
                printf("Enter the vertex 2:");
                scanf("%d",&v12);
                if(h1.insert(v11,v12)) {
                printf("Element is inserted successfully");
                }
                else {
                    printf("fail");
                }
                break;

            case 2:
                int v21;
                printf("Enter the vertex to be deleted");
                scanf("%d",&v21);
                if(h1.del(v21)) {
                    printf("%d is deleted successfully",v21);
                }
                else {
                    printf("Element is not found");
                }
                break;

            case 3:
                int v3;
                printf("Enter the vertex to search");
                scanf("%d",&v3);
                
                if(h1.search(v3)) {
                    printf("Element is found");
                }
                else {
                    printf("Element is not found");
                }
                break;

            case 4:
                h1.display();
                break;
            
            case 5:
                printf("PROGRAM ENDED");
                return 0;
        }
    
    }
}

//Method to insert the element in the graph
//Time complexity => O(n^2) but O(1) if adjacency list for u or is already present
int hash:: insert(int v1,int v2) {
    struct node *newnode1=(struct node *)malloc(sizeof(struct node));
    struct node *newnode2=(struct node *)malloc(sizeof(struct node));
    
    newnode1->data=v1;
    newnode1->next=NULL;
    newnode2->data=v2;
    newnode2->next=NULL;

    for (int i=0;i<cur;i++) {
        if(adjacencylist[i]->data==v1) { // Inserting v2 to v1
            for(int k=0;k<cur;k++) {
                if(adjacencylist[k]->data==v2) {
                struct node *temp=adjacencylist[i];
                while(temp->next!=NULL) { 
                temp=temp->next;
                }
                temp->next=newnode2;
                return 1;
                }
            }
            adjacencylist[cur]=newnode2;
            cur++;
            return 1;
        }
        if(adjacencylist[i]->data==v2) { // Inserting v1 to v2
            for(int k=0;k<cur;k++) {
                if(adjacencylist[k]->data==v1) {
                struct node *temp=adjacencylist[i];
                while(temp->next!=NULL) { 
                temp=temp->next;
                }
                temp->next=newnode1;
                return 1;
                }
            }
            adjacencylist[cur]=newnode1;
            cur++;
            return 1;
        }
    }
    if(v1==v2) {
        adjacencylist[cur]=newnode1;
        adjacencylist[cur]->next=newnode2;
        cur++;
        return 1;
    }
    adjacencylist[cur]=newnode1;
    adjacencylist[cur+1]=newnode2;
    cur+=2;
    return 1;
}

//Method to display in the graph
//Time complexity => O(n)
void hash:: display() { // Display linked list
   for(int i=0;i<cur;i++) {
    printf("%d\t",adjacencylist[i]->data);
   }
}

//Method to delete the element in the graph
//Time complexity => O(n)
int hash:: del(int v) {
    for (int i=0;i<cur;i++) {
        if(adjacencylist[i]->data==v) {
            adjacencylist[i]=NULL;
            for (int k=i;k<cur;k++) {
                adjacencylist[k]=adjacencylist[k+1];
            }
            cur--;
            return 1;
        }
    }
    return 0;
}

//Method to search in the graph
//Time complexity => O(n)
int hash::search(int v) {
    for (int i=0;i<cur;i++) {
        if(adjacencylist[i]->data==v) {
            return 1;
        }
    }
    return 0;
}
