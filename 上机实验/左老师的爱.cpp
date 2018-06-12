// Description:
// 左老师有n个题目，他希望出一张考试试卷，从中选取一定数量的题目，在不改变给定题目顺序的情况下，要求选取的题目难度严格递增，为了防止有人AK，左老师希望在考试中出尽可能多的题目，求最大题目数量。
//
// Input:
// 每个测试点只有一组测试数据。
// 第一行一个整数n表示题目数量，第二行n个整数ai表示题目难度。
//
// Output:
// 输出一个整数ans，一场考试中题目数量的最大值
//
// Sample Input:
// 5
// 1 2 3 1 5
//
// Sample Output:
// 4
//
// Hint:
// 可以选取第1、2、3、5题

#include <iostream>

using namespace std;

int number[1000000];
int Len_Of_Small[1000000];

int BiSearch(int *b, int len, int w)
{
    int left = 0, right = len - 1;
    int mid;
    while (left <= right)
    {
        mid = left + (right-left)/2;
        if (b[mid] > w)
            right = mid - 1;
        else if (b[mid] < w)
            left = mid + 1;
        else    //找到了该元素，则直接返回
            return mid;
    }
    return left;//数组b中不存在该元素，则返回该元素应该插入的位置
}


int main()
{
	int sum ; cin >> sum;
	int len = 1;
	for(int i = 0;i < sum;i++) cin >> number[i];
	Len_Of_Small[0] = number[0];
	for(int i = 1;i < sum;i++)
	{
		if(number[i] > Len_Of_Small[len-1])
		{
			Len_Of_Small[len] = number[i];
			len++;
		}
		else
		{
			int index = BiSearch(Len_Of_Small,len,number[i]);
			Len_Of_Small[index] = number[i];
		}
	}
	cout << len;

	return 0;
}
