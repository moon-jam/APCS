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

vi arr, pre;
vii mm;

int solve(int l, int r){
    if(l==r) return arr[l];
    int m = mm.back().S;
    while(m<l || m>r) mm.pob(), m = mm.back().S;
    if(pre[r]-pre[m]>=(m>0? pre[m-1] : 0)-(l>0? pre[l-1] : 0)) return solve(m+1, r);
    else return solve(l, m-1);
}

signed main() {
    ios;
    int n;
    cin >> n;
    arr.resize(n), pre.resize(n);
    for(int &i : arr) cin >> i;
    pre[0]=arr[0]; mm.eb(arr[0], 0);
    rep(i, 1, n-1) pre[i]=pre[i-1]+arr[i], mm.eb(arr[i], i);
    sort(rall(mm));
    cout << solve(0, n-1) << '\n';
    return 0;
}
