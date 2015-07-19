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

int n, m, h;
int tot, x;
void precompute() {
	
}
void read() {
	s(n), s(m), s(h);
	--h;
	for (int i = 0; i < m; ++i) {
		int num;
		s(num);
		if(i == h) x = num;
		tot += num;
	}
}
void preprocess() {
	
}
void solve() {
	if(tot < n) {
		cout << -1;
		return;
	}
	if(n == 1) {
		cout << 0;
		return;
	}
	double ans = tot - x;
	int p1 = 1, p2 = 1;
	while(p1 <= n - 2 and p2 <= n - 1) {
		ans *= (tot - x - p1);
		p1++;
		if(ans > (tot - p2)) {
			ans /= (tot - p2);
			p2++;
		}
		//cerr << ans << '\n';
	}
	while(p1 <= n - 2) {
		ans *= (tot - x - p1);
		p1++;
	}
	while(p2 <= n - 1) {
		ans /= (tot - p2);
		p2 ++;
	}
	cout << 1 - ans;
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}