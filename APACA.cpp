/* Code Jam Template */
#include <bits/stdc++.h>
using namespace std;
#define MOD 					1000000007
#define pb(x) 					push_back(x)
#define mp(x,y)                 make_pair(x,y)
#define FF 						first
#define SS 						second
#define s(n) 					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define ss(n) 					scanf("%s",n)
//special macro for reading a character of input
#define sc(n)                   {char temp[4]; ss(temp); n=temp[0];}
#define INF						(int)1e9
#define LINF					(long long)1e18
#define EPS						1e-9
/*
Use these macros when comparing variables of different data types.
For e.g. comparing int and long long will give error when used with std::max, use maX instead.
*/
#define maX(a,b)				((a)>(b)?(a):(b))
#define miN(a,b)				((a)<(b)?(a):(b))
#define abS(x)					((x)<0?-(x):(x))
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

/*Main code begins now*/
int n, m;
ll C[101][101];
ll power(ll base, ll exponent, ll mod) {
    ll res = 1, k = base;
    if (k == 1) return 1 % mod;
    for (ll p = exponent; p > 0; p >>= 1) {
        if ((p & 1) == 1) res = (res * k) % mod;
        k = (k * k) % mod;
    }
    return res % mod;
}
void precompute(int n, ll module) {
    for (int i = 0; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            if (C[i][j] >= module)
                C[i][j] -= module;
        }
    }
}
void read() {
    s(n);
    s(m);
}
void solve() {
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += (C[m][i] * power(m - i, n, MOD) )% mod; 
        if(ans >= MOD) ans -= MOD;
    }
    printf("%lld\n", ans);
}
/*
This main function will remain same in all implementations.
Make sure that input file is present in same directory and if changing the filename(s), don't forget to include extensions(.in) as well.
*/
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	precompute(100, MOD);
	int t;
	s(t);
	for(int T = 1; T <= t; T++) {
	    read();
	    printf("Case #%d: ",T);
        solve();
  	}
	return 0;
}