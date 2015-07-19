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

ll n;
void precompute() {
	
}
void read() {
	sl(n);
}
void preprocess() {
	
}
bool ok(ll num, ll parts) {
	return num >= (parts * (parts + 1) >> 1);	
}
void solve() {
	int ans = 0;
	for (int h = 1;; ++h) {
		ll sum = n + h;		
		if(sum % 3 != 0) continue;
		if(ok(sum / 3, h)) {
			ans ++;
		} else break;
	}
	printf("%d\n", ans);
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}