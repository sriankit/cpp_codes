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
vector<int> adj[50];
PII l[50];
int mark[50];

void precompute() {
	
}
void read() {
	s(n);
	s(m);
	for (int i = 0; i < m; ++i) {
		int h1, h2, m1, m2;
		scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
		int p1 = m1 + h1 * 60;
		int p2 = m2 + h2 * 60;
		if(p2 <= p1) p2 += 12 * 60;
		l[i] = make_pair(p2, p1);
	}	
}
void preprocess() {
	sort(l, l + m);	
}
void solve() {
	memset(mark, 0, sizeof mark);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int en = -1;
		for (int j = 0; j < m; ++j) {
			if(mark[j]) continue;
			if(en <= l[j].SS) {
				ans ++;
				en = l[j].FF;
				mark[j] = 1;
			}
		}
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