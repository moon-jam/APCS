// https://zerojudge.tw/ShowProblem?problemid=b965
#include <bits/stdc++.h>
using namespace std;

int arr[11][11];
int c,r,m;

void turn(){
    int tmp[11][11];
    for(int i = 0; i<c; i++)
        for(int j = r-1; j>=0; j--)
            tmp[r-1-j][i]=arr[i][j];
    swap(c,r);
    for(int i = 0; i< c; i++)
        for(int j = 0; j<r; j++)
            arr[i][j] = tmp[i][j];
}

void reverse(){
    for(int i = 0; i<c/2; i++)
        for(int j = 0; j<r; j++)
            swap(arr[i][j], arr[c-1-i][j]);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> c >> r >> m){
        for(int i = 0; i< c; i++)
            for(int j = 0; j<r; j++)
                cin >> arr[i][j];
        bool cmd[11];
        for(int i = 0; i<m; i++) cin >> cmd[i];
        for(int i = m-1; i>=0; i--){
            if(cmd[i]) reverse();
            else turn();
        }
        cout << c << ' ' << r << '\n';
        for(int i = 0; i< c; i++){
            for(int j = 0; j<r; j++){
                cout << arr[i][j];
                if(j<r-1) cout << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}

