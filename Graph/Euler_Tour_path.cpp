
/// remind the conditions to exist a cicle tour -> even graph
/// to exist path 0 or 2 vertex odd degree and they will the ini and the end, start EulerTour in one of them
vector<int> ans;
vector<pair<int,bool> > adj[5];
void EulerTour(int x){
    for(int i = 0;i < sz(adj[x]); i++){
        if(adj[x][i].second==1){
            adj[x][i].second = 0;
            auto e = adj[x][i].first;
            for(int j=0;j<sz(adj[e]);j++){
                if(adj[e][j].first == x){
                    adj[e][j].second=0;
                    break;
                }
            }
            EulerTour(adj[x][i].first);
        }
    }
    ans.push_back(x);
}