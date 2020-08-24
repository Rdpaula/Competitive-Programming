/// creates fpow in main
struct M {
    vector<vector<int>> t;
    M(ll n,ll m){
        t.resize(n,vector<int>(m));
    }
    M operator * (const M& b) const{
        ll n = t.size();
        ll m = t[0].size();
        ll mm = b.t[0].size();
        M c = M(n,mm);
        rep(i,0,n){
            rep(j,0,mm){
                rep(k,0,m){
                    c.t[i][k] = soma(c.t[i][k],mult(t[i][j],b.t[j][k]));
                }
            }
        }
        return c;
    }
};