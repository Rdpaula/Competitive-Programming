// A pretty nice and very quick matrix multiplier mod 10^9+7
 
#include <iostream>
#include <cstring>
#include <cassert>
#include <random>
#include <algorithm>
#include <chrono>
#include <vector>
#define ull unsigned long long
#define ll long long
 
const ull MOD = 1000000007L;
 
void mult(unsigned int * __restrict__ A, unsigned int * __restrict__ B, unsigned int * __restrict__ C, int Cn, int Am, int Cm)
{
    static ull buf[1000];
 
    for (int j=0; j<Cm; ++j)
    {
        std::fill(buf,buf+Cn,0);
        int k = 0;
        for (; k+18<=Am; k+=18)
        {
            for (int _k=k; _k<k+18; ++_k)
                for (int i=0; i<Cn; ++i)
                    buf[i] += (ull)A[_k*Cn + i]*B[j*Am +_k];
            for (int i=0; i<Cn; ++i)
                buf[i] %= MOD;
        }
        for (; k<Am; ++k)
            for (int i=0; i<Cn; ++i)
                buf[i] += (ull)A[k*Cn + i]*B[j*Am + k];
        for (int i=0; i<Cn; ++i)
            C[j*Cn + i] = buf[i]%MOD;
    }
}
 
 
template<typename T>
struct Matrix {
    std::vector<T> data;
    int n;
    int m;
    Matrix(int n, int m) : n(n), m(m), data(n*m) {
    }
    T* operator [](int j) {
        return data.data() + j*n;
    }
    void fill(T val)
    {
        std::fill(data.begin(), data.end(), val);
    }
    Matrix operator* (Matrix& B)
    {
        assert(this->m==B.n);
        Matrix<T> C(this->n,B.m);
        mult((*this)[0],B[0],C[0],C.n,this->m,C.m);
        return C;
    }
    
    void operator<< (Matrix& B)
    {
        assert(this->m==B.n);
        int Cn = this->n;
        int Cm = B.m;
        assert(this->n==Cn);
        assert(this->m==Cm);
        auto C = new T[Cn*Cm];
        mult((*this)[0],B[0],C,Cn,this->m,Cm);
        std::copy(C,C+Cn*Cm,(*this)[0]);
        delete[] C;
    }
    
    void operator>> (Matrix& B)
    {
        assert(this->m==B.n);
        int Cn = this->n;
        int Cm = B.m;
        assert(B.n==Cn);
        assert(B.m==Cm);
        auto C = new T[Cn*Cm];
        mult((*this)[0],B[0],C,Cn,this->m,Cm);
        std::copy(C,C+Cn*Cm,B[0]);
        delete[] C;
    }
};
 
using Mat = Matrix<unsigned int>;
 
template<typename T>
T power(T &A, T &B, ull m)
{
    if (m==0)
        return B;
    while (m>1)
    {
        if (m&1)
        {
            A>>B;
        }
        A>>A;
        m/=2;
    }
    A>>B;
    return B;
}