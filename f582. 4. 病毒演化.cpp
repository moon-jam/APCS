// https://zerojudge.tw/ShowProblem?problemid=f582
#include <bits/stdc++.h>
#define Max 1000000

using namespace std;

int n, m;
int dp[1003][81][6];
// dp[i][j][k] 代表第i個陣列的第j個字元為k時的單點至葉子最小距離
// k=1,2,3,4代表A,U,C,G
// 當該點已經被是確認的點時（不為@）設其dp值為 Max
// dp[i][j][k] = Σmin(dp[i_child][j][1~4]+k!=1~4)
// if i no child: dp[i][j][k] = 0
map<char, int> get_index = {{'A',1},{'U',2},{'C',3},{'G',4}};
vector<int> child[1003];

int calculate(int idx, int num, int ch){
    if(dp[idx][num][ch] != -1) return dp[idx][num][ch];
    if(child[idx].empty()) return dp[idx][num][ch] = 0;
    dp[idx][num][ch] = 0;
    for(int i: child[idx]){
        int add = Max;
        for(int k = 1; k<=4; k++)
            add = min(add, (calculate(i, num, k) + (k!=ch)));
        dp[idx][num][ch] += add;
    }
    //cout << idx << ' ' << num << ' ' << ch << ": " << dp[idx][num][ch] << '\n';
    return dp[idx][num][ch];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n >> m;
    int root_idx;
    string tmp;
    for(int i = 0, tmpI, tmpJ; i < n; i++){
        cin >> tmpI >> tmpJ;
        if(tmpI == tmpJ) root_idx = tmpI;
        else child[tmpJ].push_back(tmpI);
        cin >> tmp;
        for(int j = 0; j < m; j++){
            for(int k = 1; k <= 4; k++){
                dp[tmpI][j][k] = -1;
                if(tmp[j] != '@' && k != get_index[tmp[j]]) 
                    dp[tmpI][j][k] = Max;
            }
        }
    }
    int ans = 0;
    for(int j = 0; j< m; j++){
        int little_ans = Max;
        for(int k = 1; k <= 4; k++)
            little_ans=min(little_ans, calculate(root_idx, j, k));
        ans+=little_ans;
    }
    cout<<ans<<'\n';
    return 0;
}