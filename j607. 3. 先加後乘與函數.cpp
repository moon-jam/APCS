//https://zerojudge.tw/ShowProblem?problemid=j607

#include <bits/stdc++.h>
using namespace std;
#define int long long

string in;
int len, max_times_size=0;
vector<int> record;

int f(vector<int> arr){
    int Min=222, Max=-1;
    for(int i : arr)
        Min=min(Min, i), Max=max(Max, i);
    return Max-Min;
}

int get_sum(vector<int> num){
    int sum = 0, pos=1;
    while(!num.empty())
        sum+=num.back()*pos, pos*=10, num.pop_back();
    return sum;
}

// return 最後位置+1
int calculate(int idx){
    if(idx>=len) return len;
    if(in[idx]==')') return idx+1;
    if(in[idx]==',') {
        max_times_size=record.size();
        return calculate(idx+1);
    }
    if(in[idx] == '+'){
        idx++;
        return calculate(idx);
    }else if(in[idx]=='f'){
        int last_max_times_size=max_times_size;
        vector<int> process;
        idx+=2; //f(
        int now_record_size = record.size();
        idx = calculate(idx);
        while(record.size()>now_record_size)
            process.push_back(record.back()), record.pop_back();
        cout << idx << ' ' <<f(process) << '\n';
        record.push_back(f(process));
        max_times_size=last_max_times_size;
        cout << idx << '\n';
        return calculate(idx);
    }else if(in[idx]=='*'){
        vector<int> process;
        idx++;
        int origin = 0;
        while(record.size()>max_times_size)
            origin+=record.back(), record.pop_back();
        cout <<"origin " << origin << '\n';
        record.push_back(origin);
        max_times_size = record.size();
        calculate(idx);
        int times = 0;
        while(record.size()>max_times_size)
            times+=record.back(), record.pop_back();
        *record.rbegin()*=times;
        max_times_size--;
        cout << "time " << times << ' ' << record.back()<< '\n';
        return len;
    }else { //number
        vector<int> num;
        while(in[idx]!='+'&&in[idx]!='*'&&in[idx]!='f'&&in[idx]!=')'&&in[idx]!=','&&idx<len)
            num.push_back(in[idx]-'0'), idx++;
        int sum = get_sum(num);
        // cout << idx << ' ' << sum << '\n';
        record.push_back(sum);
        return calculate(idx);
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> in;
    string tmp = "+"+in;
    in = tmp;
    len = in.size();
    calculate(0);
    int ans=0;
    for(int i : record) ans+=i;
    cout << ans << '\n';
    return 0;
}
