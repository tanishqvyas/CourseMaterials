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
void del_from_end(NODE**);
void ins_at_pos(int ,int, NODE**);
void del_at_pos(int, NODE**);
void display(NODE**);
void insert_in_order(int, NODE**);
int find_key(int, NODE**);

int main()
{
	int choice,x,x1,pos;
	NODE *head, *ptr;
	head=NULL;
	printf("Enter your choice \n1) Insert data at front of the list\n2) Insert data at end of the list\n3) Display the list");
	printf("\n4) Delete data from front of the list\n5) Delete data from end of the list\n6) Insert data at a given position\n7) Delete data at a given position \n");
	printf("8) Insert data in ordered manner \n9) Find the data");
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
			//printf("The deleted element is  %d\n", x1 );
				}
				break;
		case 5: {
			del_from_end(&head);
			//printf("The deleted element is  %d\n", x1 );
				}
				break;
		case 6: {
			printf("Enter the element and its position to be inserted ");
			scanf("%d%d",&x,&pos);
			ins_at_pos(x,pos, &head);
				}
				break;
		case 7: {
			printf("Enter the position of the node to be deleted ");
			scanf("%d", &pos);
			del_at_pos(pos, &head);
				}
				break;
		case 8: {
			printf("Ordered Insertion\n Enter the element");
			scanf("%d", &x);
			insert_in_order(x, &head);
				}
				break;
		case 9: {
			printf("Search a key element");
			scanf("%d", &x);
			x=find_key(x, &head);
			if (x) printf("successful search");
			else  printf("unsuccessful search");
				}
				break;
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

void del_from_front(NODE** head)
{
	NODE *temp; 
	int x;
	if (*head == NULL)
		printf("List is empty");
	else {
		temp=*head;
		*head = (*head)->link;
		printf("deleted element is %d",temp->data);
		free(temp);
		return; 
	}
}

void del_from_end(NODE** head)
{
	NODE *temp, *prev; 
	int x;
	if (  *head == NULL)
		printf("List is empty");
	else if((*head)->link==NULL)
	{
		temp=*head;
		*head=NULL;
		free(temp); 
	}
	else {
		temp=*head;
		while(temp->link!=NULL)
		{
			prev =temp;
			temp=temp->link;
		}
		prev->link=NULL;
		printf(" The deleted element is %d", temp->data);
		free(temp);
	}
}


void ins_at_pos(int x,int pos, NODE** head)
{
	int i=1;
	NODE *temp, *prev, *ptr;
	ptr = create_node(x);
	//if(head==NULL && pos==1) 
	//  head=ptr;  
	if(pos==1) 
	{
		ptr->link = *head;
		*head=ptr;
	}
	else  {
		temp=*head;
		while(temp->link!=NULL && i< pos)
		{
			prev = temp;
			temp=temp->link;i++;
		}
		if(pos == i)
		{
			ptr->link = temp;
			prev->link = ptr;
		}
		else if(++i==pos)
			temp->link=ptr;
		else printf("Invalid Position");
	}
}

void del_at_pos(int pos, NODE** head)
{
	int i=1; 
	NODE *temp, *prev;
	if(*head==NULL) 
		printf("Empty List");
	else {
		temp=*head;
		if(pos==1) 
		{ 
			*head = (*head)->link;
			free(temp);
		}
		else {  
			while(temp->link!=NULL && i< pos)
			{ prev = temp;
			temp=temp->link; i++;
			}
			if(pos == i)
			{  
				prev->link = temp->link;
				free(temp);
			}
			else printf("Invalid Position");
		}
	}
}

void insert_in_order(int x, NODE** head)
{
	NODE *temp, *prev, *ptr;
	ptr = create_node(x);
	if(*head==NULL) 
		*head=ptr;
	else if (ptr->data >= (*head)->data)
	{
		ptr->link=*head;
		*head=ptr;
	}

	else  {
		temp=*head;
		while(temp!=NULL && temp->data > ptr->data)
		{
			prev = temp;
			temp=temp->link;
		}
		//if(temp->data > ptr->data)
		//   { 
		ptr->link=temp;
		prev->link=ptr;
		//     }
		//    else temp->link=ptr;
	}
}

int find_key(int key, NODE** head)
{
	NODE *temp;
	temp=*head;
	while(temp->link!=NULL)
	{
		if(temp->data==key)return 1;
		temp=temp->link;
	}
	return 0;
}
