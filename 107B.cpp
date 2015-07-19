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

int n, m, k;
void precompute() {
	
}
void read() {
	s(n), s(m), s(k);
}
int power(int base, int ex) {
	ll ans = 1;
	for (int i = 0; i < ex; ++i) {
		ans *= base;
		if(ans >= MOD) ans %= MOD;
	}
	return ans;
}
void preprocess() {
	
}
void solve() {
	if(k > n) cout << 0;
	if(k == 1) {
		cout << power(m, n);
		return;
	}
	if(k % 2 == 0) cout << m;
	else {
		cout << (m + 1LL * m * (m - 1))% MOD << endl;
	}
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}