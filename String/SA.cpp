void count_sort(vector<ll> &p, vector<ll> &c){
    ll n = sz(p);
    vector<ll> cnt(n);
    rep(i,0,n) cnt[c[p[i]]]++;
    
    vector<ll> newpos(n);
    rep(i,1,n){
        newpos[i] = newpos[i-1] + cnt[i-1];
    }

    vector<ll> newp(n);
    rep(i,0,n){
        ll bucket = c[p[i]];
        newp[newpos[bucket]] = p[i];
        newpos[bucket]++;
    }
    p = newp;
}

vector<ll> suff_array(string &s){
    s += '$';
    ll n = sz(s);    
    // first pass
    vector<pair<char, ll>> k(n);
    vector<ll> c(n),p(n);
    rep(i,0,n){
        k[i] = {s[i], i};
    }
    sort(all(k));
    
    rep(i,0,n){
        p[i] = k[i].S;
    }
    
    c[p[0]] = 0;
    rep(i,1,n){
        if(k[i].F == k[i-1].F) c[p[i]] = c[p[i-1]];
        else c[p[i]] = c[p[i-1]] + 1;
    }
    // scaling to 2^k
    ll pot = 0;
    while((1 << pot) < n){
        rep(i,0,n){
            p[i] = (p[i] - (1 << pot) + n)%n;
        }
        count_sort(p, c);
        vector<ll> newc(n);
        newc[p[0]] = 0;
        rep(i,1,n){
            pii prev = {c[p[i-1]], c[(p[i-1] + (1 << pot)) % n]};
            pii now = {c[p[i]], c[(p[i] + (1 << pot)) % n]};

            if(prev == now) newc[p[i]] = newc[p[i-1]];
            else newc[p[i]] = newc[p[i-1]] + 1;
        }
        c = newc;
        pot++;
    }
    return p;
}