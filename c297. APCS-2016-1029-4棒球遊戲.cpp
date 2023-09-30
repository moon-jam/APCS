#include <bits/stdc++.h>

using namespace std;
//以1B,2B,3B和HR 分別代表一壘打、二壘打、三壘打和全（四）壘打
//以 FO,GO和 SO表示 出局
map<string,int> action = {{"1B",1},{"2B",2},{"3B",3},{"HR",4},{"FO",5},{"GO",5},{"SO",5}};

signed main(){
    queue<string> player[11];
    queue<bool> base;
    base.push(0),base.push(0),base.push(0);
    int out, cur_out = 0, score=0;
    for(int i = 0,n; i<9; i++){
        cin >> n;
        string tmp;
        for(int j=0; j < n; j++) cin>>tmp, player[i].push(tmp);
    }
    cin >> out;
    bool clear=0;
    for(int cur_pl = 0; out!=cur_out; cur_pl=(cur_pl+1)%9){
        if(clear){
            for(int i = 0; i<3; i++) base.pop(),base.push(0);
            clear=0;
        }
        int cmd = action[player[cur_pl].front()];
        player[cur_pl].pop();
        if(cmd==5) cur_out++, clear=!(cur_out%3);
        else{ 
            base.push(1),score+=base.front(),base.pop();
            for(int i = 0; i<cmd-1; i++)
                score+=base.front(),base.pop(),base.push(0);
        }
    }
    cout << score << '\n';
    return 0;
}
