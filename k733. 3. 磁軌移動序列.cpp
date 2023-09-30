#include <bits/stdc++.h>
#define int long long
#define piii pair<int,pair<int,int> >
#define sum first
#define first_num second.first
#define last_num second.second
#define out(s,f,l) make_pair(s,make_pair(f,l))
using namespace std;

queue<int> in;
char S[100006];

piii get_dis(){
    int dis=0, last = in.front(), _first = in.front();
    while(in.front()!=-1){
        int cur = in.front();
        in.pop();
        if(cur >= 10) dis+=abs(cur-last), last=cur;
        else{
            int time=cur;
            piii inside=get_dis();
            dis+=time*inside.sum+(time-1)*abs(inside.first_num-inside.last_num);
            if(_first<10) _first=inside.first_num;
            else dis+=abs(last-inside.first_num);
            last = inside.last_num;
        }
    }in.pop();
    return out(dis, _first, last);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> S;
    for(int i=0; S[i]; i++){
        if(S[i]=='T') in.push((S[i+1]-'0')*10+(S[i+2]-'0')),i+=2;
        if(S[i]=='L') in.push((S[i+1]-'0')),i+=1;
        if(S[i]=='E') in.push(-1);
    }in.push(-1);
    piii res = get_dis();
    cout << res.sum + abs(10 - res.first_num) << '\n';
    return 0;
}
