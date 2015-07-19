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
vector<int> avl;
int target;
void precompute() {
	
}
void read() {
	avl.clear();
	for (int i = 0; i < 10; ++i) {
		int x;
		s(x);
		if(x) avl.push_back(i);
	}
	s(target);
}
void preprocess() {
	
}
void solve() {
	printf("Case #%d: ", TEST_NO);
	queue<TRI> q;
	q.push(make_pair(0, make_pair(1, 0)));
	int ans = 0;
	while(!q.empty()) {
		TRI top = q.front();
		q.pop();
		int f = top.SS.FF, s = top.SS.SS, moves = top.FF;		
		cerr << f << " " << s << " " << moves << endl;
		system("pause");
		ll num = 1LL * top.SS.FF * top.SS.SS;
		if(num == target) {
			ans = top.FF;
			break;
		}
		if(num > target) continue;
		for (std::vector<int>::iterator it = avl.begin(); it != avl.end(); ++it) {
			int dig = *it;
			int f = top.SS.FF, s = top.SS.SS, moves = top.FF;		
			s = s * 10 + dig;
			ll num = 1LL * f * s;
			if(num > target || num == 0) continue;
			q.push(make_pair(moves + 1, make_pair(f, s)));
		}	
		if(f * s > 0) q.push(make_pair(moves + 1, make_pair(f * s, 0)));
	}
	if(ans == 0) puts("Impossible");
	else printf("%d\n", ans + 1);
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