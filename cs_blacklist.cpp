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

int n, k;
int a[10][20];
ll dp[20][1024];
void precompute() {
	
}
void read() {
	s(n), s(k);
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < n; ++j) {
			s(a[i][j]);
		}
	}

}
void preprocess() {
	memset(dp, -1, sizeof dp);
}
ll go(int st, int mask) {
	if(st == n) return 0;
	ll &ret = dp[st][mask];
	if(ret == -1) {
		for (int merc = 0; merc < k; ++merc) {
			if((mask & (1 << merc)) == 0) {
				ll add = 0;
				for (int i = st; i < n; ++i) {
					add += a[merc][i];
					ll res = go(i + 1, mask | (1 << merc)) + add;
					if(ret == -1 || ret > res) {
						ret = res;
					}
				}
			}
		}
		if(ret == -1) ret = INF;
	}
	return ret;

}
void solve() {
	cout << go(0, 0);
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}