
//program to ckeck if 2 BST are similar
//is a BST
#include<stdio.h>
#include<stdlib.h>
struct tnode
{
  int data;
  struct tnode *left;
  struct tnode *right;
};
void insert(struct tnode**, int);
void preorder(struct tnode*);
int identical(struct tnode *,struct tnode*);
int main()
{
 int num,r;
 struct tnode *root1,*root2;
 root1=NULL;
 root2=NULL;
 printf("\nCreating Tree 1..\n");
 while(1)
 {

   printf("Enter the element");
   scanf("%d",&num);
   if(num==0)
     break;
   insert(&root1,num);
   
 }
 printf("\npre order traversal of Tree 1..\n");
 preorder(root1);
 printf("\nCreating Tree 2..\n");
 while(1)
 {

   printf("Enter the element");
   scanf("%d",&num);
   if(num==0)
     break;
   insert(&root2,num);
 }
 printf("\npre order traversal of Tree 2..\n");
 preorder(root2);
 printf("\nChecking for Similarity..\n");
 r=identical(root1,root2);
 if(r)
   printf("Identical trees..\n");
 else
   printf("Not Identical Trees..\n");
}


void preorder(struct tnode*t)
   {
     if(t!=NULL)
      {
         printf("%d   ",t->data);
         preorder(t->left);
         preorder(t->right);
      }
    }

void insert(struct tnode **t, int x)
 {
   struct tnode *temp,*prev,*curr;
   //create node

   temp=(struct tnode*)malloc(sizeof(struct tnode));
   temp->data=x;
   temp->left=temp->right=NULL;

   //if empty tree
   if(*t==NULL)
     *t=temp;//make root point to the first element
   else
   {
     prev=NULL;
     curr=*t;
     while(curr!=NULL)
     {
       prev=curr;
       if(x<curr->data)
         curr=curr->left;//move left
       else
          curr=curr->right;//move right
     }
     if(x<prev->data)
       prev->left=temp;
     else
       prev->right=temp;
    }
  }   

 int identical(struct tnode *t1, struct tnode *t2)
 {
   int m,n;
   if((t1==NULL)&&(t2==NULL))
    return 1;
   if((t1!=NULL)&&(t2!=NULL))
   {
     if(t1->data==t2->data)
     {
      m=identical(t1->left,t2->left); 
      n=identical(t1->right,t2->right);
      return(m&&n);
     }
     return 0;
   }
   return 0;
  }  





