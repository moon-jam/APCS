//https://zerojudge.tw/ShowProblem?problemid=c291

#include <bits/stdc++.h>
#define Max 50005

using namespace std;

bool vis[Max];
int people[Max];
int group = 0;

void dfs(int i){
    if(vis[i]) return;
    vis[i] = true;
    if(vis[people[i]])
        group++;
    dfs(people[i]);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(vis,0, sizeof(vis));
    int n;
    cin >> n;
    for(int i = 0; i< n; i++) cin >> people[i];

    for(int i = 0; i< n; i++) dfs(people[i]);

    cout << group << '\n';

    return 0;
}
