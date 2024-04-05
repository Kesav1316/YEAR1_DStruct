//program to implement binary expression tree
#include<stdio.h>
#include<stdlib.h>
class bintree
{
    struct node
    {
        struct node *left;
        char data;
        struct node *right;
        struct node *next;
        
    };
    struct node *root;

    void inorder(struct node *root)
    {
        if (root==NULL)
        {
            return ;
        }
        else
        {
            inorder(root->left);
            printf("%c\t",root->data);
            inorder(root->right);
        }
    }

    void preorder(struct node *root)
    {
        if(root==NULL)
        {
            return;
        }
        else
        {
            printf("%c\t",root->data);
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(struct node *root)
    {
        if(root==NULL)
        {
            return;
        }
        else
        {
            postorder(root->left);
            postorder(root->right);
            printf("%c\t",root->data);
        }
    }
 void  push(struct node *newnode)
 {
    if(root==NULL)
    {
        root=newnode;
    }
    else
    {
       newnode->next=root;
       root=newnode;
    }
 }

struct node * pop()
{
    if (root==NULL)
    {
      return NULL;
    }
    else
    {
    struct node *temp=root;
    root=root->next;
    return temp;
    }
}

    public:
    
        void callin()
        {
            inorder(root);
        }
        void callpre()
        {
            preorder(root);
        }
        void callpost()
        {
            postorder(root);
        }
       
        bintree()
        {
            root=NULL;
            
        }
        
        void insert(char string[25]);   
            
};
int main()
{
    bintree b1;
    char string[25];
    int choice;
    

    while(1)
    {
        printf("\n(1) Postfix Expression");
        printf("\n(2) Preorder");
        printf("\n(3) Inorder ");
        printf("\n(4) postorder");
        printf("\n(5) Exit");

        printf("\nEnter your choice");
        scanf("%d",&choice);
        getchar();

        switch (choice)
        {
            case 1:
            printf("Enter the expression");
            scanf(" %24s",string);
            b1.insert(string);
            break;

            case 2:
            b1.callpre();
            break;

            case 3:
            b1.callin();
            break;

            case 4:
            b1.callpost();
            break;

            case 5:
            return 0;

        }
    }
    
}
void bintree:: insert(char string[25])
{
    for(int i=0;string[i]!='\0';i++)
    {
           struct node *newnode=(struct node *)malloc(sizeof(struct node));
            newnode->data=string[i];
            newnode->left=NULL;
            newnode->right=NULL;
            newnode->next=NULL;
        
        if(string[i]=='*' || string[i]=='/' || string[i]=='+'|| string[i]=='-')
        {
            newnode->right=pop();
            newnode->left=pop();
        }
         push(newnode);
    }
   
}





