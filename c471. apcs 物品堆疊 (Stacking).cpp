//https://zerojudge.tw/ShowProblem?problemid=c471
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define w first
#define f second
#define vi vector<int>
#define vii vector<pii>
#define si set<int>
#define mii map<int,int>
#define tomax(a,b) (a)=max((a),(b))
#define tomin(a,b) (a)=min((a),(b))
#define rep(i, a, b) for(int i = a; i<=b; i++)
#define rev(i, a, b) for(int i = a; i>=b; i--)
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define all(a) a.begin(),a.end()
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

signed main(){
    ios;
    int n;
    cin >> n;
    vii item(n);
    for(pii &i : item) cin >> i.w;
    for(pii &i : item) cin >> i.f;
    sort(all(item), [](pii a, pii b){
        return a.w*b.f < b.w*a.f;
    });
    int last=0;
    reverse(all(item));
    for(pii &i : item) last+=i.f, i.f=last-i.f;
    reverse(all(item));
    int ans = 0;
    for(pii i : item) ans+=i.w*i.f;
    cout << ans << '\n';
    return 0;
}
