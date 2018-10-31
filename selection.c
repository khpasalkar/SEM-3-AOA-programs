#include<stdio.h>

void selection_sort(int a[],int);

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
    selection_sort(a,n);
    printf("\nafter sorting:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}

void selection_sort(int a[],int n)
{
    int i,j,temp,min;
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}
