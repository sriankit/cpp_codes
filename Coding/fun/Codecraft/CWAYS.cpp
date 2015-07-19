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
int m, num;
PII pts[1005];
ll dp[1005][2];
ll f[200005], inv[200005];

ll C(int n, int r) {
	return ((f[n] * inv[r] % MOD) * inv[n - r]) % MOD;
}

void precompute() {	
	f[0] = 1;
	for (int i = 1; i < 200005; ++i) {
		f[i] = (f[i - 1] * i) % MOD;
	}	
	inv[1] = 1;
	for (int i = 2; i < 200005; i++)
        inv[i] = (MOD - MOD / i * inv[((int) (MOD % i))] % MOD) % MOD;
    inv[0] = 1;
    for (int i = 1; i < 200005; i++)
        inv[i] = inv[i] * inv[i - 1] % MOD;
}
void read() {
	s(n), s(m), s(num);
	pts[0] = make_pair(1, 1);
	for (int i = 1; i <= num; ++i) {
		int x, y;
		s(x), s(y);
		pts[i] = make_pair(x, y);
	}
	pts[num + 1] = make_pair(n, m);
}
void preprocess() {
	sort(pts, pts + num + 1);
}
/*
ll go(int i, int last, int odd) {	
	ll &ret = dp[i][last][odd];
	if(ret == -1) {
		int n1 = pts[i].FF - pts[last].FF;
		int m1 = pts[i].SS - pts[last].SS;
		ll moves = C[n1 + m1][n1];
		if(i == num + 1) return moves 
		ret = ((moves * go(i + 1, i, 1 - odd) % MOD) + go(i + 1, last, odd) + 2 * MOD) % MOD;
	}
	return ret;
}
*/
void solve() {
	memset(dp, 0, sizeof dp);
	dp[0][1] = 1;
	for (int i = 1; i < num + 2; ++i) {
		for (int last = 0; last < i; ++last) {
			int n1 = pts[i].FF - pts[last].FF;
			int m1 = pts[i].SS - pts[last].SS;
			if(n1 < 0 or m1 < 0) continue;
			dp[i][0] += (dp[last][1] * C(n1 + m1, n1)) % MOD;
			dp[i][1] += (dp[last][0] * C(n1 + m1, n1)) % MOD;
			if(dp[i][0] >= MOD) dp[i][0] -= MOD;
			if(dp[i][1] >= MOD) dp[i][1] -= MOD;
		}
	}
	printf("%lld\n", (dp[num + 1][0] - dp[num + 1][1] + MOD) % MOD);
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