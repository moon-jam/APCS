//https://zerojudge.tw/ShowProblem?problemid=c296
#include <bits/stdc++.h>
#define N 200005
using namespace std;

int sg[4*N];
// sg[idx]的右界
int sg_R[4*N];

void build(int l, int r, int idx){
    if(r-l==1){
        sg[idx]=1,sg_R[idx]=r;
        return;
    }
    int mid = (r+l)/2;
    build(l,mid,idx*2), build(mid,r,idx*2+1);
    sg[idx]=sg[idx*2]+sg[idx*2+1], sg_R[idx]=r;
}

void del(int l, int r, int idx, int del_pos){
    sg[idx]--;
    if(r-l==1) return;
    int mid = (l+r)/2;
    if(del_pos<mid) del(l,mid,idx*2,del_pos);
    else del(mid,r,idx*2+1,del_pos);
}

//找第k大的idx
int search_bigger_idx(int l, int r, int idx, int order){
    if(r-l==1) return idx;
    int mid = (r+l)/2;
    if(sg[idx*2]>=order) {
        return search_bigger_idx(l, mid, idx*2, order);
    }
    else return search_bigger_idx(mid, r, idx*2+1, order-sg[idx*2]);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n, m ,k, step=0;
    cin >> n >> m >> k;
    build(0,n,1);
    for(int i = 0; i<k; i++){
        step = (step+m)%sg[1];
        if(step==0) step=sg[1];
        int idx = search_bigger_idx(0,n,1,step);
        del(0,n,1,sg_R[idx]-1);
        step--;
    }
    step = (step+1)%sg[1];
    if(step==0) step=sg[1];
    // 應該會是該位置的右界-1，但因為要從0-base轉1-base還要+1，所以就抵銷了
    cout << sg_R[search_bigger_idx(0,n,1,step)] << '\n';
    return 0;
}

