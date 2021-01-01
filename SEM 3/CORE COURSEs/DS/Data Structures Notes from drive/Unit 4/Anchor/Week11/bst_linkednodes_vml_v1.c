#include <stdio.h>
#include <stdlib.h>

typedef struct tree {

    int data;
    struct tree *leftChild;
    struct tree *rightChild;

} TREE;




TREE* getnode(int key) {

    TREE  *ptr;
    ptr = (TREE*)malloc(sizeof(TREE));
    ptr -> data = key;              
    ptr -> leftChild = NULL;
    ptr -> rightChild = NULL;
    return ptr;

}

void insert(TREE **proot,int key) {//proot pointer to root

    TREE *p;
    TREE *temp;
    TREE *previousTemp;

    p = getnode(key);
   
    if(*proot == NULL) {

        *proot = p;

    }

    else {

         temp = *proot;

         while(temp != NULL) {

              if(temp -> data < key) {

                  previousTemp = temp;
                  temp = temp -> rightChild;

              }

              else {

                   previousTemp = temp;
                   temp = temp -> leftChild;
              }

         }

          if(previousTemp -> data < key)
              previousTemp -> rightChild = p;

          else
              previousTemp -> leftChild = p;
     
    }
}


void inorder(TREE *n) {

    if(n != NULL) {

         inorder(n -> leftChild);
         printf("%d\n", n -> data);
         inorder(n -> rightChild);
    }
}


void preorder(TREE *n) {

     if(n != NULL) {

          printf("%d\n", n -> data);
          preorder(n -> leftChild);
          preorder(n -> rightChild);

     }

}


void postorder(TREE *n) {

     if(n != NULL) {

          postorder(n -> leftChild);
          postorder(n -> rightChild);
          printf("%d\n", n -> data);

     }

}


void search(TREE *root,int key) {

     TREE *temp;
     temp = root;
     
     while(temp != NULL) {
     
          if(key < temp -> data) {
          
              temp = temp -> leftChild;

          }

          else if(key > temp -> data) {
          
              temp = temp -> rightChild;

          }

          else {
          
               printf("\nKey Found");
               return;

          }
     }

     printf("\nKey Not Found");
}




void delete(TREE **proot,int key) 
{

    TREE *current = *proot;
    TREE* previous;
    TREE* successor;
    TREE* replacement;

    if(*proot == NULL)
	{

        printf("\nTree Is Empty\n");
    }

    else {

        previous = NULL;

        while(current != NULL) 
		{   

            if(key == current -> data)
                break;

            else if(key > current -> data) 
			{

                previous = current;
                current = current -> rightChild;
            }

            else 
			{

                previous = current;
                current = current -> leftChild;
            }
        }   

        if(current == NULL) {
         
            printf("\nThe Element To Be Deleted Is Not Found");
        }

        else {
			
			

            if((current -> rightChild) == NULL && (current -> leftChild) == NULL)
                replacement = NULL;


            else if((current -> rightChild) == NULL && (current -> leftChild) != NULL)
                   replacement = current -> leftChild;


            else if((current -> leftChild) == NULL && (current -> rightChild) != NULL)
                replacement = current -> rightChild;


            else if((current -> leftChild) != NULL && (current -> rightChild) != NULL)
			{
                
                // To find Successor, take a right, and keep moving left. `
                successor = current -> rightChild;

                while((successor -> leftChild) != NULL) 
                    
                    successor = successor -> leftChild;
                

                successor -> leftChild = current -> leftChild;
                replacement = current -> rightChild;
        }
		}

		

        if(current == *proot)
            *proot = replacement;

        else if(current == (previous -> rightChild))
            previous -> rightChild = replacement;

        else
            previous -> leftChild = replacement;
		printf("deleting the node %d",current->data);
        free(current);
    }
}



int main() {

     int i, n, num, choice, key;
     int number;
     TREE *root = NULL;

     for(;;) {
     
          printf("\nEnter Choice:\n1.Insert into BST  \n2.Display BST By Using Inorder Traversal\n3.Display BST By Using Preorder Traversal\n4.Display BST By Using Postorder Traversal\n5.Search For An Element\n6.Delete An Element\n7. Exit\n");
          scanf("%d",&choice);
         
          switch(choice) {
          
               case 1:
                      
                       printf("\nEnter A Number ");
                       scanf("%d", &num);
                       insert(&root,num);

                     

                      break;

               case 2:inorder(root);
                      break;

               case 3:preorder(root);
                      break;

               case 4:postorder(root);
                      break;

               case 5:printf("\nEnter The Element To Be Searched ");
                      scanf("%d", &key);
                      search(root,key);
                      break;

               case 6:printf("Enter Element To Delete\n");
                      scanf("%d", &number);
                      delete(&root,number);
                      break;

               case 7:exit(0);
               
               default:printf("\nInvalid Choice");
          }
     }

    return 0;
}




















 

