/* Ankit Srivastava */
#include <bits/stdc++.h>
using namespace std;

#define MOD                     1000000007
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
ll a, b;
int p;
void precompute() {
	
}
void read() {
	sl(a), sl(b);
	s(p);
}
void preprocess() {
	
}
ll range(ll num, ll l, ll r) {
	l -= num;
	r -= num;
	l += p;
	r += p;
	return r / p - (l - 1) / p;
}
void solve() {
	ll ans = 0;
	for (ll mod = 0; mod < p; ++mod) {
		ll cube = mod * mod *mod;
		if(cube % p == 1) ans += range(mod, a, b);	
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