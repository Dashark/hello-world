#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <string>
#include <iostream>

using namespace std;

map<string, bool> All;

struct node
{
	char s[14];
	int steps;
};

void transform(queue<node> &q, node n, int N)
{
	char c;
	node temp;
	for (int i = 0; i < N - 1; i++)
	{
		strcpy(temp.s, n.s);
		c = temp.s[i];
		temp.s[i] = temp.s[i+1];
		temp.s[i+1] = c;
		temp.steps = n.steps + 1;
		if (All.count(temp.s) == 0)
		{
			All[temp.s] = false;
			q.push(temp);
		}
	}
	return;
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		char sourse[14];
		scanf("%s", &sourse);
		All.clear();
		queue<node> search;
		node temp;
		bool If_find = false;
		strcpy(temp.s, sourse);
		temp.steps = 0;
		All[temp.s] = false;
		search.push(temp);
		while (!search.empty() && If_find == false)
		{
			temp = search.front();
			if (All[temp.s] == true) search.pop();
			else
			{
				if (strstr(temp.s, "2012") != NULL)
				{
					printf("%d\n", temp.steps);
					If_find = true;
				}
				else
				{
					transform(search, temp, n);
					All[temp.s] = true;
					search.pop();
				}
			}
		}
		if (If_find == false)
		{
			printf("-1\n");
		}
	}
	return 0;
}


