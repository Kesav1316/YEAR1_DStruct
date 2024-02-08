//Array implementation of List ADT
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
class List
{
    int arr[SIZE];
    int cur;
    public:
        List()
        {
            cur = -1;
        }
        int insertbeg(int);
        void display();
        int append(int);
        int insertpos(int,int);
        int deletebeg();
        int pop();
        int deletepos(int);
        int search(int);
};

int main()
{
    List l1;
    int choice, num;
    int app;
    while (1)
    {
        //getchar();
        //getchar();
        //system("clear");
        printf("\nEnter \n1. Insert Begin\n2. Append\n3. Insert Position");
        printf("\n4. Delete Begin\n5. Pop\n6. Delete Position");
        printf("\n7. Search\n8. Display\n9. Exit");
        printf("\n Enter a choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter the number insert:");
            scanf("%d",&num);
            if(l1.insertbeg(num))
            {
                printf("\n %d successfully inserted.",num);
            }
            else
            {
                printf("\n Failed to insert %d. The list is full",num);
            }
            break;
        case 2:
            printf("\n Enter the number to append");
            scanf("%d",&app);
            if(l1.append(app)) {
                printf("\n %d SUCCESSFULLY APPENDED ",app);
            }
            else {
                printf("Failed to append");
            }
            break;
        
        case 3:
            int num;
            int pos;
            printf("\n Enter the number to insert and its position ");
            scanf("%d %d",&num,&pos);
            if(l1.insertpos(num,pos)) {
                printf("Sucessfully inserted %d",num);
            }
            else{
                printf("Empty in middle or position greater than size");
            }
            break;
        case 4:
            if(l1.deletebeg()) {
                printf("Successfully deleted");
            }
            else {
                printf("Empty list");
            }
            break;
        
        case 5:
            if(l1.pop()) {
                printf("Successfully poped");
            }
            else {
                printf("Empty list");
            }
            break;

        case 6:
            int position;
            printf("Enter the position of the list to delete ");
            scanf("%d",&position);
            if(l1.deletepos(position)) {
                printf("Sucessfully deleted");
            }
            else if(l1.deletepos(position) == 2) {
                printf("The position is empty");
            }
            else {
                printf("List empty");
            }
            break;

        case 7:
            int searchelement;
            printf("Enter the element to search in the list ");
            scanf("%d",&searchelement);
            if(!l1.search(searchelement)) {
                printf("Not Found");
            }
            break;
        case 8:
            l1.display();
            break;
        
        case 9:
            exit(0);
            break;
        default:
            printf("\n Enter a valid choice\n");
            break;
        }

    }
    return 0;
}

//Method to insert a number in begining of the list
int List::insertbeg(int num)
{
    if(cur==SIZE-1)
    {
        return 0;
    }
    else if(cur==-1)
    {
        cur = 0;
        arr[0]=num;
        return 1;
    }
    else
    {
        for(int i=cur;i>=0;i--)
        {
            arr[i+1]=arr[i];
        }
        cur = cur + 1;
        arr[0]=num;
        return 1;

    }
}
//Method to append a number to last of the list
int List::append(int num) {
    if(cur == SIZE-1) {
        return 0;
    }
    else if (cur == -1) {
        cur = 0;
        arr[0] = num;
        return 1;
    }
    else {
        cur = cur + 1;
        arr[cur] = num;
        return 1;
        
    }
}
//Method to insert a value in its position and shifting the previous values to the right
int List::insertpos(int num , int pos) {
    if(pos > cur + 1 || pos > SIZE) {
        return 0;
    }
    else if(cur == -1 && pos == 0){
        cur = 0;
        arr[0] = num;
        return 1;
    }
    else {
        for(int i=cur;i>=pos;i--){
            arr[i+1]=arr[i];
        }
        cur = cur + 1;
        arr[pos]=num;
        return 1;
        
    }
}

//Method to delete the beginning value
int List::deletebeg() {
    if(cur == -1) {
        return 0; // LIST EMPTY
    }
    else {
        for(int i = 0;i <cur + 1 ; i++) {
            arr[i] = arr[i+1];

        }
        cur = cur - 1;
        return 1;

    }
}

//Method to pop the last element
int List::pop() {
    if (cur == -1) {
        return 0;
    }
    else {
        arr[cur] = NULL;
        cur = cur - 1;

    }
}

//Method to delete element in the position of the list
int List::deletepos(int pos) {
    if (cur == -1 || pos > cur) {
        return 0;
    }
    else {
        for( int i = pos + 1 ; i < cur + 1; i++ ) {
            arr[i] = arr[i+1];
        }
        cur = cur - 1;
        return 1;
    }
}

//Method to search for the element in the list
int List::search(int searchelement) {
    for(int i = 0 ; i< (cur + 1) ; i++) {
        if(arr[i] == searchelement) {
            printf("The element %d is found in the %d position",searchelement,i);
            return 1;
        }
    }
    return 0;
}

//Method to display the contents of the list
void List::display() {
{
    printf("\nThe contents of the list are:");
    for(int i=0;i<=cur;i++)
    {
        printf("%d ",arr[i]);
    }
}





}
