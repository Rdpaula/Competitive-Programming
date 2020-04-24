vector<ll> zfunc(string s){
    int n=sz(s);
    vector<ll> z(n,0);
    int l=0,r=0;
    rep(i,1,n){
        if(i<=r)z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<n && s[z[i]]==s[i+z[i]])z[i]++;
        if(i+z[i]-1>r){
            l=i,r=i+z[i]-1;
        }
    }
    return z;
}