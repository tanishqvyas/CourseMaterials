#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *link;
};
typedef struct Node* Node;



Node create_node(int element)
{
	Node temp = (Node)malloc(sizeof(struct Node));
	temp->link = temp;
	temp->data= element;
	return temp;
}

Node insert_end(Node head, int element)
{
	Node temp = create_node(element);

	if(head->data==0)
	{
		head->link = temp;
		temp->link = head;
	}

	else
	{
		Node first = head;
		while(first->link != head)
		{
			first = first->link;
		}
		first->link = temp;
		temp->link =head;

	}

	head->data++;
	return head;
}


Node delete_end(Node head)
{
	if(head->data==0)
	{
		printf("EMPTY LIST Nothing to delete\n");
		return head;
	}

	else
	{
		Node first = head->link;
		Node prev = head;
		while(first->link != head)
		{
			prev = first;
			first = first->link;
		}
		Node temp = first;
		first = first->link;
		free(temp);
		prev->link = first;

	}

	head->data--;
	return head;
}


void display(Node head)
{
	if(head->data==0)
	{
		printf("EMPTY\n");
	}
	else
	{
		Node first = head->link;

		while(first->link != head )
		{
			printf("%d ",first->data);
			first = first->link;
		}
		printf("%d\n",first->data);
	}
	return;
}



Node insert_front(Node head, int element)
{
	Node ele = create_node(element);

	if(head->data==0)
	{
		head->link = ele;
		ele->link = head;
	}

	else
	{
		Node first = head->link;
		head->link = ele;
		ele->link =first;
	}

	head->data++;
	return head;

}


Node delete_front(Node head)
{
	if(head->data==0)
	{
		printf("EMPTY NOTHING TO DELETE\n");
		return head;
	}

	else if (head->data == 1)
	{
		Node temp = head->link;
		free(temp);
		head->link = head;

	}

	else
	{
		Node first = head->link;
		Node temp = first;
		first = first->link;
		free(temp);
		head->link = first;
	}

	head->data--;
	return head;
}


int get_josephus(int num_of_nodes)
{
	
	//making circular linked list without head
	Node head = create_node(1); 
    Node prev = head; 
    for (int i = 2; i <= num_of_nodes; i++) 
    { 
        prev->link = create_node(i); 
        prev = prev->link; 
    } 
    prev->link = head;


    Node ptr1 = head, ptr2 = head; 
    while(ptr1->link != ptr1) 
    {  
        int count = 1; 
        while (count != 2) 
        { 
            ptr2 = ptr1; 
            ptr1 = ptr1->link; 
            count++; 
        } 
  
        ptr2->link = ptr1->link; 
        ptr1 = ptr2->link; 
    } 
  
  	return ptr1->data;

}


void main()
{
	Node head = create_node(0);
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
	printf("8. Get Josephus Node \n");
	printf("9. Quit\n");


	int choice,joseph;
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
			
			joseph = get_josephus(head->data);
			printf("Position : %d\n",joseph);
			goto XY; 
			break;

		case 9:
			// to quit out of the switch
			break;									
		
		default:
			printf("Enter a Valid option from 1 - 8\n");
			goto XY;
			break;


	}
}