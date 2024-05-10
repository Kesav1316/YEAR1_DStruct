#include <stdio.h>
#include <stdlib.h>
class List {
    struct Node {
        struct Node * next;
        int data;
    };

    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *head = NULL;

    public:
        List() {
            head = NULL;
        }
        int insertbeg(int num);
};

int main() {
    List l1;
    int choice;
    int num;
    printf("Enter the choice ");
    scanf("%d",&choice);

    switch(choice) {
        case 1:
            printf("Enter the value of num ");
            scanf("%d",&num);

            if(l1.insertbeg(num)) {
                printf("Successful");
            }
            break;

    }

}

int List::insertbeg(int num) {
    printf("%d",num);
    return 1;
}