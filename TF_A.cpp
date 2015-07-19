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
map<int, int> ma[5];
int sz[5];
void precompute() {
	
}
void read() {
	s(n);
	for (int i = 0; i < n; ++i) {
		char c;
		sc(c);
		int ind = c - 'A';
		int x;
		s(x);
		ma[ind][x] += 1;
		sz[ind]++;
	}
}
void preprocess() {
	
}
void solve() {
	for (int i = 0; i < 5; ++i) {
		int num = sz[i] / 10;
		int add = 0;
		for (std::map<int, int>::iterator it = ma[i].begin(); it != ma[i].end(); ++it) {
			if(it->SS > num) {
				add ++;
				printf("%d ", it->FF);
			}
		}
		if(add == 0) printf("Nothing Unusual");
		putchar('\n');
	}
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}