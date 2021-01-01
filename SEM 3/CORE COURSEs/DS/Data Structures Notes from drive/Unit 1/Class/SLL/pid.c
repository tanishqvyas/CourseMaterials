// position inseretion and position deletion

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}; 

typedef struct node NODE;
NODE *create(int x);
void FI(int x, NODE** head);
void PI(int x, int pos, NODE** head);
int main()
{
	int choice, x,pos,x1;
	NODE *head, *ptr;
	printf(1: front insertion\n  2: position insertion\n  3: display\n");
	while(1)
	{
		switch(choice)
		{
			case 1: {
				printf("enter the item\n");
				scanf("%d", &x);
				FI(x, &head);
				} break;

			case 2: {
				printf("enter the element and position\n");
				scanf("%d%d", &x, &pos);
				PI(x,pos,&head);
				}break;
			case 3: {
				display(&head);
				} break;
			default : printf("invalid\n");
		}
	}
}

NODE *create(int x)
{
	NODE *ptr = ((NODE*) malloc (sizeof(NODE)));
	ptr->data = x;
	ptr->link = NULL;
	return ptr;
}
	
void FI(int x, NODE** head)
{
	NODE *ptr = create(x);
	if(head==NULL)
		*head = ptr;
	else
		{
			ptr->link = *head;
			*head=ptr;
		
		}
}

void PI(int x, int pos, NODE** head)
{
	int i=1;
	NODE *ptr , *temp, *prev;
	ptr = create();
	if(pos ==1)
	{
		ptr->link = *head;
		*head = ptr;
	}
	else
	{
		temp = *head;
		while(temp->next !=NULL && i < pos)
		{
			prev = temp;
			temp = temp->next;
			i++;
		}
		if(pos == i)
		{
			prev->link = ptr;
			ptr->link = temp;
		}
		else if( ++i == pos)
			temp ->link = ptr;

		else 	
			printf("Invalid\n");
	}
	
}


