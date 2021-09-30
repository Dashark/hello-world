#include<iostream>
#include<vector>
using namespace std;
#define MAXN 999999;
int main(void)
{
    int numbers, path_num, start;
    cin >> numbers >> path_num >> start;
    int length[numbers][numbers];
    int from,to,len;
    for(int i = 0; i < numbers; i++)
    {
        for(int j = 0; j < numbers; j++)
        {
            length[from][to] = MAXN;
        }
    }
    for(int i = 0; i < path_num; i++)
    {
        cin >> from >> to >> len;
        length[from-1][to-1] = len;
    }
    vector <int> starting;
    starting.push_back(start);
    
}