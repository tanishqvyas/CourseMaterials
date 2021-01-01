 //program to check if a undirected graph is connected using DFS
 #include<stdio.h>
 int visit[100];
 void creategraph();
 void dfs(int);
 int a[100][100],n;
 int connect();
 int main()
 {
   int i,v,k;
   
   printf("Enter the number of vertices..");
   scanf("%d",&n);

   creategraph();
   int result=connect();
   if(result)
    printf("The graph is connected..\n");
   else
     printf("The graph is not connected.\n");
 
  }

  int connect()
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
  }

  void dfs(int v)
  {
    int w;
    visit[v]=1;
      
    for(w=1;w<=n;w++)
    {
      if((a[v][w]==1)&&(visit[w]==0))
         dfs(w);
    }
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
        a[i][j]=a[j][i]=1;
     }
  }

  














 


     



