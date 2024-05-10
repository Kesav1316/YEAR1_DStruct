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

class hash
{
    private:
        struct Node 
        {
            int data;
            struct Node *next;
        };
        struct Node *arr[size];

        void hashdisp(struct Node* head,int i)
        {
            struct Node *temp = head;
            if(head == NULL) 
            {
                printf("List empty in %d\n",i);
            }
            else 
            {
                while(temp != NULL) 
                {
                    printf("%d ",temp->data);
                    temp=temp->next;
                }
            }
        }



    public:
        hash()
        {
            for(int i=0;i<size;i++)
            {
                arr[i]=NULL;
            }
        }

        int insert(int);
        void disp();
        int deletion(int);
        int search(int);
};

//Method to insert into hash ig
int hash::insert(int num)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));  
    newnode->data=num;   
    newnode->next=NULL;
    int target=num%size;
    if(arr[target]==NULL)
    {
        arr[target]=newnode;  
        return 1;      
    }
    else
    {
        struct Node *temp = arr[target];
        while(temp -> next != NULL) 
        {
            if(temp->data==num)
            {
                return 0;
            }
            temp = temp -> next;
        }
        temp -> next = newnode;
        return 1;
    }
}

//to display ig
void hash::disp()
{
    for(int i=0;i<size;i++)
    {
        hashdisp(arr[i],i);
    }
}

//deletion ig
int hash::deletion(int num) 
{
    int target = num % size;
    if(arr[target]==NULL)
    {
        return 0; 
    }
    else
    {
        struct Node *temp = arr[target];
        struct Node *prev = arr[target];
        do 
        {
            if(temp->data==num)
            {
                prev->next=temp->next;
                free(temp);
                return 1;
            }
            prev = temp;
            if(temp->next==NULL)
            {
                return 0;
            }
            temp = temp -> next;
        }while(temp->next!= NULL);
    }
}

//Search
int hash::search(int num) 
{
    int target=num%size;
    if(arr[target]==NULL)
    {
        return 0;      
    }
    else
    {
        struct Node *temp = arr[target];
        while(temp != NULL) 
        {
            if(temp->data==num)
            {
                return 1;
            }
            temp = temp -> next;
        }
    }
}


int main() 
{
    hash h;
    int choice;
    int num;
    int pos;
    while(1) 
    {

        printf("1. Insert \n2. Delete \n3. Search \n4. Exit");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("Enter the number ");
                scanf("%d",&num);
                if(h.insert(num)) {
                    printf("\n Inserted successfully.");
                }
                else {
                    printf("\n Insertion unsuccessful.");
                }
                break;
            
            case 2:
                printf("Enter the number ");
                scanf("%d",&num);
                if(h.deletion(num)) 
                {
                    printf("\n Deleted successfully.");
                }
                else 
                {
                    printf("\n Deletion unsuccessful.");
                }
                break;

            case 3:
                printf("Enter the number ");
                scanf("%d",&num);
                if(h.search(num)) 
                {
                    printf("\n Element exists in hash.");
                }
                else 
                {
                    printf("\n Element does not exist in hash.");
                }            
                break;

            case 4:
                return 0;
                break;
            
            case 5:
                h.disp();
        }
    }
}
