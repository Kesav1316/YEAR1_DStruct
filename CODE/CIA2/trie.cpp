//Program to inplement trie
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define nodecount 128

class trie
{
    private:
        struct node
        {
            struct node *next[nodecount];
            bool end;
        };
        struct node *root;

        struct node *nodecreate()
        {
            struct node *newnode=(struct node *)malloc(sizeof(struct node));
            for(int i=0;i<nodecount;i++)
            {
                newnode->next[i]=NULL;
            }
            newnode->end = false;
            return newnode;
        }        

        void displayrec(struct node *temp, char left[], int curlength)
        {
            if(temp->end==true)
            {
                left[curlength]='\0';
                printf("%s ",left);
            }
            for(int i=0;i<nodecount;i++)
            {
                if(temp->next[i]!=NULL)
                {
                    left[curlength]=i;
                    displayrec(temp->next[i],left,curlength+1);
                }
            }
        }

        int deleterec(struct node *temp, char input[], int cur, int len)
        {
            if(cur==len)
            {
                for(int i=0;i<nodecount;i++)
                {
                    if(temp->next[i]!=NULL)
                    {
                        temp->end = false;
                        return 2;
                    }
                }
                temp->end = false;
                return 1;
            }
            else if(temp==NULL)
            {
                return -1;   //Invalid input
            }
            else
            {
                int result = deleterec(temp->next[(int)input[cur]], input, cur+1, len);
                if(result==1)
                {
                    for(int i=0;i<nodecount;i++)
                    {
                        if(i==(int)input[cur])
                        {
                            continue;
                        }
                        if(temp->next[i]!=NULL)
                        {
                            return 2;
                        }
                    }
                    free(temp->next[(int)input[cur]]);
                    temp->next[(int)input[cur]]=NULL;
                    return 1;
                }
                else if(result==2)
                {
                    return 2;
                }
                else
                {
                    return -1;
                }
            }
        }
        
        int searchrec(struct node *temp, char input[], int cur, int len)
        {
            if(cur==len)
            {
                return 1;
            }
            else if(temp==NULL)
            {
                return 0; 
            }
            return searchrec(temp->next[(int)input[cur]], input, cur+1, len);
        }

        int prefixsearchrec(struct node *temp, char input[], int cur, int len)
        {
            if(cur==len)
            {
                printf("The words in the trie are : ");
                displayrec(temp,input,len);
                return 1;
            }
            else if(temp==NULL)
            {
                return 0; 
            }
            return prefixsearchrec(temp->next[(int)input[cur]], input, cur+1, len);
        }

        int wordcountrec(struct node *temp)
        {
            int count = 0;
            if(temp->end==true)
            {
                count++;
            }
            for(int i=0;i<nodecount;i++)
            {
                if(temp->next[i]!=NULL)
                {
                    count+=wordcountrec(temp->next[i]);
                }
            }
            return count;            
        }

    public:
        trie()
        {
            root=nodecreate();
        }

        int insert(char[]);
        int display();
        int deletion(char[]);
        int search(char[]);
        int prefixsearch(char[]);
        int wordcount();
};

int main()
{   
    trie t1;    
    int choice,len;
    char input[100];
    while(1)    
    {   getchar();
        printf("\nEnter your choice: \n1.Insert \n2.Display \n3.Delete \n4.Search");
        printf("\n5.Prefix search \n6.Word count \n7.Exit");        
        scanf("%d",&choice);
        switch(choice)
        {
            case(1):
                printf("\n Enter the word to insert:");
                scanf(" %s",input);
                len = strlen(input);
                for(int i=0;i<len;i++)
                {
                    if((int)input[i]>=nodecount || (int)input[i]<0)
                    {
                        printf("Invalid input");
                        break;
                    }
                }
                if(t1.insert(input))
                {
                    printf("Successfully inserted");
                }
                else
                {
                    printf("Word already exists in trie");
                }
                break;

            case(2):
                t1.display();
                break;  
                  
            case(3):
                printf("\n Enter the word to delete:");
                scanf(" %s",input);
                len = strlen(input);
                for(int i=0;i<len;i++)
                {
                    if((int)input[i]>=nodecount || (int)input[i]<0)
                    {
                        printf("Invalid input");
                        break;
                    }
                }
                if(t1.deletion(input)==-1)
                {
                    printf("Word does not exist in trie");
                }
                else
                {
                    printf("Successfully deleted");
                }
                break;

            case(4):
                printf("\n Enter the word to search:");
                scanf(" %s",input);
                len = strlen(input);
                for(int i=0;i<len;i++)
                {
                    if((int)input[i]>=nodecount || (int)input[i]<0)
                    {
                        printf("Invalid input");
                        break;
                    }
                }
                if(t1.search(input))
                {
                    printf("Word exists in trie");
                }
                else
                {
                    printf("Word does not exist in trie");
                }
                break;                

            case(5):
                printf("\n Enter the word to search:");
                scanf(" %s",input);
                len = strlen(input);
                for(int i=0;i<len;i++)
                {
                    if((int)input[i]>=nodecount || (int)input[i]<0)
                    {
                        printf("Invalid input");
                        break;
                    }
                }
                if(!t1.prefixsearch(input))
                {
                    printf("\nNo word with given prefix exists in trie");
                }                
                break;

            case(6):
                printf("The number of words in the tree is %d",t1.wordcount());
                break;

            case(7):
                exit(0);
                break; 
        }
    }
}

//Method to insert into trie
int trie::insert(char input[])
{
    struct node *temp = root;
    int inplen=strlen(input);
    for(int i=0;i<inplen;i++)
    {
        if(temp->next[(int)input[i]]==NULL)
        {   
            temp->next[(int)input[i]] = nodecreate();
            if(temp->next[(int)input[i]]==NULL)
            {
                printf("Memory allocation failed");
                return 0;
            }
        }
        temp=temp->next[(int)input[i]];
    }
    if(temp->end)
    {
        return 0;
    }
    temp->end=true;
    return 1;
}

//Method to print all words
int trie::display()
{
    for(int i=0;i<nodecount;i++)
    {
        if(root->next[i]!=NULL)
        {
            printf("The words in the trie are : ");
            char start[100];
            displayrec(root,start,0);
            return 1;                
        }
    }
    printf("The trie is empty");
    return 0;
}

//Method to delete a word
int trie::deletion(char input[])
{
    int len = strlen(input);
    return(deleterec(root,input,0,len));
}

//Method to search a word
int trie::search(char input[])
{
    int len = strlen(input);
    return(searchrec(root,input,0,len));
}

//Method to search for a particular prefix
int trie::prefixsearch(char input[])
{
    int len = strlen(input);
    return(prefixsearchrec(root,input,0,len));
}

//Method to count number of words stored in trie
int trie::wordcount()
{
    return(wordcountrec(root));
}