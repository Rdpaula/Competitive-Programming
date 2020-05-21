ll mult(ll a,ll b){
    return a*b%MOD;
}
ll fastpow(ll a, ll b){
    ll ans=1;
    for(;b>=1LL;b/=2LL){
        if((b&1LL))ans=mult(ans,a);
        a=mult(a,a);
    }
    return ans;
}
ll soma(ll a,ll b){
    if(a+b>MOD)return a+b-MOD;
    else return a+b;
}
ll subt(ll a,ll b){
    if(a-b<0)return a-b+MOD;
    else return a-b;
}