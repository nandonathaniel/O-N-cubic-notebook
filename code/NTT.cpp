// TEMPLATE FFT/NTT AWOKWOK
const int mod = 998244353;

ll pang(ll x,ll y){
	if(x==0)return 0;
	if(y==0)return 1;
	if(y==1)return x;
	ll z=pang(x,y/2);
	return z*z%mod*pang(x,y%2)%mod;
}

const int root = pang(3,119);
const int root_1 = pang(root,mod-2);
const int root_pw = 1 << 23;

ll inv[300005],fact[300005],ifact[300005];

void fft(vector<ll> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % mod);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert) {
        int n_1 = inv[n];
        for (ll & x : a)
            x = (int)(1LL * x * n_1 % mod);
    }
}
