bool cmp(pair<pii,LL> a,pair<pii,LL> b){
	if(a.first.first/SQRT==b.first.first/SQRT)return a.first.second<b.first.second;
	return a.first.first/SQRT<b.first.first/SQRT;
}

sort(que.begin(),que.end(),cmp);
LL L=1,R=1;
for(auto isi : que){
	LL ki=isi.first.first,ka=isi.first.second; 
	while(R<=ka)update(R++);
	while(L-1>=ki)update(--L);
    while(R-1>ka)remove(--R);
    while(L<ki)remove(L++);
    ans[isi.second]=ret;
}