// https://zerojudge.tw/ShowProblem?problemid=b966
// https://zerojudge.tw/ShowProblem?problemid=f855
#include <bits/stdc++.h>
#define pii pair<int, int>
#define l first
#define r second
using namespace std;

priority_queue<pii, vector<pii>, greater<pii> > pq;
int n;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>> n;
    for(int i = 0, tmp1, tmp2; i<n; i++)
        cin >> tmp1 >> tmp2, pq.push(make_pair(tmp1, tmp2));
    int max=pq.top().l, result=0;
    while(!pq.empty()) {
        pii cur = pq.top();
        pq.pop();
        // cout << cur.l << ' ' << cur.r <<' '<<result<< ' ' << max << '\n';
        if(cur.r<=max) continue;
        else if(cur.first<=max) result+=cur.r-max, max=cur.r;
        else result+=(cur.r-cur.l), max=cur.r;
    }

    cout << result << '\n';
    
    return 0;
}
