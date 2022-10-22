ll vet[maxn],segt[4*maxn];
void build(int id ,int l,int r){
    if(l == r) segt[id] = vet[l];
    else{
        int mid = (l+r)>>1;
        build(id<<1,l,mid);
        build(id<<1|1,mid+1,r);
        segt[id] = segt[id<<1] + segt[id<<1|1];
    }
}
void update(int id,int l,int r,int pos,int val){
    if(l == r){
        segt[id] += val;
    }
    else{
        int mid = (l+r)>>1;
        if(pos <= mid)update(id<<1,l,mid,pos,val);
        else update(id<<1|1,mid+1,r,pos,val);
        segt[id] = segt[id<<1] + segt[id<<1|1];
    }
}
int query(int id,int l,int r,int x,int y){
    if(x<=l && r<=y)return segt[id];
    else if(l>y || r<x)return 0;
    else{
        int mid = (l+r)>>1;
        return query(id<<1,l,mid,x,y) + query(id<<1|1,mid+1,r,x,y);
    }
}

// Walk on segment tree. PS: adapt to question
// On complete inside segments can use +1/-1/(saving ans), but be aware bb treat l == r separetdly and it will be nlogloglog.... fast than nlog^2

int walk(int id,int l,int r,int x,int y, int val){
    if(l > y || r < x) return -1;
    if(x <= l && r <= y) {
        if(segt[id] <= val) return -1;
        while(l != r) {
            int mid = l + (r-l)/2;
            if(segt[2*id] > val) {
                id = 2*id;
                r = mid;
            }
            else{
                id = 2*id+1;
                l = mid+1;
            }
        }
        return l;
    }

    int mid = l + (r-l)/2;
    int dir = walk(2*id, l, mid, x, y, val);
    if(dir != -1) return dir;
    return walk(2*id+1, mid+1, r, x, y, val);
}
