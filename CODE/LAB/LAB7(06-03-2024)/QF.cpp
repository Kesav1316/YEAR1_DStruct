/*
Take a string from the user that consists of the '+' symbol. Process the string such that the final string does not include the '+' symbol and the immediate left non-'+' symbol. Select and choose the optimal ADT. Implement the program by including the appropriate header file.
*/
#include<stdio.h>
#include<stdlib.h>
#include"QF.h"
int main() {   
    List l1;    
    int num;
    printf("Enter length of input string:");
    scanf("%d",&num);
    char string[num];
    printf("Enter input string:");
    scanf("%s",string);
    
    for(int i=0;i<num;i++) {
        if(l1.isempty()) {
            l1.push(string[i]);
            continue;
        }

        if(string[i]=='+') {
            l1.popreturn();
        }

        else {
            l1.push(string[i]);
        }
    }
    int strlen=-1;
    while(l1.isempty()!=1) {
        strlen++;
        string[strlen]=l1.popreturn();
    }
    printf("\nThe string is \n");
    for(int i=strlen;i>=0;i--) {
        printf("%c",string[i]);
    }
    return 0;
}                 