#include <iostream>
#include<stdio.h>
using namespace std;

const int length=10000;
int main()
{
    void mergeSort(int arr[],int left,int right);

    int a[length]= {0};
    int i=0,n=0;

    scanf("%d",&n);

    while(i<n)
    {
        scanf("%d",&a[i]);
        i++;
    }

    mergeSort(a,0,n-1);

    for(i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}

void mergeSort(int arr[],int left,int right)
{
    int mid=0,k=0,i=0,j=0;
    int temp[length]= {0};

    if(left>=right)
    {
        return;
    }

    mid =(left+right)/2;

    mergeSort(arr,left,mid);//
    mergeSort(arr,mid+1,right);//

    i=left;
    j=mid+1;

    while(i<=mid&&j<=right)
    {
        if (arr[i]<=arr[j])
        {
            temp[k]=arr[i];
            i++;
        }
        else if(arr[j]<arr[i])
        {
            temp[k]=arr[j];
            j++;
        }
        k++;
    }

    while(i<=mid)
    {
        temp[k]=arr[i];
        k++;
        i++;
    }

    while(j<=right)
    {
        temp[k]=arr[j];
        k++;
        j++;
    }

    for(i=left,j=0; i<=right; i++,j++)
    {
        arr[i]=temp[j];
    }

}
