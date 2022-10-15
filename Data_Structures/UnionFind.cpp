ll pai[maxn];
ll ranks[maxn];

void init(int n){
    for(int i = 0; i < n+1; i++){
        pai[i] = i;
        ranks[i] = 1;
    }
}

ll find(ll x){
    if(pai[x] == x) return x;
    else return pai[x] = find(pai[x]);
}

void unions(ll a, ll b){
    ll paia = find(a);
    ll paib = find(b);
    if(paia == paib) return;
    if(ranks[paia] < ranks[paib]) swap(paia,paib);
    pai[paib] = paia;
    ranks[paia] += ranks[paib];
}