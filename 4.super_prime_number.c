#include<stdio.h>

int division(int a);

int main()
{
    int count=0,sum=0,max;
    for(int i=100;i<=999;i++)
    {
        if(division(i))
        {
            count++;
            sum+=i;
            max=i;
        }
    }
    printf("super_prime_number_count:%d\nthe_sum_of_prime:%d\nmax_of_prime:%d",count,sum,max);
    return 0;
}

int division(int a)
{
    int b,c,d;
    for(int j=2;j<a;j++)
    {
        if(a%j==0)
        {
            return 0;
        }
    }
    b=a/100+a/10%10+a%10;
    for(int j=2;j<b;j++)
    {
        if(b%j==0)
        {
            return 0;
            break;
        }
    }
    c=(a/100)*(a/10%10)*(a%10);
    for(int j=2;j<c;j++)
    {
        if(c%j==0)
        {
            return 0;
            break;
        }
    }
    d=((a/100)*(a/100))+((a/10%10)*(a/10%10))+((a%10)*(a%10));
    for(int j=2;j<d;j++)
    {
        if(d%j==0)
        {
            return 0;
            break;
        }
    }
    return 1;
}