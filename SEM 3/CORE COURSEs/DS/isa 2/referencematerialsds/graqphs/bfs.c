 //program to implement BFS for a digraph
 #include<stdio.h>
 int visit[100];
 void creategraph();
 void bfs(int);
 void qinsert(int);
 int qdelete();
 int qisempty();
 int a[100][100],n;
 int q[100];
 int f,r;
 int main()
 {
   int i,v,k;
   printf("Enter the number of vertices..");
   scanf("%d",&n);
for(i=0;i<=n;i++)
printf("%d",visit[i])
   creategraph();
   printf("Enter the source vertex..\n");
   scanf("%d",&v);

   printf("The vertices reachable from %d using BFS are..\n",v);
   bfs(v);
 
  }

  void creategraph()
  {
    int i,j;
    while(1)
    {
        printf("Enter the source and the destination vertex..");
        scanf("%d%d",&i,&j);
        if((i==0)&&(j==0))
           break;
        a[i][j]=1;
     }
  }

  void bfs(int v)
  {
    int x,w;
    visit[v]=1;
    printf("%d ",v);
    qinsert(v);

    while(!qisempty())
    {
      x=qdelete();
      for(w=1;w<=n;w++)
      {
        if((a[x][w]==1)&&(visit[w]==0))
        {
           visit[w]=1;
           printf("%d ",w);
           qinsert(w);
         }
      }
    }
  }

   void qinsert(int v)
   {
     r++;
     q[r]=v;
     if(f==-1)
       f=0;
   }

   int qdelete()
   {
    int x;
    x=q[f];
    if(f==r)
      f=r=-1;
    else
      f++;
    return x;
  }

  int qisempty()
  {
     if(f==-1)
        return 1;
     return 0;
  }
   


























  



  




  
 
  








 















 


   /*void dfs(int v)
   {
     int w;
     visit[v]=1;
     for(w=1;w<=n;w++)
     {
       if((a[v][w]==1) && (visit[w]==0))
           dfs(w);
     }
   }
        
 
   int connected()
   {
     int i;
     for(i=1;i<=n;i++)
       visit[i]=0;
     dfs(1);
     for(i=1;i<=n;i++)
     {
       if(visit[i]==0)
          return 0;
     }
    return 1;
  } */


      

     



