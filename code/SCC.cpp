void dfs(LL now,vector<LL> adj[],vector<LL> &urut){
	visited[now]=true;
	for(auto nxt : adj[now]){
		if(!visited[nxt]){
			dfs(nxt,adj,urut);
		}
	}
	urut.push_back(now);
}

for(LL i=1;i<=m;i++){
	cin >> u >> v;
	adj[u].push_back(v);
	radj[v].push_back(u);
}
vector<LL> order;
for(LL i=1;i<=n;i++){
	if(!visited[i])dfs(i,adj,order);
}
reverse(order.begin(),order.end());
memset(visited,false,sizeof(visited));
for(auto x : order){
	if(!visited[x]){
		vector<LL> scc;
		dfs(x,radj,scc);
	}
}
