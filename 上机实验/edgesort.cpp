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

#include <iostream>
#include <algorithm>

using namespace std;

struct PATH
{
	int point_u;
	int point_v;
	int len;
	int time;
	int cost;
	int volume;
	int flow;
};

bool cmp(const PATH &a,const PATH &b)
{
	if(a.len < b.len) return true;
	else if(a.len > b.len) return false;
	else
	{
		if(a.time < b.time) return true;
		else if(a.time > b.time) return false;
		else
		{
			if(a.cost < b.cost) return true;
			else if(a.cost > b.cost) return false;
			else
			{
				if(a.volume < b.volume) return true;
				else if(a.volume > b.volume) return false;
				else
				{
					if(a.flow < b.flow) return true;
					else if(a.flow > b.flow) return false;
					else return true;
				}
			}
		}
	}
}

void show(const PATH& path)
{
	cout << path.point_u << " " << path.point_v << " " << path.len << " " <<path.time << " " <<path.cost
	<< " " <<path.volume << " "<<path.flow << endl;
}

int main()
{
	int n; cin >> n;
	PATH paths[n];
	for(int i = 0;i < n;i++)
	{
		cin >> paths[i].point_u;
		cin >> paths[i].point_v;
		cin >> paths[i].len;
		cin >> paths[i].time;
		cin >> paths[i].cost;
		cin >> paths[i].volume;
		cin >> paths[i].flow;
	}
	sort(paths,paths+n,cmp);
	int count; cin >> count;
	while(count--)
	{
		int rank; cin >> rank;
		show(paths[rank-1]);
	}

	return 0;
}
