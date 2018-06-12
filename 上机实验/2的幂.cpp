// A: 2的幂次方
// 题目描述
//     Every positive number can be presented by the exponential form.For example, 137 = 2^7 + 2^3 + 2^0。     Let's present a^b by the form a(b).Then 137 is presented by 2(7)+2(3)+2(0). Since 7 = 2^2 + 2 + 2^0 and 3 = 2 + 2^0 , 137 is finally presented by 2(2(2)+2 +2(0))+2(2+2(0))+2(0).        Given a positive number n,your task is to present n with the exponential form which only contains the digits 0 and 2.
// 输入描述:
// For each case, the input file contains a positive integer n (n<=20000).
//
// 输出描述:
// For each case, you should output the exponential form of n an a single line.Note that,there should not be any additional white spaces in the line.
// 
// 输入
// 1315
//
// 输出
// 2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string f(int N)
{
	if(N==0) return "0";
	string str;
	int n = N;
	while(N > 0)
	{
		int sum = 0;
		while((n = n/2) > 0) sum++;
		if(sum == 1) str+="2";
		else
		{
			str+="2()";
			if(sum == 0) str.insert(str.length()-1,"0");
			else
			{
				string mid_1 = f(sum);
				str.insert(str.length()-1,mid_1);
			}
		}
		N -= pow(2,sum);
		if(N > 0) str+="+";
		n = N;
	}
	return str;
}

int main()
{
	int n;	cin >> n;
	cout << f(n);
	return 0;
}
