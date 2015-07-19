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

int n, tk;
ll w[100005];
ll dp[100005][201];
vector<int> adj[100005];
int st[100005], r[100005];
bool done[100005][202];
int cur = 0;
void precompute() {
	
}
void read() {
	s(n), s(tk);
	for (int i = 0; i < n; ++i) {
		sl(w[i]);
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		s(u); s(v);
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}
void preprocess() {
	memset(dp, -1, sizeof dp);
}
int dfs(int v, int par) {
	int ind = cur;
	st[cur++] = v;
	r[ind] = 1;
	for (std::vector<int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i) {
		int ch = *i;
		if(ch == par) continue;		
		r[ind] += dfs(ch, v);
	}
	return r[ind];
}
ll go(int i, int rem) {
	if(i >= cur) return 0;	
	ll &ret = dp[i][rem];
	if(!done[i][rem]) {
		done[i][rem] = true;
		ret = w[st[i]] + go(i + 1, rem);
		if(rem > 0) ret = max(ret, go(i + r[i], rem - 1));		
	}
	return ret;
}
void debugArr(int *a, int len) {
	for (int i = 0; i < len; ++i) {
		if(i != 0) putchar(' ');
		printf("%d", a[i]);
	}
}
void solve() {
	dfs(0, 0);
	cout << go(0, tk);
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}