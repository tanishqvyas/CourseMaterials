#include<stdio.h>
#include <stdlib.h>


struct elemento
{
	int data;
	struct elemento *link;
	
};
typedef struct elemento* NODE;


NODE create_node(int element)
{
	NODE temp = (NODE) malloc(sizeof(struct elemento));
	temp->link = NULL;
	temp->data = element;
	return temp;
}// func create_node ends here

NODE insert_end(NODE head,int element)
{
	if(head==NULL)
	{
		NODE temp = create_node(element);
		return temp;
	}

	else
	{

		NODE temp = create_node(element);
		NODE first = head;
		while(first->link!=NULL)
		{
			first= first->link;
		}
		first->link = temp;
		return head;
	}

}//func insert_end ends here


NODE delete_end(NODE head)
{
	if(head == NULL)
	{
		printf("Empty List Nothing to delete\n");
		return head;
	}
	else
	{
		NODE first = head;
		if(first->link !=NULL)
		{			
			NODE prev = NULL;
			while(first->link != NULL)
			{
				prev = first;
				first = first->link;
			}
			printf("THe deleted node is : %d\n",first->data);
			free(first);
			prev->link = NULL;
			return head;
		}

		else // for case when we have only 1 element
		{
			printf("THe deleted node is : %d\n",first->data);
			free(first);
			return NULL;
		}

	}

}// func delete_end ends here

void display(NODE head)
{
	if (head==NULL)
	{
		printf("Empty List\n");
		return;
	}

	else
	{
		NODE first = head;
		while(first != NULL)
		{
			printf("%d ",first->data);
			first = first->link;
		}
		return;
	}

}// func display ends here


NODE insert_front(NODE head,int element)
{
	if(head == NULL)
	{
		NODE temp = create_node(element);
		return temp;
	}

	else
	{
		NODE temp = create_node(element);
		temp->link = head;
		return temp;
	}

}// func insert_front ends here

NODE delete_front(NODE head)
{
	if(head == NULL)
	{
		printf("NOTHING to delete bro\n");
		return head;
	}

	else
	{
		NODE temp = head->link;
		free(head);
		return temp;
	}
}

NODE insert_pos(NODE head,int element,int pos)
{
	if(head == NULL)
	{
		//yet to implement
	}
}

NODE delete_pos(NODE head,int pos)
{
	//yet to implement
}


void main()
{
	NODE head = NULL;
	int num;

	XY:
	printf("\n\n\nMENU\n\n");
	printf("1. Insert End\n");
	printf("2. Deletion End\n");
	printf("3. Display\n");
	printf("4. Insert At Beginning\n");
	printf("5. Insert At position - n\n");
	printf("6. Deletion Front\n");
	printf("7. Deletion at Position - n\n");
	printf("8. Quit\n");


	int choice;
	printf("Enter choice : ");
	scanf("%d",&choice);

	switch(choice)
	{

		case 1:
			
			printf("Enter the number : ");
			scanf("%d",&num);
			head = insert_end(head,num);
			goto XY;
			break;
		
		case 2:
		
			head = delete_end(head);
			goto XY;
			break;
		
		case 3:
		
			display(head);
			goto XY;
			break;
		
		case 4:
			printf("Enter the number : ");
			scanf("%d",&num);
			head = insert_front(head,num);
			goto XY;
			break;
	
		case 5:
			break;
		
		case 6:
			head = delete_front(head);
			goto XY;
			break;
		
		case 7:
			break;
		
		case 8:
			// to quit out of the switch
			break;									
		
		default:
			printf("Enter a Valid option from 1 - 8\n");
			goto XY;
			break;


	}
}