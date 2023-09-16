//https://zerojudge.tw/ShowProblem?problemid=b967

#include <bits/stdc++.h>
#define Max 100001
using namespace std;

vector<int> edge[Max];
bool vis[Max];
int max_dis=0;

int dfs(int node){
    //我定義的dis是節點個數，因此在最後輸出時需要-1
    //小孩要回傳他到自己最深的層數，母親記錄子代最大血緣距離（小孩最大的前兩個相加）、自己到最深的距離(最深距離+1)
    //並拿去跟max_dis取max，終端條件是沒有小孩的節點，回傳1
    if(vis[node]) return 0;
    vis[node]=1;
    int child_max_rank=0, child_second_max_rank=0;
    for(int child : edge[node]){
        int rank=dfs(child);
        if(rank>child_max_rank) child_second_max_rank=child_max_rank,child_max_rank=rank;
        else if(rank>child_second_max_rank) child_second_max_rank=rank;
    }
    max_dis = max(max_dis,child_max_rank+child_second_max_rank+1);
    // cout << node << ' '<< child_max_rank << ' ' << child_second_max_rank << ' ' << max_dis << '\n';
    return child_max_rank+1; //加上自己到子代的那層
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    while(cin >> n){
        max_dis=0;
        for(int i=0; i<n; i++) edge[i].clear(), vis[i]=0; //因為節點事是0~n所以是<n而不是<n-1
        // memset(vis, 0, sizeof(vis)); 這裡用memset會TLE，應該就是說不用每次都把100001個都改掉
        for(int i=0, tmp1, tmp2; i<n-1; i++)
            cin>>tmp1>>tmp2, edge[tmp1].push_back(tmp2), edge[tmp2].push_back(tmp1);
            //雖然題目聽起來是有向圖，但為了後續dfs遍歷整棵樹，這邊就用無向圖紀錄，之後再定向即可
        dfs(0);
        cout << max_dis-1 << '\n';
    }
    return 0;
}
