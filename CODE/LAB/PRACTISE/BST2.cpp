#include <stdio.h>
#include <stdlib.h>

class List {
    struct Node {
        struct Node * left;
        struct Node * right;
        int data;
    };
    struct Node *root;

    public:
        List() {
            root = NULL;
        }
    
    int insert(int);
    int inorder();
    int inorderrec(struct Node *temp);
    int preorder();
    int preorderrec(struct Node *temp);
    int postorder();
    int postorderrec(struct Node *temp);
};

int main() {
    List l1;
    int choice;
    int num;
    while(1) {
        printf("Enter the choice ");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("Enter the value of num ");
                scanf("%d",&num);
                if(l1.insert(num)) {
                    printf("Successful\n");
                }
                else {
                    printf("Not successful\n");
                }
                break;
            case 2:
                l1.inorder();
                break;
            
            case 3:
                l1.preorder();
                break;
            
            case 4:
                l1.postorder();
                break;
            default:
                printf("Over");
        }
    }

}

int List::insert(int num) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode -> left = NULL;
    newnode -> right = NULL;
    newnode -> data = num;
    

    if(root == NULL) {
        root = newnode;
        return 1;
    }
    else {
        struct Node *temp = root;
        while(1) {
            if (num > temp->data) {
                if(temp -> right == NULL) {
                    temp -> right = newnode;
                    return 1;
                }
                else {
                    temp = temp -> right;
                }
            }

            else if (num < temp->data) {
                if(temp -> left == NULL) {
                    temp -> left = newnode;
                    return 1;
                }
                else {
                    temp = temp -> left;
                }
            }
        }
        
    }
    return 0;
}

int List::inorder() {
    return inorderrec(root);
}

int List::inorderrec(struct Node *temp) { //L Ro Ri
    if(temp == NULL ) {
        return 1;
    }

    else {
        inorderrec(temp->left);
        printf("%d\n",temp->data);
        inorderrec(temp->right);
        return 1;
    }
}

int List::preorder() {
    return preorderrec(root);
}

int List::preorderrec(struct Node* temp) {
    if(temp == NULL) {
        return 1;
    }

    else {
        printf("%d\n",temp->data);
        preorderrec(temp->left);  // First visit left subtree
        preorderrec(temp->right); // Then visit right subtree
        return 1;
    }
}

int List::postorder() {
    postorderrec(root);
}

int List::postorderrec(struct Node* temp) {
    if(temp == NULL) {
        return 1;
    }

    else {
        postorderrec(temp->left);  // Corrected from root->left to temp->left
        postorderrec(temp->right); // Corrected from root->right to temp->right
        printf("%d\n",temp->data);
        return 1;
    }
}

