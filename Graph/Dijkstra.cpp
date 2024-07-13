const ll INF = 1e18 + 9;

vector<pii> adj[maxn];
ll dis[maxn];
void addedge(ll a,ll b,ll c){
    adj[a].push_back({b,c});
}
void INFINITAR(){
    for(ll i = 0; i < maxn; i++){
        dis[i] = INF;
    }
}
void dijkstra(int x){
    INFINITAR();
    dis[x] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0,x});
    while(!pq.empty()){
        auto f = pq.top();
        ll vert = f.second;
        ll disand = f.first;
        pq.pop();

        if(dis[vert] < disand) continue;
        for(auto e: adj[vert]){
            ll to_vert = e.first;
            ll wei = e.second;

            if(disand + wei < dis[to_vert]){
                dis[to_vert] = disand + wei;
                pq.push({dis[to_vert], to_vert});
            }
        }
    }
}
