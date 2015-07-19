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
#define GYM 1

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
ll dp[202][202];
void precompute() {
	
}
void read() {
	s(n);
	s(m);	
}
void preprocess() {
	memset(dp, - 1, sizeof dp);	
}
ll go(int i, int st) {
	if(i == n) {
		return 1;
	}
	if(st > m) return 0;
	ll &ret = dp[i][st];
	if(ret == -1) {
		ret = 0;
		for (int h = st; h <= m; ++h) {
			ret += go(i + 1, h + 1);
			if(ret >= MOD) ret -= MOD;
		}		
	}
	return ret;
}
void solve() {
	printf("%lld\n", go(0, 1));
}
int main() {
	#if GYM
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}