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
void solve() {
	ll pr[50];
	int cnt = 0;
	ll ln = n;
	for (int i = 2; i <= n / i; ++i) {
		if(n % i == 0) {
			int p = 0;
			while(n % i == 0) {
				n /= i;
				p++;
			}
			if(p > 2) {
				printf("1\n%d\n", i * i);
				return;
			}
			else {
				while(p > 0) {
					pr[cnt++] = i;
					p --;
				}
			}
		}
		if(cnt >= 3) {
			printf("1\n%lld\n", pr[0] * pr[1]);
			return;
		}
	}
	if(ln == n) puts("1\n0");
	else {
		if(n > 1) {
			if(cnt == 2) printf("1\n%lld\n", pr[0] * pr[1]);
			else puts("2");
		} else puts("2");
	}
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}