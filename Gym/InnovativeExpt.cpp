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
int done = 0;
void precompute() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
void read() {
	sl(k);
}
void preprocess() {

}
void printCycle(int len, int start) {
	for (int i = 1; i < len; ++i) {
		printf("%d ", start	+ i);
	}
	printf("%d ", start);
}
void solve() {
	if(k == 1) {
		puts("1\n1");
		return;
	}
	int n = 0;
	vector<pair<int,int> > sol;
	int maxn = 100000;
	for (int i = 2; i <= maxn && k > 1; ++i) {
		if(k % i == 0) {
			int cy = 1;
			while(k % i == 0 && cy <= maxn) {
				cy *= i;
				k /= i;
			}
			sol.push_back(make_pair(cy, n + 1));
			n += cy;
			if(cy > maxn) break;			
		}
	}
	if(k == 1 && n <= maxn) {
		printf("%d\n", n);
		for (std::vector<pair<int,int> >::iterator it = sol.begin(); it != sol.end(); ++it) {
			printCycle(it->FF, it->SS);
		}
	} else puts("No solution");
}
int main() 
{
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}