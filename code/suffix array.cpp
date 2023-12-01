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
const ll nax = 5e5 + 5;

ll n;
ll sa[nax], ra[nax];
ll tempSA[nax], tempRA[nax];
ll freq_radix[nax];
string s;

void radixSort(ll k){
	ll maxi = max(300ll, n);
	memset(freq_radix, 0, sizeof(freq_radix));
	for(ll i = 0; i < n; i++){
		if(i + k < n){
			freq_radix[ra[i+k]]++;
		}
		else{
			freq_radix[0]++;
		}
	}
	ll sum = 0;
	for(ll i = 0; i < maxi; i++){
		ll temp = freq_radix[i];
		freq_radix[i] = sum;
		sum += temp;
	}
	for(ll i = 0; i < n; i++){
		ll temp = sa[i] + k;
		if(temp < n){
			tempSA[freq_radix[ra[temp]]++] = sa[i];
		}
		else{
			tempSA[freq_radix[0]++] = sa[i];
		}
	}
	for(ll i = 0; i < n; i++){
		sa[i] = tempSA[i];
	}
}

void builtSA(){
	for(ll i = 0; i < n; i++){
		ra[i] = s[i];
		sa[i] = i;
	}
	for(ll k = 1; k < n; k *= 2){
		radixSort(k);
		radixSort(0);
		tempRA[sa[0]] = 0;
		ll r = 0;
		for(ll i = 1; i < n; i++){
			if(ra[sa[i]] == ra[sa[i-1]] && ra[sa[i]+k] == ra[sa[i-1]+k]){
				tempRA[sa[i]] = r;
			}
			else{
				tempRA[sa[i]] = ++r;
			}
		}
		for(ll i = 0; i < n; i++){
			ra[i] = tempRA[i];
		}
		if (ra[sa[n-1]] == n-1) break; // nice optimization trick
	}
}

int main(){ 
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    
    /* 
	contoh input
	qwedasd
	
	contoh output
	asd: URUTAN KE 1
	d: URUTAN KE 2
	dasd: URUTAN KE 3
	edasd: URUTAN KE 4
	qwedasd: URUTAN KE 5
	sd: URUTAN KE 6
	wedasd: URUTAN KE 7
	*/
    
    cin >> s;
    s += '$';
    n = s.size();
    builtSA();
    for(ll i = 1; i < n; i++){
		for(ll j = sa[i]; j < n - 1; j++){
			cout << s[j];
		}
		cout << ": URUTAN KE " << i << '\n';
	}
}
