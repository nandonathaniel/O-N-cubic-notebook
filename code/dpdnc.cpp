void calc(int L,int R,int optL,int optR,int j){
    if(L>R)return;
    int mid=(L+R)/2;
    int res=2e9;
    int opt=-1;
    for(int i=optL;i<=min(optR,mid-1);i++){
        if(dp[j-1][i]+cost(i+1,mid)<res){
            res=dp[j-1][i]+cost(i+1,mid);
            opt=i;
        }
    }
    dp[j][mid]=res;
    calc(L,mid-1,optL,opt,j);
    calc(mid+1,R,opt,optR,j);
}
for(int i=1;i<=n;i++)dp[1][i]=cost(1,i);
for(int i=2;i<=k;i++){
    calc(i,n,i-1,n,i); //mau ngisi dp[i][...] dengan ... dari i sampai n karena dengan k gondola minimal k orang
}