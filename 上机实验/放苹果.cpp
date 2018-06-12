/* 功能Function Description:     POJ-1664
   开发环境Environment:          DEV C++ 4.9.9.1
   技术特点Technique:
   版本Version:
   作者Author:                   可笑痴狂
   日期Date:                      20120815
   备注Notes:
   解题分析：
        设f(m,n) 为m个苹果，n个盘子的放法数目，则先对n作讨论，
        当n>m：必定有n-m个盘子永远空着，去掉它们对摆放苹果方法数目不产生影响。即if(n>m) f(m,n) = f(m,m)　　
        当n<=m：不同的放法可以分成两类：
        1、有至少一个盘子空着，即相当于f(m,n) = f(m,n-1);
        2、所有盘子都有苹果，相当于可以从每个盘子中拿掉一个苹果，不影响不同放法的数目，即f(m,n) = f(m-n,n).
        而总的放苹果的放法数目等于两者的和，即 f(m,n) =f(m,n-1)+f(m-n,n)
    递归出口条件说明：
        当n=1时，所有苹果都必须放在一个盘子里，所以返回１；
        当没有苹果可放时，定义为１种放法；
        递归的两条路，第一条n会逐渐减少，终会到达出口n==1;
        第二条m会逐渐减少，因为n>m时，我们会return f(m,m)　所以终会到达出口m==0．
*/
//POJ 1664
#include<iostream>

using namespace std;

int dp(int m,int n) //the ways of put m apples into n plates
{
	if(m == 0 || n == 1) return 1; //因为我们总是让m>=n来求解的，所以m-n>=0,所以让m=0时候结束，如果改为m=1，
	else if(m < n) return dp(m,m);//则可能出现m-n=0的情况从而不能得到正确解
	else return dp(m,n-1)+dp(m-n,n);
}

int main()
{
	int k; cin >> k;
	while(k--)
	{
		int m,n; scanf("%d%d",&m,&n);
		cout << dp(m,n);
	}
	return 0;
}
