
#include <stdio.h>
#include <stdlib.h>

// Node of the circulat linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Handle of the list.
// Head points to the first node in the list.
// Tail points to the last node in the list.
typedef struct List
{
    Node *head;
    Node *tail;
    int length;
} List;

// initializes a cirucular linked list
List* initialize_list();

// Creates a node and stores the data in it.
Node* create_node(int data);

// Inserts data at offset position pos. No operation is required if pos is out of range.
void position_insert(List* cll, int data, int pos);

// Deletes the node at position pos. No operation is required if pos is out of range.
void position_delete(List* cll, int pos);

// Print the data present in the safe node according to the josephus problem.
int josephus(List* cll,int k);

// Prints the entire list. Prints "EMPTY" if the list is empty.
void display(List* cll);

// Deallocates resources held by the list
void destroy_list(List*);

int main()
{

    List* cll = initialize_list();
    int ele,choice,pos,k;
    
    do
    {
        scanf("%d",&choice);

        switch(choice)
        {
            // Insert at position;
            case 1:
                scanf("%d %d",&ele,&pos);
                position_insert(cll,ele,pos);
                break;

            // Delete at position
            case 2:
                scanf("%d",&pos);
                position_delete(cll, pos);
                break;

            // Josephus problem
            case 3:
                scanf("%d",&k);
                ele = josephus(cll,k);
                printf("%d\n",ele);
                break;

            // Print entire list
            case 4:
                display(cll);
                break;        
        }
    }
    while (choice != 0);

    destroy_list(cll);
    return 0;
}

List* initialize_list()
{
    List* cll = (List*)malloc(sizeof(List));
    cll->head = NULL;
    cll->tail = NULL;
    cll->length = 0;
    return cll;
}

Node* create_node(int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp -> next = NULL;
    temp -> data = data;
    return temp;
}

void position_insert(List* cll, int data, int pos)
{
    Node* newNode = create_node(data);
    Node* cur = cll -> head;
    Node* prev = cll -> tail;
    if(pos>=0 && pos<=cll->length){
        for(int i = 0;i<pos;++i){
            prev = cur;
            cur = cur->next;
        }
        if(cur){
            prev -> next = newNode;
            newNode -> next = cur;
            if(pos == 0)
                cll->head = newNode;
            else if(pos == cll->length)
                cll->tail = newNode;
        }
        else{
            cll->head = newNode;
            cll->tail = newNode;
            newNode->next = newNode;
        }
        ++cll->length;
    }
}

void position_delete(List* cll, int pos)
{
    Node* prev = cll->tail;
    Node* cur = cll->head;
    if(pos>=0 && pos<cll->length){
        for(int i = 0;i<pos;++i){
            prev = cur;
            cur = cur->next;
        }
        if(cur == prev){
            free(cur);
            cll->head = NULL;
        }
        else{
            prev->next = cur->next;
            free(cur);
            if(pos == 0){
                cll->head = prev -> next; 
            }
            else if(pos == cll->length-1){
                cll->tail = prev;
            }
        }
        --cll->length;
    }
}

int josephus(List* cll, int k)
{
    Node* cur = cll->head;
    Node* prev = cll->tail;
    for(int i=0;i<=k;++i){
        prev = cur;
        cur = cur->next;
    }
    while(cll->length>1){
        prev->next=cur->next;
        free(cur);
        --cll->length;
        cur = prev->next->next;
        prev = prev->next;
    }
    cll->head = prev;
    cll->tail = prev;
    prev -> next = prev;
    return prev->data;
}

void display(List* cll)
{
    Node* cur = cll->head;
    if(cur){
        do{
            printf("%d ", cur->data);
            cur = cur->next;
        }while(cur!=cll->head);    
    }
    else{
        printf("EMPTY");
    }
    printf("\n");
}

void destroy_list(List* cll)
{
    free(cll);
}