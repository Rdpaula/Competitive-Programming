///ALL EDGES in same component = adj completely erased
/// to exist path 0 or 2 vertex odd degree and they will the ini and the end, start EulerTour in one of them INDIREC
/// to exist path 1 vertex with indg greater and other with outdg greater will be end and begin respectively DIRECT

/// this is implemented for directed graphs

ll n,m;
vector<ll> adj[maxn];
ll indg[maxn];
ll outdg[maxn];
vector<ll> ans;

// rests to see if ALL EDGES belong to the same component = adj completely erased
ll verify(){ // 0 - both impossible, 1 - path, 2 - tour(aka path to the same node)
    ll ins = 0;
    ll outs = 0;
    bool can = true;
    rep(i,0,maxn){
        if(indg[i] > outdg[i]) ins++;
        else if(indg[i] < outdg[i]) outs++;

        if(abs(indg[i] - outdg[i]) > 1) can = false;
    }
    if(!can || !((ins == 0 && outs == 0) || (ins == 1 && outs == 1))) return 0;
    else if(ins == 1 && outs == 1) return 1;
    else return 2;
}

void tour(ll x){
    stack<ll> st;
    st.push(x);
    while(!st.empty()){
        auto tp = st.top();
        if(sz(adj[tp])){
            st.push(adj[tp].back());
            adj[tp].pop_back();
        }
        else{
            ans.pb(tp);
            st.pop();
        }
    }
}


// undirected graphs -> can be improved with hashmap

ll n,m;
vector<ll> adj[maxn];
vector<ll> ans;
map<pii,ll> apag;

// rests to see if ALL EDGES belong to the same component = adj completely erased
ll verify(){ // 0 - both impossible, 1 - path, 2 - tour(aka path to the same node)
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
