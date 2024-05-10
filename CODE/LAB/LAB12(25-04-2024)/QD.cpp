/*
D. Write a separate C++ menu-driven program to implement Graph ADT with an adjacency list. Maintain proper boundary conditions and follow good coding practices. The Graph ADT has the following operations,

1. Insert
2. Delete
3. Search
4. Display
5. Exit

What is the time complexity of each of the operations? 
*/

#include<stdio.h>
#include<stdlib.h>
#define N 6
class graph {
    
    int adjacencymatrix[N][N];
    int cur;
    public:
    graph() {
        for (int i=0;i<N;i++) {
            for (int j=0;j<N;j++) {
            adjacencymatrix[i][j]=0;
            }
        }
        cur=1;
    }
    int insert (int u,int v);
    void display();
    int del(int v);
    int search(int v);
};

int main() {
    graph g1;
    int choice;
    while(1) {
        printf("\n1) Insert");
        printf("\n2) Delete");
        printf("\n3) Search");
        printf("\n4) Display");
        printf("\n5) Exit");
        printf("\n Enter your choice ");
        scanf("%d",&choice);
        
        switch (choice) {
            case 1:
                int v1,v2;
                printf("Enter the vertex 1:");
                scanf("%d",&v1);
                printf("Enter the vertex 2:");
                scanf("%d",&v2);
                if(g1.insert(v1,v2)) {
                printf("vertex is inserted successfully");
                }
                break;

            case 2:
                int v;
                printf("Enter the vertex to be deleted:");
                scanf("%d",&v);
                if(g1.del(v)) {
                    printf("vertex is deleted successfully");
                }
                else {
                    printf("vertex is not present");
                }
                break;

            case 3:
                int v3;
                printf("Enter the vertex to search");
                scanf("%d",&v3);
                
                if(g1.search(v3)) {
                    printf("vertex is found");
                }
                else {
                    printf("vertex is not found");
                }
                break;

            case 4:
                g1.display();
                break;
            
            case 5:
                printf("PROGRAM ENDED");
                return 0;
        }
    
    }
}

//Method to insert in the graph
//Time complexity => O(n)
int graph:: insert(int v1,int v2) {
    if(cur>=N) {
        printf("Vertex does not exist");
        return 0;
    }
    else  {
        int row=0,col=0;
        for (int i=1;i<=cur;i++) {
            if(adjacencymatrix[0][i]==v1) {
                col=i;
            }
            if(adjacencymatrix[i][0]==v2) {
                row=i;
            }
        for (int i=1;i<=cur;i++) {
            if(adjacencymatrix[0][i]==v2) {
                col=i;
            }
            if(adjacencymatrix[i][0]==v1) {
                row=i;
            }
        }
        if(row!=0 && col!=0) {
            adjacencymatrix[row][col]=1;
            adjacencymatrix[col][row]=1;
            return 1;
        }
        else if(row!= 0 && col==0|| row==0 && col!=0) {
            printf("Please provide a valid vertex");
            return 0;
        }
        
        else {
            adjacencymatrix[0][cur]=v1;
            adjacencymatrix[0][cur+1]=v2;
            adjacencymatrix[cur][0]=v1;
            adjacencymatrix[cur+1][0]=v2;
            adjacencymatrix[cur][cur+1]=1;
            adjacencymatrix[cur+1][cur]=1;
            cur+=2;
            return 1;
        }
    }
}
}

//Method to display in the graph
//Time complexity => O(n)
void graph::display() {
    for (int i=0;i<cur;i++) {
        for (int j=0;j<cur;j++) {
            printf("%d\t",adjacencymatrix[i][j]);
        }
        printf("\n");
    }
}

//Method to delete in the graph
//Time complexity => O(n)
int graph:: del(int v) {
    if(cur==1) {
        printf("The matrix is empty already");
        return 0;
    }
    for (int i=1;i<=cur;i++) {
        if(adjacencymatrix[0][i]==v) {
            for (int j=i;j<=cur;j++) {
                adjacencymatrix[0][j]=adjacencymatrix[0][j+1];
            }
        }
        if(adjacencymatrix[i][0]==v) {
            for(int j=i;j<=cur;j++) {
                adjacencymatrix[j][0]=adjacencymatrix[j+1][0];
            }
            cur--;
        }
    }
    return 1;
}

//Method to search in the graph
//Time complexity => O(n)
int graph:: search(int v) {
    for (int i=1;i<=cur;i++) {
        if(adjacencymatrix[0][i]==v) {
            return 1;
        }
    }
    return 0;
}

