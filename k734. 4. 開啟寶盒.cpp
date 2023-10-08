//https://zerojudge.tw/ShowProblem?problemid=k734
#include <bits/stdc++.h>

using namespace std;

vector<int> keys[100005]; //鑰匙索引可被開啟的
vector<int> keys_get[100005]; //開啟後得到的
int need_many_keys[100005], n ,m ,k;

void add_key(int num){
    while(!keys[num].empty()){
        int cur = keys[num].back(); keys[num].pop_back();
        need_many_keys[cur]--;
        if(!need_many_keys[cur])
            for(int i : keys_get[cur])
                add_key(i);
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) need_many_keys[i]=k;
    int ans = 0, now_key[100005], t;
    cin>>t;
    for(int i=0;i<t;i++) cin >> now_key[i];
    for(int i = 0; i< n;i++)
        for(int j = 0,tmp;j<k;j++)
            cin>>tmp, keys[tmp].push_back(i);
    for(int i = 0; i< n;i++)
        for(int j = 0,tmp;j<k;j++)
            cin>>tmp, keys_get[i].push_back(tmp);
    for(int i =0; i<t; i++) add_key(now_key[i]);
    
    for(int i = 0; i<n;i++) ans += (need_many_keys[i]<=0);
    cout<<ans<<'\n';
    return 0;
}
