#include"utility.h"
#include"Simple_list_without_head_node.h"
#include<iostream>



int main()
{
	using namespace std;
	int choice, position;
	NOHEAD<double>la, lb;
	double e;

	cout << "1.生成线性表。" << endl;
	cout << "2.显示线性表。" << endl;
	cout << "3.检索线性表。" << endl;
	cout << "4.设置元素值。" << endl;
	cout << "5.删除元素。" << endl;
	cout << "6.插入元素。" << endl;
	cout << "7.退出" << endl;
	cout << "请输入你想要进行的操作:";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << endl << "输入e（e=0时退出）: ";
		cin >> e;
		while (e != 0)
		{
			la.Insert(la.Length() + 1, e);
			cin >> e;
		}

		break;
	}
	case 2:
	{
		lb = la;           //对赋值运算符进行测试
		lb.Traverse(Write<double>);//调用Write函数，以double类型显示线性表

		break;
	}
	case 3:
	{
		cout << endl << "请输入元素位置：";
		cin >> position;
		if (la.GetElem(position, e) == NOT_PRESENT)
			cout << "元素不存储。" << endl;
		else
			cout << "元素：" << e << endl;
		break;
	}
	case 4:
	{
		cout << endl << "请输入元素位置：";
		cin >> position;
		cout << endl << "请输入元素值：";
		cin >> e;
		if (la.SetElem(position, e) == RANGE_ERROR)
			cout << "位置范围错误。" << endl;
		else
			cout << "设置成功。" << endl;
		break;
	}
	case 5:
	{
		cout << endl << "请输入元素位置：";
		cin >> position;
		if (la.Delete(position, e) == RANGE_ERROR)
			cout << "位置范围错误。" << endl;
		else
			cout << "被删除元素值：" << e << endl;

		break;
	}
	case 6:
	{
		cout << endl << "请输入元素位置：";
		cin >> position;
		cout << endl << "请输入元素值：";
		cin >> e;
		if (la.Insert(position, e) == RANGE_ERROR)
			cout << "位置范围错误。" << endl;
		else
			cout << "插入成功，插入元素值：" << e << endl;
		break;
	}
	case 7:    break;

	}
	return 0;
}
