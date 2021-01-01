#include<stdio.h>
#include<stdlib.h>
struct tnode
{
  int data;
  struct tnode *left;
  struct tnode *right;
};
void inorder(struct tnode*);
void preorder(struct tnode*);
void postorder(struct tnode*);
void insert(struct tnode**,int);
int count(struct tnode *);
int leafcount(struct tnode *);
int height(struct tnode *);
struct tnode* rinsert(struct tnode *, int);
struct tnode* tdelete(struct tnode*,int );
int search(struct tnode *, int );
int rsearch(struct tnode *, int );
int minimum(struct tnode*);
int maximum(struct tnode*);
void main()
{
  struct tnode *root;
  int ch,num,k,n;
   root=NULL;
 while(1)
 {
      printf("\n1.Insert");
      printf("\n2.Preorder");   
      printf("\n3.Postorder");
      printf("\n4.Inorder");
      printf("\n5.No. of nodes");
      printf("\n6.No. of Leaf nodes");
      printf("\n7.Height of a tree");
      printf("\n8.delete a node");
      printf("\n9..recursively insert..");
      printf("\n10..search..");
      printf("\n11..search using recursion..");
      printf("\n13.find smallest");
      printf("\n14.find largest");
      printf("\n15..exit");
      scanf("%d",&ch);
       switch(ch)
       {
         case 1 :printf("Enter the element");
                 scanf("%d",&num);
                 insert(&root,num);
                 break;
        case 2: preorder(root);
                 break; 
        case 3: postorder(root);
                 break;
        case 4:inorder(root);
                 break;
        case 5: k=count(root);
                 printf("\nthe number of nodes=%d",k);

                 break;
       case 6: k=leafcount(root);
                 printf("\nthe number of nodes=%d",k);

                 break;
       case 7: k=height(root);
                 printf("\nthe height of tree=%d",k);

                 break;
        case 8:printf("Enter the node to be deleted\n");
                scanf("%d",&num);
                root=tdelete(root,num);
                 break;
       case 9 :printf("Enter the element");
                 scanf("%d",&num);
                 root=rinsert(root,num);
                 break;

        case 10:printf("Enter the element");
                 scanf("%d",&num);
                 int k=search(root,num);
                 if(k)
                    printf("Key found\n");
                 else
                     printf("Not found..\n");
                 break;

         case 11:printf("Enter the element");
                 scanf("%d",&num);
                 int m=rsearch(root,num);
                 if(m)
                    printf("Key found\n");
                 else
                     printf("Not found..\n");
                 break;
         case 13:n=minimum(root);
                 printf("\nThe smallest element = %d\n",n);
                 break;
         case 14:n=maximum(root);
                 printf("\nthe largest element = %d\n",n);
                 break;
         case 15:exit(0);
       }
    }
  }    

  //returns the smallest element in BST
  int minimum(struct tnode *t)
  {
    while(t->left!=NULL)
     t=t->left;
    return(t->data);
  }

  //returns the largest element in BST
  int maximum(struct tnode *t)
  {
    while(t->right!=NULL)
     t=t->right;
    return(t->data);
  }



  //search with recursion
 int rsearch(struct tnode *t, int x)
 {
    int l;
    if(t==NULL)
      return 0;
    if(t->data==x)
      return 1;
    if(x<t->data)
     //search in left subtree
      l=rsearch(t->left,x);
    else
      //search in right subtree
      l=rsearch(t->right,x);
    return l;
  }



 int search(struct tnode *t, int key)
 {
   struct tnode *curr;
   curr=t;
   while((curr!=NULL)&&(curr->data!=key))
   {
     if(key<curr->data)
       curr=curr->left;
     else
       curr=curr->right;
   }
   if(curr==NULL)
     return 0;
   return 1;
 }

