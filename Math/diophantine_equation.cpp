#include<bits/stdc++.h>
#define pi 3.1415  
#define ll long long
#define pii pair<ll,ll>
#define debug(a) cout<<a<<'\n'
#define maxn 300009
#define MOD 1000000007
#define INF (ll)3000009
using namespace std;
void shift_solution(ll & x, ll & y, ll a, ll b, ll cnt) { /// gerator of others solutions
    x += cnt * b;   
    y -= cnt * a;
}

void extendedEuclid(ll a,ll b){
    if(b==0){x = 1; y = 0, d = a; return;} /// store x and y in global variables
    extendedEuclid(b, a%b);
    ll x1 = y;
    ll y1 = x - (a/b) * y;
    x = x1;
    y = y1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    return 0;
}   