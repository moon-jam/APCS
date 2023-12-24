// https://zerojudge.tw/ShowProblem?problemid=c462
#include <bits/stdc++.h>
#define int long long
#define F first
#define S second
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define mii map<int, int>
#define si set<int>
#define all(v) v.begin(), v.end()
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define rev(i, a, b) for (int i = a; i >= b; i--)
#define pb push_back
#define pob pop_back
#define eb emplace_back
#define tomax(a, b) (a) = max((a), (b))
using namespace std;

signed main() {
    ios;
    queue<int> arr;
    int k, ans = 0, cur_ans = 0, cur_cnt = 1;
    bool now;
    string in;
    cin >> k >> in;
    now = (in[0] >= 'a' && in[0] <= 'z');
    for (int i = 1; in[i]; i++) arr.push((in[i] >= 'a' && in[i] <= 'z'));
    do {
        while (!arr.empty() && arr.front() == now) arr.pop(), cur_cnt++;
        if (cur_cnt > k) cur_ans++, tomax(ans, cur_ans), cur_ans = 1;
        if (cur_cnt == k) cur_ans++, tomax(ans, cur_ans);
        if (cur_cnt < k) cur_ans=0;
        if (!arr.empty()) cur_cnt = 1, now = arr.front(), arr.pop();
    } while (!arr.empty());
    cout << ans*k << '\n';
    return 0;
}
