#include <iostream>

using namespace std;
const int N=10;//有多少行
const int M=10;//有多少列

void output(int n,int m,int sum[][M]);

int main()
{
    void input(int n,int m,int a[][M]);
    void pre_sum(int n,int m,int a[][M],int sum[][M]);
    void pre_sumD(int n,int m,int d[][M],int sum[][M],int a[][M],int result[][M]);
    int get_sum(int x1,int y1,int x2,int y2,int sum[][M]);
    void add(int x1,int y1,int x2,int y2,int v,int d[][M]);


    int a[N][M]= {{0}};
    int sum1[N][M]= {{0}};
    int sum2[N][M]= {{0}};
    int d[N][M]= {{0}};
    int result[N][M]= {{0}};
    int n=0,m=0;
    int x1=0,y1=0,x2=0,y2=0;
    int v=0;

    printf("-----设置行和列-----\n");
    scanf("%d %d",&n,&m);

    printf("---------输入初始数组------\n");
    input(n,m,a);

    printf("--------需要运算的位置---------\n");
    printf("input 5 number x1,y1,x2,y2,v\n");
    scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&v);

    printf("--------打完标记的差分数组d---------\n");
    add(x1,y1,x2,y2,v,d);
    output(n,m,d);

    printf("--------未运算的矩阵和---------\n");
    pre_sum(n,m,a,sum1);
    output(n,m,sum1);

    printf("--------运算完毕的差分数组d---------\n");
    pre_sumD(n,m,d,sum2,a,result);
    output(n,m,sum2);

    printf("-------初始数组的值----------\n");
    output(n,m,a);

    printf("-------运算完毕的初始数组----------\n");
    output(n,m,result);

    printf("--------运算完毕的初始数组的矩阵和---------\n");
    pre_sum(n,m,result,sum2);
    output(n,m,sum2);

    printf("------------------\n");
    printf("程序结束\n");
    return 0;
}

void input(int n,int m,int a[][M])
{
    int i=0,j=0;

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}

void pre_sum(int n,int m,int a[][M],int sum[][M])
{
    int i=0,j=0;

    sum[0][0]=a[0][0];
    for(i=1; i<n; i++)
    {
        sum[i][0]=sum[i-1][0]+a[i][0];
        //计算第一行的前缀和
    }
    for(j=1; j<m; j++)
    {
        sum[0][j]=sum[0][j-1]+a[0][j];
        //计算第一列的前缀和
    }
    for(i=1; i<n; i++)
    {
        for(j=1; j<m; j++)
        {
            sum[i][j]
                =a[i][j]+sum[i][j-1]        //[i][j]点上方的矩阵和
                 +sum[i-1][j]               //[i][j]点左侧的矩阵和
                 -sum[i-1][j-1];            //减去多加的矩阵和
        }
    }
}

void pre_sumD(int n,int m,int d[][M],int sum[][M],int a[][M],int result[][M])
{
    int i=0,j=0;

    sum[0][0]=d[0][0];
    for(i=1; i<n; i++)
    {
        sum[i][0]=sum[i-1][0]+d[i][0];
        //计算第一列的前缀和
    }
    for(j=1; j<m; j++)
    {
        sum[0][j]=sum[0][j-1]+d[0][j];
        //计算第一行的前缀和
    }

    //从第二行第二列开始计算
    for(i=1; i<n; i++)
    {
        for(j=1; j<m; j++)
        {
            sum[i][j]
                =d[i][j]+sum[i][j-1]        //[i][j]点上方的矩阵和
                 +sum[i-1][j]               //[i][j]点左侧的矩阵和
                 -sum[i-1][j-1];            //减去多加的矩阵和
        }
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            result[i][j]=sum[i][j]+a[i][j];
            //d需要映射到a的矩阵
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

void add(int x1,int y1,int x2,int y2,int v,int d[][M])
//对d进行处理
{
    d[x1][y1]+=v;
    d[x2+1][y1]-=v;
    d[x1][y2+1]-=v;
    d[x2+1][y2+1]+=v;

}

void output(int n,int m,int sum[][M])
{
    int i=0,j=0;

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            printf("%2d ",sum[i][j]);
        }
        printf("\n");
    }
}
