#include <bits/stdc++.h>

#define ll long long
#define MOD 1000000007

using namespace std;

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

// Performance: single flat 1D allocation instead of pointer-to-pointer.
// Eliminates per-row heap allocations and improves cache locality.
struct Matrix {
    vector<ll> m;
    int rows, cols;

    ll& at(int i, int j)             { return m[i * cols + j]; }
    const ll& at(int i, int j) const { return m[i * cols + j]; }

    void ident() {
        for(int i = 0; i < min(rows, cols); i++)
            at(i, i) = 1;
    }

    Matrix(int row, int col) : rows(row), cols(col), m(row * col, 0LL) {}

    // Performance: i,k,j loop order — inner loop accesses res and o rows
    // sequentially, avoiding cache misses on the transposed dimension.
    Matrix operator % (const Matrix& o) const {
        assert(cols == o.rows);
        Matrix res(rows, o.cols);
        for(int i = 0; i < rows; i++) {
            for(int k = 0; k < cols; k++) {
                if(m[i * cols + k] == 0) continue; // skip zero entries
                for(int j = 0; j < o.cols; j++) {
                    res.at(i, j) = add(res.at(i, j), mul(m[i * cols + k], o.m[k * o.cols + j]));
                }
            }
        }
        return res;
    }

    Matrix operator ^ (ll exp) const {
        Matrix res(rows, cols), base = *this;
        res.ident();

        while(exp) {
            if(exp & 1) res = res % base;
            exp >>= 1;
            if(exp) base = base % base;
        }
        return res;
    }
};

int main() {
}
