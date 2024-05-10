/*
B. A substring is a contiguous sequence of characters in a string. An ideal sub-string has a length of 3 with no repeating characters. Identify the optimal ADT and data structure to count the ideal number of substrings given a string of length 'n'. Multiple occurrences of a substring can be counted. 
*/
#include <stdio.h>
#include <stdlib.h>
#include "Q2.h"

int main(){
    List L;
    struct List::First3 *a;
    char in;
    int c=0;
    printf("Enter the substring \n");
    getchar();
    while((in = getchar()) != EOF && in!='\n'){
        L.Append_Node(in);
    }
    while((a = L.firstThree()) != nullptr){
        if(a->F != a->L && a->F != a->M && a->L!= a->M){
            c++;
        }  
        L.Delete_Beg_Node();
    }
    printf("Total unique substrings = %d",c);

}