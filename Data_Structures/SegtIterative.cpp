// vet is 0-indexed, set N to power of 2(2^18 for 2*10^5 constant) and segt has size 2*N
// Use N as your vet size and fill empty spaces with neutral values
const ll N = 1<<18;
ll tree[2*N]; 

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
