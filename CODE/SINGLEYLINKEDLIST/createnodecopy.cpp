#include<stdio.h>
#include<stdlib.h>

class LinkList
{    
    struct node
    {   
        int data;
        struct node *next;
    };
    struct node *head;

    public:
        LinkList()
        {
            head=NULL;
            struct node *newnode=(struct node)malloc(sizeof(struct node));
        }
        int insbeg(int);
        void insend(int);
        int inspos(int,int);
        void display();
};

int main()
{   LinkList ll1;    
    int choice,num,pos;
    while(1)    
    {   getchar();
        getchar();
        system("clear"); 
        printf("Enter your choice: \n 1. Insert at Beginning \n 2. Append \n 3.Insert");
        printf("4.");
        printf("\n 8. Display \n 9. Exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case(1):
                printf("\n Enter the number to insert:");
                scanf("%d",&num);
                ll1.insbeg(num);
                printf("Successfully inserted");
                break;

            case(2):
                printf("\n Enter the number to append:");
                scanf("%d",&num);
                ll1.insend(num);
                printf("Successfully inserted");
                break;    

            case(3):
                printf("\n Enter the number to insert:");
                scanf("%d",&num);
                printf("\n Enter the location:");
                scanf("%d",&pos);
                if(ll1.inspos(num,pos))
                    printf("Successfully inserted");
                else
                    printf("Invlid Index");    
                break;

            case(4):


            case(8):
                ll1.display();
                break;       

            case(9):
                exit(0);
                break;     
        }
    }
    return 0;
}


//Method to insert value at the beginning
int LinkList::insbeg(int num)
{
    
    newnode->data=num;
    newnode->next=head;
    head=newnode;
}

//Method to insert value at the end
void LinkList::insend(int num)
{
    struct node *add;
    add=head;
    struct node newnode=(struct node)malloc(sizeof(struct node));
    while(add!=NULL)
    {   if (add->next==NULL)
        {   
            add->next=newnode;
            break;
        }    
        else
            add = add->next;
    }
    newnode->data=num;
}

//Method to insert value
int LinkList::inspos(int num,int pos)
{   
    struct node *add;
    add=head;
    struct node newnode=(struct node)malloc(sizeof(struct node));
    newnode->data=num;
    if(pos==0)
    {
        insbeg(num);
    }
    while(pos>1)
    {
        add=add->next;
    }
    add->next=newnode;
    newnode->next=add->next;
    return 1;
}



//Method to display the List
void LinkList::display()
{
    struct node *add;
    add=head;
    printf("[ ");
    while(add!=NULL)
    {
        printf("%d, ",add->data);
        add=add->next;
    }
    printf("]");
}
\