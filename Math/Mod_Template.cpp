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