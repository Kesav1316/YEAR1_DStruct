#include<stdio.h>
#include<stdlib.h>

class doub
{
   struct Node{
      int data;
      struct Node * next;
      struct Node * prev;
   };
   struct Node * head;
   public:
   doub()
   {
    head = NULL;
   }
   int insbeg(int);
   int append(int);
   void display();
   int inspos(int,int);
   int delbeg();
   int delend();
   int delpos(int);
   int search(int);
};
int main()
{
    doub d1;
    int num,pos,opp;
    while(1)
    {
        printf("\n enter the option\n1.INSBEG\n2.APPEND\n3.DISPLAY\n4.INSPOS\n5.DELBEG\n6.DELEND\n7.DELPOS\n8.SEARCH\n9.EXIT");
        scanf("%d",&opp);
        switch(opp)
        {
            case 1:
            printf("\n enter the numebr");
            scanf("%d",&num);
            if(d1.insbeg(num))
            {
                printf("\n inserted ig");
            }
            else{
                printf("\n spfmig");
            }
            break;
            case 2:
             printf("\n enter the numebr");
            scanf("%d",&num);
            if(d1.append(num))
            {
                printf("\n appended ig");

            }
            else
            {
                printf("\n spfmig");
            }
            break;
            case 3:
            d1.display();
            break;
            case 4:
            printf("\n enter the number");
            scanf("%d",&num);
            printf("\n enter the position");
            scanf("%d",&pos);
            if(d1.inspos(num,pos))
            {
                printf("\n inserted ");
            }
            else{
                printf("\n spfmig");
            }
            break;
            case 5:
            if(d1.delbeg())
            {
                printf("\n deleted");
            }
            else{
                printf("\n not able to delete");
            }
            break;
            case 6:
            if(d1.delend())
            {
                printf("\n deleted");

            }
            else{
                printf("\n not able to delete");
            }
            break;
            case 7:
            printf("\n enter the position");
            scanf("%d",&pos);
            if(d1.delpos(pos))
            {
                printf("\n deleted");
                
            }
            else
            {
                printf("\n not able to delete");
            }
            break;
            case 8:
            printf("\n enter the number to search");
            scanf("%d",&num);
            if(d1.search(num)==num)
            {
                printf("\n the number is present");
            }
            else{
                printf("\n not present");
            }
            break;


            case 9:
            exit(0);
            break;
            default:
            printf("\n enter valid option ig");
            break;

        }
    }
}
int doub::insbeg(int num)
{
    struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
    if(head==NULL)
    {
        newnode->data = num;
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
    }
    else{
        newnode->data = num;
        newnode->next = head;
        newnode -> prev = NULL;
        head = newnode;
    }
    return 1;
}
int doub::append(int num)
{
    struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
    struct Node * temp;
    temp = head;
    if(head==NULL)
    {
         newnode->data = num;
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
    }
    else{
      while(temp->next!=NULL)
      {
        temp = temp->next;
      }
      
      newnode->data = num;
      newnode->prev = temp;
      temp->next = newnode;
      newnode->next = NULL;

    }
    return 1;
}
void doub::display()
{
    struct Node * temp;
    temp = head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
}
int doub::inspos(int num,int pos)
{
    struct Node * newnode = (struct Node * )malloc(sizeof(struct Node));
    struct Node * temp;
    struct Node * temp2;
    temp = head ;
    if(head ==NULL || pos==1) {
        insbeg(num);
    }
    else {
        for(int i = 2; i<pos ; i++)
        {
            temp = temp->next;
        }
        if(temp->next == NULL)
        {
            append(num);
        }
        else {
        temp2 = temp->next;
        temp->next = newnode;
        temp2->prev = newnode;
        newnode->data = num;
        newnode->prev = temp;
        newnode->next  = temp2;
       
        }
    }
    return 1;
}
int doub::delbeg()
{
    struct Node * temp;
    struct Node * temp2;
    if(head==NULL)
    {
        printf("\n The list is empty");
    }
    else{
       temp = head;
       temp2  = temp->next;
       temp2->prev = NULL;
       head = head -> next;
       free(temp);
    }
    return 1;
}
int doub::delend()
{
    struct Node * temp;
    struct Node * temp2;
    temp  = head;
    while(temp->next!=NULL)
    {
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next   = NULL;
    free(temp);
    return 1;
}
int doub::delpos(int pos)
{
    struct Node * temp;
    struct Node * temp2;
    temp = head;
    if(head==NULL)
    {
        printf("\n EMPTY");
    }
    if(pos==1)
    {
        delbeg();
    }
    else{
    for(int i=2;i<pos;i++)
    {
    
    temp = temp->next;
    }
    if(temp->next->next==NULL)
    {
        delend();
    }
    else{
    temp2 = temp->next->next;
    temp->next = temp2;
    temp2->prev = temp;
    }
    }


}
int doub::search( int num)
{
    struct Node * temp;
    temp = head;
    if(head==NULL)
    {
        printf("\n list is empty");
    }
    while(temp!=NULL)
    {
        if(num==temp->data)
        {
            
            return num;
            
        }
        
        else{
            temp = temp->next;
          //  return 0;
        }
    }
    

}