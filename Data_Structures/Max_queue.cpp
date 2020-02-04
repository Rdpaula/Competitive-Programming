//thanks tfg
typedef long long ll;
typedef std::pair<ll, int> ii;
 
struct Max_Queue {
	std::vector<ii> q;
	int l;
 
	void init() {
		q.clear();
		l = 0;
	}
 
	void push(ll val) {
		int freq = 1;
		while(q.size() > l && q.back().first <= val) {
			freq += q.back().second;
			q.pop_back();
		}
		q.emplace_back(val, freq);
	}
 
	void pop() {
		q[l].second--;
		if(q[l].second == 0) {
			l++;
		}
	}
 
	ll top() {
		if(l == q.size()) {
			return -1e18;
		}
		return q[l].first;
	}
};
 
Max_Queue q;