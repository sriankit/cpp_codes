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
int TEST_NO;
int a, b;
ll dp1[2002][2002], dp2[2002][2002];

void precompute() {
	
}
void read() {
	scanf("%d-%d", &a, &b);
}
void preprocess() {
	
}

inline void upd(ll &a, ll inc) {
	a += inc;
	if(a >= MOD) a-= MOD;
}

ll go_free(int p1, int p2) {
	if(p1 == a and p2 == b) return 1;
	if(dp1[p1][p2] == -1) {		
		dp1[p1][p2] = 0;
		if(p1 + 1 <= a and p1 + 1 > p2) upd(dp1[p1][p2], go_free(p1 + 1, p2));
		if(p2 + 1 <= b and p1 > p2 + 1) upd(dp1[p1][p2], go_free(p1, p2 + 1));
	}
	return dp1[p1][p2];
}

ll go_ful(int p1, int p2) {
	if(p2 == b) return 1;
	if(dp2[p1][p2] == -1) {		
		dp2[p1][p2] = 0;
		if(p1 + 1 <= a and p1 + 1 <= p2) upd(dp2[p1][p2], go_ful(p1 + 1, p2));
		if(p2 + 1 <= b and p1 <= p2 + 1) upd(dp2[p1][p2], go_ful(p1, p2 + 1));
	}
	return dp2[p1][p2];	
}

void solve() {
	memset(dp1, -1, sizeof dp1);
	memset(dp2, -1, sizeof dp2);
	printf("Case #%d: %lld %lld\n", TEST_NO, go_free(0, 0), go_ful(0, 0));
}
int main() {
	freopen("input2.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
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