//https://zerojudge.tw/ShowProblem?problemid=c294
#include <bits/stdc++.h>

using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[4];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr+3);
    cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << '\n';
    if(arr[0]+arr[1]<=arr[2]) cout << "No\n";
    else if(arr[0]*arr[0]+arr[1]*arr[1]<arr[2]*arr[2]) cout << "Obtuse\n";
    else if(arr[0]*arr[0]+arr[1]*arr[1]==arr[2]*arr[2]) cout << "Right\n";
    else if(arr[0]*arr[0]+arr[1]*arr[1]>=arr[2]*arr[2]) cout << "Acute\n";

    return 0;
}
