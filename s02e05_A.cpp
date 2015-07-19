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
int a[105][105];
bool seen[105][105];
string s;
void precompute() {
	
}
void read() {
	s(n);
	s(m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%1d", &a[i][j]);
		}
	}
	cin >> s;
}
void preprocess() {
	
}
int get(int i, int j) {
	if(seen[i][j]) return a[i][j] / 2;
	seen[i][j] = true;
	return a[i][j];
}
int trav(int i, int j, int ni, int nj) {
	if(ni == i) {
		j = min(j, nj);
		return get(i, j) + get(i - 1, j);
	}
	else {
		i = min(i, ni);
		return get(i, j) + get(i, j - 1);
	}
}
void solve() {
	int dx[] = {0, 1, 0, -1};
	int dy[] = {1, 0, -1, 0};
	int state = 0;
	int ans = 0;
	int i = 1, j = 1;
	for (int idx = 0; idx < s.size(); ++idx) {
		char op = s[idx];
		if(op == 'M') {
			int ni = i + dx[state];
			int nj = j + dy[state];
			ans += trav(i, j, ni, nj);
			i = ni;
			j = nj;
		} else if(op == 'L') state = (state + 3) % 4;
		else state = (state + 1) % 4;
	}
	cout << ans;
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}