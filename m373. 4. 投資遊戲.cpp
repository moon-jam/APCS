#include <bits/stdc++.h>
using namespace std;

int n, k;
int dp[150005][21], p[150005], max_dp = 0;
// dp[i][j] 代表到第i個使用j個金牌可以得到最多多少收益
// dp[i][j] = max(dp[i-1][j]+p[i], dp[i-1][j-1])
// dp[0][j] = p[0]
// dp[i][0] = max(dp[i-1][0]+p[i], p[i])

signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i<n; i++) cin >> p[i];
    for(int j = 0; j<=k; j++) dp[0][j] = p[0];
    for(int i = 1; i<n; i++){
        max_dp = max(max_dp, dp[i][0] = max(dp[i-1][0]+p[i], p[i]));
        for(int j = 1; j<=k; j++)
            max_dp = max(max_dp, dp[i][j] = max(dp[i-1][j]+p[i], dp[i-1][j-1]));
    }cout << max_dp << '\n';
    return 0;
}