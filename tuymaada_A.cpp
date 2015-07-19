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
vector<int> pr;
void precompute() {
	int sieve[201];
	memset(sieve, 0, sizeof sieve);
	sieve[0] = sieve[1] = 1;
	for (int i = 0; i < 201; ++i) {
		if(sieve[i] == 0) {
			pr.push_back(i);
			for (int j = i + i; j < 201; j += i) {
				sieve[j] = 1;
			}
		}
	}
}
void read() {
	sl(n);
}
void preprocess() {
	
}
pair<ll, ll> go(ll num, int i, int pw) {
	int p = pr[i];
	ll e = p;
	pair<ll, ll> mxa = make_pair(1, 1);
	for (int pwr = 1; e <= num and pwr <= pw; ++pwr) {
		pair<ll, ll> res = go(num / e, i + 1, pwr);
		res.SS *= (pwr + 1);
		res.FF *= e;
		if(res.SS > mxa.SS) {
			mxa = res;			
		} else if(res.SS == mxa.SS && res.FF < mxa.FF) {
			mxa = res;
		}		
		e *= p;
	}
	//cout << num << " " << i << " " << mxa.FF << " " << mxa.SS << endl;  
	return mxa;
}
void solve() {
	pair<ll, ll> ans = go(n, 0, 60);
	printf("%lld\n", ans.FF);
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}