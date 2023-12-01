const ull pr[] = {2,3,5,7,11,13,17,19,23,29,31,37,61};
ll modmul(ll a,ll b,ll mod) {
    a %= mod; b %= mod;
    if (mod <= INF) return (a * b) % mod;
    ll ret = 0;
    while (b) {
        if (b&1LL)
        {
            ret = (ret + a);
            if (ret >= mod)
            ret -= mod;
        }
        a += a;
        if (a >= mod) a -= mod;
        b >>= 1;
    }
    return ret;
}
bool isPrime(ll num) { // deterministic Miller-Rabin, prime checking
    if (num == 2ll) return 1;
    if ((num&1ll) == 0ll) return 0;
    int s = 0;
    ll d = num;
    --d;
    while ((d&1ll) == 0){
        ++s;
        d >>= 1;
    }
    ll kko = num;
    --kko;
    FOR (i,0,13) {
    ll x = pr[i];
        if (x == num) continue;
        ll tmp = modpow(x,d,num);
        if (tmp != 1ll) {
            if (tmp != kko) {
                int i = 0;
                while (i < s) {
                    tmp = modmul(tmp,tmp,num);
                    if (tmp == kko) break;
                    ++i;
                }
                if (i >= s) return 0;
            }
        }
    }
    return 1;
}
ll pollardRho(ll x) { // find factor of x
    ll a,b,gcd;
    a = b = 2;
    do {
        a = modmul(a,a,x);
        a += x - 1;
        if (a >= x) a -= x;
        b = modmul(b,b,x);
        b += x - 1;
        if (b >= x) b -= x;
        b = modmul(b,b,x);
        b += x - 1;
        if (b >= x) b -= x;
        ll tmp = (a > b) ? a - b : b - a;
        gcd = __gcdll(tmp,x);
    } while (gcd == 1LL);
    return gcd;
}