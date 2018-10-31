#include<stdio.h>

void selection_sort(int[],int);

void main()
{
    int a[50],n,i;
    printf("enter the size of array:\n");
    scanf("%d",&n);
    printf("enter the elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("unsorted array is:\n");
    for(i=0;i<n;i++)
        printf("%d",a[i]);
    selection_sort(a,n);
    printf("sorted array is:\n");
    for(i=0;i<n;i++)
        printf("%d",a[i]);
}

void selection_sort(int a[],int n)
{
    int temp,i,j,imin;
    for(i=0;i<n;i++)
    {
        imin=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[imin])
                imin=j;
        }
        temp=a[i];
        a[i]=a[imin];
        a[imin]=temp;
    }
}

OUTPUT:
enter the size of array:
5
enter the elements:
2
3
5
6
1
unsorted array is:
23561
sorted array is:
12356
Process returned 5 (0x5)   execution time : 9.852 s
Press any key to continue.


