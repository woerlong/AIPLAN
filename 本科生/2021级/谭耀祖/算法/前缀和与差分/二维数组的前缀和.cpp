#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>

using namespace std;
const int N=10,M=10;

void output(int n,int m,int sum[][M]);
void input(int n,int m,int a[][M]);
void calcD(int x1,int y1,int x2,int y2,int v,int d[][M]);
void pre_sum(int n,int m,int a[][M],int d[][M],int sum[][M]);
void get_sum(int n,int m,int a[][M],int sum[][M],int sum1[][M]);
int res(int x,int y,int a[][M],int sum[][M]);

const int length=10;

int main()
{
    int a[N][M]= {{0}};
    int d[N][M]= {{0}};
    int sum[N][M]= {{0}};
    int sum1[N][M]= {{0}};
    int x1,y1,x2,y2;
    int n,m;
    int v;
    int x,y,result;

    int i,times;

    printf("--------矩阵的行和列---------\n");
    scanf("%d %d",&n,&m);

    printf("--------矩阵的初始值---------\n");
    input(n,m,a);

    printf("--------需要运算的次数---------\n");
    scanf("%d",&times);

    for(i=0; i<times; i++)
    {
        printf("--------第%d次需要运算的位置和值---------\n",i+1);
        printf("input 5 number x1,y1,x2,y2,v\n");
        scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&v);

        calcD(x1,y1,x2,y2,v,d);
        printf("--------第%d次未运算的d---------\n",i+1);
        output(n,m,d);


    }

    printf("--------第%d次运算过后的d---------\n",i+1);
    pre_sum(n,m,a,d,sum);
    output(n,m,sum);

    printf("--------第%d次运算过后的a---------\n",i+1);
    get_sum(n,m,a,sum,sum1);
    output(n,m,sum1);

    printf("--------result---------\n");
    scanf("%d %d",&x,&y);
    result=res(x,y,a,sum);
    printf("a[%d][%d]=%d",x,y,result);

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

void calcD(int x1,int y1,int x2,int y2,int v,int d[][M])
{
    d[x1][y1]+=v;
    d[x2+1][y1]-=v;
    d[x1][y2+1]-=v;
    d[x2+1][y2+1]+=v;
}

void pre_sum(int n,int m,int a[][M],int d[][M],int sum[][M])
{
    int i,j;
    sum[0][0]=d[0][0];
    for(i=1; i<n; i++)
    {
        sum[i][0]=sum[i-1][0]+d[i][0];
        //第一列
    }
    for(j=1; j<m; j++)
    {
        sum[0][j]=sum[0][j-1]+d[0][j];
        //第一行
    }

    for(i=1; i<n; i++)
    {
        for(j=1; j<m; j++)
        {
            sum[i][j]=d[i][j]
                      +sum[i][j-1]
                      +sum[i-1][j]
                      -sum[i-1][j-1];
        }
    }
}

int res(int x,int y,int a[][M],int sum[][M])
{
    int result;
    result=a[x][y]+sum[x][y];
    return result;
}

void get_sum(int n,int m,int a[][M],int sum[][M],int sum1[][M])
{
    int i,j;

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            sum1[i][j]=a[i][j]+sum[i][j];
        }
    }
}
