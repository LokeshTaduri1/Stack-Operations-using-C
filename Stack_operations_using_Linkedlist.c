/* Stack Operations using Linkedlist */




#include<stdio.h>
#include<stdlib.h>
#include<climits>
struct node 
{
    int data;
    struct node *next;
}*top=NULL;


void push(int x)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    if(t==NULL)  
       printf("Stack overflow");
    else
    {
       t->data=x;
       t->next=top;
       top=t;
    }
}


void pop()
{
    if(top==NULL)
    {
        printf("Stack Underflow");
    }
    else
    {
      struct node *p;
      p=top;
      top=top->next;
      free(p);
    }
}


int peek(int pos)
{
    struct node *p;
    p=top;
    for(int i=0;i<pos-1&&p!=NULL;i++)
    {
        p=p->next;
    }
    return p->data;
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


int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    pop();
    display();
    printf("%d",peek(1));
    return 0;
}
