
bool dfs(int now){
    if(visited[now])return false;
    visited[now]=true;
    for(auto nxt : adj[now]){
        if(match[nxt]==-1 || dfs(match[nxt])){
            match[nxt]=now;
            return true;
        }
    }
    return false;
}

memset(match,-1,sizeof(match));
for(int i=0;i<n;i++){
    memset(visited,0,sizeof(visited));
    if(dfs(i))matching++;
}
