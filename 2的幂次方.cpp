#include<stdio.h>

void put(int num,int n);

int main()
{
    int num;
    scanf("%d",&num);
    put(num,0);
}

void put(int m,int n)
//m为被分解的数，n为二进制位数，r为位数上的数值。 
{
    int r; 
    if(m==0)//m已经被分解完，返回 
    {
        return;
    }
    r=m%2;
    m=m/2;
    put(m,n+1);
    if(m!=0&&r!=0)
    //如果m不为0且r不为0证明这不是第一个2的幂次方，输出+
    {
        printf("+");
    }
    if(r==1)
    {
        if(n==0)
        {
            printf("2(0)");
        }
        else if(n==1)
        {
            printf("2");
        }
        else if(n==2)
        {
            printf("2(2)");
        }
        else
        {
            printf("2(");
            put(n,0);
            //如果指数不能用2(0),2,2(2)表示则继续分解
            printf(")");
        }

    }
}
