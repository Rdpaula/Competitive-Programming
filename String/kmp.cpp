vector<ll> kmp(string s){
	vector<ll> pi(sz(s),0);
	int j=0;
	rep(i,1,sz(s)){
		j=pi[i-1];
		while(j>0 && s[i]!=s[j]){
			j=pi[j-1];
		}
		if(s[i]==s[j])j++;
		pi[i]=j;
	}
	return pi;
}