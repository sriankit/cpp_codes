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

ll a, b, c;
map<ll, int> ind;
void precompute() {
	
}
void read() {
	sl(a);
	sl(b);
	sl(c);
	a %= c;
}
void preprocess() {
	
}
void solve() {
	ll last = 1;
	ind[1] = 0;
	int fr = -1, ans = -1;
	for (int i = 1; i < 2e7; ++i) {
		ll num = (a * last + last % b) % c;
		if(ind.count(num)) {
			int idx = ind[num];
			if(fr == -1 || idx < fr) {
				fr = idx;
				ans = i;
			}
		} else ind[num] = i;
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