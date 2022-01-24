#include <iostream>

using namespace std;
const int N=3;
const int M=4;

int main()
{
    void pre_sum(int n,int m,int a[][M],int sum[][M]);
    int get_sum(int x1,int y1,int x2,int y2,int sum[][M]);
    void output(int n,int m,int sum[][M]);

    int a[N][M]={{0}};
    int sum[N][M]={{0}};
    int n=0,m=0;
    int x1=0,y1=0,x2=0,y2=0;
    int i=0,j=0;

    scanf("%d %d",&n,&m);

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    pre_sum(n,m,a,sum);
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    get_sum(x1,y1,x2,y2,sum);


    return 0;
}

void pre_sum(int n,int m,int a[][M],int sum[][M])
{
    int i=0,j=0;

    sum[0][0]=a[0][0];
    for(i=1;i<n;i++)
    {
        sum[i][0]=sum[i-1][0]+a[i][0];
        //计算每一行的前缀和，把二维矩阵看作一维的
    }
    for(j=1;j<m;j++)
    {
        sum[0][j]=sum[0][j-1]+a[0][j];
        //计算每一列的前缀和，把二维矩阵看作一维的
    }
    for(i=1;i<n;i++)
    {
        for(j=1;j<m;j++)
        {
            sum[i][j]
            =a[i][j]+sum[i][j-1]//[i][j]点上方的矩阵和
            +sum[i-1][j]//[i][j]点左侧的矩阵和
            -sum[i-1][j-1];//减去多加的矩阵和
        }
    }
}

int get_sum(int x1,int y1,int x2,int y2,int sum[][M])
{
    int result=0;
    if(x1==0&&y1==0)
    {
        result=sum[x2][y2];
        return result;
    }
    else if(x1==0)
    {
        result=sum[x2][y2]-sum[x2][y1-1];
        return result;
    }
    else if(y1==0)
    {
        result=sum[x2][y2]-sum[x1-1][y2];
        return result;
    }
    else
    {
        result
        =sum[x2][y2]
        -sum[x2][y1-1]
        -sum[x1-1][y2]
        +sum[x1-1][y1-1];
        return result;
    }
}

output(int n,int m,int sum[][M])
{
    int i=0,j=0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ",sum[i][j])
        }
        printf("\n");
    }
}
