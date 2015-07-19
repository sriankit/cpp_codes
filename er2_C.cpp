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

int n, k;
vector<int> adj[303];
int dist[303];
bool vis[303];
void precompute() {
	
}
void read() {
	s(n), s(k);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		s(u), s(v);
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}
void dfs_dist(int v, int p, int d) {
	dist[v] = d;
	for (std::vector<int>::iterator it = adj[v].begin(); it != adj[v].end(); ++it){
		int child = *it;
		if(child != p) {
			if(!vis[child]) dfs_dist(child, v, d + 1);
		}
	}
}
void preprocess() {
}
int solveOne(int root) {
	dfs_dist(root, root, 0);
	memset(vis, false, sizeof vis);
	priority_queue<int> pq;
	for (int i = 0; i < n; ++i) {
		pq.push(make_pair(dist[i], i));
	}
	int lk = k;
	while(lk --) {
		pair<int, int> pr = pq.top();
		vis[pr.FF] = true;
		pq.pop();
	}	
	pair<int, int> pr = pq.top();
	int leaf = pr.FF;
	dfs_dist(leaf, leaf, 0);
	int ans = -1;
	for (int i = 0; i < n; ++i) {
		if(!vis[i] and ans < dist[i]) ans = dist[i];	
	}
	return ans;
}
void solve() {	
	int ans = -1;
	for (int i = 0; i < n; ++i) {
		int res = solveOne(i);
		if(ans == -1 || res < ans) ans = res;
	}
	printf("%d\n", ans);
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}