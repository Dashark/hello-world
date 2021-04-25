#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	char a[10]="AclRqsiFp";

	for(int i=0;i<10;i++)
	{
		std::cout<<a[i]<<"\t";
	}
	
	std::cout<<"\n";
	std::sort(a,a+10,std::greater<char>());
	
	for(int i=0;i<10;i++)
	{
		std::cout<<a[i]<<"\t";
	}
	
	
	
	
	//system("pause");
	return 0;
}




