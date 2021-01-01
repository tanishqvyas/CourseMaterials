//binary search tree using array
#include<stdio.h>
#include<stdlib.h>

void insert(int *, int);
void preorder(int*,int);
void postorder(int*,int);
void inorder(int*,int);
int minimum(int*);
int maximum(int*);
void main()
{
  int t[100];//place for tree elements 
  int ch,num,k,i;
  for(i=0;i<100;i++)
    t[i]=-1;
 while(1)
 {
      printf("\n1.Insert");
      printf("\n2.Preorder");   
      printf("\n3. Postorder");
      printf("\n4.Inorder");
      printf("\n5. Minimum");
      printf("\n6.largest");
      scanf("%d",&ch);
       switch(ch)
       {
         case 1 :printf("Enter the element");
                 scanf("%d",&num);
                 insert(t,num);
                 break;
        case 2: preorder(t,0);
                 break; 
       case 3: postorder(t,0);
                 break;
        case 4:inorder(t,0);
                 break;
      case 5 : k=minimum(t);
                printf("The smallest elemenet = %d",k);
                break;
       case 6 : k=maximum(t);
                printf("The largest elemenet = %d",k);
                break;
      
        
         case 7:exit(0);
       }
    }
  }    
  
   int minimum(int *t)
   {
    int i=0;
    while(t[2*i+1]!=-1)
      i=2*i+1;
    return(t[i]);
   }
      
    int maximum(int *t)
   {
    int i=0;
    while(t[2*i+2]!=-1)
      i=2*i+2;
    return(t[i]);
   }


  


    void insert(int *t, int x)
    {
     int i;
     i=0;

     while(t[i]!=-1)
     {
        if(x<t[i])
         i=2*i+1;//move left
        else
         i=2*i+2;//move right
     }
    t[i]=x;
  }
  
  
  void preorder(int *t, int i)
  {
    if(t[i]!=-1)
    {
       printf("%d ",t[i]);
       preorder(t,2*i+1);
       preorder(t,2*i+2);
     }
  }

  void inorder(int *t, int i)
  {
    if(t[i]!=-1)
    {
       inorder(t,2*i+1);
       printf("%d ",t[i]);
       inorder(t,2*i+2);
     }
  }

 void postorder(int *t, int i)
  {
    if(t[i]!=-1)
    {
       postorder(t,2*i+1);
       postorder(t,2*i+2);
       printf("%d ",t[i]);
     }
  }


























/*void insert(int *t, int key)
    {
      int i=0;

      while(t[i]!=0)
      {
        if(key<t[i])
          i=2*i+1;//move left
       else
          i=2*i+2;//move right
      }
    t[i]=key;
   }
           
   

  int min(int *t)
  {
    int i=0;
    while(t[i*2+1]!=0)
      i=2*i+1;
    return t[i];
  }

  int max(int *t)
  {
    int i=0;
    while(t[i*2+2]!=0)
      i=2*i+2;
    return t[i];
  } */












