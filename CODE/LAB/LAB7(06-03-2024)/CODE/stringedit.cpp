//Program to implement queue using linked list
#include<stdio.h>
#include<stdlib.h>
#include"stringeditfunc.h"


int main()
{   
    LinkList l1;    
    int num;
    printf("Enter length of input string:");
    scanf("%d",&num);
    char string[num];
    printf("Enter input string:");
    scanf("%s",string);
    
    for(int i=0;i<num;i++)
    {
        if(l1.check()==0)
        {
            l1.push(string[i]);
            continue;
        }
        if(string[i]=='+')
        {
            l1.popreturn();
        }
        else
        {
            l1.push(string[i]);
        }
    }
    int strlen=-1;
    while(l1.check()==1)
    {
        strlen++;
        string[strlen]=l1.popreturn();
    }
    printf("\nThe resultant string is\n");
    for(int i=strlen;i>=0;i--)
    {
        printf("%c",string[i]);
    }
    return 0;
}                 