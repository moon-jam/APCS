// https://zerojudge.tw/ShowProblem?problemid=c575
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

signed main() {
    ios;
    int n, k, m=0;
    cin >> n >> k;
    vi p(n);
    for (int &i : p) cin >> i, tomax(m, i);
    sort(all(p));
    int l = 0, r = m;
    while (r > l + 1) {
        int mid = (l + r) / 2, go = p.front() + mid, kk = 1;
        for (int i : p)
            if (i > go) kk++, go = i + mid;
        // cout << mid << ' ' << kk << '\n';
        if (k >= kk)
            r = mid;
        else
            l = mid+1;
    }
    int go = p.front() + l, kk = 1;
    for (int i : p)
        if (i > go) kk++, go = i + l;
    if(kk<=k) cout << l << '\n';
    else cout << r << '\n';
    return 0;
}
