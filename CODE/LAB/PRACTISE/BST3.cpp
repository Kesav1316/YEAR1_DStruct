/*
Tree ADT using a binary search tree
*/

#include <stdio.h>
#include <stdlib.h>

void menu();

class bst{

    struct node{
        
        struct node *left;
        int data;
        struct node *right;
    };

    struct node *root;
    void inorder_private(struct node *);
    void postorder_private(struct node *);
    void preorder_private(struct node *);
    int delete_private(struct node *, int);
    int search_private(struct node *, int);

    public:
        bst(){

            root = NULL;
        }
        void insert(int);
        void postorder();
        void preorder();
        void inorder();
        void remove(int);
        void search(int);
};

int main(){

    bst tree1;
    int choice, num;

    while(1){

        menu();
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("Enter a number: ");
                scanf("%d", &num);

                tree1.insert(num);
                printf("Inserted Successfully");

                break;

            case 2:
                printf("Enter a number: ");
                scanf("%d", &num);

                tree1.remove(num);
                break;

            case 3:
                tree1.preorder();
                break;

            case 4:
                tree1.inorder();
                break;

            case 5:
                tree1.postorder();
                break;

            case 6:
                printf("Enter a number: ");
                scanf("%d", &num);

                tree1.search(num);
                break;

            case 7:
                printf("Exited !");
                return 0;

            default:
                printf("Invalid Choice");
                break;
        }
    }
}

//Inserts the number into the bst
void bst::insert(int number){

    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = number;
    new_node->left = NULL;
    new_node->right = NULL;

    if(root == NULL)
        root = new_node;

    else{

        struct node *temp = root;

        while(temp){

            if(temp->data > number){

                if(temp->left == NULL){

                    temp->left = new_node;
                    temp = new_node;
                }
                
                temp = temp->left;
            }

            else if(temp->data <= number){

                if(temp->right == NULL){

                    temp->right = new_node;
                    temp = new_node;
                }
                
                temp = temp->right; 
            }
        }
    }
}

//Deletes the element for the bst
void bst::remove(int number){

    delete_private(root, number);
    printf("Successfully Deleted %d", number);
}

int bst::delete_private(struct node *root, int number){

    int ret;

    if(root == NULL)
        return 0;

    else{

        ret = delete_private(root->left, number);
        if(ret)
            root->left = NULL;

        if(root->data == number){

            if(root->left == NULL && root->right == NULL){

                free(root);
                return 1;
            }

            else if(root->left == NULL && root->right != NULL){

                int swap = root->data;
                root->data = root->right->data;
                root->right->data = swap;

                ret = delete_private(root->right, number);
                if(ret)
                    root->right = NULL;
            }

            else{

                int swap = root->data;
                root->data = root->left->data;
                root->left->data = swap;

                ret = delete_private(root->left, number);
                if(ret)
                    root->left = NULL;
            }
        }

        ret = delete_private(root->right, number);
        if(ret)
            root->right = NULL;
    }
}

//Displays the tree in the preorder format
void bst::preorder(){

    printf("Elements in the tree are: ");
    preorder_private(root);
}

void bst::preorder_private(struct node *root){

    if(root == NULL)
        return;
    
    else{

        printf("%d ", root->data);
        preorder_private(root->left);
        preorder_private(root->right);
    }
}

//Displays the tree in the inorder format
void bst::inorder(){

    printf("Elements in the tree are: ");
    inorder_private(root);
}

void bst::inorder_private(struct node *root){

    if(root == NULL)
        return;
    
    else{

        inorder_private(root->left);
        printf("%d ", root->data);
        inorder_private(root->right);
    }
}

//Displays the tree in the postorder format
void bst::postorder(){

    printf("Elements in the tree are: ");
    postorder_private(root);
}

void bst::postorder_private(struct node *root){

    if(root == NULL)
        return;
    
    else{

        postorder_private(root->left);
        postorder_private(root->right);
        printf("%d ", root->data);
    }
}

// Searches for a number in the tree
void bst::search(int number){

    if(search_private(root, number))
        printf("Found %d in the tree", number);
    
    else
        printf("%d is NOT found in the tree", number);
}

int bst::search_private(struct node *root, int number){

    if(root == NULL)
        return 0;

    else if(root->data == number)
        return 1;

    else{

        if(root->data > number)
            search_private(root->left, number);

        else
            search_private(root->right, number);
    }
}

void menu(){

    printf("\n");
    getchar();
    getchar();
    system("cls");

    printf("1) Insert\n");
    printf("2) Delete\n");
    printf("3) Preorder\n");
    printf("4) Inorder\n");
    printf("5) Postorder\n");
    printf("6) Search\n");
    printf("7) Exit\n");

    printf("Enter: ");
}