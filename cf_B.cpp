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

int p, q;
int TEST_NO;
void precompute() {
	
}
void read() {
	s(p), s(q);
}
void preprocess() {
	
}
void printAns(int i, int ai) {
	printf("%d ", ai);
	for (int j = 0; j < i - 1; ++j)
	{
		printf("%d ", 0);
	}
	printf("%d\n", p - ai);
}
void solveCrux() {
	int d = q - p;
	ll ex = p;
	int cnt = 0, ind = 0, ais = 0;
	for (int i = 1; i < 32; ++i) {
		int den = ex - 1;
		if(d % den == 0)  {
			int ai = (d / den);
			if(p - ai > 0) {
				cnt ++;
				ind = i;
				ais = ai;
			}
 		}
 		ex *= p;
	}
	if(cnt == 0) puts("IMPOSSIBLE");
	else if(cnt == 1) printAns(ind, ais);
	else puts("AMBIGUOUS");
}
void solve() {
	if(q < p) puts("IMPOSSIBLE");
	else if(q == p) {
		printf("%d\n", p);
	}
	else if(p <= 1) puts("IMPOSSIBLE");
	else {
		solveCrux();
	}
	
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