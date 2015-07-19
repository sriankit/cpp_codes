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
ll k;
int a[55];


void precompute() {
	
}
void read() {
	s(n);
	sl(k);
}
void preprocess() {
	
}

void go(int lo, int hi, int trm) {
	//cerr << lo << hi << trm << endl;
	if(lo > hi) return;
	if(1LL << (hi - lo - 1) >= k) {		
		a[lo] = trm;
		go(lo + 1, hi, trm + 1);
	}
	else {
		k -= 1LL << (hi - lo - 1);
		a[hi] = trm;
		go(lo, hi - 1, trm + 1);
	}
}

void solve() {	
	go(0, n - 1, 1);
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}