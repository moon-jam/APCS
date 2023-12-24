// https://zerojudge.tw/ShowProblem?problemid=g598
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

int n, m, color[20004];
vi g[20004]; // 0-base

bool dfs(int p, int draw){
    if(g[p].empty()) {color[p]=0;return 1;}
    if(color[p]) return 1;
    bool ok = true;
    color[p]=draw;
    for(int i : g[p]) 
        if(color[i]==draw) return 0;
        else ok = ok && dfs(i, draw%2+1);
    return ok;
}

vii con[10004];
mii bye;
int x, y, p, k;

bool isok(int to){
    mii time;
    bool ok = true;
    rep(i, 1, to){
        if(!bye[i])
            for(pii j : con[i]){
                g[j.F].eb(j.S), g[j.S].eb(j.F);
                time[j.F]++, time[j.S]++;
            }
    }
    memset(color, 0, sizeof(color));
    rep(i, 0, n-1) ok = ok && dfs(i, 1);
    for(auto &i : time)
        while(i.S) g[i.F].pob(), i.S--;
    return ok;
}

signed main() {
    ios;
    cin >> n >> m;
    rep(i, 1, m) cin >> x >> y, g[x].eb(y), g[y].eb(x);
    cin >> p >> k;
    rep(i, 1, p)
        rep(j, 1, k)
            cin >> x >> y, con[i].eb(x,y);
    rep(i, 1, 3){
        int l = 1, r = p;
        while(r>l){
            int mid = (l+r)/2;
            if(isok(mid)) l=mid+1;
            else r=mid;
        }if(l!=p) cout << l << '\n', bye[l]++;
        else if(!isok(l)) {cout << l << '\n'; break;}
    }
    return 0;
}
