#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};
typedef struct node NODE;
void display(NODE *front, NODE *rear);
void enq(int x, NODE **front, NODE **rear);
int deq(NODE **front, NODE **rear);

int main()
{
	int x, ch, k;
	NODE *front, *rear;
	front=rear=NULL;
	while(1)
	{
		display(front,rear);
		printf("1:insert from rear\n 2: delete from front\n 3: exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("enter the element\n");
				scanf("%d",&x);
				enq(x,&front,&rear);
				break;
		
			case 2: k = deq(&front,&rear);
				break;
		
			case 3: exit(24);
		}	

	}
}

void enq(int x, NODE **front, NODE **rear)
{
	NODE *temp;
	temp = (NODE*)malloc(sizeof (NODE));
	temp->data = x;
	temp->link=NULL;

	if(*front==NULL)
		*front=*rear=temp;

	else
	{
		(*rear)->link=temp;
		*rear=temp;
	}
}

int deq(NODE **front, NODE **rear)
{
	int x;
	NODE *q=*front;	
	if(*front == NULL)
		{
		printf("list is empty\n");
		return 0;
		}	
	else
		{
			x = q->data;
			if(*front == *rear)
			{
				*front=*rear=NULL;
			}

			else
				(*front)=(*front)->link;
				free(q);	
				return x;
		}	
}
void display(NODE *front, NODE *rear)
{
	if(front==NULL)
	{
	printf("list is empty\n");
	//return 0;
	}
	else
	{
		while(front!=rear)
		{
			printf("%d->", front->data);
			front=front->link;
			
		}
		printf("%d->", front->data);
	}	
}











