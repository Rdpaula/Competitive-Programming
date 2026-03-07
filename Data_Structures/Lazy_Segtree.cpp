ll vet[maxn],segt[4*maxn],lazy[4*maxn];

#define NEUTRAL -1

// Performance: lazy is initialised to NEUTRAL (-1) meaning "no pending set".
// push() is called only when lazy[id] != NEUTRAL, avoiding unnecessary writes
// to children when the parent has no pending operation.
// After propagation lazy[id] is reset to NEUTRAL (not 0) so that a genuine
// "set-to-0" operation is not confused with "nothing pending".

void push(ll id, ll l, ll r) {
    if(lazy[id] == NEUTRAL) return; // nothing to propagate
    ll mid = (l + r) >> 1;
    // set left child
    segt[id<<1] = lazy[id];
    lazy[id<<1] = lazy[id];
    // set right child
    segt[id<<1|1] = lazy[id];
    lazy[id<<1|1] = lazy[id];
    lazy[id] = NEUTRAL;
}

void update(ll id,ll l,ll r,ll x,ll y,ll val){
    if(x<=l && r<=y){ segt[id] = val; lazy[id] = val; return; }
    if(l>y || r<x) return;
    ll mid=(l+r)>>1;
    push(id, l, r);
    update(id<<1,l,mid,x,y,val);
    update(id<<1|1,mid+1,r,x,y,val);
    segt[id]=max(segt[id<<1],segt[id<<1|1]);
}

ll query(ll id,ll l,ll r,ll x,ll y){
    if(x<=l && r<=y) return segt[id];
    if(l>y || r<x)   return NEUTRAL;
    ll mid=(l+r)>>1;
    push(id, l, r);
    return max(query(id<<1,l,mid,x,y),query(id<<1|1,mid+1,r,x,y));
}
