#include<iostream> 
using namespace std;

class Prime 
{
    public:
        Prime(int num);
//      ~Prime();

        bool isPrime();
        
        Prime sumBit();
        Prime multiBit();
        Prime sqaureSumBit();
    private:
        const int mNum;
};

Prime::Prime(int num):mNum(num){}

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

Prime Prime::sumBit()
{
	int a,b,c,d;
	a=mNum%10;//个位 
	b=(mNum-a)/10%10;//十位 
	c=(mNum-a-b*10)/10/10%10;//百位 
	d=mNum/1000;//千位 
	return a+b+c+d;
}

Prime Prime::multiBit()
{
	int a,b,c,d;
	a=mNum%10;//个位 
	b=(mNum-a)/10%10;//十位 
	c=(mNum-a-b*10)/10/10%10;//百位 
	d=mNum/1000;//千位 
	if(d!=0)
	return a*b*c*d;
	else
	return a*b*c;
}

Prime Prime::sqaureSumBit()
{
	int a,b,c,d;
	a=mNum%10;//个位 
	b=(mNum-a)/10%10;//十位 
	c=(mNum-a-b*10)/10/10%10;//百位 
	d=mNum/1000;//千位 
	return a*a+b*b+c*c+d*d;
}

int main()
{
	int super[1105];
	int counter=0;
	for(int i=100;i<=9999;i++)
    {
    	Prime pm(i);
        Prime sb = pm.sumBit();
        Prime mb = pm.multiBit();
        Prime ssb = pm.sqaureSumBit();
        if(pm.isPrime() && sb.isPrime() && mb.isPrime() && ssb.isPrime())
        {
        	super[counter]=i;
        	counter++;
		}
	}
	printf("最大的超级素数是%d\n",super[counter-1]);
	printf("超级素数共%d个\n",counter);
	int SUM=0;
	for(int j=0;j<counter;j++)
	SUM+=super[j];
	printf("超级素数之和为%d\n",SUM);
    return 0;
}
