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
int mines;
int TEST_NO;
int grid[303][303], avl[303][303], vis[303][303];
int dx[] = {-1, 0, 1};
int dy[] = {-1, 0, 1};
void precompute() {
	
}
void read() {	
	memset(avl, 0, sizeof avl);
	memset(vis, 0, sizeof vis);
	s(n);
	for (int i = 0; i < n; ++i) {
		char str[303];
		ss(str);
		for (int j = 0; j < n; ++j) {
			grid[i][j] = str[j] == '*';
			mines += grid[i][j];
			vis[i][j] = grid[i][j];
		} 
	}
}
bool bound(int i, int j) {
	return i >= 0 and i < n and j >= 0 and j < n;
}
int check_ngh(int i, int j) {
	//cerr << i << " " << j << endl;
	for (int x = 0; x < 3; ++x) {
		for (int y = 0; y < 3; ++y) {
			int ni = dx[x] + i, nj = dy[y] + j;
			if(bound(ni, nj) and grid[ni][nj] == 1) {
				//cerr << " f " << ni << " " << nj << endl;						
				return 0; 
			}
		}
	}
	return 1;
}
void preprocess() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int res = check_ngh(i, j);
			if(res) avl[i][j] = 1;
		}
	}
}
void dfs(int i, int j) {
	vis[i][j] = 1;
	if(avl[i][j] == 0) return;
	for (int x = 0; x < 3; ++x) {
		for (int y = 0; y < 3; ++y) {
			int ni = dx[x] + i, nj = dy[y] + j;
			if(bound(ni, nj) and vis[ni][nj] == 0) 
				dfs(ni, nj);
		}
	}
}
void solve() {
	printf("Case #%d: ", TEST_NO);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			//cerr << avl[i][j] << " ";
			if(avl[i][j] and !vis[i][j]) {
				dfs(i, j);
				ans++;
			}
		}
		//cerr << '\n';
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if(!vis[i][j]) ans++;
		}
	}
	printf("%d\n", ans);
}
int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
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