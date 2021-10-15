ll fact[maxn], ifact[maxn];

ll mul(ll a,ll b){
    return a*b%MOD;
}
ll fpw(ll a, ll b){
    ll calc=1;
    for(;b>=1LL;b/=2LL){
        if((b&1LL))calc=mul(calc,a);
        if(b!=1)a=mul(a,a);
    }
    return calc;
}
ll add(ll a,ll b){
    if(a+b>=MOD)return a+b-MOD;
    else return a+b;
}
ll sub(ll a,ll b){
    if(a-b<0)return a-b+MOD;
    else return a-b;
}

ll cnk(ll n, ll k){
    ll den = mul(ifact[k],ifact[n-k]);
    return mul(fact[n],den);
}

void preprocess(){
    fact[0] = 1;
    ifact[1] = 1;
    ifact[0] = 1;
    rep(i,1,maxn){
        fact[i] = mul(i,fact[i-1]);
    }
    
    ifact[maxn-1] = fpw(fact[maxn-1],MOD-2);
    
    per(i,maxn-1,2){
        ifact[i] = mul(i+1,ifact[i+1]);
    }
}