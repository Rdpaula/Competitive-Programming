const int MOC = 1e9 + 6;
int MOC2=MOC;
ll phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

ll mult(ll a, ll b){
    return (a*b)%(MOC2);
}

ll fastpow(ll a,ll b){
    ll ans=1;
    for(; b > 0;b/=2){
        if(b&1) ans = mult(ans,a);
        a = mult(a,a);
    }
    return ans;
}

template <class T>
T fexp(T x, long long e) {
    T ans(1);
    for(; e > 0; e /= 2) {
        if(e & 1) ans = ans * x;
        x = x * x;
    }
    // cout<<ans.val<<endl;
    return ans;
}
 
template <const int mod = MOC>
struct modBase {
    modBase(int v = 0) : val(v) {}
    int val;
    void operator += (modBase<mod> o) { *this = *this + o; }
    void operator -= (modBase<mod> o) { *this = *this - o; }
    void operator *= (modBase<mod> o) { *this = *this * o; }
    modBase<mod> operator * (modBase<mod> o) { 
        if(((long long) val * o.val % mod)<0)return ((long long) val * o.val % mod)+mod;
        else return ((long long) val * o.val % mod);  
    }
    //modBase<mod> operator / (modBase<mod> o) { return *this * fexp(o, mod - 2); }
    modBase<mod> operator + (modBase<mod> o) { 
        if((val + o.val >= mod ? val + o.val - mod : val + o.val)<0) return (val + o.val >= mod ? val + o.val - mod : val + o.val)+mod;
        else return (val + o.val >= mod ? val + o.val - mod : val + o.val);
    }
    modBase<mod> operator - (modBase<mod> o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }
};
 
template<const size_t n, const size_t m, class T = modBase<>>
struct Matrix {
    T v[n][m];
    
    Matrix(int d = 0) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                v[i][j] = T(0);
            }
            if(i < m) {
                v[i][i] = T(d);
            }
        }
    }
    
    template<size_t mm>
    Matrix<n, mm, T> operator *(Matrix<m, mm, T> &o) {
        Matrix<n, mm, T> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < mm; j++) {
                for(int k = 0; k < m; k++) {
                    ans.v[i][j] = ans.v[i][j] + v[i][k] * o.v[k][j];
                }
            }
        }
        return ans;
    }
};