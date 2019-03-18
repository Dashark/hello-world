#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	int x,y,z,m,n;
	int adj1,adj2,adj3,adj4,sum=0;
	m=0,n=0;
	int a,b,c;
	int i,j;
	int sup[100];
	for(i=100;i<1000;i++)
	{
		z=i%10;//个位 
		y=(i/10)%10;//十位 
		x=i/100;//百位
//		cout<<x<<y<<z<<endl; 
		a=x+y+z;//和 
		b=x*y*z;//积 
		c=x*x+y*y+z*z;//平方和
//		cout<<a<<" "<<b<<" "<<c<<endl;
		adj1=1;
		for(j=2;j<i;j++)
		{

			if((i%j)==0)
			{
				adj1=0;
				break;
			}
		}
		adj2=1;
		for(j=2;j<a;j++)
		{
			if((a%j)==0)
			{
				adj2=0;
				break;
			}
		}
		adj3=1;
		if(b==0) adj3=0;
		for(j=2;j<b;j++)
		{
			if((b%j)==0)
			{
				adj3=0;
				break;
			}
		}
		adj4=1;
		for(j=2;j<c;j++)
		{
			if((c%j)==0)
			{
				adj4=0;
				break;
			}
		}
		if(adj1&&adj2&&adj3&&adj4)
		{
			m=i;
			sum=sum+i;
			n=n+1;
			cout<<i<<endl;
		}
	}
	
	cout<<"The number of the super prime in 100~999:"<<n<<endl;
	cout<<"The sum of the super prime in 100~999:"<<sum<<endl;
	cout<<"the max super prime in 100~999:"<<m<<endl;
	return 0;
}
