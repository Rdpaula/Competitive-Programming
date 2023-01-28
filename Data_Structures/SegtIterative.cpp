ll n;
ll tree[2*maxn]; // vet is 0-indexed
 
ll query(ll l, ll r){
    l += n, r += n;
    ll ret = INF;
    while(l <= r){
       if(l&1) ret = min(ret, tree[l++]); 
       if(!(r&1)) ret = min(ret, tree[r--]);
       l>>=1;
       r>>=1;
    }
    return ret;
}
 
void update(ll pos, ll val){
    pos += n;
    tree[pos] = val;
    for(pos >>=1; pos >= 1; pos >>=1){
        tree[pos] = min(tree[pos<<1], tree[pos<<1|1]);
    }
}

