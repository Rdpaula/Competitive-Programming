vector<int> kmp(string s){
	vector<int> pi(sz(s),0);
	int j=0;
	rep(i,1,n){
		j=pi[i-1];
		while(j>0 && s[i]!=s[j]){
			j=pi[j-1];
		}
		if(s[i]==s[j])j++;
		pi[i]=j;
	}
	return pi;
}