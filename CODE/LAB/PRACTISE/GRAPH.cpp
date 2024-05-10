//Implementing a graph with an adjacency list
#include <stdio.h>
#include <stdlib.h>

class algraph
{
    private:
        struct node 
        {
            int data;
            struct node *next;
            struct node *nextvertex;
        };
        struct node * root = NULL;

    public:
        int insertvertex(int);
        int deletevertex(int);
        int display();
        int search(int,int);

};


int main() 
{
    algraph g;
    int choice;
    int num,num2;
    while(1) 
    {

        printf("\n1. Insert vertex \n2. Delete \n3. Search \n4. Display \n5.Exit");
        scanf("%d",&choice);

        switch(choice) 
        {
            case 1:
                printf("Enter the number ");
                scanf("%d",&num);
                if(g.search(num,num))
                {
                    printf("Vertex already exists");
                    break;
                }
                if(g.insertvertex(num)) 
                {
                    printf("\n Inserted successfully.");
                }
                else 
                {
                    printf("\n Insertion unsuccessful.");
                }
                break;
            
            case 2:
                printf("Enter the number ");
                scanf("%d",&num);
                if(g.deletevertex(num)) 
                {
                    printf("\n Deleted successfully.");
                }
                else 
                {
                    printf("\n Deletion unsuccessful.");
                }
                break;

            case 3:
            {
                printf("Enter the starting vertex ");
                scanf("%d",&num);
                printf("Enter the ending vertex ");
                scanf("%d",&num2);
                int result = g.search(num,num2);
                if(result==-1) 
                {
                    printf("\n Edge not found");
                }
                else if(result == 0)
                {
                    printf("\n Edge dosent connect the given vertices");
                }   
                else
                {
                    printf("An edge connects given vertices");
                }         
                break;
            }

            case (4):
                g.display();
                break;
            
            case 5:
                exit(0);
                break;
        }
    }
}

//Method to insert a vertex
int algraph::insertvertex(int num)
{
    struct node * temp = root;
    while(temp!=NULL)
    {
        if(temp->data==num)
        {
            return 0;
        }
        temp=temp->nextvertex;
    }
    struct node *newnode = (struct node *)malloc(sizeof(struct node));  
    newnode->data=num;   
    newnode->next=NULL;
    newnode->nextvertex=NULL;
    if(root==NULL)
    {
        root=newnode;
    }
    else
    {
        newnode->nextvertex = root;
        root= newnode;
    }
    int choice;
    struct node * temp2;
    temp2 = newnode;
    temp = root;
    while (temp!=NULL)
    {
        printf("Is the vertex %d connected to %d ?",num,temp->data);
        scanf("%d",&choice);
        if(choice!=0 && choice!=1)
        {
            printf("Invalid input");
            return 0;
        }
        if(choice==1)
        {
            struct node *newnode2 = (struct node *)malloc(sizeof(struct node));  
            newnode2->data=temp->data;   
            newnode2->next=NULL;
            newnode2->nextvertex=NULL;
            temp2->next = newnode2;
            temp2=temp2->next;
        }
        temp=temp->nextvertex;
    }
    return 1;
}

//Method to delete a vertex
int algraph::deletevertex(int num)
{
    if(root==NULL)
    {
        return 0;
    }
    struct node * prev = root;
    if(root->data==num)
    {
        root=root->nextvertex;
        free(prev);
        return 1;
    }
    struct node * temp = root;
    while (temp!=NULL)
    {
        if(temp->data==num)
        {
            prev->nextvertex=temp->nextvertex;
            free(temp);
            return 1;
        }  
        prev=temp; 
        temp=temp->nextvertex;
    }
    return 0;
}

//Method to display adjacency list
int algraph::display()
{
    if(root==NULL)
    {
        return 0;
    }
    struct node * temp = root;
    struct node * temp2;
    while(temp!=NULL)
    {
        printf("%d : ",temp->data);
        temp2=temp->next;
        while(temp2!=NULL)
        {
            printf("%d ",temp2->data);
            temp2=temp2->next;
        }   
        printf("\n");
        temp=temp->nextvertex;
    }
    return 1;
}

//Method to search for an edge
int algraph::search(int v1,int v2)
{
    struct node * temp = root;
    while(temp!=NULL)
    {
        if(temp->data==v1)
        {
            struct node * temp2 = temp->next;
            while(temp2!=NULL)
            {
                if(temp2->data==v2)
                {
                    return 1;
                }
                temp2=temp2->next;
            }
            return 0;
        }
        temp=temp->nextvertex;
    }
    return 0;
}