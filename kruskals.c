#include<stdio.h>
int find(int);
int nui(int,int);
int parent[10]={0};
void main()
{
    int a,b,u,v,n,i,j,ne=1;
    int min,mincost=0,g[10][10];
    printf("enter the no. of nodes of graph:\n");
    scanf("%d",&n);
    printf("enter the cost adjacency matrix of graph:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&g[i][j]);
            if(g[i][j]==0)
                g[i][j]=999;
        }
    }
    while(ne<n)
    {
        for(i=1,min=999;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(g[i][j]<min)
                {
                    min=g[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=find(u);
        v=find(v);
     if(uni(u,v))
     {
         printf("\nedge %d:(%d %d) cost:%d",ne++,a,b,min);
         mincost+=min;
     }
     g[a][b]=g[b][a]=999;
    }
    printf("\nminimum cost=%d",mincost);
}

int find(int i)
{
    while(parent[i])
    {
        i=parent[i];
    }
    return i;
}

int uni(int i,int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 1;
    }
}
