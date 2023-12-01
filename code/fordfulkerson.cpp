LL bneck,adj[5005][5005],source,sink,ans=0,n;
bool visited[5005];

void dfs(LL node,LL bottleneck){
	if(node==sink){
		ans+=bottleneck;
		sudah=true;
		bneck=bottleneck;
		return;
	}
	if(!visited[node]){
		visited[node]=true;
		for(LL i=1;i<=n;i++){
			if(adj[node][i]>0){
				dfs(i,min(adj[node][i],bottleneck));
				if(sudah){
					adj[node][i]-=bneck;
					adj[i][node]+=bneck;
					return;
				}
			}
		}
	}
}

int main(){
	source=1,sink=n;
	sudah=true;
	while(sudah){
		memset(visited,false,sizeof(visited));
		sudah=false;
		dfs(source,1e18);
	}
	cout << ans << endl;
}