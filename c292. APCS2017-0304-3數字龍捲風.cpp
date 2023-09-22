//https://zerojudge.tw/ShowProblem?problemid=c292 解題思路（含一些小技巧） 完整題解
#include <bits/stdc++.h>

using namespace std;

// 0代表左 、1代表上 、2代表右 、3代表下
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, dir;
    int arr[55][55];
    vector<int> records;
    cin >> n >> dir;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            cin >> arr[j][i];
    int dirs_x[5] = {-1, 0, 1, 0}, dirs_y[5] = {0, -1, 0, 1};
    int cur_x=n/2, cur_y=n/2, pace=10;
    records.push_back(arr[cur_x][cur_y]);
    while(cur_x>=0&&cur_x<n&&cur_y>=0&&cur_y<n){
        for(int i = 0, cur_p=pace/10; i<cur_p; i++){
                cur_x+=dirs_x[dir], cur_y+=dirs_y[dir];
                if(cur_x>=0&&cur_x<n&&cur_y>=0&&cur_y<n)
                    records.push_back(arr[cur_x][cur_y]);
        }
        dir = (dir+1)%4, pace+=5;
    }
    for(int i : records) cout << i;
    cout << '\n';
    return 0;
}
