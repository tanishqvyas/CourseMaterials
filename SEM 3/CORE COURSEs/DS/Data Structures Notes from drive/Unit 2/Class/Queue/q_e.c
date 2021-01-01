#include<stdio.h>
#include<stdlib.h>
int enq(int x, int *q, int *f, int *r, int size);
int deq(int *q, int *f, int *r);
void display(int *q,int f, int r);
int main()
{
	int size, *q,ch,x,k;
	int f =0;
	int r =-1;
	printf("enter the size of queue\n");
	scanf("%d", &size);
	q = (int*) malloc (sizeof(int) * size);
	while(1)
	{
		display(q,f,r);
		printf("1: enque \n 2: dequeue \n 3:exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter value\n");
				scanf("%d",&x);
				 k=enq(x,q,&f, &r,size);
				if(k>0)
				printf("successfully inserted\n");
				break;

			case 2: k = deq(q,&f,&r);
				if(k>0)
				printf("deleted element is %d ", k);
				break;
			
			case 3: exit(0);
		}
	}

}
int enq(int x, int *q, int *f, int *r, int size)
{
	if(*r==size - 1)
	{
		printf("Q is full\n");
		return 0;
	}

	else
	{
		(*r)++;
		q[*r]=x;
	}
	return 1;
}

int deq(int *q, int *f, int *r)
{
	int x;
	if(*f>*r)
		{
		printf("Q is empty\n");
		return 0;
		}

	else
		{
		 x = q[*f];
		(*f)++;
		}
	
	if(*f>*r)
		{
			*f=0;*r=-1;
		}
	return 1;
}

void display(int *q, int f, int r)
{
	int i =0;
	if(r == -1)
	{
		printf("Q is empty\n");
		
	}
	else
	{
	for (i=f; i<=r;i++)
	{
		printf("%d->", q[i]);
	}
	printf("\n");
	}
}





















