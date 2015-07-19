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

int n, m;
ll dp[1000001][31];
int TEST_NO;
void precompute() {
	
}
void read() {
	s(n);
	s(m);
}
ll go(int i, int sum) {
	if(i > n) return 1;
	if(sum <= 0 || sum > m) return 0;
	ll &ret = dp[i][sum];
	if(ret == -1) {
		ret = go(i + 1, sum + 1) + go(i + 1, sum - 1);
		if(i%2 == 0) ret += go(i + 1, sum);
	}
	return ret;
}
void preprocess() {	
	memset(dp, -1, sizeof dp);
}
void solveInstance() {
	preprocess();
	ll ans = 0;
	for (int i = 0; i < m; ++i) {
		ans += go(1, i + 1);
	}
	printf("%lld ", ans);
}
void solve() {
	for (int i = 1; i <= 20; i += 2) {
		printf("%d  --> ", i);
		n = i;
		for (int j = 1; j < 2 * i; ++j)
		{
			m = j;
			solveInstance();
		}
		printf("\n");		
	}
}
int main() {
	freopen("output.txt", "w", stdout);
	precompute();
	int t;
	t = 1;
	for(TEST_NO = 1; TEST_NO <= t; TEST_NO ++) {
		//read();
		preprocess();
		solve();
	}
	return 0;
}