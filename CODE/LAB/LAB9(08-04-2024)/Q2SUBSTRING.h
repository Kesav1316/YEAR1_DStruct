/*
B. A substring is a contiguous sequence of characters in a string. An ideal sub-string has a length of 3 with no repeating characters. Identify the optimal ADT and data structure to count the ideal number of substrings given a string of length 'n'. Multiple occurrences of a substring can be counted. 
*/
#include <stdio.h>
#include <stdlib.h>

class List{
    private:
        struct Node{
            char data;
            struct Node *Next;
        };
        
        struct Node *Head;
        struct Node *Tail;
        struct Node *CurrentPoint;
        struct Node *NewNode;
    public:
        struct First3{
            char F,M,L;
        };
        struct First3 *val;
        List(){
            val = (struct First3*)malloc(sizeof(struct First3));
            Head = nullptr;
        }
        struct First3 *firstThree();
        struct Node *CreateNode();
        void DeleteNode(struct Node *);
        int IsEmpty();
        int Insert_Beg_Node(char);
        int Append_Node(char);
        int Insert_Pos_Node(char,int);
        int Delete_Beg_Node();
        int Pop_Node();
        int Delete_Pos_Node(int);
        void Display();
        char DisplayFront();
        void recursiveDisp(struct Node *);
        void Rev_Display();
        void recrev(struct Node *);
        void recrev1();
};

//Function to reate new node
struct List::Node * List::CreateNode(){
    return (struct Node *)malloc(sizeof(struct Node));
}

//Function to delete node
void List::DeleteNode(struct Node *del){
    free(del);
}

//Function to check if the list is empty
int List::IsEmpty(){
    if (Head==nullptr){
        return 1;
    }
    else{
        return 0;
    }
    
}

//Function to insert node in the beginning
int List::Insert_Beg_Node(char val){
    NewNode = CreateNode();
    NewNode->data = val;
    NewNode->Next = Head;

    if(Head==nullptr) {
        Tail=NewNode;
    }
    Head = NewNode;
    return 1;
}

//Function to insert node in the end
int List::Append_Node(char val){
    if(IsEmpty()==0){
        NewNode = CreateNode();
        NewNode->data = val;
        NewNode->Next = nullptr;
        Tail->Next = NewNode;
        Tail=NewNode;
        return 1;
    }
    else {
        Insert_Beg_Node(val);
        return 1;
    }
    return 0;
}

//Function to insert node in the position
int List::Insert_Pos_Node(char val ,int pos){
    if(pos == 0){
        Insert_Beg_Node(val);
        return 1;
    }
    if(IsEmpty()==0){
        pos--;

        CurrentPoint = Head;
        while(pos >0){
            CurrentPoint = CurrentPoint->Next;
            pos--;
        }
        printf("%d",CurrentPoint->data);
        NewNode = CreateNode();
        NewNode->data = val;
        NewNode->Next = CurrentPoint->Next;
        CurrentPoint->Next = NewNode;
        return 1;
    }return 0;
}

//Function to delete node in the beginning
int List::Delete_Beg_Node(){
    if(IsEmpty()==0){
        CurrentPoint = Head;
        Head = CurrentPoint->Next;
        DeleteNode(CurrentPoint);
        return 1;

    }else{
        return 0;
    }
}

//Function to delete node in the end
int List::Pop_Node(){
    if(IsEmpty()==0){
        CurrentPoint = Head;
        NewNode = Head;
        while(CurrentPoint->Next != nullptr){
            NewNode = CurrentPoint;
            CurrentPoint = CurrentPoint->Next;
        }
        NewNode->Next = nullptr;
        DeleteNode(CurrentPoint);
        return 1;
    }else{
        return 0;
    }
}

//Function to delete node in the position
int List::Delete_Pos_Node(int pos){
    if(pos == 0){
        Delete_Beg_Node();
        return 1;
    }
    if(IsEmpty()==0){
        CurrentPoint = Head;
        NewNode = Head;
        while((CurrentPoint->Next != nullptr) && (pos>0)){
            pos--;
            NewNode = CurrentPoint;
            CurrentPoint = CurrentPoint->Next;
        }
        if(pos>0){
            return 0;
        }else{
            NewNode->Next = CurrentPoint->Next;
            DeleteNode(CurrentPoint);
            return 1;
        }
    }
    return 0;
}


//Display the contents of the List
void List::Display(){
    if(IsEmpty()==0){
        CurrentPoint = Head;
        printf("[");
        while(CurrentPoint->Next != nullptr){
            printf("%c,",CurrentPoint->data);
            CurrentPoint = CurrentPoint->Next;
        }
        printf("%c]",CurrentPoint->data);
    }else{
        printf("[]");
    }
}

char List::DisplayFront(){
    if(Head==nullptr){
        return '~';
    }
    return Head->data;
}

//Function to display recursively
void List::recursiveDisp(struct Node *NextNode){
    if(NextNode->Next==nullptr){
        printf("[%c,",NextNode->data);
    }else{
        char val = NextNode->data;
        recursiveDisp(NextNode->Next);
        printf("%c,",val);
    }
}

//Function to display the reverse list
void List::Rev_Display(){
    if(IsEmpty()==0){
        recursiveDisp(Head->Next);
        printf("%c]",Head->data);
    }else{
        printf("[]");
    }
}

//Function to reverse using recursion
void List::recrev(struct Node *NextNode){
    if(NextNode->Next == nullptr){
        Head = NextNode;
    }else{
        recrev(NextNode->Next);
        NextNode->Next->Next = NextNode;
        NextNode->Next = nullptr;
    }
}

void List::recrev1(){
    if(IsEmpty()==0){
        recrev(Head);
    }
}

struct List::First3 *List::firstThree(){
    if(Head!=nullptr && Head->Next !=nullptr && Head->Next->Next != nullptr){
        val->F = Head->data;
        val->M = Head->Next->data;
        val->L = Head->Next->Next->data;
        return val;
    }
    return nullptr;
}
