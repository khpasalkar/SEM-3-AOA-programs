#include<stdio.h>

void quick_sort(int [],int,int);

int partition(int[],int,int);

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
    quick_sort(a,0,n-1);
    printf("\nafter sorting:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}

void quick_sort(int a[],int low,int high)
{
    int p;
    if(low<high)
    {
        p=partition(a,low,high);
        quick_sort(a,low,p-1);
        quick_sort(a,p+1,high);
    }
}

int partition(int a[],int low,int high)
{
    int left,right,loc,flag=0,temp;
    left=loc=low;
    right=high;
    while(flag!=1)
    {
        while(a[right]>=a[loc]&&loc!=right)
            right--;
        if(right==loc)
            flag=1;
        else if(a[right]<a[loc])
        {
            temp=a[right];
            a[right]=a[loc];
            a[loc]=temp;
            loc=right;
        }
        if(flag!=1)
        {
            while(a[left]<=a[loc]&&loc!=left)
                left++;
            if(left==loc)
                flag=1;
            if(a[left]>a[loc])
            {
                temp=a[left];
                a[left]=a[loc];
                a[loc]=temp;
                loc=left;
            }
        }
    }
    return loc;
}
