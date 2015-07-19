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
int a[1000006];
int gud = 0;
void precompute() {
	
}
void read() {
	s(n);
	for (int i = 0; i < n; ++i) {
		int x;
		s(x);
		a[i] = x;
	}
}
void preprocess() {
	
}
void solve() {
	int gud = 0, swap = 0;
	for (int i = 0; i < n; ++i) {
		int to = i;
		if(a[i] == i) gud++;
		else if(a[a[i]] == i) swap++;
	}
	if(gud == n) printf("%d\n", gud - 2);
	else if(swap > 0) printf("%d\n", gud + 2);
	else printf("%d\n", gud + 1);
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}