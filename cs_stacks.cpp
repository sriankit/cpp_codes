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

int n, tt;
int a[101];
ll p[101];
ll C;
ll dp[102][102];
void precompute() {
	
}
void read() {
	s(n),s(tt);
	p[0] = 0;
	for (int i = 1; i <= n; ++i) {
		s(a[i]);
		p[i] = p[i - 1] + a[i];
	}
}
void preprocess() {
	memset(dp, -1, sizeof dp);
}
ll go(int lo, int hi) {
	if(lo == hi) {
		return 0;
	}
	ll &ret = dp[lo][hi];
	if(ret == -1) {
		for (int root = lo; root <= hi; ++root) {
			ll add = (p[root] - p[lo - 1]) * (root - lo + 1) + (p[hi] - p[root]) * (hi - root) - C;
			ll res = go(lo, root) + go(root + 1, hi) + add;
			if(res < 0) res = 0;
			if(ret == -1 || ret > res) 
				ret = res;
 		}
 	}
 	return ret;
}
void solve() {
	ll lo = 0, hi = (ll)1e15;
	ll ans = 0;
	while(lo <= hi) {
		ll mid = lo + hi >> 1;
		C = mid;
		preprocess();
		ll val = go(1, n);
		if(val <= tt) {
			ans = mid;
			hi = mid - 1;
		} else lo = mid + 1;
	}
	cout << ans;
}
/*
void solve() {
	ll cost =  go(1, n);
	ll extra = tt - cost;
	if(extra <= 0) cout << 0;
	else {
		int joins = n - 1;
		if(extra % joins == 0) cout << extra /joins;
		else cout << 1 + (extra / joins);
	}
}
*/
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}