#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
class stackadt
{
    private:
    struct node
    {
        char data;
        struct node *next;
    };
    struct node *head;
    public:
    stackadt()
    { 
        head=NULL;
    }
    int push(char val);
    char pop(void);
    int empty(void);
    char peek(void);
    void display();
};
int main()
{
    char string[100];
    int choice;
    stackadt stack1,stack2;
    while(true)
    {
    printf("\nMENU");
    printf("\n1.ENTER THE TEXT");
    printf("\n2.DISPLAY THE OUTPUT");
    printf("\n3.EXIT");
    printf("\nEnter the choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
            printf("\nEnter the text:");
            scanf("%s",string);
            for(int i=0;string[i]!='\0';i++)
            {
                stack1.push(string[i]);
            }
            printf("\nSUCCESSFULLY INSERTED");
            break;
        }
        case 2:
        {
            while(stack1.empty()!=1)
            {
                int count=1;
                char s=stack1.pop();
                if (s!='+')
                {
                    stack2.push(s);
                }
                else
                {
                    while(stack1.peek()=='+')
                    {
                        stack1.pop();
                        count++;
                    }
                    while(count>0)
                    {
                        stack1.pop();
                        count--;
                    }
                }
            }
            printf("The output is:");
            stack2.display();
            break;
        }
        case 3:
        printf("EXITTING...........");
        break;
    }
    }
}
//METHOD TO CHECK IF THE STACK IS EMPTY
int stackadt::empty()
{
    if(head==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//TIME COMPEXITY O(1)
// FUNCTION FOR PUSHING THE ELEMENT
int stackadt::push(char data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(empty()==1)
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
    return 1;
}
//TIME COMPLEXITY O(1)
//METHOD FOR POPING THE ELEMENT OUT OF THE STACK
char stackadt::pop()
{
    if(empty()==1)
    {
        return 'a';
    }
    else
    {
        struct node *temp=head;
        char b=head->data;
        head=temp->next;
        return b;
    }  
}
//TIME COMPEXITY O(1)
//METHOD FOR PEEK IN THE STACK
char stackadt::peek()
{
    if(empty()==0)
    {
        return head->data;
    }
    else
    {
        return 'z';
    }
}
//METHOD FOR DISPLAYING THE LIST
//TIME COMPLEXITY : O(n)
void stackadt::display()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("The list is empty");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%c",temp->data);
            temp=temp->next;
        }
    }
}