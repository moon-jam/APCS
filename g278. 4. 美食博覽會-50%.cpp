//https://zerojudge.tw/ShowProblem?problemid=g278

#include <bits/stdc++.h>

using namespace std;
//len[i]代表第i個攤位為開頭可以往後吃多遠都不重複
int len[1000006], num[1000006], n, k;
//用一個queue從後面開始裝，同時用vis[i]代表在queue內存不存在
queue<int> q;
bool vis[1000006];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i =0;i < n; i++) cin >> num[i];
    q.push(num[n-1]),vis[num[n-1]]=1;
    int max_len=0;
    for(int i = n-2; i>=0; i--){
        while(vis[num[i]] && !q.empty())
            vis[q.front()]=0, q.pop();
        q.push(num[i]),vis[num[i]]=1;
        len[i]=q.size(), max_len=max(len[i], max_len);
    }
    cout<<max_len<<'\n';
    return 0;
}
