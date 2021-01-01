#include <stdio.h>
#include <stdlib.h>

// Node of the linked list
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Handle of the list. Its head points to the first node in the list.
typedef struct List {
    Node *head;
    int number_of_nodes;
} List;

// initializes a linked list
List* initialize_list();

// Creates a node and stores the data in it.
Node* create_node(int data);

// Inserts data at the beginning of the List
void insert_front(List* dll, int data);

// Deletes the node at position pos. No operation if pos is out of range.
void position_delete(List* dll, int pos);

// Return index of key in the list(0-based). Return -1 if not found
int search_list(List* dll, int key);

// Prints the entire list. Prints "EMPTY" if the list is empty.
void display(List* dll);

// Deallocates resources held by the list
void destroy_list(List* dll);

int main() {
    List* dll = initialize_list();
    int ele, choice, pos;

    do {
        scanf("%d", &choice);

        switch(choice) {
            // Insert at beginning
            case 1:
                scanf("%d", &ele);
                insert_front(dll, ele);
                break;

            // Delete at position
            case 2:
                scanf("%d", &pos);
                position_delete(dll, pos);
                break;

            // Search for element
            case 3:
                scanf("%d", &ele);
                pos = search_list(dll, ele);
                printf("%d\n", pos);
                break;

            // Print entire list
            case 4:
                display(dll);
                break;
        }
    }
    while (choice != 0);

    destroy_list(dll);
    return 0;
}

List l;
List* initialize_list() {
    l.head = NULL;
    l.number_of_nodes = 0;
    return &l;
}

Node* create_node(int data) {
    Node *new1 = malloc(sizeof(Node));
    new1->data = data;
    new1->prev = NULL;
    new1->next = NULL;
    return new1;

}

void insert_front(List* dll, int data) {
    Node *temp = create_node(data);
    if(dll->head == NULL)
        dll->head = temp;
    else
    {
        temp->next = dll->head;
        dll->head->prev = temp;
        dll->head = temp;
    }
}

void position_delete(List* dll, int pos) {
    Node *q = dll->head;
    int i = 0;
    while((q != NULL) && (i != pos))
    {
        q = q->next;
        i++;
    }
    if(q != NULL)
    {
        if((q->next == NULL) && (q->prev == NULL))
            dll->head = NULL;
        else if(q->prev == NULL)
        {
            dll->head = q->next;
            dll->head->prev = NULL;
        }
        else if(q->next == NULL)
            q->prev->next = NULL;
        else
        {
            q->prev->next = q->next;
            q->next->prev = q->prev;
        }
        free(q);
    }
    else
        return;
}

int search_list(List* dll, int key) {
    Node *temp = dll->head;
    int pos = 0;
    while(temp != NULL)
    {
        if(temp->data == key)
            return pos;
        pos++;
        temp = temp->next;
    }
    return -1;
}

void display(List* dll) {
    Node *temp = dll->head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    if(dll->head == NULL)
        printf("EMPTY");
}

void destroy_list(List* dll) {
    Node *temp = dll->head;
    while(temp != NULL)
    {
        Node *q = temp->next;
        free(temp);
        temp = q;
    }
}


