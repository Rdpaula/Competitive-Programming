ll cnt[maxn];
bool big[maxn];

void add(ll v, ll p, ll x){
    cnt[ col[v] ] += x;
    for(auto u: adj[v]){
        if(u != p && !big[u]) add(u, v, x);
    }
}

void dfs(ll v, ll p, bool keep){
    ll mx = -1, bigChild = -1;

    for(auto u : adj[v]){
       if(u != p && sz[u] > mx)
          mx = sz[u], bigChild = u;
    }

    for(auto u : adj[v]){
        if(u != p && u != bigChild)
            dfs(u, v, 0);  // run a dfs on small childs and clear them from cnt
    }

    if(bigChild != -1) dfs(bigChild, v, 1), big[bigChild] = 1;  // bigChild marked as big and not cleared from cnt

    add(v, p, 1);
    //now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.

    if(bigChild != -1) big[bigChild] = 0;
    if(keep == 0) add(v, p, -1);
}

ll calc(ll x, ll pai){
    ll ret = 1;
    for(auto e: adj[x]){
        if(e!=pai) ret += calc(e,x);
    }
    return sz[x] = ret;
}

