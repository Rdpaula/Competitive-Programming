vector<vector<ll> > compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    const int p2 = 37;
    const int m2 = 1e9+7;
    vector<vector<ll>> hash_value(maxn,vector<ll>(2,0));
    hash_value[0][0] = 0;
    ll p_pow = 1;
    hash_value[0][1] = 0;
    ll p_pow2 = 1;
    
    ll cont=1;
    
    for (char c : s) {
        hash_value[cont][0] = (hash_value[cont-1][0] + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
        cont++;
    }

    cont=1;
    
    for (char c : s){
        hash_value[cont][1] = (hash_value[cont-1][1] + (c - 'a' + 1) * p_pow2) % m2;
        p_pow2 = (p_pow2 * p2) % m2;
        cont++;
    }
    return hash_value;
}