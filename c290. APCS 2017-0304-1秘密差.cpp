//https://zerojudge.tw/ShowProblem?problemid=c290
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string input;
    cin >> input;
    int odd = 0, even = 0;
    for(int i = 0; input[i]; i++){
        if(i%2) even += input[i]-'0';
        else odd += input[i]-'0';
    }
    cout << abs(odd-even) << '\n';
    return 0;
}
