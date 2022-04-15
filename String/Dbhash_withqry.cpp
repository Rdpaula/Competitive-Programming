/// probability of collision is (n^2/modulo)
/// n = number of strings compared
/// when double hash modulo = modulo1 * modulo2
seed_seq seq{
    (uint64_t) chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
    (uint64_t) __builtin_ia32_rdtsc(),
    (uint64_t) (uintptr_t) make_unique<char>().get()
};
mt19937 rng(seq);
int base32 = 1<<31;


vector<ll>hash_valuen(maxn,0);
vector<ll>hash_valuen2(maxn,0);

vector<ll> invm(maxn);
vector<ll> invm2(maxn);

const ll pr = abs(uniform_int_distribution<int>(0, base32-1)(rng));
const ll md = 1e9 + 7;

const ll pr2 = abs(uniform_int_distribution<int>(0, base32-1)(rng));
const ll md2 = 536847203;

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

void init(vector<ll> &inv, ll p, ll m){
    inv[0] = gcd(p, m);
    for(int i = 1; i < maxn; i++){
        inv[i] = (inv[i-1]*inv[0])%m;
    }
}

void compute_hash(vector<ll> &hash_value, string const& st, ll p, ll m) {
    hash_value[0] = 0;
    ll p_pow = 1;
    
    int cont=1;
    
    for (char c : st) {
        hash_value[cont] = (hash_value[cont-1] + (c - '$' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
        cont++;
    }
}

ll query(int l, int r){ /// 1-indexed
    return (((hash_valuen[r] - hash_valuen[l-1]+md)%md)*invm[l])%md;
}
ll query2(int l, int r){ /// 1-indexed
    return (((hash_valuen2[r] - hash_valuen2[l-1]+md2)%md2)*invm2[l])%md2;
}
