// https://zerojudge.tw/ShowProblem?problemid=g596
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define tomax(a, b) (a) = max((a), (b))
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int g[103][103];
int n, m, max_cnt = 0, h;

int cnt() {
    int c = 0;
    rep(i, 0, n - 1) rep(j, 0, m - 1) c += (g[i][j] != 0);
    tomax(max_cnt, c);
    return c;
}

void rm(int x, int y) {
    g[x][y] = 0;
    int dir_x[] = {0, 1, 0, -1}, dir_y[] = {1, 0, -1, 0};
    rep(d, 0, 3) {
        int _x = x, _y = y;
        while (g[_x += dir_x[d]][_y += dir_y[d]] == (2 + d % 2) || g[_x][_y] == 5)
            g[_x][_y] -= (2 + d % 2);
    }
}

void build(int x, int y) {
    g[x][y] = 1;
    int dir_x[] = {0, 1, 0, -1}, dir_y[] = {1, 0, -1, 0};
    rep(d, 0, 3) {
        int _x = x, _y = y;
        bool ok = false;
        while ((_x + dir_x[d]) < n && (_x + dir_x[d]) >= 0 &&
               (_y + dir_y[d]) < m && (_y + dir_y[d]) >= 0)
            if (g[_x += dir_x[d]][_y += dir_y[d]] == 1) ok = true;
        if (!ok) continue;
        _x = x, _y = y;
        while (g[_x += dir_x[d]][_y += dir_y[d]] != 1)
            if (g[_x][_y] == 2 + (d + 1) % 2)
                g[_x][_y] = 5;
            else if(g[_x][_y] != 5)
                g[_x][_y] = (2 + d % 2);
    }
}

signed main() {
    ios;
    cin >> n >> m >> h;
    memset(g, 0, sizeof(g));
    while (h--) {
        int x, y, cmd;
        cin >> x >> y >> cmd;
        if (cmd)
            rm(x, y);
        else
            build(x, y);
        cnt();
    }
    cout << max_cnt << '\n' << cnt() << '\n';
    return 0;
}
