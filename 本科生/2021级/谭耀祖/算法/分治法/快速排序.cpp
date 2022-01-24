#include <iostream>

using namespace std;
const int length=100;
int main()
{
    void quickSort(int arr[],int l,int r);

    int i=0,n=0;
    int a[length]= {0};

    scanf("%d",&n);

    for(; i<n; i++)
    {
        scanf("%d",&a[i]);
    }

    quickSort(a,0,n-1);

    for(i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}

void quickSort(int q[], int l, int r)
{
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[l];
    while (i < j)
    {
        do i ++ ;
        while (q[i] < x);
        do j -- ;
        while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quickSort(q, l, j), quickSort(q, j + 1, r);
}
