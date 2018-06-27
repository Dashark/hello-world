#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
	int N,i;
	cin>>N;
	int arr[50];
	int m;
	 for(i=0;i<N;i++)
	{
	    cin>>arr[i];
	} 
		if(N%2==1)
	{
		m=(N-1)/2;
		cout<<arr[m]<<endl;
	}
	else
	{
		m=N/2;
		cout<<arr[m]<<arr[m+1]<<endl;
	}
	 return 0;
}
