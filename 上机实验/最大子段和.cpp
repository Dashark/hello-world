// Description:
// 给出一段序列，选出其中连续且非空的一段使得这段和最大。
// Input:
// 第一行是一个正整数N（N <= 200000），表示了序列的长度。
// 第接下来的N行包含N个绝对值不大于10000的整数A[i]，描述了这段序列。
// Output:
// 仅包括1个整数，为最大的子段和是多少。子段的最小长度为1。
// Sample Input:
// 7
// 2
// -4
// 3
// -1
// 2
// -4
// 3
// Sample Output:
// 4
// Hint:

#include <iostream>

using namespace std;

int number[200000];
int mid[200000]; //表示以i为末尾的最大子段和

int main()
{
	int num; cin >> num;
	for(int i = 1;i <= num ;i++)
	{
		cin >> number[i];
		mid[i] = number[i];
	}
	//the solvement one;
	// int MAX = number[0];
	// for(int i = 0;i < num;i++)
	// {
	// 	int sum = 0;
	// 	for(int j = i;j < num;j++)
	// 	{
	// 		sum+=number[j];
	// 		if(MAX < sum) MAX = sum;
	// 	}
	// }
	//cout << MAX;
	/**************************/
	//the dp is //
	// 定义 f[i] 为以 num[i] 为结尾的最大子段和。对于已经知道 f[i-1] 来说，
	// f[i]其实就是 num[i] 拿与不拿的问题，由此可得 f[i] = max( f[ i ] , f[ i - 1 ] + num[ i ] );
	for(int i = 1;i <= num;i++) mid[i] = max(mid[i-1]+number[i],mid[i]);
	int MAX = -200000;
	for(int i = 1;i <= num;i++) MAX = max(MAX,mid[i]);
	cout << MAX;
	return 0;
}
