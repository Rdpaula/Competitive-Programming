/// remind the conditions to exist a cicle tour -> even graph
/// to exist path 0 or 2 vertex odd degree and they will the ini and the end, start EulerTour in one of them

/// this is implemented for directed graphs, for undirected implement with multiset O(mlogm) or catch in cp algorithms for O(m) but more memory
bool verify(){
    bool can = true;
    ll dif = 0;
    for(int i = 1; i <= n; i++){
        ll sald = degs[i] - dege[i];
        if(abs(sald) > 1)can = false;
        else{
            if(sald > 0)ini = i;
            if(abs(sald)!=0)dif++;
        }
    }
    return can && (dif == 2 || dif == 0);
}

void EulerTour(int x){
    vis[x] = 1; 
    while(sz(adj[x])){
        auto f = adj[x].back();
        adj[x].pop_back();
        EulerTour(f.first);
    }
    ans.push_back(x);
}