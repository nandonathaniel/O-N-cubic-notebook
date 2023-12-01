void dfs(int now,int par){
	for(auto nxt : adj[now]){
		if(nxt==par)continue;
		pa[0][nxt]=now;
		for(int i=1;i<LOG;i++)pa[i][nxt]=pa[i-1][pa[i-1][nxt]];
		depth[nxt]=depth[now]+1;
		dfs(nxt,now);
	}
}

int LCA(int u,int v){
	if(depth[u]<depth[v])swap(u,v);
	int diff=depth[u]-depth[v];
	for(int i=LOG-1;i>=0;i--){
		if(diff&(1<<i))u=pa[i][u];
	}
	if(u==v)return u;
	for(int i=LOG-1;i>=0;i--){
		if(pa[i][u]!=pa[i][v]){
			u=pa[i][u];
			v=pa[i][v];
		}
	}
	return pa[0][u];
}
