#include<stdlib.h>
#include<stdio.h>
struct node
{
  int data;
  struct node *next,*prev;
};
struct dequeue
{
  struct node *front;
  struct node *rear;
};

void qdisplay(struct dequeue);
void qinsert_head(int ,struct dequeue*);
void qinsert_tail(int ,struct dequeue*);
int qdelete_head(struct dequeue*);
int qdelete_tail(struct dequeue*);
int main()
{
  int k,x,ch;
  struct dequeue dq; 
  dq.front=dq.rear=NULL;
 
  while(1)
  {
    qdisplay(dq);
    printf("\n1..insert head");
    printf("\n2..insert Tail");
    printf("\n3..Delete Head");
    printf("\n4..Delete Tail");
    printf("\n5..display");
    printf("\n6..EXIT");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:printf("Enter the value..");
              scanf("%d",&x);
              qinsert_head(x,&dq);
               break;
       case 2:printf("Enter the value..");
              scanf("%d",&x);
              qinsert_tail(x,&dq);      
              break;
       case 3:k=qdelete_head(&dq);
              printf("Element deleted = %d\n",k);
              break;
       case 4:k=qdelete_tail(&dq);
              printf("Element deleted = %d\n",k);
              break;
        case 5:qdisplay(dq); 
   }
  }
 }

   void qinsert_head(int x,struct dequeue *dq)
   {
     struct node *temp;

     temp=(struct node*)malloc(sizeof(struct node));
     temp->data=x;
     temp->prev=temp->next=NULL;

     if(dq->front==NULL)
        dq->front=dq->rear=temp;
      else
       {
          temp->next=dq->front;
          dq->front->prev=temp;
          temp->prev=NULL;
          dq->front=temp;
       }
   }


  void qinsert_tail(int x,struct dequeue* dq)
  {
    struct node *temp;

     temp=(struct node*)malloc(sizeof(struct node));
     temp->data=x;
     temp->prev=temp->next=NULL;

     if(dq->front==NULL)
        dq->front=dq->rear=temp;
      else
        {
          dq->rear->next=temp;
          temp->prev=dq->rear;
          dq->rear=temp;
        }
   }

  int qdelete_head(struct dequeue* dq)
  {
     struct node *q;
     int x;
     if(dq->front==NULL)
       return -1;
           
    q=dq->front;
     x=q->data;
    if(dq->front==dq->rear)//only one node
      dq->front=dq->rear=NULL;
    else
      {
        dq->front=dq->front->next;
        dq->front->prev=NULL;
      }
      free(q);
     return x;
   }

  int  qdelete_tail(struct dequeue* dq)
  {
    struct node *q;
     int x;
     if(dq->front==NULL)
       return -1;
           
    q=dq->rear;
     x=q->data;
    if(dq->front==dq->rear)//only one node
      dq->front=dq->rear=NULL;
    else
     {
        dq->rear=dq->rear->prev;
        dq->rear->next=NULL;
      }
     free(q);
      return x;
   }

    void qdisplay(struct dequeue dq)
    {
       struct node *p;
      if(dq.front==NULL)
        printf("Empty Queue...\n");
      else
      {
       for(p=dq.front;p!=dq.rear;p=p->next)
       {
          printf("%d ",p->data);
       }
       printf("%d ",p->data);   
      }
   }
   
 
    

        
          







 
    


   
     









