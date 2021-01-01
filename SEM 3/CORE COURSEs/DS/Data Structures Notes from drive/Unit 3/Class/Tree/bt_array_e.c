//Binary Tree using Array
#include<stdio.h>
#include<stdlib.h>
void create(int *t, int x);
void preorder(int *t, int x);
void inorder(int *t, int x);
void postorder(int *t, int x);
void main()
{
	int t[100],i;
	for(i=1;i<100;i++)
		t[i]=-1;
	create(t,1);
	printf("Preorder\n");
	preorder(t,1);
	printf("Inorder\n");
	inorder(t,1);
	printf("Postorder\n");
	postorder(t,1);
}
void create(int *t, int x)
{
	int num;
	printf("enter the value\n");
	scanf("%d", &num);
	if(num==-1) return ;
	t[x]=num;
	printf("creating LST of %d\n", t[x]);
	create(t,2*x);
	printf("creating the RST of %d\n", t[x]);
	create(t,2*x+1);

	return;
}

void preorder(int *t, int x)
{
	if(t[x]!=-1)
	{
		printf("%d ", t[x]);
		preorder(t,2*x);
		preorder(t,2*x+1);
	}
}
void inorder(int *t, int x)
{
	if(t[x]!=-1)
	{
		inorder(t,2*x);
		printf("%d ", t[x]);
		inorder(t,2*x+1);
	}
}
void postorder(int *t, int x)
{
	if(t[x]!=-1)
	{
		postorder(t,2*x);
		postorder(t,2*x+1);
		printf("%d ", t[x]);
	}
}