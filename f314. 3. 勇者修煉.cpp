// https://zerojudge.tw/ShowProblem?problemid=f314
#include <bits/stdc++.h>

using namespace std;

int n, m, arr[51][10004], dp[51][10004];
// dp[i][j] 表示第i層的第j個到第0層的最大經驗
// 左至右
// dp[0][0]=arr[0][0]
// dp[0][j]=max(dp[0][j-1], 0)+arr[0][j], j>0
// dp[i][0]=dp[i-1][0]+arr[i][0], i>0
// dp[i][j]=max(dp[i-1][j], dp[i][j-1])+arr[i][j], j>0, i>0
// 右至左
// _dp[0][n-1]=arr[0][n-1]
// _dp[0][j]=max(_dp[0][j+1], 0)+arr[0][j], j<n-1
// _dp[i][n-1]=_dp[i-1][n-1]+arr[i][n-1], i>0
// _dp[i][j]=max(_dp[i-1][j], _dp[i][j+1])+arr[i][j], j<n-1, i>0
// 每層先取完左至右跟右至左後，去較大者為dp[i][j]
// ans=max(dp[m-1][j]), 0<=j<=n-1

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, 0, sizeof(dp));
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) 
            cin >> arr[i][j];
    
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if (i == 0 && j==0)
                dp[0][0] = arr[0][0];
            else if (i==0)
                dp[0][j] = max(dp[0][j-1], 0)+arr[0][j];
            else if (j == 0)
                dp[i][0] = dp[i-1][0] + arr[i][0];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + arr[i][j];
        }
        int tmp_r_dir[10004];
        for(int j = n-1; j >= 0; j--){
            if (i == 0 && j==n-1)
                tmp_r_dir[j] = arr[0][n-1];
            else if (i==0)
                tmp_r_dir[j] = max(tmp_r_dir[j+1], 0)+arr[0][j];
            else if (j == n-1)
                tmp_r_dir[n-1] = dp[i-1][n-1]+arr[i][n-1];
            else
                tmp_r_dir[j] = max(dp[i-1][j], tmp_r_dir[j+1])+arr[i][j];
        }for(int j = 0; j < n; j++) dp[i][j] = max(dp[i][j], tmp_r_dir[j]);
    }
    
    int ans = -5000006;
    for(int j = 0; j < n; j++)
        ans = max(ans, dp[m - 1][j]);
    cout << ans << '\n';
    return 0;
}
