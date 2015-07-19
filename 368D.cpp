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

int n, m, p;
int a[200005];
LL bhash = 0;
LL BASE = 1000000007;
LL pw[200005];
set<int> sols;
void precompute() {
	
}
void read() {
	s(n), s(m), s(p);
	for (int i = 0; i < n; ++i) {
		s(a[i]);		
	}
	for (int i = 0; i < m; ++i) {
		int x;
		s(x);
		bhash = (bhash * BASE) + x;
	}
}
void preprocess() {
	pw[0] = 1;
	for (int i = 0; i < 200005; ++i) {
		pw[i] = pw[i - 1] * BASE;
	}
}
void chkSol(int q) {
	LL hash = 0;
	for (int i = 0; i * p < n; ++i)
	{
		int idx = i * p;
		hash = (hash * BASE) + a[idx];
		if(i >= m - 1) {
			int start = i - (m - 1);
			if(hash == bhash) {
				sols.insert(start);				
			}
			hash -= a[start] * pw[m];
		}
	}	
}
void solve() {
	for (int i = 0; i < p; ++i) {
		chkSol(i);
	}
	printf("%d\n", (int)sols.size());
	for (std::set<int>::iterator it = sols.begin(); it != sols.end(); ++it) {	
		printf("%d ", *it + 1);
	}
}
int main() 
{
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}