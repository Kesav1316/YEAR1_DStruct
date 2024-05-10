//Program to implement tree data structure using linked list adt
#include<stdio.h>
#include<stdlib.h>

class Tree
{  
    private: 
        
        struct node
        {   
            int data;
            struct node *left;
            struct node *right;
        };

        struct node *root;

        int recins(struct node *temp,struct node *newnode)
        {
            int loc;
            printf("\n Enter left(0) or right(1) ");
            scanf("%d",&loc);

            if(loc==0)
            {
                if(temp->left==NULL)
                {
                    temp->left=newnode;
                    return 1;
                }
                temp=temp->left;
            }
            else if(loc==1)
            {
                if(temp->right==NULL)
                {
                    temp->right=newnode;
                    return 1;
                }            
                temp=temp->right;
            }
            return recins(temp,newnode);
        }

        int recpre(struct node *temp)
        {
            if(temp==NULL)
            {
                return 1;
            }
            printf("%d\n",temp->data);
            recpre(temp->left);                
            recpre(temp->right);
            return 1;
        }

        int recpost(struct node *temp)
        {
            if(temp==NULL)
            {
                return 1;
            }
            recpost(temp->left);    
            recpost(temp->right);      
            printf("%d\n",temp->data);      
            return 1;
        }

        int recin(struct node *temp)
        {
            if(temp==NULL)
            {
                return 1;
            }

            recin(temp->left);
            printf("%d\n",temp->data);
            recin(temp->right);
            return 1;
        }       

        int recsearch(struct node *temp, int num)
        {
            if(temp==NULL)
            {
                return 0;
            }
            if(temp->data==num)
            {
                return 1;
            }
            if(recsearch(temp->left,num))
            {
                return 1;
            }          
            if(recsearch(temp->right,num))
            {
                return 1;
            }
            return 0;     
        }

        int recrecdel(struct node *temp)
        {
            if(temp==NULL)
            {
                return 1;
            }
            recrecdel(temp->left);    
            recrecdel(temp->right);    
            free(temp);
            return 1;            
        }

        int recdel(struct node *temp,struct node *prev)
        {
            int loc;
            printf("\n Enter the number to delete ");
            scanf("%d",&loc);

            if(loc==0)
            {
                if(temp->left==NULL)
                {
                    return 0;
                }
                prev=temp;
                temp=temp->left;
            }
            else if(loc==1)
            {
                if(temp->right==NULL)
                {
                    return 0;
                }            
                prev=temp;
                temp=temp->right;
            }           
            else if(loc==2) 
            {
                if(prev->left==temp)
                {
                    prev->left=NULL;
                }
                else if(prev->right==temp)
                {
                    prev->right=NULL;
                }
                else if(prev==temp)
                {
                    prev=NULL;
                }
                return(recrecdel(temp));
            }
            return(recdel(temp,prev));
        }

    public:
        Tree()
        {
            root=NULL;
        }

        int insert(int);
        int inorder();
        int preorder();
        int postorder();
        int search(int);
        int deletion();
};

int main()
{   
    Tree t1;    
    int choice,num;
    while(1)    
    {  
        printf("Enter your choice: \n1.Insert \n2.Preorder \n3.Inorder \n4.Postorder \n5.Search \n6.Delete \n7.Exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case(1):
                printf("\n Enter the number to insert:");
                scanf("%d",&num);
                t1.insert(num);
                break;
            case(2):
                t1.preorder();
                break;    
            case(3):
                t1.inorder();
                break; 
            case(4):
                t1.postorder();
                break; 
            case(5):
                printf("\n Enter the number to search:");
                scanf("%d",&num);
                if(t1.search(num))
                {
                    printf("The element is present in the tree");
                }
                else
                {
                    printf("The element is not present in the tree");
                }
                break;   
            case(6):
                if(t1.deletion())
                {
                    printf("The element is deleted");
                }
                else
                {
                    printf("End of tree");
                }
                break;     
            case(7):
                printf("PROGRAM ENDED");
                exit(0);
                break;    
        }
    }
    return 1;
}


//Method to insert value
int Tree::insert(int num)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->left=NULL;
    newnode->right=NULL;

    if(root==NULL)
    {
        root=newnode;
        return 1;
    }

    return recins(root,newnode);
}

//Method for preorder
int Tree::preorder()
{
    return recpre(root);
}

//Method for inorder
int Tree::inorder()
{
    return recin(root);
}

//Method for postorder
int Tree::postorder()
{
    return recpost(root);
}

//Method for searching
int Tree::search(int num)
{
    return recsearch(root,num);
}

//Method for deletion
int Tree::deletion()
{
    return recdel(root,root);
}