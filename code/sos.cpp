//DP SOS (Sum over submask)
for(int i=0;i<m;i++){
	for(int mask=(1<<m)-1;mask>=0;mask--){
		if(mask & (1<<i))dp[mask]+=dp[mask^(1<<i)];
	}
}