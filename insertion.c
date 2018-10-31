#include<stdio.h>

void insertion_sort(int a[],int);

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
    insertion_sort(a,n);
    printf("\nafter sorting:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}

void insertion_sort(int a[],int n)
{
    int i,j,k,temp;
    for(i=1;i<n;i++)
    {
        j=i-1;
        temp=a[i];
        while(j>=0&&temp<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
