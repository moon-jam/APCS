//https://zerojudge.tw/ShowProblem?problemid=g278

#include <bits/stdc++.h>

using namespace std;
//len[i]代表第i個攤位為開頭可以往後吃多遠都不重複
//dp[i][j]代表i個人從0~j可以吃多少
int len[1000006], num[1000006], n, k, dp[22][1000006];
//dp[i][j] = max(dp[i][j], dp[i][j-1])
//dp[i+1][j+len[j]-1] = max(dp[i+1][j+len[j]-1], dp[i][j-1]+len[j])
//dp[j][j-1]=j
//用一個queue從後面開始裝，同時用vis[i]代表在queue內存不存在
queue<int> q;
bool vis[1000006];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, 0, sizeof(dp));
    cin >> n >> k;
    for(int i =0;i < n; i++) cin >> num[i];
    q.push(num[n-1]),vis[num[n-1]]=1;
    for(int i = n-2; i>=0; i--){
        while(vis[num[i]] && !q.empty())
            vis[q.front()]=0, q.pop();
        q.push(num[i]),vis[num[i]]=1;
        len[i]=q.size();
        dp[1][i+len[i]-1]= max(dp[1][i+len[i]-1], len[i]);
    }
    for(int i = 1; i<=k; i++){
        dp[i][i-1]=i;
        for(int j = i;j<n; j++){
            dp[i][j] = max(dp[i][j], dp[i][j-1]);
            dp[i+1][j+len[j]-1] = max(dp[i+1][j+len[j]-1], dp[i][j-1]+len[j]);
        }
    }
    cout<<dp[k][n-1]<<'\n';
    return 0;
}
