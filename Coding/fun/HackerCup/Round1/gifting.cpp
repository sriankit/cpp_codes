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
VI adj[200005];
int dp[200005][3];

void precompute() {
	
}

void read() {	
	s(n);
	for (int i = 0; i < n; ++i) {
		adj[i].clear();
	}
	for (int i = 0; i < n; ++i) {
		int p;
		s(p);
		if(p > 0) {
			--p;
			adj[p].push_back(i);
		}
	}
}
void preprocess() {
	
}

int go(int v, int col) {
	if(dp[v][col] != -1) return dp[v][col];
	int cost = col;	
	for (std::vector<int>::iterator it = adj[v].begin(); it != adj[v].end(); ++it) {
		int child = *it;
		if(col == 1) cost += min(go(child, 2), go(child, 3));
		if(col == 2) cost += min(go(child, 1), go(child, 3));
		if(col == 3) cost += min(go(child, 1), go(child, 2));		
	}
	return dp[v][col] = cost;
}

void solve() {
	memset(dp, -1, sizeof dp);
	int minCost = min(go(0, 1), go(0, 2));
	minCost = min(minCost, go(0, 3));
	printf("Case #%d: %d\n", TEST_NO, minCost);	
	//cerr << "DONE" << TEST_NO << endl;	
}
int main() {
	//freopen("input4.txt", "r", stdin);
	//freopen("output4.txt", "w", stdout);
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