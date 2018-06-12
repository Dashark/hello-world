// Description景观水道是江安一道非常靓丽的风景，一共有L mathons(这是Mathon发明的长度单位)长，每隔一mathon都有一颗银杏树即0, 1, 2, …, L都有一棵银杏树。Mathon非常喜欢景观水道，
// 时常会来景观水道走走。
// 昨晚成都狂风大作，大雨倾盆，据说景观水道不少区域里所有的树都被连根拔起。Mathon知道后感到非常伤心，他想知道这场大风过后还剩下多少银杏树，你能帮帮他么。
// Input
// 输入包含多组数据。第一行为测试数据的组数 T <=10
// 接下来有T组数据，每组数据的第一行为1<=L<=10000 和 1<=M<=100 ，L表示景观水道的长度，M表示区域的数目。
// 接下来的M行每行包含两个不同的整数0<=l<=r<=L表示区域的范围[l, r]，不同的区域可能有重合的部分。
// Output
// 每组数据输出一行，输出大风过后景观水道还剩下多少银杏树。
// Sample Input1
// 500 3
// 150 300
// 100 200
// 470 471
// Sample Output
// 298

#include <iostream>
#include <algorithm>

using namespace std;

struct tree
{
	int kind;
	int number;
};

bool cmp(tree a,tree b)
{
	if(a.number == b.number) return a.kind < b.kind;
	return a.number < b.number;
}

int main()
{
	int T; cin >> T;
	while(T--)
	{
		int L,M; cin >> L >> M;
		tree line[M*2+1];
		for(int i = 1;i <= 2*M;i++)
		{
			int pos; cin >> pos;
			line[i].number = pos;
			if(i % 2==1) line[i].kind = 0;
			else line[i].kind = 1;
		}
		sort(line+1,line+2*M+1,cmp);
		int number = 0,start = 0,flag = 0;
		int lenth = 0;
		for(int i = 1;i <= 2*M;i++)
		{
			if(line[i].kind == 0)
			{
				if(number == 0) start = line[i].number;
				number++;
			}
			else number--;
			if(number == 0) lenth += line[i].number-start+1;
		}
		cout << L+1-lenth << endl;
	}
	return 0;
}
