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
#define FILE 0
int TEST_NO;
#define MAXN 104
int mat[103][103];
int wt[103], off[103];
void precompute() {
	
}
void read() {
	for (int i = 0; i < 103; ++i) {
		for (int j = 0; j < 103; ++j) {
			mat[i][j] = 100005;	
		}		
		mat[i][i] = 0;		
	}
	s(n);
	memset(wt, 0, sizeof wt);
	memset(off, 0, sizeof off);
	for (int i = 0; i < n; ++i) {
		int num, w;
		s(num), s(w);
		wt[i] = w;		
		int v;
		v = off[i];
		off[i + 1] = off[i] + num;
		for (int j = 0; j < num - 1; ++j) {
			int tym;
			s(tym);
			mat[v + j][v + j + 1] = tym;
			mat[v + j + 1][v + j] = tym;
		}
	}
	int m;
	s(m);
	for (int i = 0; i < m; ++i) {
		int m1, s1, m2, s2, tym;
		scanf("%d%d%d%d%d", &m1, &s1, &m2, &s2, &tym);
		--m1, --s1, --m2, --s2;
		int u = off[m1] + s1;
		int v = off[m2] + s2;
		mat[u][v] = tym + wt[m1];
		mat[v][u] = tym + wt[m2];
	}
}
void preprocess() {
	int num = off[n];
	for (int k = 0; k < num; ++k) {
		for (int i = 0; i < num; ++i) {
			for (int j = 0; j < num; ++j) {
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			}
		}
	}
}
void solve() {
	int num = off[n];
	/*for (int i = 0; i < num; ++i) {
		cerr << "dbg ";
		for (int j = 0; j < num; ++j) {
			printf("%d ", mat[i][j]);
		}
		putchar('\n');
	}
	*/
	printf("Case #%d: ", TEST_NO);
	int q;
	s(q);
	while(q--) {
		int m1, s1, m2, s2;
		scanf("%d%d%d%d", &m1, &s1, &m2, &s2);
		--m1, --s1, --m2, --s2;
		int u = off[m1] + s1;
		int v = off[m2] + s2;
		int res = mat[u][v] + wt[m1];
		int tun = 1;
		for (int i = off[m2]; i < off[m2 + 1]; ++i) {
			int dis = mat[u][i] + mat[i][v];
			if(dis == res) tun = 0;
		}
		if(tun) cout << res - wt[m2] << endl;
		else cout << res << endl;
	}	
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