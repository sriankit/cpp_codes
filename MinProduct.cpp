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
int a[20004];
int TEST_NO;
map<int, vector<int> > ma;
void precompute() {
	
}
void read() {	
	s(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
}
void preprocess() {
	ma.clear();
}
void populate(int num) {
	for (int i = 2; i <= num / i && num > 1; ++i) {
		if(num % i == 0) {
			int pw = 0;
			while(num % i == 0) {
				pw++;
				num /= i;
			}
			ma[i].push_back(pw);
		}
	}
	if(num > 1) ma[num].push_back(1);
}
int solveInstance(vector<int> vec) {
	priority_queue<int> pq(vec.begin(), vec.end());
	while(pq.size() > 1) {
		int l1 = pq.top();
		pq.pop();
		int l2 = pq.top();
		pq.pop();
		if(l1 > 1) pq.push(l1 - 1);
		if(l2 > 1) pq.push(l2 - 1);
	}
	if(pq.empty()) return 0;
	return pq.top();
}
ll pwr(int base, int expo) {
	ll ret = 1;
	for (int i = 0; i < expo; ++i) {
		ret *= base;
		if(ret >= MOD) ret %= MOD;
	}
	return ret;
}
void solve() { 
	for (int i = 0; i < n; ++i) {
		int num = a[i];
		populate(num);
	}
	ll ans = 1;
	for (std::map<int, vector<int> >::iterator it = ma.begin(); it != ma.end(); ++it) {
		int rem = solveInstance(it->SS);
		ans *= pwr(it->FF, rem);
		if(ans >= MOD) ans %= MOD;
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