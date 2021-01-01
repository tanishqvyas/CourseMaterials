
//program to ckeck if a binary tree
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
int checkbst(struct tnode *);
int main()
{
 int num,r;
 struct tnode *root;
 root=NULL;
 while(1)
 {

   printf("Enter the element");
   scanf("%d",&num);
   if(num==0)
     break;
   insert(&root,num);
   
 }
 printf("pre order traversal..\n");
 preorder(root);
 printf("Checking for BST..\n");
 r=checkbst(root);
 if(r)
   printf("BST..\n");
 else
   printf("Not BST..\n");
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

 int checkbst(struct tnode *t)
 {
   if(t==NULL)
     return 1;
   if(t->left!=NULL)
   {
      if(t->left->data > t->data)
        return 0;
   }
   if(t->right!=NULL)
   {
     if(t->right->data < t->data)
        return 0;
   }
   if((checkbst(t->left))&& (checkbst(t->right)))
     return 1;
   return 0;
 }
  






