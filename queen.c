#include<stdio.h>
int x[100];
void queen(int k,int n)
{
    int i,z,w;
    for(i=1;i<=n;i++)
    {
        if(place(k,i))
        {
            x[k]=i;
            if(k==n)
            {
                printf("\n");
                for(i=1;i<=n;i++)
                    printf("%d\t",i);
                printf("\n");
                //printf("1\t2\t3\t4\n");
                for(z=1;z<=n;z++)
                {
                    for(w=1;w<=n;w++)
                    {
                        if(w==x[z])
                        {
                            printf("Q");
                        }
                        else
                        {
                            printf("*");
                        }
                        printf("\t");
                    }
                    printf("\n");
                }
            }
            else
                queen(k+1,n);
        }
    }
}
int place(int k,int i)
{
    int j;
    for(j=1;j<=k-1;j++)
    {
        if((x[j]==i)||(abs(x[j]-i)==abs(j-k)))
        {

            return 0;
        }
    }
    return 1;
}
void main()
{
    int n;
    printf("enter the no. of queens to be placed:\n");
    scanf("%d",&n);
    printf("possible placements are:\n");
    queen(1,n);
}
