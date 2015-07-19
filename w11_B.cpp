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

ll l, r;
int TEST_NO;
set<ll> strange;
int findLen(ll x) {
	int len = 0;
	while(x) {
		x /= 10;
		len ++;		
	}
	return len;
}
void precompute() {
	for (int i = 0; i < 10; ++i) {
		strange.insert(i);
	}
	for (std::set<ll>::iterator it = strange.begin(); it != strange.end(); ++it) {
		for (int len = 2; len <= 19; ++len) {
			ll num = *it;
			ll x = num * len;
			if(x < 0) continue;
				if(findLen(x) == len) strange.insert(x);
		}
	}
}
void read() {
	sl(l), sl(r);
}
void preprocess() {
	
}
void solve() {
	int cnt = 0;
	for (std::set<ll>::iterator it = strange.begin(); it != strange.end(); ++it) {
		if(*it >= l and *it <= r) cnt ++;
	}
	cout << cnt << endl;
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