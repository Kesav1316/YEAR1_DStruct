#include "QB.h"

int main(){
    int precedence(char);
    while(1){
        list l;
        int val;
        int choice;
        int len;
        char infix[20];
        char postfix[20];
        printf("\nMenu:\n1. Get Infix\n2. Convert Infix\n3. Evaluate Postfix\n4. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        char chk = '0';
        int i;
        int len1=0;
        switch(choice){
            //Checking if the infix expression is valid.
            //Time complexity => O(n).
            case 1:{
                while(chk=='0'){     
                    len = 0;
                    int oc = 0;
                    int ec = 0;
                    char let;
                    printf("Enter a valid infix string : ");
                    scanf("%s",&infix);
                    let = infix[len];
                    while(let!='\0'){
                        if(len%2==0 && let!='+' && let!='-' && let!='*' && let!='/' && let!='%'){
                            ec+=1;
                        }
                        else if(len%2!=0 && (let=='+' || let=='-' || let=='*' || let=='/' || let =='%')){
                            oc+=1;
                        }
                        len+=1;
                        let = infix[len];
                    }
                    if(ec==len/2+1 && oc==len/2){
                        printf("Valid infix expression");
                        chk='1';
                    }
                    else{
                        printf("Invalid infix expression\n");
                    }
                }
                break;
            }
            //Convert infix to postfix.
            //Time complexity => O(n)
            case 2:
                for(i=0;i<len;i++){
                    if (i%2==0){
                        postfix[len1]=infix[i];
                        len1+=1;
                    }
                    else{
                        if(l.peek()=='\0'){
                            l.push(infix[i]);
                        }
                        else if(precedence(infix[i]) > precedence(l.peek())){
                            l.push(infix[i]);
                        }
                        else if(precedence(infix[i]) == precedence(l.peek())){
                            if(infix[i]!='='){
                                postfix[len1]=l.pop();
                                l.push(infix[i]);
                                len1+=1;
                            }
                            else{
                                l.push(infix[i]);
                            }
                        }
                        else{
                            while(precedence(infix[i]) <= precedence(l.peek())) {
                                postfix[len1] = l.pop();
                                len1 += 1;
                            }
                            l.push(infix[i]);
                        }
                    }
                }
                while (l.peek() != '\0') {
                    postfix[len1] = l.pop();
                    len1 += 1;
                }
                postfix[len1]='\0';
                printf("%s\n",postfix);
                break;
            //Evaluate postfix expression
            //Time complexity => O(n)
            case 3:
                for(i=0;i<len;i++){
                    if(isalpha(postfix[i])!=0){
                        printf("Enter the value of %c: ",postfix[i]);
                        scanf("%d",&val);
                        l.push(char(val));
                    }
                    else{
                        switch(postfix[i]){
                            case '+':
                                l.push(char(int(l.pop())+int(l.pop())));
                                break;
                            case '-':
                                l.push(char(int(l.pop())-int(l.pop())));
                                break;
                            case '*':
                                l.push(char(int(l.pop())*int(l.pop())));
                                break;
                            case '/':
                                l.push(char(int(l.pop())/int(l.pop())));
                                break;
                            case '%':
                                l.push(char(int(l.pop())%int(l.pop())));
                                break;
                        }
                    }
                }
                printf("\nAnswer %d",int(l.pop()));
                break;
            case 4:
                return 0;
            default:
                printf("Enter a valid choice.");
                break;
        }
    }
}

//Function to check the precedence of operators.
int precedence(char op) {
    if(op=='*' || op=='/' || op=='%')
        return 2;
    else if (op=='+' || op=='-')
        return 1;
    else 
        return 0;
}