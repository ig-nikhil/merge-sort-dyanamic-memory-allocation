#include<stdio.h>
#include<stdlib.h>


void print(int*arr,int n )
{
    int i ;
    for(i=0;i<n;i++)
    {
        printf(" %d",arr[i]);
    }
}


void merge(int*arr,int l,int m,int r)
{
    int i,j,k;
    int n1,n2;

    n1=m-l+1;
    n2=r-m;

    int* left;
    int* right;

    left=(int*)malloc(n1*sizeof(int));
    right=(int*)malloc(n2*sizeof(int));

    for(i=0;i<n1;i++)
    {
        left[i]=arr[l+i];
    }

     for(j=0;j<n1;j++)
    {
        right[j]=arr[m+j+1];
    }

    i=0;
    j=0;
    k=l;

    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
        {
            arr[k]=left[i];
            i++;
        }

        else
        {
            arr[k]=right[j];
            j++;
        }

        k++;


    }

    while(i<n1)
    {
        arr[k]=left[i];
        k++;
        i++;
    }

    while(j<n2)
    {
        arr[k]=right[j];
        k++;
        j++;
    }


}


void merge_sort(int*arr,int l,int r)
{
    if(l<r)
    {
        int mid=l+ (r-l)/2;

        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);

        merge(arr,l,mid,r);
    }


}


int main(void) {
    int*arr;
    int n=7,i;

    arr=(int*)malloc(n*sizeof(int));

    if(arr==NULL)
    {
        printf("memory allocation failed \n");
    }

    else
    {
        printf("memory allocation successfull \n");
    }

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("unsorted array : ");
    print(arr,7);
    printf("\n");
    merge_sort(arr,0,6);
    printf("sorted array : ");
    print(arr,7);
    return 0;
}
