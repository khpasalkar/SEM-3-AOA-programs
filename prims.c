#include<stdio.h>

void main()
{
    int a,b,u,v,n,i,j,ne=1;
    int visited[10]={0},min,mincost=0,g[10][10];
    printf("enter the no. of nodes of graph:\n");
    scanf("%d",&n);
    printf("enter the adjacency matrix of graph:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&g[i][j]);
            if(g[i][j]==0)
                g[i][j]=999;
        }
    }
    visited[1]=1;
    printf("\n");
    while(ne<n)
    {
        for(i=1,min=999;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(g[i][j]<min)
                {
                    if(visited[i]!=0)
                    {
                        min=g[i][j];
                        a=u=i;
                        b=v=j;
                    }
                }
            }
        }
     if(visited[u]==0||visited[v]==0)
     {
         printf("\nedge %d:(%d %d) cost:%d",ne++,a,b,min);
         mincost+=min;
         visited[b]=1;
     }
     g[a][b]=g[b][a]=999;
    }
    printf("\nminimum cost=%d",mincost);
}
