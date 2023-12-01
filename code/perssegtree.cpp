int tree[2*MAXN*LOG],ki[2*MAXN*LOG],ka[2*MAXN*LOG],a[MAXN],root[MAXN],idx,MAX,balik[MAXN];
map<int,int> mp;

int build(int L,int R){
	idx++;
	int no=idx;
	tree[no]=0;
	if(L==R)return no;
	int mid=(L+R)/2;
	ki[no]=build(L,mid);
	ka[no]=build(mid+1,R);
	return no;
}

int update(int bef,int L,int R,int x){
	idx++;
	int no=idx;
	tree[no]=tree[bef]+1;
	ki[no]=ki[bef];
	ka[no]=ka[bef];
	if(L==R)return no;
	int mid=(L+R)/2;
	if(x<=mid)ki[no]=update(ki[no],L,mid,x);
	else ka[no]=update(ka[no],mid+1,R,x);
	return no;
}

int query(int a,int b,int L,int R,int k){
	if(L==R)return L;
	int mid=(L+R)/2;
	int brp=tree[ki[b]]-tree[ki[a]];
	if(brp>=k)return query(ki[a],ki[b],L,mid,k);
	else return query(ka[a],ka[b],mid+1,R,k-brp);
}

root[0]=build(1,MAX);  //seperti null
	for(int i=1;i<=n;i++)root[i]=update(root[i-1],1,MAX,mp[a[i]]);
	while(q--){
		cin >> l >> r >> k;
		l++;k++;
		cout << balik[query(root[l-1],root[r],1,MAX,k)] << '\n';
	}