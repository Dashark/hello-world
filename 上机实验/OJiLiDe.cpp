// BackGroud
//
// 在RSA密码体系中,欧几里得算法是加密或解密运算的重要组成部分。它的基本运算过程就是解 x*a=1(mod n) 这种方程。
//
// The Problem
//
// 整个解的过程是这样的，我们用一个例子来说明。
// 当a＝1001 ，n＝3837时
// 方程为 x * 1001 = 1 (mod 3837)
//
// 求解过程：
//
// 3837 = 3 * 1001 + 834
// 1001 = 1 * 834 + 167
// 834 = 4 * 167 + 166
// 167 = 166 + 1
//
// 所以
//
// 1 = 167 - 166
// = 167 - (834 - 4 * 167)
// = 5 * 167 - 834
// = 5 *(1001 - 834) - 834
// = 5 * 1001 - 6 *834
// = 5 * 1001 - 6 * (3837 -3 *1001)
// = 23 * 1001 - 6 *3837
//
// 然后对等式两端同时除以模3837得
//
// 23 * 1001 = 1 (mod 3837)
// 于是 x ＝ 23
// 现在给出a和n，你能不能在最短的时间内解出这个方程呢？
//
// 输入
//
// 输入包括多组测试数据。每组测试数据对应输入的一行，每行包括两个整数a和n。1<a,n<2^31(用long可以存下)
// 当a＝n＝0时输入结束，这组数据不包括在需要计算的数据中。
//
// 输出
//
// 对应每组输入数据，输出最小的满足题意的解x。
// 注意:本题用搜索是不可能做出来的,所以....
// 样例输入
//
// 1001 3837
// 136468984 134548555
// 0 0
// 样例输出
//
// 23
// 112206854


#include<iostream>

using namespace std;

long int INT[1010][4];
int len = 0;

long int Ojilid(int x,int y)
{
	// cout << x << endl;
	if(x==1 && y==0) return 1;
	if(y==0&&x>=0)
	{
		x -= 2;
		y = 2;
	}
	if(y == 1&&x>=0)
	{
		x -= 1;
		y = 2;
	}
	if(x==0 && y==2) return -1*INT[0][1];
	return 1*Ojilid(x,y-2)-INT[x][y-1]*Ojilid(x,y-1);
}

int main()
{
	long int num1,num2;
	while(cin >> num1 >> num2)
	{
		len = 0;
		if(num1==0 && num2==0) break;
		int a = num1,b = num2;
		while(true)
		{
			int temp = b;
			if(temp%a==0) break;
			INT[len][1] = b/a;
			INT[len][0] = 1;
			INT[len][2] = 1;
			b = a;
			len++;
			if((a = temp%a)==1) break;
		}
		if(len==0)
		{
			cout << "0" << endl;
			continue;
		}
		long int result = Ojilid(len-1,2);
		if(result < 0) result += num2;
		cout << result << endl;
	}
	return 0;
}
