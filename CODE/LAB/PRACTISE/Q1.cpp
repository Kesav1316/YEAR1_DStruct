/*
Tree ADT using a character binary tree. Linked List
*/

#include <stdio.h>
#include <stdlib.h>

void menu();
void left_or_right();

class bintree{

    struct node{

        struct node *left;
        char data;
        struct node *right;
    };
    
    struct node *root;
    int delete_private(struct node *, char);
    void preorder_private(struct node *);
    void inorder_private(struct node *);
    void postorder_private(struct node *);
    void search_private(struct node*, char);

    public:
        bintree(){

            root = NULL;
        }

        void insert(char);
        void remove(char);
        void preorder();
        void inorder();
        void postorder();
        void search(char);
};

int main(){

    bintree tree1;
    int choice;
    char data;

    while(1){

        menu();
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("Enter the character: ");
                scanf(" %c", &data);

                tree1.insert(data);

                break;

            case 2:
                printf("Enter the character: ");
                scanf(" %c", &data);

                tree1.remove(data);
                break;

            case 3:
                printf("Elements in the tree are: ");

                tree1.preorder();
                break;

            case 4:
                printf("Elements in the tree are: ");
                
                tree1.inorder();
                break;

            case 5:
                printf("Elements in the tree are: ");

                tree1.postorder();
                break;

            case 6:
                printf("Enter the character: ");
                scanf(" %c", &data);

                tree1.search(data);
                break;

            case 7:
                printf("Exited !\n");
                return 0;

            default:
                printf("Invalid Choice");
                break;
        }
    }

    return 0;
}

//Inserts data to a user guided position
void bintree::insert(char character){

    struct node *new_node = (struct node *) malloc(sizeof(struct node));

    new_node->data = character;
    new_node->left = NULL;
    new_node->right = NULL;

    if(root == NULL){
        
        root = new_node;
        printf("Inserted Successfully");
    }
    
    else{

        struct node *temp = root;
        int choice;

        while(temp){
            
            system("cls");

            left_or_right();
            scanf("%d", &choice);

            if(choice == 1){

                if(temp->left == NULL){

                    temp->left = new_node;
                    temp = new_node;
                    printf("Inserted Successfully");
                }

                temp = temp->left;
            }

            else if(choice == 2){
                
                if(temp->right == NULL){

                    temp->right = new_node;
                    temp = NULL;
                    printf("Inserted Successfully");
                }

                else
                    temp = temp->right;
    
            }

            else
                printf("Invalid Choice\n");
        }
    }
}

//Deletes all the occurance of the element from the tree
void bintree::remove(char character){

    delete_private(root, character);
    printf("Successfully deleted %c", character);
}

//Actually deletes the element from the tree
int bintree::delete_private(struct node *root, char character){

    int ret;

    if(root == NULL)
        return 0;

    else{

        ret = delete_private(root->left, character);
        if(ret)
            root->left = NULL;

        if(root->data == character){

            if(root->left == NULL && root->right == NULL){

                free(root);
                return 1;
            }

            else if(root->left == NULL && root->right != NULL){

                int swap = root->data;
                root->data = root->right->data;
                root->right->data = swap;

                ret = delete_private(root->right, character);
                if(ret)
                    root->right = NULL;
            }

            else{

                int swap = root->data;
                root->data = root->left->data;
                root->left->data = swap;

                ret = delete_private(root->left, character);
                if(ret)
                    root->left = NULL;
            }
        }

        ret = delete_private(root->right, character);
        if(ret)
            root->right = NULL;
    }
}

//Prints the tree in inorder format
void bintree::inorder(){

    inorder_private(root);
}

// Actually prints the tree in inorder format
void bintree::inorder_private(struct node *root){

    if(root == NULL)
        return;

    else{

        inorder_private(root->left);
        printf("%c ", root->data);
        inorder_private(root->right);
    }
}

//Prints the tree in preorder format
void bintree::preorder(){

    preorder_private(root);
}

//Actually prints the tree in preorder format
void bintree::preorder_private(struct node *root){

    if(root == NULL)
        return;

    else{

        printf("%c ", root->data);
        preorder_private(root->left);
        preorder_private(root->right);
    }
}

//Prints the tree in postorder format
void bintree::postorder(){

    postorder_private(root);
}

//Actually prints the tree in postorder format
void bintree::postorder_private(struct node *root){

    if(root == NULL)
        return;

    else{

        postorder_private(root->left);
        postorder_private(root->right);
        printf("%c ", root->data);
    }
}

//Prints the tree in inorder format
void bintree::search(char character){

    search_private(root, character);
}

// Actually prints the tree in inorder format
void bintree::search_private(struct node *root, char character){

    if(root == NULL)
        return;

    if(root->data == character){

        printf("Found !");
    }
    else{

        search_private(root->left, character);
        search_private(root->right, character);

        return;
    }
}

void menu(){

    printf("\n");
    getchar();
    getchar();
    system("cls");

    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Preorder\n");
    printf("4. Inorder\n");
    printf("5. Postorder\n");
    printf("6. Search\n");
    printf("7. Exit\n");
    printf("Enter: ");
}

void left_or_right(){

    printf("1) Left\n");
    printf("2) Right\n");
    printf("Enter: ");
}