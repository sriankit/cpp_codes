/* Ankit Srivastava */
#include <bits/stdc++.h>
using namespace std;

#define MOD                     1000000000
#define pb(x)                   push_back(x)
#define mp(x,y)                 make_pair(x,y)
#define FF                      first
#define SS                      second
#define s(n)                    scanf("%d",&n)
#define sl(n)                   scanf("%lld",&n)
#define sf(n)                   scanf("%lf",&n)
#define ss(n)                   scanf("%s",n)
#define sc(n)                   {char temp[4]; ss(temp); n=temp[0];}
#define INF                     (int)1e9
#define LINF                    (long long)1e18
#define EPS                     1e-9
#define maX(a,b)                ((a)>(b)?(a):(b))
#define miN(a,b)                ((a)<(b)?(a):(b))
#define abS(x)                  ((x)<0?-(x):(x))

typedef long long ll;
typedef unsigned long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<ll> vl;
typedef vector<PII> VII;
typedef vector<TRI> VT;

int n;
int TEST_NO;
int f[] = {1, 1, 1, 3, 3, 15, 15, 105, 105, 105, 105};	

void precompute() {
	
}
void read() {
	s(n);
}

int div_c(int num, int den) {
	int x = num / den;
	if(num % den) return x + 1;
	else return x;
}

ll expo(ll num, ll power) {
	ll ans = 1;
	ll base = num;
	if(num == 0) return 0;
	if(power == 0) return 1;
	while(power) {
		if(power & 1) ans = (ans * base) % MOD;
		base = (base * base) % MOD;
		power >>= 1;
	}
	return ans;
}

ll go(int n) {
	if(n <= 10) return f[n];
	else return ((expo(2, div_c(n, 4)) * go(div_c(n, 5)) % MOD) * go(div_c(n, 10))) % MOD;
}

void preprocess() {
	
}
void solve() {
	ll r = go(n);
	cerr << r << endl;
	int p[] = {1, 2, 4, 3, 5};
	ll ans = expo(r, r);
	for (int i = 0; i < 5; ++i) {
		for (int j = i + 1; j < 5; ++j) {
			if(i == 1 and j == 2) continue;
			ll x = p[i] * r;
			ll y = p[j] * r;
			ans = max(ans, expo(x, y));
			ans = max(ans, expo(y, x));
		}
	}
	printf("%lld\n", ans);
}
int main() {
	precompute();
	int t;
	s(t);
	for(TEST_NO = 1; TEST_NO <= t; TEST_NO ++) {
		read();
		preprocess();
		solve();
	}
	return 0;
}