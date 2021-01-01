//BFS using array
#include<stdio.h>
#include<stdlib.h>
int n;
int visit[100];
int a[100][100];
int q[100];
int f,r;
void creategraph();
void bfs(int v);
void insert(int v);
int delete();
int empty();

int main()
{
	int i,v;
	f=r=-1;
	printf("enter the no of vertex\n");
	scanf("%d",&n);
	creategraph();
	printf("enter the src vertex\n");
	scanf("%d",&v);
	printf("vertex reachable from %d using BFS are...\n", v);
	bfs(v);
}

void creategraph()
{
	int i,j;
	while(1)
	{
		printf("enter the src and destination\n");
		scanf("%d%d",&i,&j);
		if((i==0)&&(j==0))break;
		a[i][j]=a[j][i]=1;
	}

}



void bfs(int v)
{
	int w;
	visit[v]=1;
	printf("%d",v);
	insert(v);
	while(!empty())
		{
		v=delete();
		for(w=1;w<=n;w++)
			{
			if((a[v][w]==1) && (visit[w]==0))
				{
				visit[w]=1;
				printf("%d",w);
				insert(w);
				}
			}
		}
	
}

void insert(int v)
{
	r++;
	q[r]=v;
	if(f==-1)
		f=0;
}


int delete()
{
	int w;
	w=q[f];
	if(f==r)
		f=r=-1;
	else
		f++;
	return w;	
}

int empty()
{
	if(f==-1)
		return 1;
	return 0;
}





