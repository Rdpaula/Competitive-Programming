/// remind the conditions to exist a cicle tour -> even graph and ALL EDGES in same component = adj completely erased
/// to exist path 0 or 2 vertex odd degree and they will the ini and the end, start EulerTour in one of them

/// this is implemented for directed grapsh

vector<int> ans;
vector<pair<int,bool> > adj[maxn];
int dege[maxn],degs[maxn];
int vis[maxn];
int ini = -1;

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

// undirected graphs -> can be improved with hashmap

ll n,m;
vector<ll> adj[maxn];
vector<ll> ans;
map<pii,ll> apag;

// rests to see if ALL EDGES belong to the same component = adj completely erased
ll verify(){ // 0 - both impossible, 1 - path, 2 - tour
    ll odd = 0;
    rep(i,0,maxn){
        if(sz(adj[i])&1) odd++;
    }
    if(odd != 0 && odd != 2) return 0;
    else if(odd == 0) return 2;
    else return 1;
}

void tour(ll x){
    stack<ll> st;
    st.push(x);
    while(!st.empty()){
        auto tp = st.top();
        while(sz(adj[tp]) > 0 && apag.count({tp, adj[tp].back()})){
            adj[tp].pop_back();
        }
        if(sz(adj[tp])){
            st.push(adj[tp].back());
            apag[{adj[tp].back(),tp}] = 1;
            adj[tp].pop_back();
        }
        else{
            ans.pb(tp);
            st.pop();
        }
    }
}
