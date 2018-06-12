// Time Limit: 1000ms
// Memory Limit: 64M
//
// Description:
// 给一个正整数n，代表操作数。
// 接下来n行，每行有一下三类操作中的某一种
// I x 代表插入x到堆中
// D 代表删除最小值，保证堆非空
// Q 输出最小值，保证堆非空
//
// Sample Input:
// 12
// I 3
// I 1
// I 2
// Q
// D
// Q
// I 4
// Q
// I 1
// Q
// D
// Q
//
// Sample Output:
// 1
// 2
// 2
// 1
// 2
//
// Hint:
// 对于80%的数据 n <= 1000
// 对于100%的数据 n <= 1000000

#include <iostream>
#include <queue>
#include <functional> //VS 下包含此目录

using namespace std;

int main()
{
	priority_queue<int,vector<int>,greater<int>> q; //从小到大的顺序出队优先队列
	int count; cin >> count;
	char cmd; int number;
	while(count--)
	{
		cin >> cmd;
		if(cmd == 'I')
		{
			cin >> number;
			q.push(number);
		}
		else if(cmd == 'D')
		{
			q.pop();
		}
		else
		{
			cout << q.top() << endl;
		}
	}

	return 0;
}
