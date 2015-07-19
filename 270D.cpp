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
#define LINF                    (long long)1e15
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
int adj[2002][2002];
int ok = 1;
int prev[2002];
void precompute() {
	
}
void read() {
	s(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			sl(adj[i][j]);
			if(i == j and adj[i][j] != 0) ok = 0;
			if(i > j and adj[i][j] != adj[j][i]) ok = 0;
		}
	}
}
void preprocess() {
	
}
void makeTree() {
	int dist[2002];
	bool vis[2002];
	for (int i = 0; i < n; ++i) {
		dist[i] = LINF;
	}
	memset(prev, -1, sizeof prev);
	memset(vis, false, sizeof vis);
	dist[0] = 0;
	for (int i = 0; i < n; ++i) {
		int u = -1;
		for (int j = 0; j < n; ++j) {
			if(!vis[j] and (u == -1 || dist[j] < dist[u])) u = j;
		}
		// found min vertex as u
		// now update
		vis[u] = true;
		for (int j = 0; j < n; ++j) {
			if(vis[j] and prev[j] != -1 and j != u) {
				if(adj[j][prev[u]] + dist[u] != adj[j][u]) ok = 0;
			}
		}
		if(dist[u] == LINF) ok = 0;
		for (int j = 0; j < n; ++j) {
			if(!vis[j] and adj[u][j] > 0) {
				if(adj[u][j] < dist[j]) {
					prev[j] = u;
					dist[j] = adj[u][j];					
				}
			}
		}
	}
	for (int i = 1; i < n; ++i) {
		if(prev[i] == -1) ok = 0;
	}
}
void solve() {
	if(ok) {
		makeTree();		
		int res = ok;
		if(res) puts("YES");
		else puts("NO");
	} else puts("NO");
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}