#include<stdio.h>
#include<stdlib.h>
typedef struct Trie
{
	struct Trie* child[26];
	int eow;
}trie;
typedef struct STACK
{
	trie *m;
	int index;
}stack;
char word[100];
int length;
int top=-1;
stack s[100];
trie* getNode()
{
	trie* node=(trie*)malloc(sizeof(trie));
	for(int i=0;i<26;i++)
		node->child[i]=NULL;
	node->eow=0;
	return node;
}
void create(trie *root,char key[])
{
	int i=0,x;
	trie *cur=root;
	while(key[i]!='\0')
	{
		x=key[i]-'a';
		if(cur->child[x]==NULL)
		{
			cur->child[x]=getNode();
		}
		cur=cur->child[x];
		i++;
	}
	cur->eow=1;
}
void display(trie *curr)
{
	int i,j;
    for(i=0;i<26;i++)
    {   
        if(curr->child[i]!=NULL)
        {
            word[length++]=i+97;
            if(curr->child[i]->eow==1)
            {
                printf("\n");
                for(j=0;j<length;j++)
                {
                    printf("%c",word[j]);
                }
            }
            display(curr->child[i]);
        }
    }
    length--;
    return;
}
void sr_prefix(trie *root,char key[])
{
	trie *cur;
    int i,index;
    cur=root;
    length=0;
    for(i=0;key[i]!='\0';i++)
    {
        index=key[i]-'a';
        if(cur->child[index]==NULL)
           {
           	printf("Not found\n");
           	return;
           }
        word[length]=key[i];
        length++;
        cur=cur->child[index];
    }
    if(cur->eow==1)
    	printf("%s",key);
	display(cur);
	length=0;
}
int sr_word(trie *root,char key[])
{
	trie *cur;
    int i,index;
    cur=root;
    for(i=0;key[i]!='\0';i++)
    {
        index=key[i]-'a';
        if(cur->child[index]==NULL)
            return 0;
        cur=cur->child[index];
    }
    if(cur->eow==1)
        return 1;
    return 0;
}
int check(trie *x)
{
    int i,count =0;
    for(i=0;i<26;i++)
    {
        if(x->child[i]!=NULL)
            count++;
    }
    return count;
}
void push(trie *x,int k)
{
    ++top;
    s[top].m=x;
    s[top].index=k;
}
stack pop()
{
   	stack temp;
    temp=s[top--];
    return temp;
}
void delete(trie *root,char key[])
{
	trie *cur;
    int i,index,k;
    cur=root;
   	stack x;
    for(i=0;key[i]!='\0';i++)
    {
        index=key[i]-'a';
        if(cur->child[index]==NULL)
        {
            printf("not found\n");
            return ;
        }
        push(cur,index);
        cur=cur->child[index];
    }
    cur->eow=0;
    push(cur,-1);
    while(1)
    {
        x=pop();
        if(x.index!=-1)
            x.m->child[x.index]=NULL;
        if(x.m==root)
            break;
    k=check(x.m);
    if((k>=1)||(x.m->eow==1))
        break;
    free(x.m);
    }
    return;
}


void main()
{
	trie* root=getNode();
	int ch=1,k;
	char key[20];
	while(ch!=0)
	{
		printf("1.Insert\n2.Display\n3.Search acc to word\n4.Search acc to prefix\n5.Delete\n0.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the string to insert:");
				scanf("%s",key);
				create(root,key);
				break;
			case 2:
				printf("Display of strings:");
				display(root);
				break;
			case 3:
				printf("Enter the word to search:");
				scanf("%s",key);
				k=sr_word(root,key);
				if(k)
					printf("It is found\n");
				else
					printf("It is not found\n");
				break;
			case 4:
				printf("Enter the prefix to search:");
				scanf("%s",key);
				sr_prefix(root,key);
				break;
			case 5:
				printf("Enter the word to delete:");
				scanf("%s",key);
				delete(root,key);
				break;
			case 0:
				exit(1);
			default:
				printf("Invalid option\n");
		}
	}
}
