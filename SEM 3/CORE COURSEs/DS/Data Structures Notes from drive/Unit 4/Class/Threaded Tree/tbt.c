#include<stdio.h>
#include<stdlib.h>
struct Node
{
  struct Node *left, *right;
  int info;
  int lthread; 
  int rthread; 
};
typedef struct Node Node;
struct Node *insert(struct Node *root, int key) 
{ 
    // Searching for a Node with given value 
    Node *cur = root; 
    Node *prev = NULL; // Parent of key to be inserted 
    while (cur != NULL) 
    { 
        // If key already exists, return 
        if (key == (cur->info)) 
        { 
            printf("Duplicate Key !\n"); 
            return root; 
        } 
        prev = cur; // Update parent pointer 
        // Moving on left subtree. 
        if (key < cur->info) 
        { 
            if (!cur -> lthread) 
                cur = cur -> left; 
            else
                break; 
        } 
        // Moving on right subtree. 
        else
        { 
            if (!cur->rthread) 
                cur = cur -> right; 
            else
                break; 
        } 
    } //end of the while loop
    // Create a new node 
    Node *tmp = (Node *)malloc(sizeof(struct Node)); 
    tmp -> info = key; 
    tmp -> lthread = 1; 
    tmp -> rthread = 1; 
    if (prev == NULL) 
    { 
        root = tmp; 
        tmp -> left = NULL; 
        tmp -> right = NULL; 
    } 
    else if (key < (prev -> info)) 
    { 
        tmp -> left = prev -> left; 
        tmp -> right = prev; 
        prev -> lthread = 0; 
        prev -> left = tmp; 
    } 
    else
    { 
        tmp -> left = prev; 
        tmp -> right = prev -> right; 
        prev -> rthread = 0; 
        prev-> right = tmp; 
    } 
  
   return root; 
} 

struct Node *inorderSuccessor(struct Node *ptr) 
{ 
    // If rthread is set, we can quickly find 
    if (ptr -> rthread) 
        return ptr->right; 
  
    // Else return leftmost child of right subtree 
    ptr = ptr -> right; 
    while (!ptr -> lthread) 
        ptr = ptr -> left; 
    return ptr; 
} 
  
// Printing the threaded tree 
void inorder(struct Node *root) 
{ 
    if (root == NULL) 
        printf("Tree is empty"); 
  else
	{
    // Reach leftmost node 
    struct Node *ptr = root; 
    while (!ptr -> lthread) 
        ptr = ptr -> left; 
  
    // One by one print successors 
    while (ptr != NULL) 
    { 
        printf("%d ",ptr -> info); 
        ptr = inorderSuccessor(ptr); 
    } 
	}
} 
  
// Driver Program 
int main() 
{ 
    struct Node *root = NULL; 
    root = insert(root, 25); 
    root = insert(root, 1); 
    root = insert(root, 3); 
    root = insert(root, 50); 
    root = insert(root, 10); 
    root = insert(root, 15); 
    root = insert(root, 18); 
    root = insert(root, 13); 
    inorder(root); 
    return 0; 
} 
