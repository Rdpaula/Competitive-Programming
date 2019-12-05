ll vet[maxn],segt[4*maxn];
void build(int id ,int l,int r){
    if(l==r)segt[id]=vet[l];
    else{
        int mid=(l+r)>>1;
        build(id<<1,l,mid);
        build(id<<1|1,mid+1,r);
        segt[id]=segt[id<<1]+segt[id<<1|1];
    }
}
void update(int id,int l,int r,int pos,int val){
    if(l==r){
        segt[id]+=val;
    }
    else{
        int mid=(l+r)>>1;
        if(pos<=mid)update(id<<1,l,mid,pos,val);
        else update(id<<1|1,mid+1,r,pos,val);
        segt[id] = segt[id<<1]+segt[id<<1|1];
    }
}
int query(int id,int l,int r,int x,int y){
    if(x<=l && r<=y)return segt[id];
    else if(l>y || r<x)return 0;
    else{
        int mid=(l+r)>>1;
        return query(id<<1,l,mid,x,y)+query(id<<1|1,mid+1,r,x,y);
    }
}