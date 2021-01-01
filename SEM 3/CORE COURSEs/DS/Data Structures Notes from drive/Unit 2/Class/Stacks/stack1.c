#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
  int *s;
  int top;
  int size;
}STACK;
 
int push(STACK *,int);
int pop(STACK*);
void display(STACK);
int main()
{
  int top,size,ch,k,x;
  STACK stk;
  printf("Enter the size of the stack..\n");
  scanf("%d",&stk.size);
  stk.s=(int*)malloc(sizeof(int)*stk.size);
  stk.top=-1;
  while(1)
  {
    display(stk);
    printf("\n1..push\n");
    printf("2..pop\n");
    printf("3..display\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("Enter the data\n");
             scanf("%d",&x);
             k=push(&stk,x);
             if(k>0)
               printf("Element pushed successfully\n");
             break;
     case 2:k=pop(&stk);
            if(k>0)
               printf("Element popped=%d\n",k);
            break;
     case 3:display(stk);
            break;
     case 4:exit(0);
   }
 }
}

 int push(STACK *p, int x)
 {
  //check for overflow
  if(p->top==p->size-1)
  {
    printf("Stack overflow..cannot insert\n");
    return -1;
  }
  p->top++;
  p->s[p->top]=x;
  return 1;
 }

  int pop(STACK *p)
  {
   int x;
    //check for underflow
   if(p->top==-1)
   {
     printf("Stack under flow..cannot delete\n");
     return -1;
   }
    x=p->s[p->top];
    p->top--;
    return x;
  }

  void display(STACK stk)
  {
   int i;
   if(stk.top==-1)
     printf("Empty stack..\n");
   else
    {
      for(i=stk.top;i>=0;i--)
       printf("%d ",stk.s[i]);
    }
  }







  










































