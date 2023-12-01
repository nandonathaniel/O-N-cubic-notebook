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
typedef int ll;
typedef unsigned long long ull;
const ld PI = 4*atan((ld)1);
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ll nax = 1e6 + 5;

struct info{
	ll four, sev, inc, dec;
};

ll n, m;
ll prop[4*nax];
info seg[4*nax];
string s;

info merge(info x, info y){
	info ret;
	ret.four = x.four + y.four;
	ret.sev = x.sev + y.sev;
	ret.inc = max({x.four + y.four, x.sev + y.sev, x.four + y.inc, x.inc + y.sev});
	ret.dec = max({x.four + y.four, x.sev + y.sev, x.sev + y.dec, x.dec + y.four});
	return ret;
}

void rev(ll x){
	swap(seg[x].four, seg[x].sev);
	swap(seg[x].inc, seg[x].dec);
}

void lazy(ll x){
	if(prop[x]){
		rev(2*x), rev(2*x+1);
		prop[2*x] ^= 1, prop[2*x+1] ^= 1;
		prop[x] = 0;
	}
}

void built(ll l, ll r, ll pos){
	if(l == r){
		seg[pos] = {s[l-1] == '4', s[l-1] == '7', 1, 1};
	}
	else{
		ll mid = (l + r) / 2;
		built(l, mid, 2*pos);
		built(mid + 1, r, 2*pos+1);
		seg[pos] = merge(seg[2*pos], seg[2*pos+1]);
	}
}

void upd(ll l, ll r, ll pos, ll fl, ll fr){
	if(fl <= l && fr >= r){
		rev(pos);
		prop[pos] ^= 1;
	} 
	else if(fl > r || fr < l){
		return;
	}
	else{
		lazy(pos);
		ll mid = (l + r) / 2;
		upd(l, mid, 2*pos, fl, fr);
		upd(mid + 1, r, 2*pos+1, fl, fr);
		seg[pos] = merge(seg[2*pos], seg[2*pos+1]);
	}
}

