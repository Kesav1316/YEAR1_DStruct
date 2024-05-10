// to implement priority queue ADT using heap data structure
#include<stdio.h>
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<queue>
#define size 50
class heap
{
  int arr[size];
  int cur;

  public:

  heap()
  {
    cur=-1;
  }

  int insert(int num);
  void heapifyup();
  void display();
  int delmax();
  void sort(queue<int>gq);
  void showq(queue<int> gq);
  int search(int num);
};
int main()
{   
    queue <int> gq;
    heap h1;
    int choice;

    while (1)
    {
        printf("\n(1) Insert");
        printf("\n(2) Delete");
        printf("\n(3) Display");
        printf("\n(4) Search");
        printf("\n(5) Sort");
        printf("\n(6) Exit");
        printf("\n Enter your choice");
        scanf("%d",&choice);
        getchar();

        switch (choice)
        {
           case 1:
           int num1;
           printf("Enter the number to insert");
           scanf("%d",&num1);
           if(h1.insert(num1))
           {
            printf("Element is inserted successfully");
           }
           else
           {
            printf("Heap is full");
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
          h1.sort(gq);
          break;
           
           case 6:
           return 0;
        }
    }
}
//methods

//method to insert a number
int heap:: insert(int num)
{
  if (cur==size-1)
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

//method to heapify while inserting
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
//method to heapify while deleting
/*void heap::heapifydown() {
    int i = 0; 
    while (true) {
        int left = 2 * i + 1; 
        int right = 2 * i + 2; 
        int largest = i;

        if (left <= cur && arr[left] > arr[largest]) {
            largest = left;
        }

      
        if (right <= cur && arr[right] > arr[largest]) {
            largest = right;
        }

        
        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            i = largest; 
        } else {
            break;
        }
    }
}*/
//method to display
void heap::display()
{
  
  for(int i=0;i<=cur;i++)
  {
    printf("%d\t",arr[i]);
  }
}
//method to delete the root
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

//method to sort
void heap::sort(queue<int>gq)
{
  while(cur!=-1)
  {
    gq.push(delmax());
  }
   showq(gq);
}
void heap:: showq(queue<int> gq)
{
    queue<int> g = gq;
    while (!g.empty()) {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}

// method to search
int heap:: search(int num)
{
  for(int i=0;i<=cur;i++)
  {
    if(num==arr[i])
    {
      return i;
    }
  }
  return 0;

}