#include<iostream>
class SuperPrime
{
    private:
    int LowLimit,HighLimit;
    public:
    SuperPrime(int a,int b)
    {
        LowLimit=a;
        HighLimit=b;
    }
    ~SuperPrime()
    {

    }
    void FindSP(int*p)
    {
        IsSPrime(p);
    }
    void IsSPrime(int *r)
    {
        for(int i=LowLimit;i<=HighLimit;i++)
        {
            int j;
            for(j=2;j<i;j++)
            {
                if(i%j==0)
                {
                    break;
                }
            }
            if(j==i)
            {
                if(operation(i))
                {
                    *r=i;
                    r++;
                }
            }
        }
    }
    int operation(int k)
    {
        int number[3];
        for(int ni=0;ni<3;ni++)
        {
            number[ni]=k%10;
            k=k/10;
        }
        int NumberSum=number[0]+number[1]+number[2];
        for(int ni=2;ni<NumberSum;ni++)
        {
            if(NumberSum%ni==0)
            {
                return 0;
            }
        }
        int NumberMult=number[0]*number[1]*number[2];
        for(int ni=2;ni<NumberMult;ni++)
        {
            if(NumberMult%ni==0)
            {
                return 0;
            }
        }    
        int NumberSqrt=number[0]*number[0]+number[1]*number[1]+number[2]*number[2];
        for(int ni=2;ni<NumberSqrt;ni++)
        {
            if(NumberSqrt%ni==0)
            {
                return 0;
            }
        }
        return 1;
    }
};

int main()
{
    SuperPrime sp(100,999);
    int sum=0,SPsum=0,max;
    int SP[80]={0},*q=&SP[0];
    sp.FindSP(q);
    for(int l=0;l<80;l++)
    {
        if(SP[l]!=0)
        {
            sum++;
            SPsum+=SP[l];
            max=SP[l];
        }
    }
    std::cout <<"The Total Of Super Prime:"<<sum<<std::endl;
    std::cout<<"The Sum Of Super Prime:"<<SPsum<<std::endl;
    std::cout<<"The Max Of Super Prime:"<<max<<std::endl;
    return 0;
}