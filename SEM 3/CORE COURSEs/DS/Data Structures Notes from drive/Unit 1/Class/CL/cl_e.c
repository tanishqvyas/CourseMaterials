#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};
void display(struct node *p);
void front_insert(struct node** p, int x);
void end_insert(struct node** p, int x);
void front_delete(struct node** p);
void end_delete(struct node** p);
int main()
{
	struct node *last;
	last = NULL;
	int ch, x;
	while(1)
	{
	display(last);
	printf("\n1: Front insert\n 2: end insert\n 3: front delete \n");
	scanf("%d", &ch);
		switch(ch)
		{
			case 1: printf("enter value\n");
				scanf("%d",&x);
				front_insert(&last, x);
				break;

			case 2: printf("enter value\n");
				scanf("%d",&x);
				end_insert(&last, x);
				break;

			case 3: front_delete(&last);
				break;

			case 4: end_delete(&last);
				break;
		}
	}
}


void front_insert(struct node** p, int x)
{

	struct node* temp;
	temp = (struct node*) malloc(sizeof(struct node));
	temp->data = x;
	temp->next = temp;
	
	if(*p == NULL)
		*p = temp;

	else
		{
			temp ->next = (*p)->next;
			(*p)->next = temp;
		}

}



void end_insert(struct node** p, int x)
{

	struct node* temp;
	temp = (struct node*) malloc(sizeof(struct node));
	temp->data = x;
	temp->next = temp;
	
	if(*p == NULL)
		*p = temp;

	else
		{
			temp ->next = (*p)->next;
			(*p)->next = temp;
			*p = temp;
		}

}


void display(struct node *p)
{
	struct node *q;
	if(p == NULL)
		printf("list is empty");
		
	else
		{
		q = p->next;
		while(q!=p)
		{
			printf("%d-> ", q->data);
			q = q->next;
		}
	printf("%d-> ", q->data);
	}
}
void front_delete(struct node** p)
{
	struct node* temp;
	if(*p == NULL)
		printf("list is empty\n");
	else if( (*p) ->next == *p)
		{
			free(*p);
			*p = NULL;
		}

	else
		{
			temp = *p;
			temp = temp->next;
			(*p)->next = temp->next;
			free(temp);
		}
	 
}

void end_delete(struct node** p)
{
	struct node* temp;
	if(*p == NULL)
		printf("list is empty\n");
	else if((*p) ->next == *p)
		{
			free(*p);
			*p = NULL;
		}

	else
		{
			struct node* prev;
			prev=(*p)->next;
			temp = *p;
			while(prev->next!=(*p))
			{
				prev=prev->next;
			}
			temp=*p;
			prev->next=(*p)->next;
			*p=prev;
			free(temp);
		}
	 
}














