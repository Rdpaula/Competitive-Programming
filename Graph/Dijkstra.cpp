const ll INF = 1e15 + 9;

vector<pii> adj[maxn];
ll dis[maxn];
void addedge(ll a,ll b,ll c){
    adj[a].push_back({b,c});
    adj[b].push_back({a,c});
}
void INFINITAR(){
    for(ll i=0;i<maxn;i++){
        dis[i]=INF;
    }
}
void dijkstra(int x){
    INFINITAR();
    dis[x]=0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0,x});
    while(!pq.empty()){
        auto f=pq.top();
        pq.pop();
        if(dis[f.second]<f.first)continue;
        for(auto e: adj[f.second]){
            if(f.first+e.second<dis[e.first]){
                dis[e.first]=f.first+e.second;
                pq.push({dis[e.first],e.first});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    return 0;
}