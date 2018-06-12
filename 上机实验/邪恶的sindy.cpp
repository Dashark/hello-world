// C: 邪恶的Sidney
// Time Limit: 1000ms
// Memory Limit: 65M
//
// Description:
// 时间过得很快，又到了星期二——挂新training的日子。Sidney手里有很多备选题，每道题都有一个标程长度和难度系数，邪恶的Sidney希望在表面看起来难度不超过规定（标程长度和不超过规定）的情况下，实际的难度（标程长度*难度系数之和）最大，你能帮帮他吗？
// 抽象的，我们设第j道的标程长度为v[j]，难度系数为w[j]，共选中了k道题，编号依次为j1，j2，……，jk，则所求为：
// v[j1]*w[j1]+v[j2]*w[j2]+ …+v[jk]*w[jk]最大
//
// Input:
// 输入的第1行，为两个正整数，用一个空格隔开：N m（1 <= N <= 30000）表示预计标程长度之和不能超过的总长度，m(1 <= m <= 25)为备选的题的个数。）
// 从第2行到第m+1行，第j行给出了编号为j-1的题的基本数据，每行有2个非负整数 v p（其中v表示该题的标程长度 (1 <= v<=10000)，p表示该题的难度系数(1~5)）
//
// Output:
// 输出只有一个正整数，为标程长度与难度系数乘积之和的最大值（<1e8）
// Sample Input:
// 1000 5
// 800 2
// 400 5
// 300 5
// 400 3
// 200 2
// Sample Output:
// 3900

#include<iostream>

using namespace std;

struct Question
{
	int lenth;
	int difficulty;
}questons[30];

int Search_big[30][30010];
int Search_one[30010];

int  Search(int,int);
int Search_anthoer(int,int);

int main()
{
	int limit,number; cin >> limit >> number;
	for(int i = 1;i <= number;i++)  cin >> questons[i].lenth >> questons[i].difficulty;
	//cout << Search(limit,number) << endl;
	cout << Search_anthoer(limit,number) << endl;
	return 0;
}

int Search(int limit,int number)
{
	for(int i = 1;i <= number;i++)
	{
		for(int j = 1;j <=limit;j++)
		{
			Search_big[i][j] = Search_big[i-1][j];
			if(questons[i].lenth <= j)
			{
				if(Search_big[i-1][j-questons[i].lenth]+questons[i].lenth*questons[i].difficulty > Search_big[i-1][j])
				{
					Search_big[i][j] = Search_big[i-1][j-questons[i].lenth]+questons[i].lenth*questons[i].difficulty;
				}
			}
		}
	}
	return Search_big[number][limit];
}

int Search_anthoer(int limit,int number)
{
	for(int i = 1;i <= number;i++)
	{
		for(int j = limit;j >= questons[i].lenth;j--)
		{
			Search_one[j] = max(Search_one[j],Search_one[j-questons[i].lenth]+questons[i].lenth*questons[i].difficulty);
		}
	}
	return Search_one[limit];
}
