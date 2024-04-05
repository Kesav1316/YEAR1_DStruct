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

class tree {
    struct Node {
        struct Node *left;
        int data;
        struct Node *right;
    };

    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *root;


    public:
        tree() {
            root = NULL;
        }
        int insert(int num);
        void inorder();
        void inorderrecursive(struct Node *);
        
};

int main() {
    tree l1;
    int choice;
    int num;
    int pos;
    while(1) {

        printf("\n TREE \n");
        printf("\n 1.Insert \n 2.Delete \n 3.Preorder \n 4.Inorder \n 5.Postorder \n 6.Search \n 7.Exit");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("Enter the number ");
                scanf("%d",&num);
                if(l1.insert(num)) {
                    printf("\n Inserted successfully.");
                }
                else {
                    printf("\n Insertion unsuccessful.");
                }
                break;
            
            case 2:
                l1.inorder();
                break;
        }
    }
}

int tree::insert(int num) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp;
    char LORR;
    temp = root;
    newnode -> data = num;
    newnode -> left = NULL;
    newnode -> right = NULL;
    if(root == NULL) {
        root = newnode;
    }

    while(temp != NULL) {
        printf("Enter left or right");
        scanf("%c",&LORR);
        if(LORR == 'L') {
            if(temp -> left == NULL) {
                temp -> left = newnode;
                break;
            }
            else {
                temp = temp -> left;
                continue;

            }
        }
        if(LORR == 'R') {
            if(temp -> right == NULL) {
                temp -> right = newnode;
                break;
            }
            else {
                temp = temp -> right;
                continue;

            }
               }
    }
}

void tree::inorder() {
    inorderrecursive(root);
}

void tree::inorderrecursive(struct Node *root) {
    if (root == NULL) {
        return;
    }
    else {
        inorderrecursive(root -> left);
        printf("%d",root ->data);
        inorderrecursive(root -> right);
    }
}
