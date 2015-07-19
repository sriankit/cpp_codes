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

ll a, b;
ll ans;
void precompute() {
	
}
void read() {
	sl(a), sl(b);
}
void preprocess() {
	
}
void solve() {
	ll sum = a * (a + 1) >> 1;
	sum %= MOD;
	for (int q = 1; q < b; ++q) {
		ans += (q * (a + (b * sum) % MOD)) % MOD;
		if(ans >= MOD) ans -= MOD;
	}
	printf("%lld\n", ans);
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}