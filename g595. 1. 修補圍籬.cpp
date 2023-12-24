//https://zerojudge.tw/ShowProblem?problemid=g595
#include <bits/stdc++.h>
#define int long long 
#define pii pair<int,int>
#define F first
#define S second
#define vi vector<int>
#define vii vector<pii>
#define si set<int>
#define mii map<int,int>
#define tomax(a,b) (a)=max(a,b)
#define tomin(a,b) (a)=min(a,b)
#define rep(i,a,b) for(int i = a; i<=b; i++)
#define rev(i,a,b) for(int i = a; i>=b; i--)
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

signed main(){
    ios;
    int ans = 0, h[103], n;
    cin >> n;
    h[0]=1000, h[n+1]=1001;
    rep(i, 1, n){
        cin >> h[i];
        if(h[i-1]==0) ans += min(h[i], h[i-2]);
    }cout << ans+((h[n]==0)*h[n-1]) << '\n';
    return 0;
}
