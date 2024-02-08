//1. Write a C++ menu driven program to implement List ADT using arrays. Maintain proper boundary conditions and follow good coding practices.
//LIST ADT : INSERTION , SEARCH , DELETION , TRAVERSAL
//Program to implement List ADT using arrays

#include<stdio.h>
#include <stdlib.h>
#define SIZE 5
class List {
    int cur; //ALWAYS KEEP IT PRIVATE (DATA HIDING)
    int arr[SIZE];
    public:
        List() { //CONSTRUCTOR (AUTOMATICALLY CALLS THE FUNCTION)
        cur = -1; //ONLY THIS MEMBER CAN ACCESS PRIVATE MEMBER
        }
        //FUNCTIONS INSIDE CLASS ACTS AS FUNCTION METHODS(EX: list.append())
        int insertbeg(int); //int as it will return 0 and 1
        void display();
};

int main(){
    int choice;
    List l1; // SYNTAX : 
    while(1) {
        int choice,num,flag;
        //system("cls"); CLEARS THE PREVIOUS SCREEN
        //getchar(); DISPLAYS DEFAULT MESSAGE 
        printf("\nEnter a  choice\n1.Insert Begin\n2.Append\n3.Insert Index\n");
        printf("4.Delete Begin\n5.Delete End\n6.Delete Position");
        printf("\n7.Search\n8.Display\n");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("\n Enter a number to insert ");
                scanf("%d",&num); //SCANF ALWAYS IN MAIN FUNCTION
                flag = l1.insertbeg(num); // 0 OR 1
                if (flag) {
                    printf("The number %d is successfully inserted",num);
                }

                else {
                    printf("Failed to insert %d List is full",num);
                }
                break;
            case 8:
                l1.display();
                break;
            default:
                printf("invalid choice try again");
            break;
        }

    }
    return 0;
}
//METHOD TO INSERT AN ELEMENT IN THE BEGINNING OF A LIST
int List::insertbeg(int num) {
    if (List::cur == SIZE-1) {
        printf("\n%d\n",List::cur);
        return 0;
    }
    else if(List::cur == -1) {
        printf("\n%d\n",List::cur);
        List::cur = 0;
        arr[0] = num;
        return 1;
    }
    else { //BEGINNING IS OCCUPIED 
        printf("\n%d\n",cur);
        for(int i = cur ; i >= 0 ; i--) { //ALWAYS START FROM BOUNDARY CONDITIONS
            arr[i+1] = arr[i];
        }
        arr[0] = num;
        cur++;
        return 1;

    }
}

//METHOD TO DISPLAY THE CONTENTS OF THE LIST
void List::display() {
    printf("\nThe elements in the list are ");
    for( int i = 0 ; i < cur ; i ++ ) {
        printf("%d ",arr[i]);
    }
}
