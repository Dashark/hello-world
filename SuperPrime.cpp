#include<iostream> 
using namespace std;

class Prime
{
    public:
        Prime(int num):mNum(num){
		}
//        ~Prime();

        virtual bool isPrime();                    
    private:
    const int mNum;
};

bool Prime::isPrime()
{
	int i;
	if(mNum<2) return false;
	else if(mNum==2) return true;
	else
	{
		for(i=2;i<mNum;i++)
	    if(mNum%i==0)
	    {
	    	return false;
	    	break;
    	}
	    return true;
	}
}

class SuperPrime:public Prime
{
    public:
        SuperPrime(int num):Prime(num),num(num){
		}
//        ~SuperPrime();

        virtual bool isPrime();

        Prime sumBit();
        Prime multiBit();
        Prime sqaureSumBit();
    private:
        const int num;
};

bool SuperPrime::isPrime()
{
	int i;
	if(num<2) return false;
	else if(num==2) return true;
	else
	{
		for(i=2;i<num;i++)
	    if(num%i==0)
	    {
	    	return false;
	    	break;
    	}
	    return true;
	}
}

Prime SuperPrime::sumBit()
{
	int a,b,c,d;
	a=num%10;//个位 
	b=(num-a)/10%10;//十位 
	c=(num-a-b*10)/10/10%10;//百位 
	d=num/1000;//千位 
	return a+b+c+d;
}

Prime SuperPrime::multiBit()
{
	int a,b,c,d;
	a=num%10;//个位 
	b=(num-a)/10%10;//十位 
	c=(num-a-b*10)/10/10%10;//百位 
	d=num/1000;//千位 
	if(d!=0)
	return a*b*c*d;
	else
	return a*b*c;
} 

Prime SuperPrime::sqaureSumBit()
{
	int a,b,c,d;
	a=num%10;//个位 
	b=(num-a)/10%10;//十位 
	c=(num-a-b*10)/10/10%10;//百位 
	d=num/1000;//千位 
	return a*a+b*b+c*c+d*d;
}

int main()
{
    SuperPrime sp(113);
    if(sp.isPrime())
	{
        Prime SB = sp.sumBit();
        Prime MB = sp.multiBit();
        Prime SSB = sp.sqaureSumBit();
        if(sp.isPrime() && SB.isPrime() && MB.isPrime() && SSB.isPrime())
        cout<<"Yes"<<endl;
    }
    int super[1105];
	int counter=0;
	for(int i=100;i<=9999;i++)
    {
    	SuperPrime pm(i);
        Prime sb = pm.sumBit();
        Prime mb = pm.multiBit();
        Prime ssb = pm.sqaureSumBit();
        if(pm.isPrime() && sb.isPrime() && mb.isPrime() && ssb.isPrime())
        {
        	super[counter]=i;
        	counter++;
		}
	}
	cout<<"最大的超级素数是:"<<super[counter-1]<<endl;
	cout<<"超级素数个数"<<counter<<endl;
	int SUM=0;
	for(int j=0;j<counter;j++)
	SUM+=super[j];
	cout<<"超级素数之和："<<SUM<<endl; 
    return 0;
}
