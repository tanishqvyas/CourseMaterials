#include<stdio.h>
#include<stdlib.h>
int push(int*,int*,int,int);
int pop(int*,int*);
void display(int*,int);
int main()
{
  int top,size,ch,k,x;
  int *s;
  printf("Enter the size of the stack..\n");
  scanf("%d",&size);
  s=(int*)malloc(sizeof(int)*size);
  top=-1;
  while(1)
  {
    display(s,top);
    printf("\n1..push\n");
    printf("2..pop\n");
    printf("3..display\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("Enter the data\n");
             scanf("%d",&x);
             k=push(s,&top,size,x);
             if(k>0)
               printf("Element pushed successfully\n");
             break;
    case 2:k=pop(s,&top);
            if(k>0)
               printf("\nElement popped=%d\n",k);
            break;
     case 3:display(s,top);
            break;
     case 4:exit(0);
   }
 }
}

 int pop(int *s, int *t)
 {
   int x;
   //check for stack underflow
   if(*t==-1)
   {
     printf("Stack underflow..cannot delete..\n");
     return -1;
   }
    x=s[*t];
    (*t)--;
    return x;
  }







 int push(int *s, int *t, int size, int x)
 {
    //check for overflow

    if(*t==size-1)
    {
      printf("Stack overflow..cannot insert\n");
      return -1;
     }
     (*t)++;//or ++*t or *t=*t+1
      s[*t]=x;
     return 1;
   }

  void display(int *s, int t)
  {
    int i;
    if(t==-1)
      printf("Empty stack..\n");
    else
     {
       for(i=t;i>=0;i--)
         printf("%d  ",s[i]);
      }
  }











 





   
 


  



   

    






   

   
