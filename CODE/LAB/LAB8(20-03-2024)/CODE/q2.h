#include <stdio.h>
#include <stdlib.h>
#include "q2stack.h"

int checkoperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        return 1;
    }
    return 0;
}

class BT {
    struct Node *root;

public:
    int constructedTree;
    BT() {
        root = NULL;
        constructedTree = 0;
    }

    void constructExpressionTree(char *);
    void preorder(struct Node *);
    void postorder(struct Node *);
    void inorder(struct Node *);
    struct Node *getRoot() {
        return root;
    };
};


void BT::constructExpressionTree(char *expression) {
    struct Node *newNode;
    Stack stack;
    for (int i = 0; expression[i] != '\0'; i++) {
        if (checkoperator(expression[i]) == 0) {
            newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = expression[i];
            newNode->left = NULL;
            newNode->right = NULL;
            stack.push(newNode);
        }
        else {
            newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = expression[i];
            newNode->right = stack.pop();
            newNode->left = stack.pop();
            stack.push(newNode);
        }
    }
    root = stack.pop();
    constructedTree = 1;
}

//Method to print using inorder traversal.
void BT::inorder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%c ", root->data); 
    inorder(root->right);
}

//Method to print using preorder traversal.
void BT::preorder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%c ", root->data); 
    preorder(root->left);
    preorder(root->right);
}

//Method to print using postorder traversal.
void BT::postorder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->data); 
}



