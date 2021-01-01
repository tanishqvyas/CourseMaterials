#include<stdio.h>
#include<stdlib.h>
int qinsert(int *q, int *f, int *r, int size, int x);
int qdelete(int *q, int *f, int *r, int size);
void display(int *q, int f, int r, int size);
int main()
{
	int x, ch,k;
	int f,r,size;
	int *q;
	f=r=-1;
	printf("enter the size of Q\n");
	scanf("%d",&size);
	q = (int*)malloc(sizeof(int*)*size);
	while(1)
		{
		display(q,f,r,size);
		printf("1:insert\n 2: delete\n 3: exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
		printf("enter the element\n");
		scanf("%d",&x);
		k=qinsert(q,&f,&r,size,x);
		if(k>0)
			printf("successfully inserted\n");
		break;

		case 2: k=qdelete(q,&f,&r,size);
		if(k>0)
			printf("deleted element is %d\n", k);
		break;

		case 3: exit(0);
		}
	}
	
}

int qinsert(int *q, int *f, int *r, int size, int x)
{
	if((*r+1)%size==*f) 
	{
		printf("Q is full\n");
		return 0;
	}
	
		*r = (*r+1)%size;
		q[*r]=x;
		if(*f==-1)
		*f=0;
		return 1;
}

int qdelete(int *q, int *f, int *r, int size)
{
	int x;
	if(*f==-1)
	{
	printf("Q is empty\n");
	return 0;
	}
	else
	{
	x=q[*f];
	if(*f==*r)
	{
		*f=*r=-1;
	
	}
	else
	{
		*f =(*f+1)%size;
		 
	}
	return x;
	}
}

void display(int *q, int f, int r, int size)
{
	if(f==-1)
	printf("Q is empty\n");
	else
	{
		while(f!=r)
		{
			printf("%d-> ", q[f]);
			f=(f+1)%size;
		}
		printf("%d-> ", q[f]);
	}	
}















