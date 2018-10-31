#include<stdio.h>
#include<string.h>
int i,j,m,n,a,c[20][20];
char x[15],y[15],b[20][20];
void print_lcs(int i,int j)
{
    if(i==0||j==0)
        return;
    if(b[i][j]=='c')
    {
        print_lcs(i-1,j-1);
        printf("%c",x[i-1]);
    }
    else if(b[i][j]=='u')
        print_lcs(i-1,j);
    else
        print_lcs(i,j-1);
}
void lcs_length()
{
    m=strlen(x);
    n=strlen(y);
    for(i=0;i<=m;i++)
        c[i][0]=0;
    for(i=0;i<=n;i++)
    {
        printf("0\t");
        c[0][i]=0;
    }
    printf("\n");
    for(i=1;i<=m;i++)
    {
        printf("0\t");
        for(j=1;j<=n;j++)
        {
            if(x[i-1]==y[i-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='c';
                printf("%d D\t",c[i][j]);
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]='u';
                printf("%d U\t",c[i][j]);
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]='l';
                printf("%d L\t",c[i][j]);
            }
        }
        printf("\n");
    }
    printf("\nlongest common subsequence is:\n");
    print_lcs(m,n);
    printf("\n");
    printf("\nThe length of longest common subsequence is:%d",c[m][n]);
}
void main()
{
    printf("enter the first sequence:\n");
    scanf("%s",x);
    printf("enter the second sequence:\n");
    scanf("%s",y);
    lcs_length();
    printf("\n");
}
