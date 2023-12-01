#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The value of " << #val << " is = " << val << '\n';
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ld PI = 4*atan((ld)1);
const ll mod = 1e9 + 7;
const ll inf = 922337203685477;
const ll nax = 1e3 + 5;

const int K = 105;

struct Vertex {
    int next[K];
    vector<ll> leaf;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];

    Vertex(int P=-1, char ch='$') : p(P), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

void add_string(string const& s, ll idx) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf.pb(idx);
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 

ll tc, q;
string s, a[nax];
bool cek[nax], vis[nax];

int main(){ 
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    
    cin >> tc;
    while(tc--){
		cin >> s;
		cin >> q;
		// reset
		memset(vis, 0, sizeof(vis));
		memset(cek, 0, sizeof(cek));
		t.clear();
		t.emplace_back();
		
		for(ll i = 1; i <= q; i++){
			cin >> a[i];
			add_string(a[i], i);
			cek[i] = 0;
		}
		ll cur = 0;
		for(auto it : s){
			cur = go(cur, it);
			if(!vis[cur]){
				for(auto each : t[cur].leaf){
					cek[each] = 1;
				}
				vis[cur] = 1;
			}
		}
		for(ll i = 1; i <= q; i++){
			if(cek[i]) cout << "y\n";
			else cout << "n\n"; 
		}
	}
}
