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

int n[3];
int TEST_NO;
int a[3][100005];
void precompute() {
	
}
void read() {
	memset(a, 0, sizeof a);
	for (int i = 0; i < 3; ++i) {
		s(n[i]);
		for (int j = 1; j <= n[i]; ++j) {
			s(a[i][j]);
		}
	}
}
void preprocess() {
	
}

ll get0(int x) {
	int lo = 1, hi = min(x, n[0]) , q = 0;
	while(lo <= hi) {
		int mid = lo + hi >> 1;
		if(a[0][mid] <= a[1][x]) {
			q += mid - lo + 1;
			lo = mid + 1;
		} else hi = mid - 1;
	}
	return q;
}

ll get2(int x) {
	int lo = x, hi = n[2], q = 0;
	while(lo <= hi) {
		int mid = lo + hi >> 1;
		if(a[2][mid] >= a[1][x]) {
			q += hi - mid + 1;
			hi = mid - 1;
		} else lo = mid + 1;
	}
	return q;
}

void solve() {
	ll ans = 0;
	for (int p1 = 1; p1 <= n[1]; ++p1) {
		ans += get0(p1) * get2(p1);
		//cerr << p0 << " " << p1 << " " << p2 << endl; 
	} 
	printf("%lld\n", ans);
}
int main() {
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