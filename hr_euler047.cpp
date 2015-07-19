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

int n, k;
int dist[2000006];
int maxn = 2000006;
int TEST_NO;
void precompute() {
	
}
void read() {
	s(n),s(k);
}
void preprocess() {
	for (int i = 2; i < maxn; ++i) {
		if(dist[i] == 0) {
			for (int j = i; j < maxn; j += i) {
				dist[j] ++;
			}
		}
	}
    cerr << "done!";
}
void solve() {
	for (int i = 2; i <= n; ++i) {
		int p = 1;
		for (int j = 0; j < k; ++j) {
			if(dist[i + j] != k) p = 0;
		}
		if (p) printf("%d ", i);
	}
}
int main() {
	precompute();
	int t;
	t = 1;
	for(TEST_NO = 1; TEST_NO <= t; TEST_NO ++) {
		read();
		preprocess();
		solve();
	}
	return 0;
}