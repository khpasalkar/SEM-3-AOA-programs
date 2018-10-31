#include<stdio.h>

int min,max,a[50];

void max_min(int i,int j);

void main()
{
    int n,i;
    printf("enter the size of array:\n");
    scanf("%d",&n);
    printf("enter the elements of arrays:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    max=min=a[0];
    max_min(0,n-1);
    printf("maximum=%d\nminimum=%d",max,min);
}

void max_min(int i,int j)
{
    int max1,min1, mid;
    if(i==j)
    {
        max=min=a[i];
    }
    else if(i==j-1)
    {
        if(a[i]>a[j])
        {
            max=a[i];
            min=a[j];
        }
        else
        {
            max=a[j];
            min=a[i];
        }
    }
    else
    {
        mid=(i+j)/2;
        max_min(i,mid);
        max1=max;
        min1=min;
        max_min(mid+1,j);
        if(max1>max)
           max=max1;
        if(min>min1)
           min=min1;
    }
}
