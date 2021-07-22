vector<ll>hash_valuen(maxn,0);
vector<ll>hash_valuer(maxn,0);

ll ans[maxn];
ll inv[maxn];

const ll p = 317;
const ll m = 104000717;

ll gcd(ll a, ll tri){
    ll x = 1, y = 0, ini = tri;
    if(tri == 1) return 0;

    while(a > 1){
        ll q = a/tri;

        ll t = tri;
        tri = a%tri;
        a = t;
        t = y;
        y = x-q*y;
        x = t;
    }

    if(x < 0) x += ini;
    return x;
}

void init(){
    inv[0] = gcd(p, m);
    for(int i = 1; i < maxn; i++){
        inv[i] = (inv[i-1]*inv[0])%m;
    }
}

void compute_hash(vector<ll> &hash_value, string const& st) {
    hash_value[0] = 0;
    ll p_pow = 1;
    
    int cont=1;
    
    for (char c : st) {
        hash_value[cont] = (hash_value[cont-1] + (c - '$' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
        cont++;
    }
}
void compute_hash2(vector<ll> &hash_value2,string const& st) {
    hash_value2[0] = 0;
    ll p_pow = 1;

    int cont=1;
    
    for (char c : st) {
        hash_value2[cont] = (hash_value2[cont-1] + (c - '$' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
        cont++;
    }
}

ll query(int l, int r){ /// 1-indexed
    return (((hash_valuen[r] - hash_valuen[l-1]+m)%m)*inv[l])%m;
}