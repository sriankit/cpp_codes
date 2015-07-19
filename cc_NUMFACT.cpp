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
int a[11];
map<int,int> cnt;
int TEST_NO;
void precompute() {
	
}
void read() {
	s(n);
	for (int i = 0; i < n; ++i)
	{
		s(a[i]);
	}
}
void preprocess() {
	cnt.clear();
}
void populate(int num) {
	for (int i = 2; i <= num / i && num > 1; ++i) {
		while(num % i == 0) {
			cnt[i] ++;
			num /= i;
		}
	}
	if(num > 1) cnt[num] ++;
}
void solve() {
	for (int i = 0; i < n; ++i) {
		int num = a[i];
		populate(num);
	}
	ll ans = 1;
	for (std::map<int, int>::iterator it = cnt.begin(); it != cnt.end(); ++it) {
		ans *= (it->SS) + 1;
	}
	printf("%lld\n", ans);
}
int main() {
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