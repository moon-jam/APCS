//https://zerojudge.tw/ShowProblem?problemid=c296
#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // 直到最後還沒淘汰的
    vector<int> available_num;
    // 最後一圈時要走幾步才是那個被淘汰的，要先剪掉最後一圈被淘汰的人
    int step=-1, n, m ,k;
    cin >> n >> m >> k;
    for(int i = 1; i<=n; i++) available_num.push_back(i);
    for(int i = 0; i<k; i++){
        step = (step+m)%available_num.size();
        vector<int>::iterator it = available_num.begin()+step;
        // cout << *it << '\n';
        available_num.erase(it);
        step--;
    }
    cout << available_num[(step+1)%available_num.size()] << '\n';
    return 0;
}
