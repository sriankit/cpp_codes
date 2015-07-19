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

int n, strt;
map<int, int> one;
map<int, set<int> > ma;
void precompute() {
	
}
void read() {
	s(n);
	if(n == 0) exit(0);
	ma.clear();
	one.clear();
	for (int i = 0; i < n; ++i) {
		int x;
		s(x);
		int d = x - 2;
		int dif = 1;
		for (ll num = 0; num + dif < (long long) 1e10; dif += d) {
			num = num + dif;
			if(one.count(num)) {
				if(ma.count(num) == 0) {
					ma[num] = set<int>();
					ma[num].insert(one[num]);
				}
				ma[num].insert(x);
			} else one[num] = x;
		}
	}
	s(strt);
}
void preprocess() {
	
}
void solve() {
	int j = 5;
	for (std::map<int, set<int> >::iterator it = ma.lower_bound(strt); it != ma.end() and j --; ++it) {
		pair<int, set<int> > entry = *it;
		printf("%d: ", entry.FF);
		for (std::set<int>::iterator i = entry.SS.begin(); i != entry.SS.end(); ++i) {
			printf("%d ", *i);	
		}
		printf("\n");
	}
}
int main() {
	precompute();
	while(1) {
		read();
		preprocess();
		solve();
	}
	return 0;
}