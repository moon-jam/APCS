// https://zerojudge.tw/ShowProblem?problemid=j607
#include <bits/stdc++.h>
#define int long long
using namespace std;

string in;
int len;

// 遇到+ 就直接加上去
// 遇到* 先把後面做好
// 遇到f 把到)之前的每個數字記錄下來最後再比較

int calculate(int idx, int sum){
    if(idx>=len || in[idx]==',' || in[idx]==')') return sum;
    if(in[idx] == '+') return calculate(idx+1, sum);
    if(in[idx] == '*') return sum*calculate(idx+1, 0);
    if(in[idx] == 'f'){
        int end_idx = idx, left_num=0;
        while(in[end_idx]!=')' || left_num>0) //可在一開始建好每個函數結尾位置，複雜度可縮短至O(N)
            end_idx++, left_num+=(in[end_idx]=='(')-(in[end_idx]==')'); 
        int Min = 100004, Max = -1;
        idx++; // '(' 的位置
        while(in[idx] != ')'){
            idx++;
            int cur = calculate(idx, 0);
            Min = min(Min, cur);
            Max = max(Max, cur);
            while(in[idx]!=',' && idx<end_idx) 
                idx++, left_num+=(in[idx]=='(')-(in[idx]==')');
        }
        return calculate(idx+1,sum+(Max-Min));
    }
    if(in[idx]>='0' && in[idx]<='9'){
        vector<int> add;
        int res = 0, pos=1;
        while(in[idx]>='0' && in[idx]<='9') add.push_back(in[idx++]-'0'), pos*=10;
        for(int i : add) pos/=10, res+=i*pos;
        return calculate(idx,sum+res);
    } return -1;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> in;
    in = "+" + in;
    len = in.size();
    cout << calculate(0, 0) << '\n';
    return 0;
}
