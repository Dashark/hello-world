#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
inline int prime(int num)
	{
		int k,i;
		k=sqrt(num);
		for(i=2;i<=k;i++)
		{
			if(num%i==0)
			return 0;	
		}		
		return 1;
	}
	int main()
	{
		int a=0,n=0,i=0,s=0;
		int arr[1000];
		cin>>n;
		for(a=0;a<=n;a++)
		{
			if(prime(a)==1)
			{
				arr[i]=a;
				i++;
			}
		}
		for(int q=0;q<i;q++)
		{
			s=arr[q]*arr[q]+s;
		}
		cout<<s<<endl;
	}

	
	 
