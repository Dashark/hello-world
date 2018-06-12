// 描述
//
// 求多个正整数的最大公约数

#include<iostream>
#include<cstdio>

using namespace std;

int Big_Same(int a, int b)
{
	if(a < b &&b!=0) return Big_Same(a,b%a);
	if(a>b && b!=0) return Big_Same(b,a%b);
	return a;
}

int main()
{
	//cout << Big_Same(4,6);
	int n;
	cin >> n;
	while(n--)
	{
		int a[4];
		scanf("%d,%d,%d,%d",&a[0],&a[1],&a[2],&a[3]);
		int mid = Big_Same(a[0],a[1]);
		for(int i = 2;i < 4;i++) mid = Big_Same(mid,a[i]);
		cout << mid << endl;
	}
	return 0;
}
