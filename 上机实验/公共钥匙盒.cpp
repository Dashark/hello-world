// G: 公共钥匙盒
// 描述
//
// 有一个学校的老师共用N个教室，按照规定，所有的钥匙都必须放在公共钥匙盒里，老师不能带钥匙回家。每次老师上课前，都从公共钥匙盒里找到自己上课的教室的钥匙去开门，上完课后，再将钥匙放回到钥匙盒中。
// 钥匙盒一共有N个挂钩，从左到右排成一排，用来挂N个教室的钥匙。一串钥匙没有固定的悬挂位置，但钥匙上有标识，所以老师们不会弄混钥匙。
// 每次取钥匙的时候，老师们都会找到自己所需要的钥匙将其取走，而不会移动其他钥匙。每次还钥匙的时候，还钥匙的老师会找到最左边的空的挂钩，将钥匙挂在这个挂钩上。如果有多位老师还钥匙，则他们按钥匙编号从小到大的顺序还。如果同一时刻既有老师还钥匙又有老师取钥匙，则老师们会先将钥匙全还回去再取出。
// 今天开始的时候钥匙是按编号从小到大的顺序放在钥匙盒里的。有K位老师要上课，给出每位老师所需要的钥匙、开始上课的时间和上课的时长，假设下课时间就是还钥匙时间，请问最终钥匙盒里面钥匙的顺序是怎样的？
// 
// 输入
//
// 输入的第一行包含两个整数N, K。
// 接下来K行，每行三个整数w, s, c，分别表示一位老师要使用的钥匙编号、开始上课的时间和上课的时长。可能有多位老师使用同一把钥匙，但是老师使用钥匙的时间不会重叠。
// 保证输入数据满足输入格式，你不用检查数据合法性。
//
// 输出
//
// 输出一行，包含N个整数，相邻整数间用一个空格分隔，依次表示每个挂钩上挂的钥匙编号。
//
// 样例
//
// 输入
// 输出
// 5 2
// 4 3 3
// 2 2 7
// 1 4 3 2 5
//
//
//
// 样例说明
//
// 第一位老师从时刻3开始使用4号教室的钥匙，使用3单位时间，所以在时刻6还钥匙。第二位老师从时刻2开始使用钥匙，使用7单位时间，所以在时刻9还钥匙。
// 每个关键时刻后的钥匙状态如下（X表示空）：
// 时刻2后为1X345；
// 时刻3后为1X3X5；
// 时刻6后为143X5；
// 时刻9后为14325。
//
// 样例
//
// 输入
// 输出
// 5 7
// 1 1 14
// 3 3 12
// 1 15 12
// 2 7 20
// 3 18 12
// 4 21 19
// 5 30 9
// 1 2 3 5 4
//
//
// 样例说明
//
// 对于30%的评测用例，1 ≤ N, K ≤ 10, 1 ≤ w ≤ N, 1 ≤ s, c ≤ 30；
// 对于60%的评测用例，1 ≤ N, K ≤ 50，1 ≤ w ≤ N，1 ≤ s ≤ 300，1 ≤ c ≤ 50；
// 对于所有评测用例，1 ≤ N, K ≤ 1000，1 ≤ w ≤ N，1 ≤ s ≤ 10000，1 ≤ c ≤ 100。
//
//


#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#define MAX 99999999;

using namespace std;

struct teacher
{
	int key;
	int start;
	int end;
};

struct  cmp_start
{
	bool operator()(const teacher& a,const teacher& b)
	{
		return a.start > b.start;
	}
};

struct  cmp_end
{
	bool operator()(const teacher& a,const teacher& b)
	{
		if(a.end == b.end)   //同一时刻很多老师还的话，按钥匙号码大小还
		{
			return a.key > b.key;
		}
		return a.end > b.end;
	}
};


int main()
{
	int Key_number,teacher_number; cin >> Key_number >> teacher_number;
	int Key_box[Key_number+1];
	for(int i = 1;i <= Key_number;i++) Key_box[i] = i; //初始化钥匙盒 下标是位置 值是钥匙 -1代表空
	teacher teachers[teacher_number];
	priority_queue<teacher,vector<teacher>,cmp_start> start; //开始时间排序的队列
	priority_queue<teacher,vector<teacher>,cmp_end> end;	//以结束时间排序的队列
	priority_queue<int,std::vector<int>,greater<int> > Empty; //存取空位的队列每次取出最左边的那一个

	for(int i = 0;i < teacher_number;i++)
	{
		int a,b,c; cin >> a >> b >> c;
		teachers[i].key = a;
		teachers[i].start = b;
		teachers[i].end = b+c;
		start.push(teachers[i]);
		end.push(teachers[i]);
	}

	while(true)
	{
		if(start.empty()==true && end.empty()==true) break;
		teacher one; teacher two; //one is start two is end
		one.start = two.end = MAX;
		if(start.empty()!=true) one = start.top();
		if(end.empty()!=true) two = end.top();
		if(one.start < two.end)
		{
			int pos;//钥匙在哪个空位
			for(int i = 1;i <= Key_number;i++)
			{
				if(Key_box[i] == one.key)
				{
					pos = i;
					break;
				}
			}
			Key_box[pos] = 0;
			Empty.push(pos); //空位记录
			start.pop();
		}
		if(one.start >= two.end)
		{
			int index = Empty.top();
			Key_box[index] = two.key;
			Empty.pop();
			end.pop();
		}
	}
	for(int i = 1;i <= Key_number;i++) cout << Key_box[i] <<" ";
	return 0;
}
