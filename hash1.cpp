#include <iostream>
#include <string>
#include <cmath>
using namespace std;
const int N = 32;
int h[N] = {0};
int module(int n)
{
    return n & (N - 1);
}
int main(void)
{
    int number;
    int nn;
    cin >> nn;
    while (nn > 0)
    {
        cin >> number;
        int mod = module(number);
        while (h[mod] != 0)
        {
            mod = (1 + mod) % N;
        }
        h[mod] = number;
        nn--;
    }
    cout << "search: ";
    int n;
    cin >> n;
    int mod = module(n);
    mod--;
    bool flag = false;
    do
    {
        mod++;
        mod % N;
        if (h[mod] == n)
            flag = true;
    } while (h[(1 + mod) % N] != 0);
    if (flag)
        cout << "Y";
    else
    {
        cout << "N";
    }
    cout << endl;

    return 0;
}
