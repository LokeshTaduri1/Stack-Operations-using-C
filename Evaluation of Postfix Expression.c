
/* Evaluation of Postfix Expression */




#include<stdio.h>
#include<stdlib.h>
#include<cstring>
struct node 
{
    int data;
    struct node *next;
}*top=NULL;
void push(int x)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    t->next=top;
    top=t;
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


int pop()
{
    struct node *t;
    int x=top->data;
    t=top;
    top=top->next;
    free(t);
    return x;
}

char evaluate(char *exp)
{
    int len=strlen(exp);
    int x1,x2,i=0,r=0,j=0;
    for(i=0;exp[i]!='\0';i++)
    {
        if(isoperand(exp[i]))
        {
            push(exp[i]-'0');
        }
        else{
            x2=pop();x1=pop();
            switch(exp[i])
            {
                case '+': r=x1+x2; break;
                case '-': r=x1-x2; break;
                case '/': r=x1/x2; break;
                case '*': r=x1*x2; break;
            }
            push(r);
        }
    }
    return top->data;
}

int main()
{
    char *postfix="234*+82/-";
    printf("%d",evaluate(postfix));

}
