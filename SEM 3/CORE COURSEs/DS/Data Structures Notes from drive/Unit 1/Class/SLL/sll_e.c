#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};

typedef struct node NODE;

NODE* create_node(int);
void insert_at_front(int, NODE**);
void insert_at_end(int, NODE**);
void del_from_front(NODE**);
void display(NODE**);

int main()
{
	int choice,x,x1,pos;
	NODE *head, *ptr;
	head=NULL;
	printf("Enter your choice \n1) Insert data at front of the list\n2) Insert data at   end of the list\n3) Display the list");
	printf("\n4) Delete data from front of the list\n");
	while(1)
	{
		printf("\nEnter your choice\n");
		scanf("%d", &choice);
		switch(choice)
		{

		case 1: {
			printf("Enter the element");
			scanf("%d", &x);
			insert_at_front(x, &head);
				}
				break;

		case 2: {
			printf("Enter the element");
			scanf("%d", &x);
			insert_at_end(x, &head);
				}
				break;

		case 3: {
			printf("The element in the list are: \t");
			display(&head);
				}
				break;
		case 4: {
			del_from_front(&head);
			
				}
				break;
		case 5: {
			del_from_end(&head);
		
				}
				break;
		;
		default: {
			printf("Invalid choice \t"); 
			exit(1);
				 }
				 break;
		}
	}
	return(0);
}

NODE* create_node(int x)
{
	NODE *ptr = (NODE *)(malloc(sizeof(NODE)));
	ptr->data=x;
	ptr->link=NULL;
	return ptr;
}

void insert_at_front(int x, NODE **head)
{
	NODE *ptr = create_node(x);
	if (*head == NULL)
		*head = ptr;
	else {
		ptr->link=*head;
		*head=ptr;
	}
}

void insert_at_end(int x, NODE **head)
{
	NODE *temp;
	NODE *ptr = create_node(x);
	if( *head==NULL)
		*head=ptr;
	else {
		temp=*head;
		while(temp->link!=NULL)
			temp=temp->link;
		temp->link=ptr;
	}
}

void display(NODE** head)
{
	NODE *temp; 
	if(*head==NULL) 
		printf("Empty List ");
	else {
		temp=*head;
		printf("The List is.....\n");
		while(temp!=NULL)
		{ 
			printf("\t%d", temp->data); 
			temp=temp->link;
		}     
	}
}

