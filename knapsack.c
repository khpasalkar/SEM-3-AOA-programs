#include<stdio.h>
void knapsack(int n,int w[50],int p[50],int wk);
void merge(float temp[],int low,int mid,int high);
void merge_sort(float temp[],int low,int high);

void main()
{
    int wk,w[50],p[50],n,i;
    printf("enter no. of objects:\n");
    scanf("%d",&n);
    printf("enter weights of objects:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
    }
    printf("enter profits of objects:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("enter capacity of knapsack:\n");
    scanf("%d",&wk);
    knapsack(n,w,p,wk);
}

void knapsack(int n,int w[50],int p[50],int wk)
{
    int i,j,k,w1[20],p1[20];
    float pw[50],sum=0,temp[50],dsc[50],x[50];
    for(i=0;i<n;i++)
    {
        pw[i]=(float)p[i]/(float)w[i];
    }

    for(i=0;i<n;i++)
    {
        temp[i]=pw[i];
    }
    merge_sort(temp,0,n-1);
    i=0;
    k=n-1;
    while(k>=0)
    {
        dsc[i]=temp[k];
        i++;
        k--;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(dsc[i]==pw[j])
            {
                w1[i]=w[j];
                p1[i]=p[j];
                break;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(w1[i]<wk)
        {
            x[i]=1;
            wk=wk-w1[i];
        }
        else
            break;
    }
    if(i<=n)
    {
        x[i]=(float)wk/(float)w1[i];
    }
    printf("x array:\n");
    for(i=0;i<n;i++)
    {
        printf("%f\t",x[i]);
    }
    printf("\n");

    for(i=0;i<n;i++)
    {
        sum=sum+(p1[i]*x[i]);
    }
    printf("optimal solution is %f \n",sum);
}


void merge(float temp[],int low,int mid,int high)
{
    int i,j,k;
    float temp1[50];
    i=k=low;
    j=mid+1;
    while(i<=mid&&j<=high)
    {
        if(temp[i]<=temp[j])
        {
            temp1[k]=temp[i];
            i++;
            k++;
        }
        else
        {
            temp1[k]=temp[j];
            j++;
            k++;
        }
    }
    if(j>high)
    {
      while(i<=mid)
      {
         temp1[k]=temp[i];
         i++;
         k++;
      }
    }
    else
    {
        while(j<=high)
        {
            temp1[k]=temp[j];
            j++;
            k++;
        }
    }
    for(k=low;k<=high;k++)
    {
        temp[k]=temp1[k];
    }
}
void merge_sort(float temp[50],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        merge_sort(temp,low,mid);
        merge_sort(temp,mid+1,high);
        merge(temp,low,mid,high);
    }
}
