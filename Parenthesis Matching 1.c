/* Parenthesis Matching using Stack */


#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node
{
    char data;
    struct node *next;
}*top=NULL;
void push(char x)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    t->next=top;
    top=t;
}
void pop()
{
    struct node *t;
    t=top;
    top=top->next;
    free(t);
}

int isbalance(string exp)
{
    int x=0;
    bool flag= true;
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')  
        {
            push(exp[i]);
        }
        if(exp[i]==')'){
           struct node *t = top; 
           if(top!=NULL && t->data=='('){
               pop();
           }
           else{
            flag = false;
            break;
           }
        }
        if(exp[i]=='}'){
           struct node *t = top; 
           if(top!=NULL && t->data=='{'){
               pop();
           }
           else{
            flag = false;
            break;
           }
        }
        else if(exp[i]==']'){
           struct node *t = top; 
           if(top!=NULL && t->data=='['){
               pop();
           }
           else{
            flag = false;
            break;
           }
        }

    }
    if(top!=NULL) return 0;
    if(flag==false) return 0;
    else return 1;
}

int main()
{
    string exp="([{(a+b)*(b+c)}])";
    printf("%d",isbalance(exp));
}
