/*
A. Write a separate C++ menu-driven program to implement Tree ADT using a character binary tree. Maintain proper boundary conditions and follow good coding practices. The Tree ADT has the following operations,

1. Insert
2. Delete
3. Preorder
4. Inorder
5. Postorder
6. Search
7. Exit

What is the time complexity of each of the operations?
*/

#include <stdio.h>
#include <stdlib.h>

class List {
    struct node {
        int data;
        struct node* left;
        struct node *right;
    };
    public:
       
        struct node *root;
        List() {
            root=NULL;
        }
        void search(int);
        int search1(struct node *,int);
        void inorder(struct node *);
        void preorder(struct node *);
        void postorder(struct node *);
        void inorder1();
        void preorder1();
        void postorder1();
        int insert(int);
        void delete1(int);
        int delete2(int,struct node *);
};

int main() {
    List l1;
    int choice, num;
    while (1) {
        printf("Enter the option \n1.Insert \n2.Delete \n3.Inorder \n4.Postorder \n5.Preorder \n6.Search \n7.Exit");
        printf("\nEnter a choice:");
        scanf("%d",&choice);
        switch (choice) {
        case 1:
            printf("Enter the number to insert:");
            scanf("%d",&num);
            if(l1.insert(num)) {
                printf("\n%d inserted\n",num);
            }
            break;
        case 2:
            printf("Enter the number to delete ");
            scanf("%d\n",&num);
            l1.delete1(num);
            break;
        case 3:
            l1.inorder1();
            break;
        case 4:
            l1.postorder1();
            break;
        case 5:
            l1.preorder1();
            break;
        case 6:
            printf("Enter the number to search ");
            scanf("%d",&num);
            l1.search(num);
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("\n Enter a valid choice \n");
            break;
        }

    }
    return 0;
}


//Function to insert a number to the tree.
int List::insert(int num) {
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL) {
        root=newnode;
        return 1;
    }
    else{
        struct node *temp;
        temp=root;
        int dir;
        while(true) {
            printf("Left(1) or Right(2)");
            scanf("%d",&dir);
            if(dir==1) {
                if(temp->left==NULL) {
                    temp->left=newnode;
                    return 1;
                }
                else {
                    temp=temp->left;
                }
            }
            else {
                if(temp->right==NULL) {
                    temp->right=newnode;
                    return 1;
                }
                else {
                    temp=temp->right;
                }
            }    
            
        }
    }
}

//Function to perform inorder traversel in the tree.
void List::inorder1() {
    inorder(root);
}

void List::inorder(struct node* temp){
    if(temp==NULL){
        return;
    }
    else{
        inorder(temp->left);
        printf("%d ",temp->data);
        inorder(temp->right);
    }
}

//Function to perform postorder traversel in the tree.
void List::postorder1() {
    postorder(root);
}

void List::postorder(struct node * temp) {
    if(temp==NULL) {
        return;
    }
    else {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ",temp->data);
    } 
}

//Function to perform preorder traversel in the tree.
void List::preorder1() {
    preorder(root);
}

void List::preorder(struct node * temp)
{
    if(temp==NULL) {
          return;
     }
     else{
        printf("%d ",temp->data); 
        preorder(temp->left);
        preorder(temp->right);
    }   
}

//Function to perform search the number in the tree.
void List::search(int num) {
    search1(root,num);
}

int List::search1(struct node* temp,int num) {
    if(temp==NULL) {
        return 0;
    }
    else {
        int x=search1(temp->left,num);
        if(temp->data==num) {
            printf("The number is present.");
            return 1;
        }
        int y=search1(temp->right,num);
        if(temp==root && x==0 && y==0) {
            printf("The number is not present.");
        }
        return x+y;
    }
}

//Function to delete the number from the tree.
void List::delete1(int num) {
    delete2(num,root);
}

int List::delete2(int num,struct node * temp) {
    int x;
    if(temp==NULL) {
        return 0;
    }
    else {
        x=delete2(num,temp->left);
        if(x==1) {
            temp->left=NULL;
        }
        if(temp->data==num) {
            if(temp->left==NULL and temp->right==NULL) {
                free(temp);
                return 1;
            }
            else if(temp->left==NULL && temp->right!=NULL) {
                  int temp1=temp->data;
                  temp->data=temp->right->data;
                  temp->right->data=temp1;
                  x=delete2(num,temp->right);
                  if(x==1) {
                     temp->right=NULL;
                    }
            }
            else if(temp->right==NULL && temp->left!=NULL) {
                  int temp1=temp->data;
                  temp->data=temp->left->data;
                  temp->left->data=temp1;
                  x=delete2(num,temp->left);
                  if(x==1) {
                    temp->left=NULL;
                  }
            }
            else if(temp->right!=NULL && temp->left!=NULL) {
                  int temp1=temp->data;
                  temp->data=temp->left->data;
                  temp->left->data=temp1;
                  x=delete2(num,temp->left);
                  if(x==1) {
                    temp->left=NULL;
                  }
            }
        }
        x=delete2(num,temp->right);
        if(x==1) {
                temp->right=NULL;
        }
        return 0;
    }
}