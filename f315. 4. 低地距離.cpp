#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define vi vector<int>
#define vii vector<pii>
#define si set<int>
#define mii map<int, int>
#define tomax(a, b) (a) = max(a, b)
#define tomin(a, b) (a) = min(a, b)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define rev(i, a, b) for (int i = a; i >= b; i--)
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define all(a) a.begin(), a.end()
#define rll(a) a.rbegin(), a.rend()
#define sp << " " <<
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define lowbit(x) x & -x

vi arr[100005];
int bit[200005];
int n;

void modify(int pos, int x) {
    for (; pos <= n; pos += lowbit(pos)) bit[pos]+=x;
}
int query(int pos){
    int sum = 0;
    for( ;pos>=1; pos-=lowbit(pos)) sum+=bit[pos];
    return sum;
}

signed main() {
    ios;
    cin >> n;
    n *= 2;
    int tmp, ans = 0;
    rep(i, 1, n) cin >> tmp, arr[tmp].eb(i);
    rep(i, 1, n) modify(i,1);
    rev(i, n/2, 1){
        ans += query(arr[i][1]-1)-query(arr[i][0]);
        modify(arr[i][1], -1), modify(arr[i][0], -1);
    }cout << ans << '\n';
    return 0;
}
