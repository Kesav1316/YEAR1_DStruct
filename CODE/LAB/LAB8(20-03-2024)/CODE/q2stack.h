/*
B. Add a "construct expression tree" method to the binary tree data structure from the previous code. Import stack from the standard template library (STL) to construct the expression tree. Import the Tree ADT program into another program that gets a valid postfix expression, constructs, and prints the expression tree. It consists of the following operations.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *left;
    struct Node *right;
};

struct StackNode {
    struct Node *treeNode;
    struct StackNode *next;
};

class Stack {
    struct StackNode *top;

public:
    Stack() {
        top = NULL;
    }
    void push(struct Node *);
    struct Node *pop(){
        if (isEmpty() == 1) {
            printf("\nUnderflow error!");
            return NULL;    
        }
        else {
            struct StackNode *temp = top;
            top = top->next;
            struct Node *poppedNode = temp->treeNode;
            free(temp);
            return poppedNode;
        }
    };
    int isEmpty();
};

// Method to push the character to a stack
//Time Complexity O(1)
void Stack::push(struct Node *node) {
    struct StackNode *newNode = (struct StackNode *)malloc(sizeof(struct StackNode));
    newNode->treeNode = node;
    newNode->next = top;
    top = newNode;
}

// Method to check if the stack is empty 
//Time Complexity O(1)
int Stack::isEmpty() {
    if (top == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}