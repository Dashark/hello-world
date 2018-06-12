// Description:
// 给两个长度为n的全排列，求其最长公共子序列长度。
//
// Input:
// 第一行是一个正整数N，表示全排列长度。
// 第二行有n个整数，保证是一个n的全排列。
// 第三行有n个整数，保证是一个n的全排列。
//
// Output:
// 输出第一行有一个整数，表示两数组最长公共子序列长度。
//
// Sample Input:
// 5
// 1 3 2 4 5
// 5 2 3 1 4
//
// Sample Output:
// 2
//
// Hint:
// 对于80%的数据 n <= 1000
// 对于100%的数据 n <= 1000000
//the href to help you understand :
//https://blog.csdn.net/u012102306/article/details/53184446
// 假设Z=<z1,z2,?,zk>是X与Y的LCS， 我们观察到
// 如果Xm=Yn，则Zk=Xm=Yn，有Zk?1是Xm?1与Yn?1的LCS；
// 如果Xm≠Yn，则Zk是Xm与Yn?1的LCS，或者是Xm?1与Yn的LCS。
//O(n^2) RE
//So we find it is all permutation so it can translate
//to find The longest non descending sequence
//you can visit https://www.luogu.org/blog/user40959/solution-p1439
//and https://www.cnblogs.com/milky-w/p/8431333.html

#include<iostream>
#include<algorithm>

using namespace std;

int stand[1000010];
int Target_1[1000010];
int Target_2[1000010];
int rise[1000010];

int toFindSmall(int* num,int len,int target)
{
	if(target < num[1]) return 1; //attation
	int front = 1,end = len;
	int mid,cmp =  -1;
	if(num[len] == target) return len;
	while (front <= end)
	{
		mid = (front + end)/2;
		if(cmp == mid) return mid+1;
		cmp = mid;
		// cout << mid;
		if(num[mid] > target)
		{
			end = mid;
		}
		else if(num[mid] < target)
		{
			front = mid;
		}
		else return mid + 1;
	}
	return mid;
}

int Solution_1(int* num1,int* num2,int sum)
{
	int lenth[sum+1][sum+1];
	for(int i = 0;i <= sum;i++)
	{
		for(int j = 0;j <= sum;j++)
		{
			if(i==0 || j==0) lenth[i][j] = 0;
			else if(num1[i] == num2[j])
			{
				lenth[i][j] = lenth[i-1][j-1]+1;
			}
			else
			{
				lenth[i][j] = max(lenth[i-1][j],lenth[i][j-1]);
			}
		}
	}
	return lenth[sum][sum];
}

int Solution_2(int* num,int lenth)
{
	if(lenth == 0) return 0;
	rise[1] = stand[num[1]];
	int len = 1;
	//rise[1] = stand[num[1]]; //表示在i这个位置的最小元素
	for(int i = 2;i <= lenth;i++) //n
	{
		if(stand[num[i]] >= rise[len])
		{
			rise[++len] = stand[num[i]];
		}
		else
		{
			int k = toFindSmall(rise,len,stand[num[i]]); //logn
			int k1 = upper_bound(rise+1,rise+len+1,stand[num[i]])-rise;
			rise[k] = stand[num[i]];
		}
	} //the all is nlogn
	return len;
}

int main()
{
	int sum; cin >> sum;
	for(int i = 1;i <= sum;i++)
	{
		cin >> Target_1[i];
		stand[Target_1[i]] = i;
	}
	for(int i = 1;i <= sum;i++) cin >> Target_2[i];
	//cout << Solution_1(Target_1,Target_2,sum) << endl;
	cout << Solution_2(Target_2,sum) << endl;

	return 0;
}
