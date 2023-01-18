template<int SZ> struct TwoSat {
	vector<int> radj[2*SZ];
	int N = 0, ans[SZ];
	TwoSat(int N_): N(N_+1) {}
	int addVar() { return N++;}
	void either(int x, int y) {
		x = max(2*x,-1-2*x), y = max(2*y,-1-2*y);
		radj[y].push_back(x^1); radj[x].push_back(y^1);
	}
	void implies(int x, int y) { either(~x, y);}
	void setVal(int x) { either(x, x);}
	void xor0(int x, int y) {either(x, ~y); either(~x, y);}
	void xor1(int x, int y) {either(x, y); either(~x, ~y);}
	void atMostOne(const vector<int> &v) {
		if(v.size() <= 1) return;
		int cur = ~v[0];
		for(int i = 2; i < (int)v.size(); i++) {
			int next = addVar();
			either(cur, ~v[i]);
			either(cur,next);
			either(~v[i], next);
			cur = ~next;
		}
		either(cur, ~v[1]);
	}
	vector<int> val, comp, z; int time_ = 0;
	int dfs(int u){
		int low = val[u] = ++time_, x; z.push_back(u);
		for(int v : radj[u]) if(!comp[v])
			low = min(low, val[v] ? val[v] : dfs(v));
		if(low == val[u]) do {
			x = z.back(); z.pop_back();
			comp[x] = low;
			if(ans[x/2] == -1) ans[x/2] = x&1;
		} while(x != u);
		return val[u] = low;
	}
	bool solve() {
		fill(ans, ans + N, -1);
		val.assign(2*N, 0); comp = val;
		for(int i = 0; i < 2*N; i++) if(!comp[i]) dfs(i);
		for(int i = 0; i < 2*N; i+=2) if(comp[i] == comp[i^1]) return 0;
		return 1;
	}
};

// accepts 0-indexed and 1-indexed
TwoSat<maxn+1> twosat(maxn);