/* int search(stcuct tnode *t, int key)
 {
   struct tnode *curr;
   curr=t;
   while(curr!=NULL)
   {
     if(curr->data==key)
       return 1;
     if(key<curr->data)
       curr=curr->left;
     else
       curr=curr->right;
   }
   return 0;
 }*/



  
  struct tnode *rinsert(struct tnode *t, int x)
  {
    struct tnode *temp;
    if(t==NULL)//empty tree
    {
     temp=(struct tnode*)malloc(sizeof(struct tnode));
     temp->data=x;
     temp->left=temp->right=NULL;
     return temp;
    }
    if(x<t->data)
      //insert into the left subtree
      //return root of left subtree
      //which gets stored in t->left
      t->left=rinsert(t->left,x);
   else
      //insert into the right subtree
      //return root of right subtree
      //which gets stored in t->right
      t->right=rinsert(t->right,x);
   return t;
 }








  struct tnode* tdelete(struct tnode *t, int key)
  {
    struct tnode *prev, *curr, *p, *q, *temp;
    prev=NULL;
    curr=t;

   //find the key in the tree
   while((curr!=NULL)&&(curr->data!=key))
   {
     prev=curr;
     if(key<curr->data)
      curr=curr->left;
     else
      curr=curr->right;
    }
    if(curr==NULL)
    {
      printf("Key not found..\n");
      return t;
    }
    //if one subtree present or no subtrees 
    if((curr->left==NULL)||(curr->right==NULL))
    {
      if(curr->left==NULL)
        q=curr->right;
      else
        q=curr->left;
       //deleting a root with one subtree
    if(prev==NULL)//deleting root
      return q;
    if(curr==prev->left)
        prev->left=q;
     else
        prev->right=q;
    free(curr);
   }
   else
   {
     //two subtrees present
     //find inorder successor
     p=NULL;//for the parent of inorder successor     
     temp=curr->right;
     while(temp->left!=NULL)
     {
       p=temp;
       temp=temp->left;
     }
     //inorder successor found(temp)
     if(p!=NULL)
      p->left=temp->right;
     else 
      curr->right =temp->right;
     curr->data=temp->data;
     free(temp);
    }
    return t;
   }







 





 







      












  








  int height(struct tnode *t)
  {
    if(t==NULL)
      return -1;
    if((t->left==NULL)&&(t->right==NULL))
      return 0;
    int l=height(t->left);
    int r=height(t->right);
    if(l>r)
     return l+1;
    return r+1;
  }


 int leafcount(struct tnode *t)
 {
    if(t==NULL)
     return 0;
   if((t->left==NULL)&&(t->right==NULL))
     return 1;
   int l=leafcount(t->left);
   int r=leafcount(t->right);
   return(l+r);
 }

 int count(struct tnode *t)
  {
     if(t==NULL)
        return 0;
     int l=count(t->left);
     int r=count(t->right);
     return (l+r+1);
  }


 void preorder(struct tnode *t)
 {
   if(t!=NULL)
   {
      printf("%d ",t->data);
      preorder(t->left);
      preorder(t->right);
   }
 }

 void inorder(struct tnode *t)
 {
   if(t!=NULL)
   {
      inorder(t->left);
      printf("%d ",t->data);
      inorder(t->right);
   }
 }

  void postorder(struct tnode *t)
 {
   if(t!=NULL)
   {
      postorder(t->left);
      postorder(t->right);
      printf("%d ",t->data);
   }
 }

 void insert(struct tnode **t, int x)
 {
   struct tnode *temp, *curr, *prev;
   
   //create a node
  temp=(struct tnode*)malloc(sizeof(struct tnode));
  temp->data=x;
  temp->left=temp->right=NULL;
  
  //if empty tree, element being inserted is the first
  if(*t==NULL)
     *t=temp;//copy temp into root
  else
  {
    //find position for x
    prev=NULL;
    curr=*t;//copy root
    while(curr!=NULL)
    {
      prev=curr;
      if(x<curr->data)
        curr=curr->left;
      else
        curr=curr->right;
    }
    if(x<prev->data)
      prev->left=temp;
     else
       prev->right=temp;
   }
 }



















  

















  







  



















