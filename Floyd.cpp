#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 300;
int n, m, s, t, i, j, k;
int Chara[N][N];
void Floyd()
{
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                if (Chara[j][i] + Chara[i][k] < Chara[j][k])
                    Chara[j][k] = Chara[j][i] + Chara[i][k];
            }
        }
    }
}
int main()
{
    while (~scanf("%d %d", &n, &m))
    {
        int a, b, x;
        memset(Chara, 0x3f, sizeof(Chara));
        for (int i = 0; i <= n; i++)
            Chara[i][i] = 0;
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &a, &b, &x);
            if (x < Chara[a][b])
                Chara[a][b] = Chara[b][a] = x;
        }
        scanf("%d %d", &s, &t);
        Floyd();
        if (Chara[s][t] == INF)
            cout << -1 << endl;
        else
            cout << Chara[s][t] << endl;
    }
    return 0;
}