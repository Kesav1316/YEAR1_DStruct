/*
C. Given 'n' numbers, identify the optimal ADT that you can find a given number, its previous smaller element, and the next bigger element. Implement the program by including the appropriate header file.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

class BST {
    struct Node* root;
    struct Node* newnode(int data);
    struct Node* insertnode(struct Node* root, int data);
    struct Node* Prev(struct Node* root, int target);
    struct Node* Next(struct Node* root, int target);

public:
    BST() {
        root = NULL;
    }

    void insert(int data);
    void PrevandNext(int target);
};

struct Node* BST::newnode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* BST::insertnode(struct Node* root, int data) {
    if (root == NULL) return newnode(data);
    if (data <= root->data) {
        root->left = insertnode(root->left, data);
    }
    
    else {
        root->right = insertnode(root->right, data);
    }

    return root;
}

void BST::insert(int data) {
    root = insertnode(root, data);
}

void BST::PrevandNext(int target) {
    struct Node* prev = Prev(root, target);
    struct Node* next = Next(root, target);

    printf("To find %d\n", target);
    printf("Previous smaller element ");
    if (prev != NULL) {
        printf("%d\n", prev->data);
    }
    else {
        printf("Not found \n");
    }
    printf("Next greater element ");
    if (next != NULL) {
        printf("%d\n", next->data);
    }
    else {
        printf("Not found \n");
    }
}

struct Node* BST::Prev(struct Node* root, int target) {
    struct Node* prev = NULL;
    while (root != NULL) {
        if (root->data >= target) {
            root = root->left;
        } 
        else {
            prev = root;
            root = root->right;
        }
    }
    return prev;
}

struct Node* BST::Next(struct Node* root, int target) {
    struct Node* next = NULL;
    while (root != NULL) {
        if (root->data <= target) {
            root = root->right;
        } 
        else {
            next = root;
            root = root->left;
        }
    }
    return next;
}
