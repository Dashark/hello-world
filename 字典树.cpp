#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int inf = 1e9 + 9;
char str[202];
int f[202], dp[2][202][202], tmp[2][202], n, pa[202], adj[202][202], num[202];
char tm[2][202][402], nm[2][202];
char dd[2][202][202][402], g[2][202][202][402], tg[2][202][402], tp[2][202][402], ff[202][402];
int nd[2][202], ne[2][202][202], nc[202], ng[2][202][202];
int deep[202];
int vec[202][202], num_vec[202], at[202], dist[202];
char st[2][402], tr[402], sk[402];
int lr, cmft;
int len[2], vis[2][202], times;
char ans[202];
void merge(int a, int b, int c, int d, int e, int f) {
    int i, j, s, p, q, flag, ch = 0, ce;
    bool inq = false;
    len[0] = len[1] = 0;
    for (i = 0; i < nc[c] - ne[a][b][c]; i++) st[0][len[0]++] = ff[c][i];
    for (i = 0; i < ne[a][b][c]; i++) {
        if (dd[a][b][c][i] != ff[c][i + nc[c] - ne[a][b][c]])
            break;
    }
    if (i < ne[a][b][c] && dd[a][b][c][i] < ff[c][i + nc[c] - ne[a][b][c]])
        flag = 0;
    else
        flag = 1;
    st[0][len[0]++] = flag;
    ch = 1;
    if (ng[a][b][c] > ng[d][e][f])
        ch = 0;
    else if (ng[a][b][c] == ng[d][e][f]) {
        for (i = 0; i < ng[a][b][c]; i++) {
            if (g[a][b][c][i] != g[d][e][f][i])
                break;
        }
        if (i < ng[a][b][c]) {
            if (g[a][b][c][i] > g[d][e][f][i])
                ch = 0;
        }
    }
    for (i = 0; i < nc[f] - ne[d][e][f]; i++) st[1][len[1]++] = ff[f][i];
    for (i = 0; i < ne[d][e][f]; i++) {
        if (dd[d][e][f][i] != ff[f][i + nc[f] - ne[d][e][f]])
            break;
    }
    if (i < ne[d][e][f] && dd[d][e][f][i] < ff[f][i + nc[f] - ne[d][e][f]])
        flag = 0;
    else
        flag = 1;
    st[1][len[1]++] = flag;
    flag = 0;
    if (len[0] > len[1])
        flag = 1;
    else if (len[0] == len[1]) {
        for (i = 0; i < len[0]; i++) {
            if (st[0][i] < st[1][i])
                break;
            if (st[0][i] > st[1][i]) {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0) {
        if (tmp[a][c] < 0) {
            inq = true;
            if (ch == 1) {
                tmp[a][c] = dp[a][b][c];
                for (i = 0; i < ng[a][b][c]; i++) tm[a][c][i] = g[a][b][c][i];
                nm[a][c] = ng[a][b][c];
            } else {
                tmp[a][c] = dp[d][e][f];
                for (i = 0; i < ng[d][e][f]; i++) tm[a][c][i] = g[d][e][f][i];
                nm[a][c] = ng[d][e][f];
            }
        } else {
            ce = 0;
            if (ch == 1) {
                if (nm[a][c] < ng[a][b][c])
                    ce = 1;
                else if (nm[a][c] == ng[a][b][c]) {
                    for (i = 0; i < nm[a][c]; i++) {
                        if (tm[a][c][i] < g[a][b][c][i]) {
                            ce = 1;
                            break;
                        } else if (tm[a][c][i] > g[a][b][c][i])
                            break;
                    }
                }
                if (ce == 1) {
                    inq = true;
                    tmp[a][c] = dp[a][b][c];
                    nm[a][c] = ng[a][b][c];
                    for (i = 0; i < ng[a][b][c]; i++) tm[a][c][i] = g[a][b][c][i];
                }
            } else {
                ce = 0;
                if (nm[a][c] < ng[d][e][f])
                    ce = 1;
                else if (nm[a][c] == ng[d][e][f]) {
                    for (i = 0; i < nm[a][c]; i++) {
                        if (tm[a][c][i] < g[d][e][f][i]) {
                            ce = 1;
                            break;
                        } else if (tm[a][c][i] > g[d][e][f][i])
                            break;
                    }
                }
                if (ce == 1) {
                    inq = true;
                    tmp[a][c] = dp[d][e][f];
                    nm[a][c] = ng[d][e][f];
                    for (i = 0; i < nm[a][c]; i++) tm[a][c][i] = g[d][e][f][i];
                }
            }
        }
        if (inq) {
            nd[a][c] = 0;
            for (i = 0; i < ne[a][b][c]; i++) tp[a][c][nd[a][c]++] = dd[a][b][c][i];
        }
    } else {
        inq = false;
        if (tmp[d][f] < 0) {
            inq = true;
            if (ch == 1) {
                tmp[d][f] = dp[a][b][c];
                for (i = 0; i < ng[a][b][c]; i++) tm[d][f][i] = g[a][b][c][i];
                nm[d][f] = ng[a][b][c];
            } else {
                tmp[d][f] = dp[d][e][f];
                for (i = 0; i < ng[d][e][f]; i++) tm[d][f][i] = g[d][e][f][i];
                nm[d][f] = ng[d][e][f];
            }
        } else {
            ce = 0;
            if (ch == 1) {
                if (nm[d][f] < ng[a][b][c])
                    ce = 1;
                else if (nm[d][f] == ng[a][b][c]) {
                    for (i = 0; i < nm[d][f]; i++) {
                        if (tm[d][f][i] < g[a][b][c][i]) {
                            ce = 1;
                            break;
                        } else
                            break;
                    }
                }
                if (ce == 1) {
                    inq = true;
                    tmp[d][f] = dp[a][b][c];
                    nm[d][f] = ng[a][b][c];
                    for (i = 0; i < nm[d][f]; i++) tm[d][f][i] = g[a][b][c][i];
                }
            } else {
                if (nm[d][f] < ng[d][e][f])
                    ce = 1;
                else if (nm[d][f] == ng[d][e][f]) {
                    for (i = 0; i < nm[d][f]; i++) {
                        if (tm[d][f][i] < g[d][e][f][i]) {
                            ce = 1;
                            break;
                        } else if (tm[d][f][i] > g[d][e][f][i])
                            break;
                    }
                }
                if (ce == 1) {
                    inq = true;
                    tmp[d][f] = dp[d][e][f];
                    nm[d][f] = ng[d][e][f];
                    for (i = 0; i < nm[d][f]; i++) tm[d][f][i] = g[d][e][f][i];
                }
            }
        }
        if (inq) {
            nd[d][f] = 0;
            for (i = 0; i < ne[d][e][f]; i++) tp[d][f][nd[d][f]++] = dd[d][e][f][i];
        }
    }
}
void dfs(int id) {
    int i, j, s, p, q, ip, ie, ns, flag;
    int ch;
    char che;
    num_vec[id] = 2;
    vec[id][0] = n + 1;
    vec[id][1] = id;
    for (i = 0; i < num[id]; i++) {
        ip = adj[id][i];
        deep[ip] = deep[id] + 1;
        at[ip] = num_vec[id];
        dfs(ip);
        for (j = 0; j < num_vec[ip]; j++) {
            if (vec[ip][j] == n + 1)
                continue;
            vec[id][num_vec[id]++] = vec[ip][j];
        }
    }

    dp[0][id][n + 1] = n + 1;
    ng[0][id][n + 1] = (n + 1);
    ne[0][id][n + 1] = 0;
    for (i = 0; i < (n + 1); i++) g[0][id][n + 1][i] = '9';
    for (i = 0; i < num[id]; i++) {
        ip = adj[id][i];
        for (j = 0; j < at[ip] + num_vec[ip] - 1; j++) tmp[0][vec[id][j]] = tmp[1][vec[id][j]] = -1;
        for (s = 0; s < 2; s++) {
            for (j = 0; j < at[ip]; j++) {
                ie = vec[id][j];
                if (dp[s][id][ie] < 0)
                    continue;
                for (p = 0; p < num_vec[ip]; p++)
                    for (q = 0; q < 2; q++) {
                        int iq = vec[ip][p];
                        if (dp[q][ip][iq] < 0)
                            continue;
                        merge(s, id, ie, q, ip, iq);
                        ;
                    }
            }
        }
        for (j = 0; j < at[ip] + num_vec[ip] - 1; j++)
            for (s = 0; s < 2; s++) {
                ie = vec[id][j];
                dp[s][id][ie] = tmp[s][ie];
                if (tmp[s][ie] < 0)
                    continue;
                ne[s][id][ie] = nd[s][ie];
                for (p = 0; p < ne[s][id][ie]; p++) dd[s][id][ie][p] = tp[s][ie][p];
                ng[s][id][ie] = nm[s][ie];
                for (p = 0; p < nm[s][ie]; p++) g[s][id][ie][p] = tm[s][ie][p];
            }
    }
    bool op = false;
    for (i = 0; i < num[id]; i++) {
        ip = adj[id][i];
        if (str[ip] == '0')
            op = true;
    }
    char cha;
    for (i = 0; i < num_vec[id]; i++)
        for (j = 0; j < 2; j++) tmp[j][vec[id][i]] = -1;
    int nj;
    for (i = 0; i < num_vec[id]; i++)
        for (j = 0; j < 2; j++) {
            ip = vec[id][i];
            if (dp[j][id][ip] < 0 || ip == id)
                continue;
            if (nc[ip] != ne[j][id][ip]) {
                if (nc[ip] < ne[j][id][ip] + 1)
                    continue;
                for (cha = '9'; cha >= '0'; cha--) {
                    if (str[id] != '?' && str[id] != cha)
                        continue;
                    bool ok = false;
                    lr = 0;
                    tr[lr++] = cha;
                    for (s = 0; s < ne[j][id][ip]; s++) tr[lr++] = dd[j][id][ip][s];
                    if (nc[ip] == lr) {
                        if (cha == '0')
                            continue;
                    }
                    if (lr < nc[ip])
                        ok = true;
                    if (nc[ip] == lr) {
                        for (s = 0; s < lr; s++) {
                            if (tr[s] != ff[ip][s])
                                break;
                        }
                        if (s < lr && tr[s] < ff[ip][s])
                            ok = true;
                    }
                    if (ok) {
                        nj = 1;
                        for (s = 0; s < lr; s++) {
                            if (tr[s] != ff[ip][s + nc[ip] - lr])
                                break;
                        }
                        if (s < lr && tr[s] < ff[ip][s + nc[ip] - lr])
                            nj = 0;
                        if (nj == 1 && lr >= nc[ip])
                            continue;
                        bool inq = false;
                        if (tmp[nj][ip] < 0 || (tm[nj][ip][0] < cha && nm[j][ip] - 1 <= ng[j][id][ip]))
                            inq = true;
                        else if (tm[nj][ip][0] == cha) {
                            if (nm[nj][ip] - 1 < ng[j][id][ip])
                                inq = true;
                            else if (nm[nj][ip] - 1 == ng[j][id][ip]) {
                                for (s = 1; s < nm[nj][ip]; s++) {
                                    if (tm[nj][ip][s] < g[j][id][ip][s - 1]) {
                                        inq = true;
                                        break;
                                    }
                                    if (tm[nj][ip][s] > g[j][id][ip][s - 1])
                                        break;
                                }
                            }
                        }
                        if (inq) {
                            tmp[nj][ip] = dp[j][id][ip];
                            nd[nj][ip] = lr;
                            for (s = 0; s < lr; s++) tp[nj][ip][s] = tr[s];
                            nm[nj][ip] = 0;
                            tm[nj][ip][nm[nj][ip]++] = cha;
                            for (s = 0; s < ng[j][id][ip] && num[id] != 0; s++)
                                tm[nj][ip][nm[nj][ip]++] = g[j][id][ip][s];
                        }
                    }
                }
            }
            cha = ',';
            if (str[id] != '?' && str[id] != cha)
                continue;
            if (num[id] == 0 || op)
                continue;
            if (f[id] < 0) {
                f[id] = dp[j][id][ip];
                nc[id] = 0;
                for (s = 0; s < ng[j][id][ip]; s++) ff[id][nc[id]++] = g[j][id][ip][s];
            } else {
                int flag = 0;
                if (nc[id] < ng[j][id][ip])
                    flag = 1;
                else if (nc[id] == ng[j][id][ip]) {
                    for (s = 0; s < nc[id]; s++) {
                        if (ff[id][s] < g[j][id][ip][s]) {
                            flag = 1;
                            break;
                        }
                        if (ff[id][s] > g[j][id][ip][s])
                            break;
                    }
                }
                if (flag == 1) {
                    f[id] = dp[j][id][ip];
                    nc[id] = 0;
                    for (s = 0; s < ng[j][id][ip]; s++) ff[id][nc[id]++] = g[j][id][ip][s];
                }
            }
        }
    if (tmp[1][id] < 0 && f[id] >= 0) {
        tmp[1][id] = id;
        nd[1][id] = 0;
        nm[1][id] = 0;
    }
    for (i = 0; i < num_vec[id]; i++)
        for (j = 0; j < 2; j++) {
            ip = vec[id][i];
            dp[j][id][ip] = tmp[j][ip];
            if (dp[j][id][ip] < 0)
                continue;
            ne[j][id][ip] = nd[j][ip];
            for (s = 0; s < ne[j][id][ip]; s++) dd[j][id][ip][s] = tp[j][ip][s];
            ng[j][id][ip] = nm[j][ip];
            for (s = 0; s < ng[j][id][ip]; s++) g[j][id][ip][s] = tm[j][ip][s];
        }
}
bool solve(int id) {
    int i, j, s, p, q, ip, ie, iq, flag, ia, ib, ic;
    char cha;
    if (id) {
        bool ok = false;
        if (deep[id] > 1 && str[pa[id]] != ',' && !(str[id] != '?' && str[id] != ',') && num[id] != 0) {
            cha = ',';
            ip = id;
            len[0] = 0;
            ip = pa[id];
            while (ip != 0 && str[ip] != ',') {
                st[0][len[0]++] = str[ip];
                ip = pa[ip];
            }
            for (i = 0; i < len[0] - 1 - i; i++) swap(st[0][i], st[0][len[0] - 1 - i]);
            flag = 0;
            if (len[0] < nc[id])
                flag = 1;
            else if (len[0] == nc[id]) {
                for (i = 0; i < len[0]; i++) {
                    if (st[0][i] < ff[id][i]) {
                        flag = 1;
                        break;
                    }
                    if (st[0][i] > ff[id][i])
                        break;
                }
            }
            if (len[0] == 0)
                flag = 0;
            if (flag == 1) {
                if (ip != 0) {
                    ie = pa[ip];
                    len[1] = 0;
                    while (ie != 0 && str[ie] != ',') {
                        st[1][len[1]++] = str[ie];
                        ie = pa[ie];
                    }
                    for (i = 0; i < len[1] - i - 1; i++) swap(st[1][i], st[1][len[1] - 1 - i]);
                    if (len[1] > len[0])
                        flag = 0;
                    else if (len[0] == len[1]) {
                        for (i = 0; i < len[0]; i++) {
                            if (st[1][i] > st[0][i]) {
                                flag = 0;
                                break;
                            }
                            if (st[0][i] > st[1][i])
                                break;
                        }
                        if (i == len[0])
                            flag = 0;
                    }
                }
                for (i = 0; i < num[id]; i++) {
                    ip = adj[id][i];
                    if (str[ip] == ',')
                        flag = 0;
                }
                if (flag == 1) {
                    ok = true;
                    str[id] = ',';
                }
            }
        }
        if (!ok) {
            for (cha = '0'; cha <= '9'; cha++) {
                if (str[id] != '?' && str[id] != cha)
                    continue;
                len[0] = 0;
                if (cha == '0') {
                    if (pa[id] == 0 || str[pa[id]] == ',')
                        continue;
                }
                ip = pa[id];
                while (ip != 0 && str[ip] != ',') {
                    st[0][len[0]++] = str[ip];
                    ip = pa[ip];
                }
                for (i = 0; i < len[0] - 1 - i; i++) swap(st[0][i], st[0][len[0] - 1 - i]);
                st[0][len[0]++] = cha;
                st[0][len[0]] = 0;
                ok = false;
                for (j = 0; j < num[id]; j++) {
                    ia = adj[id][j];
                    if (str[ia] == ',')
                        break;
                }
                if (num[id] == 0 || j < num[id]) {
                    iq = pa[ip];
                    cmft = 0;
                    while (iq != 0 && str[iq] != ',') {
                        sk[cmft++] = str[iq];
                        iq = pa[iq];
                    }
                    for (j = 0; j < cmft - 1 - j; j++) swap(sk[j], sk[cmft - 1 - j]);
                    sk[cmft] = 0;
                    if (len[0] > cmft)
                        ok = true;
                    else if (len[0] == cmft) {
                        for (j = 0; j < len[0]; j++) {
                            if (st[0][j] > sk[j]) {
                                ok = true;
                                break;
                            }
                            if (st[0][j] > sk[j])
                                break;
                        }
                    }
                    if (ok && num[id] == 0) {
                        str[id] = cha;
                        break;
                    }
                    if (!ok)
                        continue;
                }
                for (p = 0; p < num[id]; p++) {
                    ia = adj[id][p];
                    for (i = 0; i < num_vec[ia]; i++) {
                        ie = vec[ia][i];
                        for (s = 0; s < 2; s++) {
                            if (dp[s][ia][ie] >= 0) {
                                len[1] = 0;
                                for (j = 0; j < len[0]; j++) st[1][len[1]++] = st[0][j];
                                for (j = 0; j < ne[s][ia][ie]; j++) st[1][len[1]++] = dd[s][ia][ie][j];
                                st[1][len[1]] = 0;
                                if (len[1] < nc[ie])
                                    ok = true;
                                else if (len[1] == nc[ie]) {
                                    for (j = 0; j < len[1]; j++) {
                                        if (st[1][j] < ff[ie][j]) {
                                            ok = true;
                                            break;
                                        }
                                        if (st[1][j] > ff[ie][j])
                                            break;
                                    }
                                }
                                if (ok && ip != 0) {
                                    iq = pa[ip];
                                    cmft = 0;
                                    while (iq != 0 && str[iq] != ',') {
                                        sk[cmft++] = str[iq];
                                        iq = pa[iq];
                                    }
                                    for (j = 0; j < cmft - 1 - j; j++) swap(sk[j], sk[cmft - 1 - j]);
                                    sk[cmft] = 0;
                                    len[1] = 0;
                                    for (j = 0; j < len[0]; j++) st[1][len[1]++] = st[0][j];
                                    for (j = 0; j < ng[s][ia][ie]; j++) st[1][len[1]++] = g[s][ia][ie][j];
                                    if (cmft > len[1])
                                        ok = false;
                                    else if (cmft == len[1]) {
                                        for (j = 0; j < cmft; j++) {
                                            if (st[1][j] < sk[j]) {
                                                ok = false;
                                                break;
                                            }
                                            if (st[1][j] > sk[j])
                                                break;
                                        }
                                        if (j >= cmft)
                                            ok = false;
                                    }
                                }
                                if (ok)
                                    break;
                            }
                        }
                        if (s < 2)
                            break;
                    }
                    if (i >= num_vec[ia])
                        break;
                }
                if (p >= num[id]) {
                    str[id] = cha;
                    break;
                }
            }
            if (cha > '9')
                return false;
        }
    }
    for (i = 0; i < num[id]; i++) {
        ip = adj[id][i];
        if (!solve(ip))
            return false;
    }
    return true;
}
int main() {
    int t, i, j, s, p, q;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", str);
        n = strlen(str);
        for (i = n; i >= 1; i--) str[i] = str[i - 1];
        for (i = 0; i <= n; i++) num[i] = 0;
        for (i = 1; i <= n; i++) {
            scanf("%d", &pa[i]);
            adj[pa[i]][num[pa[i]]++] = i;
        }
        memset(dp, -1, sizeof(dp));
        memset(f, -1, sizeof(f));
        memset(nc, 0, sizeof(nc));
        memset(nd, 0, sizeof(nd));
        f[n + 1] = n + 1;
        nc[n + 1] = (n + 1);
        for (i = 0; i < (n + 1); i++) ff[n + 1][i] = '9';
        dfs(0);
        if (!solve(0)) {
            puts("failed");
        } else {
            for (i = 1; i <= n; i++) putchar(str[i]);
            printf("\n");
        }
        
    }
    return 0;
}