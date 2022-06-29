/* Infix to Postfix Conversion */




#include<stdio.h>
#include<stdlib.h>
#include<cstring>
struct  node
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


int pop()
{
    int x=-1;
    struct node *t;
    t=top;
    x=top->data;
    top=top->next;
    free(t);
    return x;
}


void display()
{
    struct node *p=top;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}


int precedance(char x)
{
    if(x=='+'||x=='-')
      return 1;
    else if(x=='*'|| x=='/')
      return 2;
    
}


int isoperand(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/')
       return 0;
    else return 1;
}


char *intopost(char *infix)
{
    char *postfix;
    int len=strlen(infix);
    postfix=(char *)malloc((len+2)*sizeof(char));
    int i=0,j=0;
    while(infix[i]!='\0')
    {
        if(isoperand(infix[i]))   postfix[j++]=infix[i++];
        else{
            if(precedance(infix[i]>precedance(top->data)))  push(infix[i++]);
            else{
                postfix[j++]=pop();
            }
        }
    }
    while(top!=NULL)  postfix[j++]=pop();
    postfix[j]='\0';
    return postfix;
}


int main()
{
    char *infix ="a+b*c";
    push(' ');
    char *postfix=intopost(infix);
    printf("%s",postfix);
}
