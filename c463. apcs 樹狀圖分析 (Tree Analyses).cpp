// https://zerojudge.tw/ShowProblem?problemid=c463
#include <bits/stdc++.h>
using namespace std;
/* TYPES  */
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define vc vector
#define vi vector<int>
#define vii vector<pii>
#define mii map<int, int>
#define si set<int>
/* UTILS */
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define rev(i, a, b) for (int i = a; i >= b; --i)
#define tomax(a, b) (a) = max((a), (b))
#define tomin(a, b) (a) = min((a), (b))
#define all(a) a.begin(), a.end()
#define rall(a) (a).rbegin(), (a).rend()
#define pob pop_back
#define pb push_back
#define eb emplace_back
#define sp << " " <<
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int n, deg[100005], ans = 0;
vi e[100005];

int dfs(int p){
    if(e[p].empty()) return 0;
    int dis=0;
    for(int i : e[p])
        tomax(dis, 1+dfs(i));
    ans += dis;
    return dis;
}

signed main() {
    ios;
    int tmp, ch, t;
    memset(deg, 0, sizeof(deg));
    cin >> n;
    rep(i, 1, n) {
        cin >> tmp;
        rep(j, 1, tmp) cin >> ch, deg[ch]++, e[i].eb(ch);
    }
    rep(i, 1, n) if (deg[i] == 0) t = i;
    cout << t << '\n';
    dfs(t);
    cout << ans << '\n';
    return 0;
}
