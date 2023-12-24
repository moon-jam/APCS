// https://zerojudge.tw/ShowProblem?problemid=g597
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define vi vector<int>
#define vii vector<pii>
#define si set<int>
#define mii map<int, int>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define rev(i, a, b) for (int i = a; i >= b; i--)
#define tomax(a, b) (a) = max(a, b)
#define tomin(a, b) (a) = min(a, b)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

signed main() {
    ios;
    int n, m;
    cin >> n >> m;
    vi t(n), w(n), wd(n+1, 0);
    int l, r, wt;
    // 1-base to 0-base
    rep(i, 0, m - 1) cin >> l >> r >> wt, wd[l-1] += wt, wd[r-1 + 1] -= wt;
    w[0] = wd[0];
    rep(i, 1, n - 1) w[i] = w[i - 1] + wd[i];
    sort(rall(w));
    for (int &i : t) cin >> i;
    sort(all(t));
    int ans = 0;
    rep(i, 0, n - 1) ans += t[i] * w[i];
    cout << ans << '\n';
    return 0;
}
