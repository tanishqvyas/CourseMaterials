#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct element
{
	int key;
	char name[100];
	int mark;
};

void insert(struct element *ht,int size,int key,char *name);
void delete(struct element *ht, int size, int key);
void display(struct element *ht, int size);
int hash1(int key);

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
				insert(ht,tablesz,key,name);
				break;

			case 2: display(ht,tablesz);
				break;

			case 3: printf("enter the element to delete\n");
				scanf("%d",&key);
				delete(ht,tablesz,key);
				break;
			
		}
	}
}

void delete(struct element *ht, int size, int key)
{
	int i,index,h;
	index=key%size;
	h=1;
	for(h=1;h<size;h++)
	{
		if(ht[index].key==key)
		{
			ht[index].mark=0;
			return;
		}
		index=(index+hash1(key))%size;
		
	}	
		
}

void insert(struct element *ht,int size,int key,char *name)
{
	int i,index,h;
	index=key%size;
	h=1;
	i=index;
	for(h=1;h<=size;h++)
	{
		if(ht[i].mark==0)
		{
			ht[i].key=key;
			strcpy(ht[i].name,name);
			ht[i].mark=1;
			return;
		}

	index=(index+hash1(key))%size;
	}		
}

int hash1(int key)
{
	return key%9;
}


void display(struct element *ht,int size)
{

	int i;

	for(i=0;i<size;i++)
		{
		printf("%d: ",i);
		if(ht[i].mark!=0)
			{
			printf("key :%d, Name :%s", ht[i].key,ht[i].name);
			
		}
		printf("\n");
		}	
}



