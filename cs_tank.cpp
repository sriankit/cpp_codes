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

int n, q;
int a[51];
int dp[10000007];
void precompute() {
	
}
void read() {
	s(n);
	s(q);
	for (int i = 0; i < n; ++i) {
		s(a[i]);
	}	
}
void preprocess() {
	dp[0] = 1;
	for (int i = 1; i < 10000007; ++i) {		
		dp[i] = 0;
		for (int bkt = 0; bkt < n; ++bkt) {
			if(i - a[bkt] >= 0 and dp[i - a[bkt]] == 1) dp[i] = 1; 
		}
	}
}
int check(int num) {
	for (int i = 0; i < n; ++i) {
		if(dp[num + a[i]]) return 1;
	}
	return 0;
}
void solve() {
	while(q--) {
		int sz;
		s(sz);
		int f = 0;
		if(sz < 10000007) {
			f = dp[sz];
		}
		else {
			for (int i = 0; i < n; ++i) {
				int cap = sz % a[i];

				if(check(cap)) {
					f = 1;
					break;
				}
			}
		}
		if(f) puts("yes");
		else puts("no");
	}	 	
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}