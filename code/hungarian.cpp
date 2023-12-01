#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define ff first
#define ss second
const ld PI = 4 * atan((ld)1);
const ll nax = 25;
const ll inf = 1e16;

ll n;
ll ans;

ll dist(pair<ll,ll> x, pair<ll,ll> y){
	return abs(x.ff - y.ff) + abs(x.ss - y.ss);
}

ll hungarian(vector<pair<ll,ll>>&a, vector<pair<ll,ll>>&b){
  // pairing a ke b
	vector<ll> u(n + 1), v(n + 1), p(n + 1), way(n + 1);
	for(ll i = 1; i <= n; i++){
		p[0] = i;
		ll curM = 0;
		vector<ll> minv(n + 1, inf);
		vector<bool> used(n + 1, 0);
		while(p[curM] != 0){
			used[curM] = 1;
			ll curN = p[curM], delta = inf;
			ll nexM;
			for(int j = 1; j <= n; ++j){
				if(!used[j]){
					int cur = dist(a[curN-1], b[j-1]) - u[curN] - v[j];
					if(cur < minv[j]){
						minv[j] = cur, way[j] = curM;
					}
					if(minv[j] < delta){
						delta = minv[j], nexM = j;
					}
				}
			}
			for(int j = 0; j <= n; j++){
				if(used[j]){
					u[p[j]] += delta, v[j] -= delta;
				}
				else{
					minv[j] -= delta;
				}
			}
			curM = nexM;
		}
		do{
			ll nexM = way[curM];
			p[curM] = p[nexM];
			curM = nexM;
		}while(curM != 0);
	}
	return (-v[0]);
}

void make_diagonal(vector<pair<ll,ll>>&a){
	vector<pair<ll,ll>> b;
	for(ll i = 1; i <= n; i++){
		b.pb({i, i});
	}
	ans = min(ans, hungarian(a, b));
	b.clear();
	ll cnt = 1;
	for(ll i = n; i >= 1; i--){
		b.pb({cnt, i});
		cnt++;
	}
	ans = min(ans, hungarian(a, b));
}

void make_horizontal(vector<pair<ll,ll>> &a){
	vector<pair<ll,ll>> b;
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			b.pb({i, j});
		}
		ans = min(ans, hungarian(a, b));
		b.clear();
	}
}

void make_vertical(vector<pair<ll,ll>> &a){
	vector<pair<ll,ll>> b;
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			b.pb({j, i});
		}
		ans = min(ans, hungarian(a, b));
		b.clear();
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll ct = 0;
	while(1){
		cin >> n;
		ans = inf;
		if(n == 0){
			break;
		}
		vector<pair<ll,ll>> a;
		for(ll i = 1; i <= n; i++){
			ll x, y;
			cin >> x >> y;
			a.pb({x, y});
		}
		make_diagonal(a);
		make_horizontal(a);
		make_vertical(a);
		cout << "Board " << ++ct << ": " << ans << " moves required." << "\n\n";
	}
	
}

