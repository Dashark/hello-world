// F: Huffman
// Time Limit: 1000ms
// Memory Limit: 128M
//
// Description:
// 第一行有一个正整数n，代表单词的个数
// 第二行有n个正整数代表第i个单词在文章中出现的次数。(a[i] <= 10)
// 试求将每个单词进行01编码后文章的最小长度。
//
// Sample Input:
// 4
// 1 2 3 4
//
// Sample Output:
// 19
//
// Hint:
// 将第一个单词编码为000
// 第二个单词编码为001
// 第三个单词编码为01
// 第四个单词编码为1
// 总长度为3 * 1 + 3 * 2 + 2 * 3 + 1 * 4 = 19
//
// 对于80%的数据 n <= 1000
// 对于100%的数据 n <= 1000000


#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,number;

int main()
{
	long long total = 0;
	priority_queue< int,vector<int>,greater<int> > que;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&number);
		que.push(number);
	}
	while(que.size() > 1)
	{
		int small_1,small_2;
		small_1 = que.top();
		que.pop();
		small_2 = que.top();
		que.pop();
		total += small_1+small_2;
		que.push(small_1+small_2);
	}
	printf("%lld",total);
	return 0;
}
