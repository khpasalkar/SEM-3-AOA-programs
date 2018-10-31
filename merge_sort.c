#include<stdio.h>

void merge_sort(int [],int,int);

void merge(int[],int,int,int);

void main()
{
    int a[50],n,i;
    printf("enter the size of array:\n");
    scanf("%d",&n);
    printf("enter the coordinates of array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("before sorting:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    merge_sort(a,0,n-1);
    printf("\nafter sorting:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}

void merge_sort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void merge(int a[],int low,int mid,int high)
{
    int i,j,k,temp[50];
    i=k=low;
    j=mid+1;
    while(i<=mid&&j<=high)
    {
        if(a[i]>a[j])
        {
            temp[k]=a[j];
            j++;
        }
        else
        {
            temp[k]=a[i];
            i++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=high)
        {
            temp[k]=a[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[k]=a[i];
            i++;
            k++;
        }
    }
    for(k=low;k<=high;k++)
        a[k]=temp[k];
}
