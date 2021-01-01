//program implement tries
//inserts and deletes only words with lowercase letters
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
  struct trienode *m;
  int index;
};

struct trienode
{
   struct trienode* child[26];
   int endofword;
};


struct trienode *getnode();
void insert(struct trienode *, char *);
void display(struct trienode*);
void delete_trie(struct trienode*,char*);
int search(struct trienode *,char *);
int check(struct trienode *);
void push(struct trienode*,int);
struct stack pop();
char word[100];
int length;
int top;
struct stack s[100];//stack

int main()
{
  struct trienode *root;
  char key[100];
  int ch,k;
 //length=0;
  root=getnode();
  while(1)
  {
    printf("\n1. Insert..");
    printf("\n2. Delete..");
    printf("\n3. Search..");
    printf("\n4. Display..");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: printf("Enter word..\n");
              scanf("%s",key);
              insert(root,key);
              break;
      case 2: printf("Enter the word for deletion..\n");
               scanf("%s",key);
               top=0;
               delete_trie(root,key);
               break;
      case 3: printf("Enter the word to search..\n");
               scanf("%s",key);
               k=search(root,key);
               if(k)
                 printf("\nWord found..\n");
               else
                 printf("\nNot found..\n");
               break;

      case 4:length=0;
               display(root);
    }
  }
}
  
struct trienode *getnode()
{
    int i;
    struct trienode *temp;
    temp=(struct trienode*)malloc(sizeof(struct trienode));
    for(i=0;i<26;i++)
      temp->child[i]=NULL;
     temp->endofword=0;
    return temp;
}

void insert(struct trienode *root, char *key)
{
    struct trienode *curr;
    int i,index;

    curr=root;
    for(i=0;key[i]!='\0';i++)
    {
      index=key[i]-'a';
      if(curr->child[index]==NULL)
          curr->child[index]=getnode();
       
       curr=curr->child[index];
    }
    curr->endofword=1;
}

void display(struct trienode *curr)
{
    int i,j;
    for(i=0;i<26;i++)
    {
      if(curr->child[i]!=NULL)
      {
         word[length++]=i+97;
         if(curr->child[i]->endofword==1)//if end of word
         {
           printf("\n");//print word 
           for(j=0;j<length;j++)
             printf("%c",word[j]);
         }
        display(curr->child[i]);
      }
    }
    length--;
    return ;
}

int search(struct trienode * root,char *key)
{

  int i,index;
   struct trienode *curr;
   curr=root;

   for(i=0;key[i]!='\0';i++)
   {
     index=key[i]-'a';
     if(curr->child[index]==NULL)
        return 0;
      curr=curr->child[index];
    }
    if(curr->endofword==1)
       return 1;
   return 0;
}


void delete_trie(struct trienode *root,char *key)
{
    int i,j,index,k;
    struct trienode* curr,*temp;
    struct stack x;
    curr=root;
    
    for(i=0;key[i]!='\0';i++)
    {
      index=key[i]-'a';
      if(curr->child[index]==NULL)
      {
         printf("Key not found\n");
         return;
      }
      push(curr,index);
      curr=curr->child[index];
    }
      curr->endofword=0;
      push(curr,-1);
      while(1)
      {
         x=pop();
         if(x.index!=-1)
           x.m->child[x.index]=NULL;
         if(x.m==root)
           break;
         k=check(x.m); 
         if((k>=1)||(x.m->endofword==1))
            break;
         else
           free(x.m);
      }
    return;
}

int check(struct trienode *x)
{
    int i;
    int count=0;
    for(i=0;i<26;i++)
    {
      if(x->child[i]!=NULL)
        count++;
    }
   return count;
}

void push(struct trienode *x,int k)
{
    ++top;
    s[top].m=x;
    s[top].index=k;
} 

struct stack pop()
{
    struct stack temp;
    temp=s[top--];
    return temp;
}























 /*void display(struct trienode *curr)
 {
   int i,j;
   for(i=0;i<26;i++)
   {
     if(curr->child[i]!=NULL)
     {
       word[length++]=i+97;
       if(curr->child[i]->endofword==1)//if word found
       {
          printf("\n");//print the word
          for(j=0;j<length;j++)
             printf("%c",word[j]);
        }
       display(curr->child[i]);
     }
    }
    length--;
    return;
 }



 struct trienode *getnode()
 {
   int i;
   struct trienode *temp;
   temp=(struct trienode*)malloc(sizeof(struct trienode));
   for(i=0;i<26;i++)
    temp->child[i]=NULL;
  temp->endofword=0;
   return temp;
 }


 void insert(struct trienode * root, char *key)
 {
   int i,index;
   struct trienode *curr;
   curr=root;

   for(i=0;key[i]!='\0';i++)
   {
     index=key[i]-'a';
     if(curr->child[index]==NULL)
        curr->child[index]=getnode();
      curr=curr->child[index];
    }
    curr->endofword=1;
  }


 int search(struct trienode * root,char *key)
  {

  int i,index;
   struct trienode *curr;
   curr=root;

   for(i=0;key[i]!='\0';i++)
   {
     index=key[i]-'a';
     if(curr->child[index]==NULL)
        return 0;
      curr=curr->child[index];
    }
    if(curr->endofword==1)
       return 1;
   return 0;
  }

 void delete_trie(struct trienode *root,char *key)
  {
    int i,j,index,flag;
    struct trienode* curr;
    curr=root;
    flag=1;

    for(i=0;key[i]!='\0';i++)
    {
      index=key[i]-'a';
      if(curr->child[index]==NULL)
      {
         printf("Key not found\n");
         return;
      }
      curr=curr->child[index];
    }
      curr->endofword=0;
      return;
  }*/













 


 
 



















