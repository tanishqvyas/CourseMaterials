#include<stdio.h>
#include<stdlib.h>

// Node of the linked list
typedef struct Node {
	int data;
	struct Node *link;
} Node;

// Handle of the list. Its head points to the first node in the list.
typedef struct List {
	Node *head;
	int number_of_nodes;
} List;

// Initializes a linked list
List* list_initialize();

// Creates a node and stores the data
Node* create_node(int);

// Deletes the node at the given position
// Does not delete anything if position is out of range
void del_at_pos(int, List*);

// Displays the contents of the linked list in space seperated manner.
void display(List*);

// Inserts an element into an ordered linked list.
void insert_in_order(int, List*);

// Returns the index of the key in the linked list.
// Returns -1 if key not found
int find_key(int, List*);

// Destroy the list by freeing all the nodes.
void destroy_list(List*);

int main()
{
    int choice,element,position,index;

    // Initialize an empty list.
    List* sll = list_initialize();
    do
    {
        scanf("%d", &choice);
        switch(choice)
        {
            // Delete at given position
            case 1:
            {
                scanf("%d", &position);
                del_at_pos(position, sll);
            }
            break;

            // Insert element into the ordered list.
            case 2:
            {
                scanf("%d", &element);
                insert_in_order(element, sll);
            }
            break;

            // Display the list.
            case 3:
            {
                display(sll);
            }
            break;

            // Find the given key.
            case 4:
            {
                scanf("%d", &element);
                index = find_key(element, sll);
                printf("%d\n",index);
            }
            break;

            default:
                break;
        }
    }
    while(choice != 0);

    destroy_list(sll);

    return 0;
}
Node* create_node(int data)
{

    Node* p = (Node*)malloc(sizeof(Node));
    p->data = data;
    p->link = NULL;
    return p;
}

List* list_initialize()
{
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->number_of_nodes = 0;
    return list;
}



void display(List* sll)
{
    Node* p = sll->head;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->link;
    }
    printf("\n");
}

void del_at_pos(int position, List* sll)
{
   Node* p = sll->head;
   if(position<1||position>sll->number_of_nodes||p==NULL);
   else
   {
       if(position==1)
       {
           sll->head = p->link;
           free(p);
           sll->number_of_nodes--;
       }
       else
       {
           Node* temp = NULL;
           for(int i=1;i<position;i++){
               temp=p;
               p=p->link;
           }
           temp->link=p->link;
           free(p);
           sll->number_of_nodes--;
       }
   }
}




void insert_in_order(int element, List* sll)
{
    Node* p = sll->head;
    Node* ins = create_node(element);
    if(p!=NULL){
        Node* prev = NULL;
        while(p!=NULL && element<p->data){
            prev=p;
            p=p->link;
        }
        if(prev!=NULL){
         prev->link=ins;
        ins->link=p;
        sll->number_of_nodes++;
        }
        else{
            ins->link=p;
            sll->head=ins;
            sll->number_of_nodes++;
        }
    }
    else{
        sll->head = ins;
        sll->number_of_nodes++;
    }
}

int find_key(int key, List* sll)
{
    int pos = 0;

    Node*p = sll->head;
    while(p!=NULL){
        if(p->data==key){
            return pos;
        }
        p=p->link;
        pos++;
    }
    return -1;
}

void destroy_list(List* sll)
{
    Node* p=sll->head;
    Node* next;
    while(p!=NULL)
        {
            next=p->link;
            free(p);
            sll->number_of_nodes--;
            p=next;


        }
}
