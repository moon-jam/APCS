// https://zerojudge.tw/ShowProblem?problemid=c295
#include <bits/stdc++.h>

using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,max_nums[22],s=0;
    cin >> n >> m;
    for(int i = 0,max_=0; i<n; i++,max_=0){
        for(int j=0,tmp; j<m; j++)
            cin>>tmp, max_=max(max_,tmp);
        s+=max_,max_nums[i]=max_;
    }cout<<s<<'\n';
    bool first=0;
    for(int i = 0; i<n; i++){
        if(s%max_nums[i]==0&&!first) cout<<max_nums[i],first=1;
        else if(s%max_nums[i]==0) cout<<' '<<max_nums[i];
    }if(!first) cout<<-1;
    return 0;
}
