/* Quick Note :
 * Jangan Mikir Lama - lama, sampahin dulu aja kalo OI
 * Always Try to reset
*/
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The value of " << #val << " is = " << val << '\n';
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 922337203685477;
const ll nax = 0;

struct point{
	ll x, y;
};

ll t, n;
vector<point> a;

ll cross(point p, point q, point r){
	ll val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
	if(val == 0){
		return 0;
	}
	else if(val > 0){
		return 1;
	}
	else{
		return -1;
	}
}

ll dist(point p, point q){
	ll dx = p.x - q.x, dy = p.y - q.y;
	return dx * dx + dy * dy;
}

bool cmp(point p, point q){
	ll order = cross(a[0], p, q);
	if(order == 0){
		return dist(a[0], p) < dist(a[0], q);
	}
	else{
		return (order == -1);
	}
}

// Problem : 681 - Convex Hull Finding - UVA

int main(){ 
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    
    cin >> t;
    cout << t << '\n';
    while(t--){
		a.clear();
		cin >> n;
		ll mini = 0;
		for(ll i = 0; i < n; i++){
			ll x, y;
			cin >> x >> y;
			a.pb({x, y});
			if(y < a[mini].y){
				mini = i;
			}
		}
		if(t){
			ll gbg;
			cin >> gbg;
		}
		// Jadiin satu titik sebagai titik acuan / pivot, titik yang dipakai adalah titik yang paling bawah
		swap(a[0], a[mini]);
		// Sort by polar angel
		sort(a.begin() + 1, a.end(), cmp);
		vector<point> v;
		for(ll i = 0; i < n; i++){
			if(v.size() < 2){
				v.pb(a[i]);
			}
			else{
				// Kalau Cross product nya tidak Counter Clockwise pop_back();
				while(v.size() >= 2 && cross(v[v.size()-2], v[v.size()-1], a[i]) != -1){
					v.pop_back();
				}
				v.pb(a[i]);
			}
		}
		cout << v.size() + 1 << '\n';
		for(auto p : v){
			cout << p.x << " " << p.y << '\n';
		}
		cout << a[0].x << " " << a[0].y << '\n';
		if(t){
			cout << "-1\n";
		}
	}
}