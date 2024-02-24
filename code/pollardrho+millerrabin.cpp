#include <bits/stdc++.h>
using namespace std;

__int128 GCD(__int128 a, __int128 b) {
	return b == 0 ? a : GCD(b, a % b);
}
__int128 LCM(__int128 a, __int128 b) {
	return a / GCD(a, b) * b;
}

__int128 read() {
	__int128 x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

void print(__int128 x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

__int128 modmul(__int128 a, __int128 b, __int128 M) {
	__int128 ret = a * b - M * __int128(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (__int128)M);
}

__int128 modpow(__int128 b, __int128 e, __int128 mod) {
	__int128 ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
	if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}

bool isPrime(__int128 n) {
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	__int128 A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	s = __builtin_ctzll(n-1), d = n >> s;
	for (auto a : A) { // ^ count trai l ing zeroes
		__int128 p = modpow(a%n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}

__int128 f(__int128 x, __int128 n){
	return modmul(x, x, n) + 1;
}

__int128 pollard(__int128 n) {
//	auto f = [n](__int128 x) { return modmul(x, x, n) + 1; };

	__int128 x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	while (t++ % 40 || GCD(prd, n) == 1) {
		if (x == y) x = ++i, y = f(x,n);
		if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
		x = f(x,n), y = f(f(y,n),n);
	}
	return GCD(prd, n);
}

vector<__int128> factorize(__int128 n) {
	if (n == 1) return {};
	if (isPrime(n)) return {n};
	__int128 x = pollard(n);
	auto l = factorize(x), r = factorize(n / x);
	l.insert(l.end(), r.begin(), r.end());
	return l;
}

__int128 n;
vector<pair<__int128,__int128> > o;

vector<pair<__int128,__int128> > getAllFactors(__int128 n) {
	vector<pair<__int128, __int128>> primeFactCnt;
	auto primeFacts = factorize(n);
	sort(primeFacts.begin(), primeFacts.end());
 
	__int128 curFact = primeFacts[0], cnt = 0;
	for (auto primeFact : primeFacts) {
		if (primeFact != curFact) {
			primeFactCnt.emplace_back(curFact, cnt);	
			curFact = primeFact;
			cnt = 1;
		} else {
			cnt++;
		}
	}
	primeFactCnt.emplace_back(curFact, cnt);	
 
	return primeFactCnt;
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	n=read();
	o=getAllFactors(n);
	for(auto isi : o){
		print(isi.first);
		printf("^");
		print(isi.second);
		printf("*");
	}
	printf("\n");
	__int128 besar=109930813984377167;
	printf("%d\n",isPrime(besar));
	return 0;
}