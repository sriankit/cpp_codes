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
int a[100005];
int TEST_NO;
void precompute() {
	
}
void read() {
	s(n);
	for (int i = 0; i < n; ++i) {
		s(a[i]);
	}
}
void preprocess() {
	
}
ll pw(int base, int exp) {
	ll ans = 1;
	while(exp) {
		if(exp & 1) ans *= base;
		exp >>= 1;
		base *= base;
		if(base >= MOD) base %= MOD;
		if(ans >= MOD) ans %= MOD;
	}
	return ans;
}
void solve() { 
	int mx = 0, mxc = 0;
	for (int i = 0; i < n; ++i) {
		if(a[i] > a[mx]) {
			mxc = 0;
			mx = i;
		}
		if(a[i] == a[mx]) mxc ++;
	}
	printf("%lld\n", pw(2, mxc) - 1);
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