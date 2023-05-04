//Thanks AmandioF

#define MAX 100007

ll h[MAX], power[MAX], inv[MAX];
ll base[2] = {317, 307};
ll mod[2] = {104000717, 104000711};
ll n;

ll gcd(ll a, ll m){
    ll x = 1, y = 0, ini = m;
    if(m == 1) return 0;

    while(a > 1){
        ll q = a/m;

        ll t = m;
        m = a%m;
        a = t;
        t = y;
        y = x-q*y;
        x = t;
    }

    if(x < 0) x += ini;
    return x;
}

void init(){
    power[0] = base[0];
    inv[0] = gcd(base[0], mod[0]);
    for(int i = 1; i < MAX; i++){
        power[i] = (power[i-1]*base[0])%mod[0];
        inv[i] = (inv[i-1]*inv[0])%mod[0];
    }
}

void update(int idx, char now, char old = '$'){
    int pos = idx;
    if(old == '$') for(; idx <= n; idx += idx&(-idx)) h[idx] = (h[idx] + (now-'a'+1)*power[pos])%mod[0];
    else{
        for(; idx <= n; idx += idx&(-idx)) {
            h[idx] = (h[idx] - (old-'a'+1)*power[pos])%mod[0];
            while(h[idx] < 0) h[idx] += mod[0];
            h[idx] = (h[idx] + (now-'a'+1)*power[pos])%mod[0];
            while(h[idx] < 0) h[idx] += mod[0];
        }
    }
}
void getHash(string st){
    for(int i = 1; i <= sz(st); i++) update(i, st[i-1]);
}

ll query(int idx){
    ll hash = 0;
    for(; idx > 0; idx -= idx&(-idx)) hash = (hash + h[idx])%mod[0];
    return hash;
}

ll query(int l, int r){ // 1-indexed
    return (((query(r)-query(l-1)+ mod[0])%mod[0])*inv[l])%mod[0];
}
// init -> getHash(s)
