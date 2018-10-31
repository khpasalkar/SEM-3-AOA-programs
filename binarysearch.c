#include<stdio.h>

int binary_search(int a[],int,int,int);

void main()
{
    int a[50],i,n,x,p;
    printf("enter the size of array:\n");
    scanf("%d",&n);
    printf("enter the elements of array:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("enter the element to be searched:\n");
    scanf("%d",&x);
    p=binary_search(a,0,n-1,x);
    if(p==-1)
        printf("\nelement not found\n");
    else
        printf("element found at %d location\n",p);
}

int binary_search(int a[50],int low,int high,int x)
{
    int mid;
    if(low==high)
    {
        if(a[low]==x)
            return low;
        else
            return -1;
    }
    else
    {
        mid=(low+high)/2;
        if(a[mid]==x)
            return mid;
        else if(a[mid]>x)
           return binary_search(a,0,mid,x);
        else
            return binary_search(a,mid+1,high,x);
    }
}
