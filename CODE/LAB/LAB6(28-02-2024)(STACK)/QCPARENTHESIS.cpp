#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

class stack {
private:
    struct Node {
        char data;
        struct Node* next;
    };

    struct Node* top;

public:
    stack();
    bool isEmpty();
    int push(char item);
    int pop();
    int getSize();
    bool isBalanced(const char* str);
    void clear();
};


int main() {
    stack stack;
    char input[MAX_SIZE];
    int choice;
    while(1) {
        printf("1. Check Balance\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter a string of parentheses: ");
                fgets(input, MAX_SIZE, stdin);
                input[strcspn(input, "\n")] = '\0';
                if (stack.isBalanced(input)) {
                    printf("Parentheses are balanced.\n");
                } else {
                    printf("Parentheses are not balanced.\n");
                }
                stack.clear();
                break;
            case 2:
                printf("PROGRAM ENDED\n");
                return 0;
            default:
                printf("Invalid.\n");
        }
    }
    return 0;
}

stack::stack() {
    top = NULL;
}

bool stack::isEmpty() {
    return top == NULL;
}

//Pushing each character in the string in the stack.
//Time complexity => O(1).
int stack::push(char item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return 0;
    }
    newNode->data = item;
    newNode->next = top;
    top = newNode;
    return 1;
}

//Popping each character in the string in the stack.
//Time complexity => O(1).
int stack::pop() {
    if(isEmpty()) {
        printf("Underflow\n");
        return 0;
    }
    struct Node* temp = top;
    top = temp->next;
    free(temp);
    return 1;
}

//Getting the size of the stack.
//Time complexity => O(n).
int stack::getSize() {
    int size = 0;
    struct Node* current = top;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

//Checking if the parenthesis is balanced.
//Time complexity => O(n)
bool stack::isBalanced(const char* str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == '(') {
            push('(');
        } else if (str[i] == ')') {
            if (isEmpty() || pop() != 1) {
                return false; 
            }
        }
    }

    bool result = isEmpty();
    return result;
}

//Clearing the data from the stack.
//Time complexity => O(n)
void stack::clear() {
    while (!isEmpty()) {
        pop();
    }
}

