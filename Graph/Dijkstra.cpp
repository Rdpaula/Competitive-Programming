#include<bits/stdc++.h>
#define pi 3.1415  
#define ll long long
#define pii pair<ll,ll>
#define debug(a) cout<<a<<'\n'
#define maxn 50009
#define MOD 1000000007
using namespace std;
const ll INF = 1e15 + 9;
ll n,m;
vector<pii> adj[maxn];
ll dis[maxn];
void addedge(ll a,ll b,ll c){
    adj[a].push_back({b,c});
    adj[b].push_back({a,c});
}
void INFINITAR(){
    for(ll i=0;i<=n;i++){
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