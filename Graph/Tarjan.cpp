int dfs_low[maxn];
int dfs_num[maxn];
int vis[maxn];
int dfscounter = 1;
int contans=-1;
vector<int> anses[maxn];
vector<int> adj[maxn];
vector<int> sccs;

/// if the graph is undirected, add pai to dfs and add to if (pai!=e && vis[e]==1)
void dfs(int x){
    vis[x]=1;
    sccs.push_back(x);
    dfs_num[x] = dfs_low[x] = dfscounter++;
    for(auto e: adj[x]){
        if(dfs_num[e]==0){
            dfs(e);
        }
        if(vis[e]==1){
            dfs_low[x]=min(dfs_low[x],dfs_low[e]);
        }
    }
    if(dfs_low[x]==dfs_num[x]){
        contans++;
        while(1){
            int vert = sccs.back();
            sccs.pop_back();
            vis[vert]=0;
            anses[contans].push_back(vert);
            if(vert==x)break;
        }
    }
}