int tree[3000005],lazy[3000005],ki[3000005],ka[3000005],node=2;

//update x sampai y, jadiin 1 semua, query dari x sampe y (bisa sampe 1e9)


void pushdown(int now,int L,int R){
	int mid=(L+R)/2;
	if(ki[now]==0){
		ki[now]=node;
		node++;
	}
	if(ka[now]==0){
		ka[now]=node;
		node++;
	}
	tree[ki[now]]=mid-L+1;
	lazy[ki[now]]=1;
	tree[ka[now]]=R-mid;
	lazy[ka[now]]=1;
	lazy[now]=0;
}

void update(int now,int L,int R,int x,int y){
        if(tree[now]==R-L+1)return;
	if(L>=x && R<=y){
		tree[now]=R-L+1;
		lazy[now]=1;
		return;
	}
	if(L>y || R<x)return;
	int mid=(L+R)/2;
	if(lazy[now])pushdown(now,L,R);
	if(ki[now]==0){
		ki[now]=node;
		node++;
	}
	if(ka[now]==0){
		ka[now]=node;
		node++;
	}
	update(ki[now],L,mid,x,y);
	update(ka[now],mid+1,R,x,y);
	tree[now]=tree[ki[now]]+tree[ka[now]];
}

int query(int now,int L,int R,int x,int y){
	if(L>=x && R<=y)
	{
		return tree[now];
	}
	if(L>y || R<x || now==0)return 0;
	if(lazy[now])pushdown(now,L,R);
	int mid=(L+R)/2;
	return query(ki[now],L,mid,x,y)+query(ka[now],mid+1,R,x,y);
}