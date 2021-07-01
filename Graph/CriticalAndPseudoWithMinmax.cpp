vector<vector<ll>> findCriticalAndPseudoCriticalEdges(){
	vector<vector<pii>> ans(2);
	rep(i,0,sz(adj)){
		auto m = minmaxpath(i,adj[i].F);
		if(m > adj[i].S)ans[0].push_back(adj[i]);
		else ans[1].push_back(adj[i]);
	}
}

ll minmaxpath(ll src, ll sink){
	vector<double> maxedge[maxn];
	rep(i,0,maxn)maxedge[i] = INF;
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
	maxedge[src] = 0;
	pq.push(0,src);
	while(!pq.empty()){
		auto [large, vert] = pq.top();
		pq.pop();
		if(large > maxedge[maxn]){
			continue;
		}
		for(auto e: adj[vert]){
			if(vert == src && e == sink)continue;
			if(max(large,e.S) < maxedge[e.F]){
				maxedge[e.F] = max(large,e.S);
				pq.push({maxedge[e.F],e.F});
			}
		}
	}
	return maxedge[sink];
}