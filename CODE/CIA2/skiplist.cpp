//Accepted values from 0 to 999
#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<time.h>

#define maxlvl 4
#define maxval 1000



int toss()
{
    time_t t1;
    srand(((unsigned)time(&t1))+rand());
    return std::rand()%2;
}

class skiplist
{
    private:
        struct node
        {
            struct node * left;
            struct node * right;
            struct node * up;
            struct node * down;
            int data;
        };
        struct node * start;

    public:
        skiplist()
        {
            struct node * bl = (struct node *)malloc(sizeof(struct node));
            bl->data = -1;
            struct node * br = (struct node *)malloc(sizeof(struct node));
            br->data = maxval+1;

            bl->right = br;
            br->left = bl;

            bl->down = NULL;
            br->down = NULL;
            bl->left = NULL;
            br->right = NULL;

            for(int i=0;i<maxlvl-1;i++)
            {
                struct node * ml = (struct node *)malloc(sizeof(struct node));
                ml->data = -1;
                struct node * mr = (struct node *)malloc(sizeof(struct node));
                mr->data = maxval+1;
                
                ml->right = mr; 
                mr->left = ml;

                bl->up = ml;
                ml->down = bl;
                br->up = mr;
                mr->down = br;

                ml->left = NULL;
                mr->right = NULL;
                ml->up = NULL;
                mr->up = NULL;


                bl = bl->up;
                br = br->up;
            }
            start=bl;
        }
        int insert(int);
        int skipsearch(int);
        int display();
        int size();
        int deletion(int);
};

int main()
{   
    skiplist l;    
    int choice,num;
    while(1)    
    {   getchar();
        printf("\nEnter your choice: \n1.Insert \n2.Display \n3.Delete \n4.Skipsearch");
        printf("\n5.Size \n6.Exit");        
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
                printf("\n Enter the number to insert the skiplist:");
                scanf("%d",&num);
                if(num<0 || num>maxval)
                {
                    printf("Number exceeds range");
                    break;
                }
                if(l.insert(num))
                    printf("Successfully inserted into skiplist");
                break;

            case 2 :
                l.display();
                break;

            case 3 :
                printf("\n Enter the number to delete:");
                scanf("%d",&num);
                if(num<0 || num>maxval)
                {
                    printf("Number exceeds range");
                    break;
                }
                if(l.deletion(num))
                {
                    printf("Successfully deleted");
                }
                else
                {
                    printf("Deletion unsuccessful");
                }
                break;

            case 4 :
                printf("\n Enter the number to skipsearch:");
                scanf("%d",&num);
                if(num<0 || num>maxval)
                {
                    printf("Number exceeds range");
                    break;
                }
                if(l.skipsearch(num))
                {
                    printf("Number exists in skiplist");
                }
                else
                {
                    printf("Number does not exist in skiplist");
                }
                break;

            case 5 :
                printf("\n The number of values in the skiplist is %d",l.size());
                break;

            case 6 :
                exit(0);                
        }
    }
}

//Method to insert into skiplist
int skiplist::insert(int num)
{
    struct node * temp = start;
    struct node * rtnode = temp->right;
    while(1)
    {
        if(temp->data == num)
        {
            return 0;
        }
        if(rtnode->data>num)
        {
            if(temp->down==NULL)
            {
                //insert node at temp->right (level 1)
                struct node * newnode = (struct node *)malloc(sizeof(struct node));
                newnode->data = num;
                newnode->right = temp->right;
                temp->right = newnode;
                temp = newnode->right;
                newnode->left = temp->left;
                temp->left = newnode;
                newnode->down = NULL;
                newnode->up = NULL;
                temp = newnode;

                //using coin toss and adding further levels (above temp)
                for(int i=0;i<maxlvl-1;i++)
                {   
                    if(toss())
                    {
                        //adding node above temp
                        struct node * newnode = (struct node *)malloc(sizeof(struct node));
                        newnode->data = num;
                        newnode->down = temp;
                        temp->up = newnode;
                        newnode->up = NULL;
                        //searching for the node left to newnode
                        temp = temp->left;
                        while(temp->up == NULL)
                        {
                            temp = temp->left;
                        }
                        temp = temp->up;
                        temp->right = newnode;
                        newnode->left = temp;
                        //searching for the node right to newnode
                        temp = newnode->down;
                        temp = temp->right;
                        while(temp->up == NULL)
                        {
                            temp = temp->right;
                        }
                        temp = temp->up;
                        temp->left = newnode;
                        newnode->right = temp;
                        //reinitializing temp
                        temp = newnode;                        
                    }
                    else
                    {
                        return 1;
                    }
                }

            }
            else
            {
                temp=temp->down;
            }
        }
        else
        {
            temp=temp->right;
        }
        rtnode = temp->right;
    }
}

//Method to display skiplist
int skiplist::display()
{
    struct node * temp = start;
    struct node * temp2;
    while(temp!=NULL)
    {
        temp2 = temp->right;
        while(temp2->right!=NULL)
        {
            printf("%d ",temp2->data);
            temp2 = temp2 -> right;
        }
        printf("\n");
        temp = temp->down;
    }
    return 1;
}

//Method for skipsearch
int skiplist::skipsearch(int num)
{
    struct node * temp = start;
    struct node * rtnode = temp->right;
    while(1)
    {
        if(temp->data == num)
        {
            return 1;
        }
        if(rtnode->data>num)
        {
            if(temp->down==NULL)
            {
                return 0;
            }
            else
            {
                temp=temp->down;
            }
        }
        else
        {
            temp=temp->right;
        }
        rtnode = temp->right;
    }
}

//Method to find size of skiplist
int skiplist::size()
{
    struct node * temp = start;
    while(temp->down!=NULL)
    {
        temp = temp->down;
    }
    int count = -1;
    while(temp->data!=maxval+1)
    {
        temp = temp->right;
        count++;
    }
    return count;
}

//Method to delete a value in the skiplist
int skiplist::deletion(int num)
{
    struct node * temp = start;
    struct node * rtnode = temp->right;
    while(1)
    {
        if(temp->data == num)
        {
            //navigating to the topmost level
            while(temp->up!=NULL)
            {
                temp = temp->up;
            }
            //deleting nodes (from the top)  
            while(temp!=NULL)
            {   
                struct node * temp2 = temp->left;
                temp2->right = temp->right;
                temp2 = temp->right;
                temp2->left = temp->left;
                temp2 = temp;
                temp = temp->down;
                free(temp2);                
            }      
            return 1;
        }
        if(rtnode->data>num)
        {
            if(temp->down==NULL)
            {
                return 0;
            }
            else
            {
                temp=temp->down;
            }
        }
        else
        {
            temp=temp->right;
        }
        rtnode = temp->right;
    }
}

