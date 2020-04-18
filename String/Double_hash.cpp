pii compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    const int p2 = 37;
    const int m2 = 1e9+7;
    ll hash_value = 0;
    ll p_pow = 1;
    ll hash_value2 = 0;
    ll p_pow2 = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    for (char c : s){
        hash_value2 = (hash_value2 + (c - 'a' + 1) * p_pow2) % m2;
        p_pow2 = (p_pow2 * p2) % m2;
    }
    return make_pair(hash_value,hash_value2);
}