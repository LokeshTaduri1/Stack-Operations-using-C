/* Parenthesis Matching  */





#include<stdio.h>
#include<stdlib.h>
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
void display()
{
    struct node *p=top;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

int isbalance(char *exp)
{
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')  
        {
            push(exp[i]);
        }
        else if(exp[i]==')')
        {
            if(top==NULL)  return 0;
            pop();
        }
    }
    if(top==NULL)   
    {
        return 1;
    }
    else {
        return 0;
    }
}

int main()
{
    char *exp="((a+b)*(b+c))";
    printf("%d",isbalance(exp));
}
