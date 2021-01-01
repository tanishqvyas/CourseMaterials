#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node* node;

//node tree_initialize(node root);
node tree_insert(node root, int data);

void inorder(node root);
void preorder(node root);
void postorder(node root);
node create_node(int data);

node tree_destroy(node root);

int main()
{
    int choice, loop = 1;
    node root;
    root  = NULL;
    while (loop)
    {
        scanf("%d", &choice);
        switch (choice)
        {
            int number_of_elements, element, index;
            int data;
        case 1:
            /* Insert elements */
            scanf("%d", &element);
            root = tree_insert(root, element);
            break;
        case 2:
            /* Print elements in the inorder fashion */
            preorder(root);
            printf("\n");
            break;
        case 3:
            /* Print elements in the preorder fashion */
            inorder(root);
            printf("\n");
            break;
        case 4:
            /* Print elements in the postorder fashion */
            postorder(root);
            printf("\n");
            break;
        default:
            root = tree_destroy(root);
            loop = 0;
            break;
        }
    }
    return 0;
}

node create_node(int data)
{
    node temp = (node)malloc(sizeof(struct node));
    temp->left = NULL;
    temp->right = NULL;
    temp->data = data;
    return temp;
}


node tree_insert(node root, int data)
{
    node ele = create_node(data);

    if(root == NULL)
    {
        return ele;
    }
    
    else
    {
        if(data < root->data)
        {
            root->left = tree_insert(root->left, data);
        }
        
        else if(data > root->data)
        {
            root->right = tree_insert(root->right, data);
        }
        return root;
    }

}
/*
node tree_insert(node root, int data)
{
    node ele = create_node(data);
    
    if(root == NULL)
    {
        return ele;
    }
    
    else
    {
        node cur = root;
        node prev = NULL;
        
        while(cur != NULL)
        {
            if(data < cur->data)
            {   
                prev = cur;
                cur = cur->left;
            }
            else if(data > cur->data)
            {
                prev = cur;
                cur = cur->right;
            }
        }
        
        if(data < prev->data)
        {
            prev->left = ele;
            return root;
        }
        else if(data > prev->data)
        {
            prev->right = ele;
            return root;
        }
            
            
        
    }
}
*/

void postorder(node root)
{
    if(root != NULL)
    {

        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }


}

void preorder(node root)
{
    if(root != NULL)
    {   
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }

    return;
    
}

void inorder(node root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }

    return;

}



node tree_destroy(node root)
{
    return NULL;
}
