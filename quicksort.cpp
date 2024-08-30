#include <iostream>
using namespace std;
//int i = 0;
void rank1(int a[], int left, int right) // [left,right)
{
    //cout  << "running...." << i++ << endl;
    if (left >= right - 1)
        return;
    else
    {
        int standard = a[left];
        int space = left; //space:the location of the number
        int start = left;
        int end = right - 1;
        while (start < end)
        {
            while (end > start && a[end] > standard)
            {
                end--;
            }
            if (start >= end)
                break;
            while (start < end && a[start] <= standard)
            {
                start++;
            }
            if (start >= end)
                break;
            swap(a[start], a[end]);
        }
        swap(a[start], a[space]);
        rank1(a, left, start);
        rank1(a, start + 1, right);
        return;
    }
    return;
}
int main(void)
{
    //freopen("out.txt", "r", stdin);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    rank1(a, 0, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    //fclose(stdin);
    return 0;
}
