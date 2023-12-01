ll kmpt[100050];

void kmp(string s){
	kmpt[0] = -1; kmpt[1] = 0;

	ll cnd = 0;
	FOR(i, 2, s.length()){
		if(s[i-1] == s[cnd]){
			kmpt[i] = ++cnd;
		}
		else{
			while(cnd > 0 && s[i-1] != cnd) cnd = kmpt[cnd];
		}
	}
}
