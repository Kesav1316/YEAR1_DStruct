#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
class hash {
    int hashtable[SIZE];

    public:
        hash() {
            for(int i = 0 ; i<SIZE + 1;i++) {
                hashtable[i] = -1;
            }
        }
        int insert(int);
        int search(int);

};

int main() {
    hash l1;
    int option;
    int num;

    while(1) {
        printf("Enter the option ");
        scanf("%d",&option);
        if(option == 1) {
            printf("Enter the value of num ");
            scanf("%d",&num);
            l1.insert(num);
        }

        if(option == 2) {
            printf("Enter the value of num ");
            scanf("%d",&num);
            if(l1.search(num)) {
                printf("The element is found ");
            }
            else {
                printf("The element is not found ");
            }
        }
    }
}

int hash::insert(int num) {
    int index;
    index = num % SIZE;
    if(hashtable[index] == -1) {
        hashtable[index] = num;
        return 1;
    }
    else {
        while(index < SIZE + 1) {
            if(hashtable[index] ==-1) {
                hashtable[index] = num;
                return 1;
            }
            index = index + 1;
        }
    }
    return 0;
}

int hash::search(int num) {
    int index;
    index = num % SIZE;
    while(index < SIZE + 1) {
        if( hashtable[index] == num ){
            return 1;
        }

        else if(hashtable[index] == -1) {
            return 0;
        }
        index = index + 1;

    }
    return 0;
}

