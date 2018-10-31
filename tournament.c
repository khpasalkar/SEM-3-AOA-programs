#include<stdio.h>
int schedule[20][20];
int i,j,n;
void tennis(int n)
{
    if(n==2)
    {
        schedule[1][1]=2;
        schedule[1][2]=1;
    }
    else
    {
        tennis(n/2);
        for(j=1;j<=n/2-1;j++)
        {
            for(i=n/2+1;i<=n;i++)
            {
                schedule[j][i]=(schedule[j][i-n/2]+n/2);
            }
        }
        for(i=1;i<=n/2;i++)
        {
            schedule[n/2][i]=i+n/2;
        }
        for(i=n/2+1;i<=n;i++)
        {
            schedule[n/2][i]=i-n/2;
        }
        for(j=n/2+1;j<=n-1;j++)
        {
            for(i=1;i<=n/2;i++)
            {
                if((schedule[j-1][i]+1)>n)
                {
                    schedule[j][i]=(schedule[j-1][i]+1)-n/2;
                }
                else
                {
                    schedule[j][i]=schedule[j-1][i]+1;
                }
            }
        }
        for(j=n/2+1;j<=n-1;j++)
        {
            for(i=n/2+1;i<=n;i++)
            {
                if((schedule[j-1][i]-1)<1)
                {
                    schedule[j][i]=(schedule[j-1][i]-1)+n/2;
                }
                else
                {
                    schedule[j][i]=schedule[j-1][i]-1;
                }
            }
        }
    }
}

void show(int n)
{
    printf("\t");
    for(j=1;j<=n-1;j++)
    {
        printf("%d\t",j);
    }
    printf("\n\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",i);
        for(j=1;j<=n-1;j++)
        {
            printf("%d\t",schedule[j][i]);
        }
        printf("\n");
    }
}

void main()
{
    printf("enter number of players:\n");
    scanf("%d",&n);
    printf("\n");
    tennis(n);
    show(n);
}
