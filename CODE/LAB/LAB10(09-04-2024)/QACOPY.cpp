/*
A. Write a separate C++ menu-driven program to implement Priority Queue ADT using a max heap. Maintain proper boundary conditions and follow good coding practices. The Priority Queue ADT has the following operations,

1. Insert
2. Delete
3. Display
4. Search
5. Sort (Heap Sort) 
6. Exit

What is the time complexity of each of the operations?
*/

//Child using parent
//Left = 2i+1
//Right = 2i+2

//Parent using child
//Left parent = (i - 1)/2
//Right parent = (i+1)/2
//i is index starting from 0 

//Insertion max heap: Check whether child is smaller than parent or replace
//Deletion: Replace root with rightmost and delete the root and see if HPV
//Heapsort: On deleting , the elements are placed in an array . Max heap : descending order

#include <stdio.h>
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<queue>
#define SIZE 50
class heap {
    int arr[SIZE];
    int cur;
    public:
        heap() {
            cur = -1;
        }
    int insert(int num);
    void heapifyup();
    void display();
    int delmax();
    void sort(queue<int>q1);
    void showq(queue<int>q1);
    int search(int num);
    
        
};

int main() {
    queue <int> q1; 
    heap h1;
    int choice;
    int element;
    int pos;
    while(1) {

        printf("\n PRIORITY QUEUE ADT \n");
        printf("\n 1. Insert \n 2. Delete \n 3. Display \n 4. Search \n 5. Sort \n 6. Exit");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("Enter the character ");
                scanf(" %d",&element);
                if(h1.insert(element)) {
                    printf("\n Inserted successfully.\n");
                }
                else {
                    printf("\n Insertion unsuccessful.\n");
                }
                break;
            
            case 2:
                if(h1.delmax())
                {
                printf("Element is deleted successfully");
                }
                else
                {   
                printf("The heap is already empty");
                }
                break;
            
            case 3:
                h1.display();
                break;

            case 4:
                int num4;
                printf("Enter a number to search");
                scanf("%d",&num4);
                if(h1.search(num4))
                {
                    printf("the number is found at %d",h1.search(num4));
                }
                else
                {
                    printf("Element is not found");
                }
                break;
            
            case 5:
                h1.sort(q1);
                break; 
           
            case 6:
                return 0;

        }
    }

}

//Method to push into heap.
//Time complexity => O(logn).
int heap:: insert(int num)
{
  if (cur==SIZE-1)
  {
    return 0;
  }
  else if(cur==-1)
  {
    arr[0]=num;
    cur++;
    return 1;
}
  else
  {
    cur++;
    arr[cur]=num;
    heapifyup();
    return 1;
  }
}

//Method for heapify.
void heap:: heapifyup()
  {
     int i=cur;     
     while(i>0)
     {
        int parent=(i-1)/2;
        if(arr[i]>arr[parent])
        {
          int temp=arr[i];
          arr[i]=arr[parent];
          arr[parent]=temp;
      
        }
        i--;
      
        
     } 
  }

//Method to display the elements.
//Time complexity => O(n).
void heap::display()
{
  
  for(int i=0;i<=cur;i++)
  {
    printf("%d\t",arr[i]);
  }
}

//Method to delete.
//Time complexity => O(logn).
int heap:: delmax()
{
  if(cur==-1)
  {
    return '\0';
  }
  else
  {
    int temp=arr[0];
    arr[0]=arr[cur];
    cur--;
    heapifyup();
    return temp;
  }
}

//Method to sort the heap.
//Time complexity => O(nlogn).
//Sorting n times.
void heap::sort(queue<int>q1)
{
  while(cur!=-1)
  {
    q1.push(delmax());
  }
   showq(q1);
}

void heap:: showq(queue<int> q1)
{
    queue<int>q2 = q1;
    while (!q2.empty()) {
        printf("\n%d\n",q2.front());
        q2.pop();
    }

}


//Method to search.
//Time complexity => O(n).
int heap:: search(int num)
{
  for(int i=0;i<=cur;i++)
  {
    if(num==arr[i])
    {
      return i+1;
    }
  }
  return 0;

}




