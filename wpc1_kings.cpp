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

int n, e, good;
int adj[202][202];
int goods[12];
int d[202][202];
int gd[12][12];
map<pair<int, int>, int> dp;
void precompute() {
	
}
void read() {
	s(n), s(e), s(good);
	memset(adj, -1, sizeof adj);
	for (int i = 0; i < e; ++i) {
		int u, v, w;
		s(u);
		s(v);
		s(w);
		--u, --v;
		adj[u][v] = w;
		adj[v][u] = w;
	}
	for (int i = 0; i < good; ++i) {
		s(goods[i]);
		--goods[i];
	}
	for (int i = 0; i < n; ++i) {
		adj[i][i] = 0;
	}
}

void preprocess() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			d[i][j] = adj[i][j];
			if(d[i][j] == -1) d[i][j] = 100000000;
		}
	}
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				d[i][j]	= min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	for (int i = 0; i < good; ++i) {
		for (int j = 0; j < good; ++j) {
			gd[i][j] = d[goods[i]][goods[j]];
			assert(gd[i][j] < 100000000);
		}
	}
}
vector<int> ext_ones(int mask) {
	vector<int> res;
	int j = 0;
	while(mask and j < good) {
		if(mask & 1) {
			res.push_back(j);
		}
		mask >>= 1;
		j++;
	}
	return res;
}
int go(pair<int, int> m) {
	vector<int> avl = ext_ones(~(m.FF | m.SS));
	int ply = good - avl.size();
	int player = (ply + 1) & 1;
	if(ply == good) {
		int cost = 0;
		std::vector<int> v0 = ext_ones(m.first);
		std::vector<int> v1 = ext_ones(m.second);
		for (std::vector<int>::iterator it = v0.begin(); it != v0.end(); ++it) {
			for (std::vector<int>::iterator it1 = v1.begin(); it1 != v1.end(); ++it1) {
				cost += gd[*it][*it1];
			}
		}
		return cost;
	}
	if(dp.count(m) == 0) {			
		int ans = -1;
		for (std::vector<int>::iterator it = avl.begin(); it != avl.end(); ++it) {
			player ? m.FF |= (1 << *it) : (m.SS |= (1 << *it));
			int cost = go(m);
			if(ans == -1 || (player == 0 and cost < ans) || (player == 1 and cost > ans)) 
				ans = cost;
			player ? m.FF ^= (1 << *it) : (m.SS ^= (1 << *it));
		}
		dp[m] = ans;
	}
	return dp[m];
}
void solve() {	
	cout << go(make_pair(0, 0));
	
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}