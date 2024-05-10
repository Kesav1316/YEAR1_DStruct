#include<stdio.h>
#include<stdlib.h>
class graph
{
    public:
    int *arr1,vertex,i,*varr,*wqueue,*stack,front,rear,cur,top;
    struct node 
    {
        int data;
        struct node *next;
    };
    struct node **arr2;
    graph()
    {
        printf("\nEnter the no of vertexes : ");
        scanf("%d",&vertex);
        arr1=(int*)malloc(vertex*sizeof(int));
        printf("\nNOTE : Do not enter -1");
        printf("\nEnter the vertexes : ");
        for(i=0;i<vertex;i++)
        {
            scanf("%d",&arr1[i]);
        }
        arr2=(struct node**)malloc(vertex*sizeof(struct node));
        for(i=0;i<vertex;i++)
        {
            arr2[i]=NULL;
        }
        wqueue=(int*)malloc(vertex*sizeof(int));
        stack=(int*)malloc(vertex*sizeof(int));
        varr=(int*)malloc(vertex*sizeof(int));
        front=0;
        rear=-1;
        cur=0;
        top=0;
    }
    int insertver(int);
    int insertcon(int,int,int,int);
    int delver(int);
    int delcon(int,int);
    int searchver(struct node*,int);
    int searchcon();
    void disver();
    void discon();
    int searchindex(int);
    void dfs(struct node *);
    void bfs(struct node *);
    void searchcon(int,int);
};
int main()
{
    int ch;
    graph g;
    while(1)
    {
        printf("\n1.Insert vertex\n2.Insert connection\n3.Display vertex\n4.Display connection\n5.Delete connection\n6.Delete vertex\n7.BFS traversal\n8.DFS traversal\n9.Search connection\n10.Search vertex");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                int num;
                printf("\nEnter the vertex : ");
                scanf("%d",&num);
                if(g.insertver(num))
                {
                    printf("\nInserted the vertex successfully");
                }
                else
                {
                    printf("\nCannot be inserted");
                }
                break;
            }
            case 2:
            {
                int num1,num2,index1,index2,i;
                printf("\nEnter the numbers to be connected : ");
                scanf("%d %d",&num1,&num2);
                for(i=0;i<g.vertex;i++)
                {
                    if(g.arr1[i]==num1)
                    {
                        index1=i;
                    }
                    if(g.arr1[i]==num2)
                    {
                        index2=i;
                    }
                }
                if(g.insertcon(index1,index2,num1,num2))
                {
                    printf("\nConnection inserted successfully");
                }
                else
                {
                    printf("\nConnection cannot be inserted");
                }
                break;
            }
            case 3:
            {
                g.disver();
                break;
            }
            case 4:
            {
                g.discon();
                break;
            }
            case 5:
            {
                int num1,num2;
                printf("\nEnter the numbers to be disconnected : ");
                scanf("%d %d",&num1,&num2);
                if(g.delcon(num1,num2))
                {
                    printf("\nDeleted the connection succesfully");
                }
                else
                {
                    printf("\nConnection cannot be deleted");
                }
                break;
            }
            case 6:
            {
                int num;
                printf("\nEnter the vertex to be deleted : ");
                scanf("%d",&num);
                if(g.delver(num))
                {
                    printf("\nDeleted the vertex successfully");
                }
                else
                {
                    printf("\nVertex cannot be deleted");
                }
                break;
            }
            case 7:
            {
                int num,index,i;
                printf("\nEnter the number to start with : ");
                scanf("%d",&num);
                index=g.searchindex(num);
                g.varr[g.cur]=g.arr1[index];
                g.bfs(g.arr2[index]);
                for(i=0;i<=g.cur;i++)
                {
                    printf("%d ",g.varr[i]);
                } 
                break;
            }
            case 8:
            {
                int num,index,i;
                printf("\nEnter the number to start with : ");
                scanf("%d",&num);
                index=g.searchindex(num);
                g.varr[g.cur]=g.arr1[index];
                g.dfs(g.arr2[index]);
                for(i=0;i<=g.cur;i++)
                {
                    printf("%d ",g.varr[i]);
                } 
                break;
            }
            case 9:
            {
                int num1,num2;
                printf("\nEnter two numbers to check for connection : ");
                scanf("%d %d",&num1,&num2);
                g.searchcon(num1,num2);
                break;
            }
            case 11:
            {
                exit(1);
                break;
            }
            case 10:
            {
                int num,index,i,num_search;
                printf("\nEnter the number to start with : ");
                scanf("%d",&num);
                printf("Enter the number to be searched : ");
                scanf("%d",&num_search);
                index=g.searchindex(num);
                g.varr[g.cur]=g.arr1[index];
                if(g.varr[0]==num_search)
                {
                    printf("\nVertex found successfully");
                }
                else
                {
                    if(g.searchver(g.arr2[index],num_search))
                    {
                        printf("\nVertex found successfully");
                    }
                    else
                    {
                        printf("\nVertex cannot be found");
                    }
                }
                break;
            }
        }
        getchar();
        getchar();
    }
    return 0;
}
//Method to insert a vertex
int graph::insertver(int num)
{
    arr1=(int*)realloc(arr1,(vertex+1)*sizeof(int));
    arr1[vertex]=num;
    vertex=vertex+1;
    arr2=(struct node**)realloc(arr2,vertex*sizeof(struct node));
    arr2[vertex-1]=NULL;
    return 1;
}
//Method to insert a connection
int graph::insertcon(int num1,int num2,int d1,int d2)
{
    struct node *newnode1=(struct node*)malloc(sizeof(struct node));
    struct node *newnode2=(struct node*)malloc(sizeof(struct node));
    newnode1->data=d1;
    newnode2->data=d2;
    if(d1!=d2)
    {
        newnode1->next=arr2[num2];
        arr2[num2]=newnode1;
        newnode2->next=arr2[num1];
        arr2[num1]=newnode2;
        return 1;
    }
    else
    {
        newnode1->next=arr2[num2];
        arr2[num2]=newnode1;
        return 1;
    }
}
//Method to display vertexes
void graph::disver()
{
    int i;
    for(i=0;i<vertex;i++)
    {
        if(arr1[i]!=-1)
        {
            printf("%d ",arr1[i]);
        }
    }
}
//Medthod to display connections
void graph::discon()
{
    int i;
    for(i=0;i<vertex;i++)
    {
        printf("\nThe connections of %d are : ",arr1[i]);
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp=arr2[i];
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
//Method to search index of an element
int graph::searchindex(int num)
{
    int i;
    for(i=0;i<=vertex;i++)
    {
        if(arr1[i]==num)
        {
            return i;
        }
    }
    return 0;
}
//Method to delete a connection
int graph::delcon(int num1,int num2)
{
    int index1,index2;
    index1=searchindex(num1);
    index2=searchindex(num2);
    struct node *temp1=arr2[index1];
    struct node *temp2=arr2[index2];
    if(num1!=num2)
    {
        if(temp1->data==num2 && temp2->data==num1)
        {
            arr2[index1]=arr2[index1]->next;
            arr2[index2]=arr2[index2]->next;
            return 1;
        }
        else if(temp1->data==num2 && temp2->data!=num1)
        {
            arr2[index1]=arr2[index1]->next;
            struct node *temp4=(struct node*)malloc(sizeof(struct node));
            while(temp2->next!=NULL)
            {
                if(temp2->next->data==num1)
                {
                    temp4=temp2->next;
                    temp2->next=temp2->next->next;
                    free(temp4);
                    break;
                }
                temp2=temp2->next;
            }
            return 1;
        }
        else if(temp1->data!=num2 && temp2->data==num1)
        {
            arr2[index2]=arr2[index2]->next;
            struct node *temp3=(struct node*)malloc(sizeof(struct node));
            while(temp1->next!=NULL)
            {
                if(temp1->next->data==num2)
                {
                    temp3=temp1->next;
                    temp1->next=temp1->next->next;
                    free(temp3);
                    break;
                }
                temp1=temp1->next;
            }
            return 1;
        }
        else
        {
            struct node *temp3=(struct node*)malloc(sizeof(struct node));
            struct node *temp4=(struct node*)malloc(sizeof(struct node));
            while(temp1->next!=NULL)
            {
                if(temp1->next->data==num2)
                {
                    temp3=temp1->next;
                    temp1->next=temp1->next->next;
                    free(temp3);
                    break;
                }
                temp1=temp1->next;
            }
            while(temp2->next!=NULL)
            {
                if(temp2->next->data==num1)
                {
                    temp4=temp2->next;
                    temp2->next=temp2->next->next;
                    free(temp4);
                    break;
                }
                temp2=temp2->next;
            }
            return 1;
        }
    }
    else
    {
        if(arr2[index1]->data==num1)
        {
            arr2[index1]=arr2[index1]->next;
            return 1;
        }
        else
        {
            struct node *temp5=(struct node*)malloc(sizeof(struct node));
            while(temp1->next!=NULL)
            {
                if(temp1->next->data==num1)
                {
                    temp5=temp1->next;
                    temp1->next=temp1->next->next;
                    free(temp5);
                    break;
                }
            }
            return 1;
        }
    }
}
//Method to delete a vertex
int graph::delver(int num)
{
    int index = searchindex(num);
    for (int i = 0; i < vertex; i++)
    {
        if (arr1[i] != num)
        {
            delcon(arr1[i], num);
        }
    }
    arr1[index] = -1;
    free(arr2[index]);
    arr2[index] = NULL;

    return 1;
}
//Method for Breadth first traversal
void graph::bfs(struct node *temp)
{
    int flagq=0,flagv=0,i,num;
    if(cur==vertex-1)
    {
        return;
    }
    else if(temp==NULL)
    {
        cur++;
        varr[cur]=wqueue[front];
        front++;
        num=searchindex(varr[cur]);
        bfs(arr2[num]);  
    }
    else
    {
        for(i=0;i<=cur;i++)
        {
            if(temp->data==varr[i])
            {
                flagv=1;
                break;
            }
        }
        for(i=front;i<=rear;i++)
        {
            if(temp->data==wqueue[i])
            {
                flagq=1;
                break;
            }
        }
        if(flagq==0 && flagv==0)
        {
            rear++;
            wqueue[rear]=temp->data;
        }
        bfs(temp->next);
    }
}
//Method for depth first traversal
void graph::dfs(struct node *temp)
{
    int flagq=0,flagv=0,i,num;
    if(cur==vertex-1)
    {
        return;
    }
    else if(temp==NULL)
    {
        cur++;
        varr[cur]=stack[top];
        top--;
        num=searchindex(varr[cur]);
        dfs(arr2[num]);  
    }
    else
    {
        for(i=0;i<=cur;i++)
        {
            if(temp->data==varr[i])
            {
                flagv=1;
                break;
            }
        }
        for(i=0;i<=top;i++)
        {
            if(temp->data==stack[i])
            {
                flagq=1;
                break;
            }
        }
        if(flagq==0 && flagv==0)
        {
            top++;
            stack[top]=temp->data;
        }
        dfs(temp->next);
    }
}
//Method to search a connection
void graph::searchcon(int num1,int num2)
{
    int index1,index2,flag1=0,flag2=0;
    index1=searchindex(num1);
    index2=searchindex(num2);
    struct node *temp1=arr2[index1];
    struct node *temp2=arr2[index2];
    while(temp1!=NULL)
    {
        if(temp1->data==num2)
        {
            flag1=1;
            break;
        }
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        if(temp2->data==num1)
        {
            flag2=1;
            break;
        }
        temp2=temp2->next;
    }
    if(flag1==1 && flag2==1)
    {
        printf("\nConnection is found");
    }
    else
    {
        printf("\nConnection is not found");
    }
}
//Method to search a vertex
int graph::searchver(struct node *temp,int nums)
{
    int flagq=0,flagv=0,i,num,s;
    if(cur==vertex-1)
    {
        return 0;
    }
    else if(temp==NULL)
    {
        cur++;
        varr[cur]=wqueue[front];
        front++;
        num=searchindex(varr[cur]);
        if(nums==varr[cur])
        {
            return 1;
        }
        return searchver(arr2[num],nums);
    }
    else
    {
        for(i=0;i<=cur;i++)
        {
            if(temp->data==varr[i])
            {
                flagv=1;
                break;
            }
        }
        for(i=front;i<=rear;i++)
        {
            if(temp->data==wqueue[i])
            {
                flagq=1;
                break;
            }
        }
        if(flagq==0 && flagv==0)
        {
            rear++;
            wqueue[rear]=temp->data;
        }
        s=searchver(temp->next,nums);
        if(s==1)
        {
            return s;
        }
        return 0;
    }
}