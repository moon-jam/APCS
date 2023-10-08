//https://zerojudge.tw/ShowProblem?problemid=i402
#include <bits/stdc++.h>
#define Max(a,b,c) max(a,max(b,c))
using namespace std;

int a[1005], b[1005], n, m, dp[1005][1005], pre[1005][1005], ans=-100000008;
//dp[i][j]表示a[i]與b[j]之後的最大內積
//pre[i][j]表示包含a[i]與b[j]最大前綴合
//init: dp[i][j]=a[i]*b[j]
//dp[i][j]=max(a[i]*b[j], dp[i+1][j+1], pre[i+1][j+1]+a[i]*b[j]) | n-i>1 && m-j>1
//pre[i][j]=max(a[i]*b[j], pre[i+1][j+1]+a[i]*b[j])

void calculate(){
    memset(dp, 0, sizeof(dp));
    memset(pre, 0, sizeof(pre));
    for(int i = n-1;i>=0;i--){
        for(int j = m-1;j>=0;j--){
            dp[i][j]=a[i]*b[j];
            if(n-i>1 && m-j>1)
                dp[i][j] = Max(a[i]*b[j], dp[i+1][j+1], pre[i+1][j+1]+a[i]*b[j]);
            pre[i][j]=max(a[i]*b[j], pre[i+1][j+1]+a[i]*b[j]); //pre[i][j]超過範圍的地方會是0
            ans=max(ans, dp[i][j]);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 0; i<n;i++) cin>> a[i];
    for(int i = 0; i<m;i++) cin >> b[i];
    calculate();
    for(int i = 0; i< n/2; i++) swap(a[i],a[n-i-1]);
    calculate();
    cout<<ans<<'\n';
    return 0;
}
