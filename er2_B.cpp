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
ll k;
int a[100005];
int maxe = -1;
void precompute() {
	
}
void read() {
	s(n);
	sl(k);
	for (int i = 0; i < n; ++i) {
		s(a[i]);
		if(maxe == -1 || maxe < a[i]) maxe = a[i];
	}
}
void preprocess() {
	
}
ll go(int l, int r, ll h) {
	int mxi = l;
	int cnt = 0;
	for (int i = l; i <= r; ++i) {
		if(a[i] > a[mxi]) {
			mxi = i;	
			cnt = 0;
		}
		if(a[i] == a[mxi]) cnt++;
	}
	ll ans = h - a[mxi];
	if(cnt == r - l + 1) return h - a[mxi];
	int st = l;
	for (int i = l; i <= r; ++i) {
		if(a[i] == a[mxi]) {
			if(st != i) ans += go(st, i - 1, h);
			st = i + 1;	
		}
	}
	if(st != r + 1) ans += go(st, r, h);
	return ans;
}
bool ok(ll h) {
	ll cost = go(0, n - 1, h);
	return cost <= k;
}
void solve() {
	ll lo = maxe;
	ll hi = (ll)1e12;
	cerr << ok(2) << " " << ok(3) << endl;
	ll ans = -1;
	while(lo <= hi) {
		ll mid = lo + hi >> 1;
		if(ok(mid)) {
			ans = mid;
			lo = mid + 1;
		} else hi = mid - 1;
	}
	if(ans == -1) puts("0");
	else printf("%lld\n", ans - maxe + 1);
}	
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}