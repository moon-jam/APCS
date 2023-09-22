//https://zerojudge.tw/ShowProblem?problemid=c296
#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int ans=0, n, m ,k;
    cin >> n >> m >> k;
    for(int i = n-k+1; i<=n; i++) ans=(ans+m)%i;
    cout << ans+1 << '\n';
    return 0;
}
