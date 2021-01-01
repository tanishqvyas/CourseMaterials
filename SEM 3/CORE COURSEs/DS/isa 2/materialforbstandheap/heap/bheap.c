  #include<stdio.h>
 //implement heap by using bottom up technique
  void bot_heap(int*,int);
  void top_heap(int*,int);
  
  int main()
  {
    int h[100];//heap;
    int i,n;//no of elements
    printf("Enter the no of elements..\n");
    scanf("%d",&n);
    printf("Enter the elements..\n");
    for(i=0;i<n;i++)
      scanf("%d",&h[i]);
    bot_heap(h,n-1);//pass index of last element
    printf("After creating heap..\n");
    for(i=0;i<n;i++)
      printf("%d ",h[i]);
  }


  void bot_heap(int *h, int n)//n-index of the last element in array
  {
   int i,j,k,key;
   for(k=(n-1)/2;k>=0;k--)
   {
    j=k;
     key=h[j];
     i=2*j+1;//find the left child 
     while(i<=n)//while left child exists
     {
       if((i+1)<=n)//check whether right exits
        {
           if(h[i+1]>h[i])
              i++;//get the index of largest child
        }
       if(key<h[i])
       {
         h[j]=h[i];//move child up
         j=i;
         i=2*j+1;//find the new left child
        }
       else
        break;
     }//end while
     h[j]=key;//insert key
    }//end for
  }








 



































/*
  void heapsort(int *h, int n)
  {
    int t,i;
    void heapify(int*,int);
    //create initial heap
    bot_heap(h,n);

    for(i=n-1;i>0;i--)
    {
      //swap the first and the last number
     t=h[0];
     h[0]=h[i];
     h[i]=t;

     heapify(h,i);//recreate the heap for reduced set(by 1)
    }
   }
       
   void heapify(int *h, int n)//bottom up approach for the root
    {
     int i,j,k,key;
      j=0;//j is the root
      key=h[j];
      i=2*j+1;//find the left child
      
      while(i<n)//if left child exists
      {
        if((i+1)<n)//check whether right child exists
        {
           if(h[i+1]>h[i])
             i++;//get the index of the larger child
        }
        if(key < h[i])
        {
          h[j]=h[i];//move the child up   
          j=i;
          i=2*j+1;//find the left child
         }
        else
         break;
      }
     h[j]=key;
    }

  void top_heap(int *h, int n)
  {
    int i,j,k,key;

    for(k=1;k<n;k++)
    {
      i=k;
      key=h[i];
      j=(i-1)/2;

       while((i>0)&&(key>h[j]))
       {
           h[i]=h[j];//move the parent down
           i=j;
           j=(i-1)/2;//find position of new parent
       }
       h[i]=key;
     }
   }

  
  void bot_heap(int *h, int n)
  {
     int i,j,k,key;
     for(k=(n-2)/2;k>=0;k--)
     {
      j=k;
      key=h[j];
      i=2*j+1;//find the left child
      
      while(i<n)//if left child exists
      {
        if((i+1)<n)//check whether right child exists
        {
           if(h[i+1]>h[i])
             i++;//get the index of the larger child
        }
        if(key < h[i])
        {
          h[j]=h[i];//move the child up   
          j=i;
          i=2*j+1;//find the left child
         }
        else
         break;
      }
     h[j]=key;
    }
 }

*/























      






















