ll vet[maxn],segt[4*maxn],lazy[4*maxn];

#define NEUTRAL -1

void add(int id,int l,int r,int val){
    // cout<<l<<" "<<r<<" "<<val<<endl;
    segt[id] = val,lazy[id] = val;
}
void update(ll id,int l,ll r,ll x,ll y,ll val){
    if(x<=l && r<=y)add(id,l,r,val);
    else if(l>y || r<x)return;
    else{
        int mid=(l+r)>>1;
        add(id<<1,l,mid,lazy[id]);
        add(id<<1|1,mid+1,r,lazy[id]);
        lazy[id]=0;
        update(id<<1,l,mid,x,y,val);
        update(id<<1|1,mid+1,r,x,y,val);
        segt[id]=max(segt[id<<1],segt[id<<1|1]);
    }
}
int query(ll id,ll l,ll r,ll x,ll y){
    if(x<=l && r<=y)return segt[id];
    else if(l>y || r<x)return NEUTRAL;
    else{
        int mid=(l+r)>>1;
        add(id<<1,l,mid,lazy[id]);
        add(id<<1|1,mid+1,r,lazy[id]);
        lazy[id]=0;
        return max(query(id<<1,l,mid,x,y),query(id<<1|1,mid+1,r,x,y));
    }
}
