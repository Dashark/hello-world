#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Number{
	public:
		Number(int number);
		int maxDivisor(int numout);
		void show();
	private:
		int num,out;
		int big,sma,maxdivisor;
};
int main() 
{
    int n,n1,n2;
    std::cin>>n;
    for(int i=0;i<n;++i) 
	{
        std::cin>>n1>>n2;
        Number no1(n1);
        no1.maxDivisor(n2);  //最大公约数
        no1.show();
    }
    return 0;
}
Number::Number(int number){
	num=number;
}
int Number::maxDivisor(int numout){
	out=numout;
	
	if(num>=out) big=num,sma=out;
	else big=out,sma=num;
	
	for(int i=sma;i>=1;i--)
	{
		if((big%i==0)&&(sma%i==0))
		{
			maxdivisor=i;
			break;
		}
	}
}
void Number::show(){
	cout<<maxdivisor<<endl;
}




