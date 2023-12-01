#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll nax = 1e6 + 5;

struct info{
	ll x, y, a;
};

bool cmp(info x, info y){
	return x.x < y.x;
}

struct line{
	ll m, c;
	ll val(ll x){
		return m * x + c;
	}
	ll intersect(line l){
		return (ld) (c - l.c) / (l.m - m);
	}
};

ll n;
info inp[nax];
deque<line> dq;

ll binser(ll x){
	ll l = 0, r = (ll)dq.size() - 1;
	while(l < r){
		ll mid = (l + r) / 2;
		if(dq[mid].intersect(dq[mid+1]) >= x){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	return l;
}

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	
	cin >> n;
	for(ll i = 1; i <= n; i++){
		cin >> inp[i].x >> inp[i].y >> inp[i].a;
	}
	sort(inp + 1, inp + 1 + n, cmp);
	dq.push_front({0, 0});
	ll ans = 0;
	for(ll i = 1; i <= n; i++){
		ll idx = binser(inp[i].y);
		ll ret = dq[idx].val(inp[i].y) + inp[i].x * inp[i].y - inp[i].a;
		ans = max(ans, ret);
		line cur = {-inp[i].x, ret};
		while((ll)dq.size() >= 2 && cur.intersect(dq[0]) >= dq[0].intersect(dq[1])){
			dq.pop_front();
		}
		dq.push_front(cur);
	}
	cout << ans << '\n';
}
