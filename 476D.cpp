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
void precompute() {
	
}
void read() {
	s(n), s(k);
}
void preprocess() {
	
}
void solve() {
	vector<vector<int> > v;
	vector<int> temp;
	int i;
	for (i = 1; ; i+=2) {
		temp.push_back(i);
		if(temp.size() == 3) {
			temp.push_back(i - 1);
			v.push_back(temp);
			temp.clear();
		}
		if(v.size() == n) break;
	}
	printf("%d\n", i * k);
	for (std::vector<vector<int> >::iterator it = v.begin(); it != v.end(); ++it) {
		for (std::vector<int>::iterator i = (*it).begin(); i != (*it).end(); ++i) {
			printf("%d ", (*i) * k);
		}
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