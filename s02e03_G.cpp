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
char a[55][55];
int p[55][55];
void precompute() {
	
}
void read() {
	s(m), s(n);	
	for (int i = 0; i < n; ++i) {
		ss(a[i]);
	}
}
void preprocess() {
	
}
int go(int x, int y) {
	if(x < 0 or x >= n or y >= m or y < 0) return 0; 
	if(a[x][y] == 'T' || a[x][y] == '#') return 0;
	p[x][y] = 1;
	int res = 0;
	int dx[4] = {-1, 0, 0, 1};
	int dy[4] = {0, -1, 1, 0};
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(p[nx][ny] == 0) res = max(res, go(nx, ny));
	}
	return res + (a[x][y] == 'G');
}
void solve() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if(a[i][j] == 'P') cout << go(i, j);			
		}	
	}/*	
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if(p[i][j] and a[i][j] == 'G') 
				ans++;
		}
	}
	printf("%d\n", ans);*/
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}