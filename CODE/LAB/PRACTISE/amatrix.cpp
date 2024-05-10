#include<stdio.h>
#include<stdlib.h>
class amatrix 
{
    public:
    int *arr1,**arr2,vertex,i,j,*varr,*wqueue,front,rear,cur,*stack,top;
    amatrix()
    {
        printf("\nEnter the no of vertex : ");
        scanf("%d",&vertex);
        arr1=(int*)malloc(vertex*sizeof(int));
        arr2=(int**)malloc(vertex*sizeof(int *));
        for(i=0;i<vertex;i++)
        {
            arr2[i]=(int*)malloc(vertex*sizeof(int));
        }
        printf("\nNOTE : Do not enter -1");
        printf("\nEnter the vertexes : ");
        for(i=0;i<vertex;i++)
        {
            scanf("%d",&arr1[i]);
        }
        for(i=0;i<vertex;i++)
        {
            for(j=0;j<vertex;j++)
            {
                arr2[i][j]=0;
            }
        }
        wqueue=(int*)malloc(vertex*sizeof(int));
        varr=(int*)malloc(vertex*sizeof(int));
        stack=(int*)malloc(vertex*sizeof(int));
        front=0;
        rear=-1;
        cur=0;
        top=0;
    }
    int insert(int,int);
    int deletioncon(int,int);
    int deletionver(int,int);
    int search(int,int,int);
    void displayver(int);
    void displaycon(int);
    int insertver(int);
    int searchcon(int,int);
    int searchindex(int);
    void bfs(int,int);
    void dfs(int,int);
};
int main()
{
    amatrix a;
    int ch,i,j,temp;
    while(1)
    {
        system("cls");
        printf("\n1.Insert vertex\n2.Insert a connection\n3.Deletion of an edge\n4.Deletion of a vertex\n5.Search Vertex\n6.Search Connection\n7.Display vertex\n8.Display connection\n9.Birth First traversal\n10.Depth First traversal\n11.Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                int num;
                printf("Enter the vertex to insert : ");
                scanf("%d",&num);
                if(a.insertver(num))
                {
                    printf("\nInserted the vertex succesfully");
                }
                else
                {
                    printf("\nCannot insert a vertex");
                }
                break;
            }
            case 2:
            {
                int num1,num2;
                printf("\nEnter two numbers to be connected : ");
                scanf("%d %d",&num1,&num2);
                for(i=0;i<a.vertex;i++)
                {
                    if(a.arr1[i]==num1)
                    {
                        num1=i;
                    }
                    if(a.arr1[i]==num2)
                    {
                        num2=i;
                    }
                }
                if(a.insert(num1,num2))
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
                int num1,num2;
                printf("\nEnter two numbers to delete the connections : ");
                scanf("%d %d",&num1,&num2);
                for(i=0;i<a.vertex;i++)
                {
                    if(a.arr1[i]==num1)
                    {
                        num1=i;
                    }
                    if(a.arr1[i]==num2)
                    {
                        num2=i;
                    }
                }
                if(a.deletioncon(num1,num2))
                {
                    printf("\nConnection deleted successfully");
                }
                else
                {
                    printf("\nConnection cannot be deleted");
                }
                break;
            }
            case 4:
            {
                int num;
                printf("\nEnter the vertex to be deleted : ");
                scanf("%d",&num);
                for(i=0;i<a.vertex;i++)
                {
                    if(a.arr1[i]==num)
                    {
                        num=i;
                    }
                }
                if(a.deletionver(num,a.vertex))
                {
                    printf("\nVertex deleted successfully");
                }
                else
                {
                    printf("\nVertex cannot be deleted");
                }
                break;
            }
            case 7:
            {
                a.displayver(a.vertex);
                break;
            }
            case 8:
            {
                a.displaycon(a.vertex);
                break;
            }
            case 5:
            {
                int num,nums,index;
                printf("\nEnter the vertex to be searched : ");
                scanf("%d",&num);
                printf("\nEnter the number to start with : ");
                scanf("%d",&nums);
                index=a.searchindex(nums);
                if(a.search(index,0,num))
                {
                    printf("\nData found");
                }
                else
                {
                    printf("\nData cannot be found");
                }
                break;
            }
            case 6:
            {
                int num1,num2;
                printf("\nEnter the numbers to be search for their connection : ");
                scanf("%d %d",&num1,&num2);
                if(a.searchcon(num1,num2))
                {
                    printf("\nConnection found");
                }
                else
                {
                    printf("\nConnection cannot be found");
                }
                break;
            }
            case 11:
            {
                exit(1);
                break;
            }
            case 9:
            {
                int num,index,i;
                printf("\nEnter the element to start with : ");
                scanf("%d",&num);
                a.varr[a.cur]=num;
                index=a.searchindex(num);
                a.bfs(index,0);
                for(i=0;i<=a.cur;i++)
                {
                    printf("%d ",a.varr[i]);
                }
                break;
            }
            case 10:
            {
                int num,index,i;
                printf("\nEnter the element to start with : ");
                scanf("%d",&num);
                a.cur=0;
                a.varr[a.cur]=num;
                index=a.searchindex(num);
                a.dfs(index,0);
                for(i=0;i<=a.cur;i++)
                {
                    printf("%d ",a.varr[i]);
                }
                break;
            }
        }
        getchar();
        getchar();
    }
    return 0;
}
//Method to insert a connection
int amatrix::insert(int num1, int num2)
{
    if (num1 >= vertex || num2 >= vertex || num1 < 0 || num2 < 0) 
    {
        return 0;
    }

    // Update connections for the new vertex
    arr2[num1][num2] = 1;
    arr2[num2][num1] = 1;

    return 1;
}
//Method to delete a connection
int amatrix::deletioncon(int num1,int num2)
{
    arr2[num1][num2]=0;
    arr2[num2][num1]=0;
    return 1;
}
//Method to delete a vertex 
int amatrix::deletionver(int num,int vertex)
{
    arr1[num]=-1;
    for(i=0;i<vertex;i++)
    {
        arr2[i][num]=0;
        arr2[num][i]=0;
    }   
}
//Method to display the vertexes
void amatrix::displayver(int num)
{
    int i;
    for(i=0;i<num;i++)
    {
        if(arr1[i]!=-1)
        {
            printf("%d ",arr1[i]);
        }
    }
}
//Method to disply the connections
void amatrix::displaycon(int num)
{
    int i,j;
    for(i=0;i<num;i++)
    {
        if(arr1[i]!=-1)
        {
            printf("\nConnections of %d : ",arr1[i]);
            for(j=0;j<num;j++)
            {
                if(arr2[i][j]==1)
                {
                    printf("%d",arr1[j]);
                }
            }
        }
    }
}
//Method to search a vertex 
int amatrix::search(int indexx, int indexy, int nums) 
{
    int flagq = 0, flagv = 0, i, num, s;
    if (cur == vertex - 1) 
    {
        return 0;
    } 
    else if (indexy == vertex) 
    {
        cur++;
        varr[cur] = wqueue[front];
        front++;
        num = searchindex(varr[cur]);
        indexx = num;
        indexy = 0;
        if (nums == varr[cur]) 
        {
            return 1;
        }
        return search(indexx, indexy, nums);  // Return the result of the recursive call
    } 
    else 
    {
        if (arr2[indexx][indexy] == 1) 
        {
            for (i = 0; i <= cur; i++) 
            {
                if (arr1[indexy] == varr[i]) 
                {
                    flagv = 1;
                    break;
                }
            }
            for (i = front; i <= rear; i++) 
            {
                if (arr1[indexy] == wqueue[i]) 
                {
                    flagq = 1;
                    break;
                }
            }
            if (flagq == 0 && flagv == 0) 
            {
                rear++;
                wqueue[rear] = arr1[indexy];
            }
        }
        s = search(indexx, indexy + 1, nums);  // Recursive call
        if (s == 1) 
        {
            return s;  // Return the result if data is found
        }
        return 0;  // Otherwise, return 0
    }
}
//Method to insert a vertex 
int amatrix::insertver(int num)
{
    int *new_arr1=(int*)realloc(arr1,(vertex+1)*sizeof(int));
    arr1=new_arr1;
    int **new_arr2=(int**)realloc(arr2,(vertex+1)*sizeof(int*));
    arr2=new_arr2;
    int *new_queue=(int*)realloc(wqueue,(vertex+1)*sizeof(int));
    wqueue=new_queue;
    int *new_varr=(int*)realloc(varr,(vertex+1)*sizeof(int));
    varr=new_varr;
    vertex=vertex+1;
    arr1[vertex-1]=num;
    arr2[vertex-1]=(int*)malloc(vertex*sizeof(int));
    for(int i=0;i<vertex;i++)
    {
        arr2[vertex-1][i]=0;
        arr2[i][vertex-1]=0;
    }
    return 1;
}
//Method to search a connection
int amatrix::searchcon(int num1,int num2)
{
    int i;
    for(i=0;i<vertex;i++)
    {
        if(arr1[i]==num1)
        {
            num1=i;
        }
        if(arr1[i]==num2)
        {
            num2=i;
        }
    }
    if(arr2[num1][num2]==1 && arr2[num2][num1]==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//Method to search for index of an element 
int amatrix::searchindex(int num)
{
    int i;
    for(i=0;i<vertex;i++)
    {
        if(arr1[i]==num)
        {
            return i;
        }
    }
    return 0;
}
//Method for Breadth First traversal
void amatrix::bfs(int indexx,int indexy)
{
    int flagq=0,flagv=0,i,num;
    if(cur==vertex-1)
    {
        return;
    }
    else if(indexy==vertex)
    {
        cur++;
        varr[cur]=wqueue[front];
        front++;
        num=searchindex(varr[cur]);
        indexx=num;
        indexy=0;
        bfs(indexx,indexy);  
    }
    else
    {
        if(arr2[indexx][indexy]==1)
        {
            for(i=0;i<=cur;i++)
            {
                if(arr1[indexy]==varr[i])
                {
                    flagv=1;
                    break;
                }
            }
            for(i=front;i<=rear;i++)
            {
                if(arr1[indexy]==wqueue[i])
                {
                    flagq=1;
                    break;
                }
            }
            if(flagq==0 && flagv==0)
            {
                rear++;
                wqueue[rear]=arr1[indexy];
            }
        }
        bfs(indexx,indexy+1);
    }
}
//Method for Depth First Traversal
void amatrix::dfs(int indexx,int indexy)
{
    int flagq=0,flagv=0,i,num;
    if(cur==vertex-1)
    {
        return;
    }
    else if(indexy==vertex)
    {
        cur++;
        varr[cur]=stack[top];
        top--;
        num=searchindex(varr[cur]);
        indexx=num;
        indexy=0;
        dfs(indexx,indexy);  
    }
    else
    {
        if(arr2[indexx][indexy]==1)
        {
            for(i=0;i<=cur;i++)
            {
                if(arr1[indexy]==varr[i])
                {
                    flagv=1;
                    break;
                }
            }
            for(i=0;i<=top;i++)
            {
                if(arr1[indexy]==stack[i])
                {
                    flagq=1;
                    break;
                }
            }
            if(flagq==0 && flagv==0)
            {
                top++;
                stack[top]=arr1[indexy];
            }
        }
        dfs(indexx,indexy+1);
    }
}