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
#define FILE 1
int TEST_NO;
#define MAXN 1000006
int dp[1000006];
int memo[1000006];
int avl[10];
void precompute() {
	
}
void read() {
	memset(avl, 0, sizeof avl);
	for (int i = 0; i < 10; ++i) {
		s(avl[i]);
	}	
}
void preprocess() {
	memset(dp, -1, sizeof(dp));
}
int go(int x) {	
	int &ret = dp[x];
	if(dp[x] == -1) {
		ret = -2; //Impossible
		for (int i = 2; i <= x / i; ++i) {
			if(x % i != 0) continue;
			int r1 = go(i);
			int r2 = go(x / i);
			if(r1 == -2 or r2 == -2) continue;
			int add = r1 + r2 + 1;
			if(ret == -2 || ret > add)
				ret = add;
		}
	}
	//cerr << " going for " << x << " " << ret << endl;
	return ret;
}
void solve() {
	printf("Case #%d: ", TEST_NO);
	dp[0] = 0;
	for (int i = 0; i < MAXN; ++i) {
		if(dp[i] == -1) continue;
		for (int dig = 0; dig < 10; ++dig) {
			if(!avl[dig]) continue;
			int num = i * 10 + dig;
			if(num > MAXN) continue;
			if(dp[num] == -1 || dp[num] > dp[i] + 1) 
				dp[num] = dp[i] + 1;
		}
	}
	int target;
	s(target);
	int res = go(target);
	if(res != -2) cout << res + 1 << endl;
	else cout << "Impossible" << endl;
}
int main() {
	#if FILE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif
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