int vet[maxn],segt[4*maxn],lazy[4*maxn];
void add(int id,int l,int r,int val){
    // cout<<l<<" "<<r<<" "<<val<<endl;
    if((l==r && l==val) || val==0){ 
 
    }
    else{
        segt[id]=val,lazy[id]=val;
    }
}
void update(int id,int l,int r,int x,int y,int val){
    if(x<=l && r<=y)add(id,l,r,val);
    else if(l>y || r<x)return;
    else{
        int mid=(l+r)>>1;
        add(id<<1,l,mid,lazy[id]);
        add(id<<1|1,mid+1,r,lazy[id]);
        lazy[id]=0;
        update(id<<1,l,mid,x,y,val);
        update(id<<1|1,mid+1,r,x,y,val);
        segtree[id]=max(segtree[id<<1],segtree[id<<1|1]);
    }
}
int query(int id,int l,int r,int x,int y){
    if(x<=l && r<=y)return segt[id];
    else if(l>y || r<x)return -1;
    else{
        int mid=(l+r)>>1;
        add(id<<1,l,mid,lazy[id]);
        add(id<<1|1,mid+1,r,lazy[id]);
        lazy[id]=0;
        return max(query(id<<1,l,mid,x,y),query(id<<1|1,mid+1,r,x,y));
    }
}