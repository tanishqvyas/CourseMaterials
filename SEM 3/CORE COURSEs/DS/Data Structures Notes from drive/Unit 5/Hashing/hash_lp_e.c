#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct element
{
	int key;
	char name[100];
	int mark;
};
void search(struct element *ht, int size, int key,int count);
void display(struct element *ht,int size);
void delete(struct element *ht, int size, int key,int *count);
void insert(struct element *ht,int size,int key,char *name, int *count);

int main()
{
	int ch,key,noe,i;
	int tablesz;
	char name[100];
	struct element *ht;
	printf("enter the size of HT\n");
	scanf("%d",&tablesz);
	ht=(struct element*)malloc(tablesz * sizeof(struct element));

	for(i=0;i<tablesz;i++)
	ht[i].mark=0;
	noe=0;

	while(1)
	{
		printf("1:insert\n 2: display\n 3:delete\n 4:search\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("enter key\n");
				scanf("%d",&key);
				printf("enter name\n");
				scanf("%s",name);
				insert(ht,tablesz,key,name,&noe);
				break;

			case 2: display(ht,tablesz);
				break;

			case 3: printf("enter the element to search\n");
				scanf("%d",&key);
				search(ht,tablesz,key,noe);
				break;

			case 4: printf("enter the element to delete\n");
				scanf("%d",&key);
				delete(ht,tablesz,key,&noe);
				break;
			
		}
	}
}

void search(struct element *ht, int size, int key,int count)
{
	int i, index;
	if(count==0)
		{
			printf("Table is empty\n");
			return;
		}

	index=key%size;
	i=0;
	while(ht[index].key !=key && i<count)
	{
		index=(index+1)%size;
		i++;
	}

	if(ht[index].key==key)
	{
		printf("Found! Details....\n");
		printf("Key =%d",ht[index].key);
		printf("Name=%s",ht[index].name);
	}
	else
	{
			printf("not found\n");
			return;
	}
}


void delete(struct element *ht, int size, int key,int *count)
{
	int i, index;
	if(*count==0)
		{
			printf("Table is empty\n");
			return;
		}

	index=key%size;
	i=0;
	while(ht[index].key !=key && i<(*count))
		{
		index=(index+1)%size;
		i++;
		}

	if(ht[index].key==key)
	{
		ht[index].mark=0;
		--(*count);
	}
	else
		{
			printf("not found\n");
			return;
		}
}




void insert(struct element *ht,int size,int key,char *name, int *count)
{
		int index;
		if(*count==size)
			{
			printf("Table is full\n");
			return;
			}
		index=key%size;
		while(ht[index].mark==1)
			index=(index+1)%size;
		
		ht[index].key=key;
		strcpy(ht[index].name,name);
		ht[index].mark=1;
		++(*count);
		return;
}


void display(struct element *ht,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d: ",i);
		if(ht[i].mark!=0)
			printf("Key :%d,Name :%s",ht[i].key,ht[i].name);
		printf("\n");
	}
}



