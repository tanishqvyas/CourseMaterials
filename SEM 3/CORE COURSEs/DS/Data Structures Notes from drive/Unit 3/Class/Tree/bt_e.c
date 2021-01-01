//Binry Tree using Linkeed List
#include<stdio.h>
#include<stdlib.h>

struct tnode
{
	int data;
	struct tnode *left;
	struct tnode *right;
};
struct tnode* create();
void inorder(struct tnode *root);
void preorder(struct tnode *root);
void postorder(struct tnode *root);
int main()
{
	struct tnode *root;
	root = NULL;
	printf("CREATING A BINARY TREE\n");
	root= create();

	printf("PRE ORDER TRAVERSAL\n");
	preorder(root);

	printf("IN ORDER TRAVERSAL\n");
	inorder(root);

	printf("POST ORDER TRAVERSAL\n");
	postorder(root);
}

struct tnode* create()
{
	int x;
	struct tnode *p;

	printf("enter the value of data\n");
	scanf("%d",&x);
	if(x==-1) return NULL;

	p=(struct tnode*) malloc(sizeof(struct tnode));
	p->data=x;
	printf("create the LST for %d\n", x);
	p->left=create();
	printf("create the RST for %d\n", x);
	p->right=create();

	return p;
}

void preorder(struct tnode *root)
{
	if(root!=NULL)
	{
		printf("%d",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}


void inorder(struct tnode *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
	}
}



void postorder(struct tnode *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d",root->data);
	}
}
