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
int adj[102][102][102];

void precompute() {
	
}
void read() {
	s(n), s(m);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		s(a), s(b), s(c);
		--a, --b, --c;
		adj[c][a][b] = 1;
		adj[c][b][a] = 1;
	}
}
void preprocess() {
	for (int c = 0; c < m; ++c) {
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if(adj[c][i][k] && adj[c][k][j]) adj[c][i][j] = 1;
				}
			}
		}
	}
}
void solve() {
	int q;
	s(q);
	while(q--) {
		int a, b;
		s(a), s(b);
		--a, --b;
		int res = 0;
		for (int c = 0; c < m; ++c) {
			res += adj[c][a][b];
		}
		printf("%d\n", res);
	}
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}