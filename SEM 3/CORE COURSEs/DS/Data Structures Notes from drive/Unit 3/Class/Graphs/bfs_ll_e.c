//BFS LList of directed graph
#include<stdio.h>
#include<stdlib.h>
int visit[10];
int n,f,r;
int q[10];

struct node
{
	int data;
	struct node* next;
};
struct node *a[100];
void creategraph();
void bfs(int v);
void insert(int i, int j);
void qinsert(int v);
int qempty();
int qdelete();
int main()
{
	int  i,v;
	f=-1;
	r=-1;
	printf("enter the number of vertices\n");
	scanf("%d",&n);
	creategraph();
	printf("enter the src\n");
	scanf("%d",&v);
	printf("vertices reachable  from %d using BFS are...", v);
	bfs(v);
	
}

void creategraph()
{
	int i,j;
	for(i=1;i<=n;i++)
	a[i]=NULL;
	while(1)
		{
			printf("enter the src and dst\n");
			scanf("%d %d",&i,&j);
			if((i==0)&&(j==0)) break;
			insert(i,j);
		}
	
}
void insert(int i, int j)
{
	struct node *temp;
	temp = (struct node*) malloc(sizeof(struct node));
	temp->data=j;
	temp->next=a[i];
	a[i]=temp;
}
void bfs(int v)
{
	struct node *p;
	int w;
	visit[v]=1;
	printf("%d",v);
	qinsert(v);
	while(!qempty())
		{
			v=qdelete();
			for(p=a[v];p!=NULL;p=p->next)
			{
				w=p->data;
				if(visit[w]==0)
				{
					visit[w]=1;
					printf("%d ", w);
					qinsert(w);
				}
		}	}
}

void qinsert(int v)
{
	r++;
	q[r]=v;
	if(f==-1)
		f=0;
}

int qdelete()
{
	int w;
	w=q[f];
	if(f==r)
	f=r=-1;
	else
	f++;
	return w;
}

int qempty()
{
	if(f==-1) 
	return 1;
	else
	return 0;
}

