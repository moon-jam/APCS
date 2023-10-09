//https://zerojudge.tw/ShowProblem?problemid=e465
#include <bits/stdc++.h>

using namespace std;

int n, m, s, total_x=0, x[100005];
bool add[100005];
vector<int> add_history;
//add[i] 表示x陣列是否能任意選取使得加總為i
//將題目轉換判斷x陣列是否能任意選取使得加總為k，再遍歷整個陣列找大於等於需要量的最小值

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(add,0,sizeof(add));
    cin>> m>> s >> n;
    for(int i = 0; i<n; i++) cin >> x[i], total_x+=x[i];
    add_history.push_back(0), add[0]=1;
    for(int i = n-1;i>=0;i--){
        vector<int> new_history;
        for(int num : add_history){
            int cur = num+x[i];
            if(!add[cur]) add[cur]=1, new_history.push_back(cur);
        }for(int num : new_history) add_history.push_back(num),add[num]=1;
    }

    s -= (m-total_x); //s表示還需要的櫃子數量
    if(s<=0){
        cout << 0 << '\n';
    }else{
        for(int i = s;i<=total_x; i++)
            if(add[i]){
                cout << i << '\n'; break;
            }
    }

    return 0;
}
