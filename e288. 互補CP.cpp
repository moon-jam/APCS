#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i <= b; ++i)

signed main() {
    int n, m;
    unordered_map<int, int> cp;
    scanf("%lld %lld", &m, &n);
    rep(i, 1, n) {
        char s[1000];
        scanf("%s", s);
        int res = 0;
        for (char c : (string)s)
            res |= (int)1 << (c <= 'Z' ? (c - 'A') : (c - 'a') + 26);
        cp[res]++;
    }
    int ans = 0;
    for (auto &i : cp) {
        int tmp = (((int)1 << m) - 1) & (-i.first - 1);
        if (cp.find(tmp) != cp.end()) ans += i.second * cp[tmp];
    }
    printf("%lld\n", ans >> 1);
    return 0;
}
