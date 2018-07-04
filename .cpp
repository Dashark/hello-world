#include<iostream> 
#define ll long long 
using namespace std;
int main()
{
	const int N=50022;
	ll energy[N];
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> energy[i];
	}
	ll temp,min=0;
	temp = min;
	for(int i=0;i<n;i++){
		min += energy[i];
		if(min<temp) temp = min;
	}
	cout << -temp;
	return 0;
}
