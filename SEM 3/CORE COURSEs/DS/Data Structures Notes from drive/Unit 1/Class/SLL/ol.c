#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int key;
	struct node *link;
}node_t;

typedef struct mylist
{
	struct node *head;
}list_t;

void init(list_t *p);
void insert_list(list_t *p,int ele);
int sum_of_key(list_t *p);
int find_middle_node(list_t *p);
int find_last_node(list_t *p);
void free_list(list_t *p);
void disp_list(list_t *p);
void copy(list_t *p,list_t *t);
int main()
{
	list_t l;
	init(&l);
	list_t nl;
	int ele;int op;int sum=0;int res;
	int last_ele; int middle_ele;
	printf("Enter your	option:\n1:insert\n2:display\n3:sum_of_nodes\n4:find_last_node\n5:find_middle_node\n6:copy list\n0:exit\n");
	scanf("%d",&op);
	while(op)
		{
		switch(op)
		{
			case 1:printf("Enter key element to insert into ordered list\n");
				scanf("%d",&ele);
				insert_list(&l,ele);
			break;

			case 2:disp_list(&l);
			break;

			case 3:sum=sum_of_key(&l);
				printf("Sum of nodes=%d\n",sum);
				break;

			case 4:last_ele=find_last_node(&l);
				printf("Last node is %d\n",last_ele);
				break;

			case 5:middle_ele=find_middle_node(&l);
				printf("Middle node is %d \n",middle_ele);
				break;

			case 6:copy(&l,&nl);
				disp_list(&nl);
				break;
		}	
		printf("Enter youroption:\n1:insert\n2:display\n3:sum_of_nodes\n4:find_last_node\n5:find_middle_node\n6:copy list\n0:exit\n");
		scanf("%d",&op);
		}
free_list(&l);
return 0;
}

void init(list_t *p)
	{
		p->head=NULL;
	}

void insert_list(list_t* p,int ele)
{
	node_t *temp;
	temp=(node_t*)malloc(sizeof(node_t));
	temp->key=ele;
	temp->link=NULL;
	if(p->head == NULL)
		{
		p->head=temp;
		temp->link=NULL;
		}
	else
	{
	node_t* prev=NULL;
	node_t* pres=p->head;
	while(pres!=NULL && pres->key < temp->key)
	{
		prev=pres;
		pres=pres->link;
	}
	if(prev==NULL)
	{
	temp->link=pres;
	p->head=temp;
	}
	else
	{
	temp->link=pres;
	prev->link=temp;
	}
	}//else
}


int sum_of_key(list_t *p)
{
	struct node *q=p->head;
	int sum=0;
	while(q!=NULL)
	{
		sum+=q->key;
		q=q->link;
	}
	return sum;
}

int find_last_node(list_t *p)
{
	struct node *pres=p->head;
	while(pres->link!=NULL)
	{
		pres=pres->link;
	}
	return pres->key;
}


int find_middle_node(list_t *p)
{
	struct node *prev=p->head;
	struct node *pres=p->head;
	while(pres!=NULL && pres->link!=NULL)
	{
	pres=pres->link->link;
	prev=prev->link;
	}
	return prev->key;
}


void copy(list_t *p,list_t *t)
{
	node_t *q=p->head;
	init(t);
	while(q!=NULL)
		{
		insert_list(t,q->key);
		q=q->link;
		}
}

void free_node(node_t *q)
{
	node_t *r=q;
	while(q!=NULL)
	{
		r=q->link;
		printf("Freed node with key is %d\n",q->key);
		free(q);
		q=r;
	}
}

void free_list(list_t *p)
{
	if(p->head==NULL)
		{
		printf("List is Empty!\n");
		}
	else
		{
		free_node(p->head);
		}
}

void print(node_t *q)
{
	printf("Elements in the list are:\n");
	while(q!=NULL)
	{
	printf("%d\n",q->key);
	q=q->link;
	}
}

void disp_list(list_t *p)
{
	if(p->head==NULL)
	{
	printf("List is Empty!\n");
	}
	else
	{
	print(p->head);
	}
}
/*

typedef struct node
{
int key;
struct node *link;
}node_t;
typedef struct mylist
{
struct node *head;
}list_t;
void init(list_t *p);
void insert_list(list_t *p,int ele);
int sum_of_key(list_t *p);
int find_middle_node(list_t *p);
int find_last_node(list_t *p);
void free_list(list_t *p);
void disp_list(list_t *p);
void copy(list_t *p,list_t *t);*/
