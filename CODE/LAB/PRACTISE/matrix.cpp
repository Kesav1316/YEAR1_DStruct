#include <stdio.h>
#include <stdlib.h>

class List {
    int arr[100];
    int matrix[5][5];
    int cur;

    public:
        List() {
            cur = -1;
            for(int i = 0 ; i < 5 ; i++) {
                for(int j = 0 ; j < 5 ; j++) {
                    matrix[i][j] = -1;
                }
            }
        }
    
    void insert( int , int );
    void display();

};

int main() {
    List l1;
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
                l1.insert(v1,v2);
                break;
            
            case 4:
                l1.display();
}

    }

}

void List::insert(int v1 , int v2) {
    int u1;
    int u2;
    int cur;
    int c;
    c = 1;
    int c2;
    c2 = 1;

    int i1;

    int i2;

    if(cur == -1) {
        arr[0] = v1;
        arr[1] = v2;
        cur = 1;
    }
    
    else {
        for(int i = 0 ; i < 5 ; i++ ) {
            if(arr[i] == v1) {
                c = 0;
                break;
            }
        }
        if(c == 1) {
            cur = cur + 1;
            arr[cur] = v1;
        }

        for(int i = 0 ; i < 5 ; i++ ) {
            if(arr[i] == v2) {
                c2 = 0;
                break;
            }
        }
        if(c2 == 1) {
            cur = cur + 1;
            arr[cur] = v2;
        }
    }


    for(int i = 0 ; i < 5 ; i++) {
        if(arr[i] == v1) {
            i1 = i;
        }

        if(arr[i] == v2) {
            i2 = i;
        }
    }
    printf("%d",i1);
    printf("%d",i2);
}

void List::display() {
    for(int i = 0 ; i <=cur ; i++) {
        printf("%d",arr[i]);
    }
}