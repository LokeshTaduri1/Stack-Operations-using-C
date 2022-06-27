
/* Stack Operations in C */



#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    int *a;
}st;
void create(struct stack *st)
{
    printf("Enter size");
    scanf("%d",&st->size);
    st->top=-1;
    st->a=(int *)malloc(st->size*sizeof(int));
}
void display(struct stack st)
{
    for(int i=st.top;i>=0;i--)
    {
        printf("%d ",st.a[i]);
    }
}
void push(struct stack *st,int x)
{
    if(st->top==st->size-1)  printf("Stack overflow");
    else{
        st->top++;
        st->a[st->top]=x;
    }
}

void pop(struct stack *st)
{
    if(st->top==-1)  printf("Stack Underflow");
    else st->top--;
}
int peek(struct stack st,int index)
{
    int x=-1;
    if(st.top-index+1<0)   printf("Invalid Index");
    else   x=st.a[st.top-index+1];
    return x;
}
int isempty(struct stack st)
{
    if(st.top==-1)
    {
        return -1;
    }
    return 0;
}
int isfull(struct stack st)
{
    if(st.top==st.size-1)  return 1;
    return 0;
}
int main()
{
    struct stack st;
    create(&st);
    push(&st,10);
    push(&st,12);
    push(&st,13);
    printf("%d \n",isempty(st));
    display(st);
    
}
