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
int a[100005];
vector<int> pr[1000006];
int TEST_NO;
void precompute() {
	for (int i = 2; i < 1000006; ++i) {
		if(pr[i].size() == 0) {
			for (int j = i; j < 1000006; j += i) {
				pr[j].push_back(i);
			}
		}	
	}
}
void read() {
	s(n);
	for (int i = 0; i < n; ++i) {
		s(a[i]);		
	}	
}
void preprocess() {
	int ans = 0;
	map<int, int> maxe;
	for (int i = 0; i < n; ++i) {
	 	int x = a[i];
	 	for (std::vector<int>::iterator dt = pr[x].begin(); x > 1 and dt != pr[x].end(); ++dt) {
	 		int ct = 0;
	 		int dv = *dt;
	 		while(x % dv == 0) {
	 			x /= dv;
	 			ct++;
	 		}
	 		if(maxe.count(dv) == 0 || maxe[dv] < ct) maxe[dv] = ct;
	 	}
	}
	for (std::map<int, int>::iterator it = maxe.begin(); it != maxe.end(); ++it) {
		ans += it -> SS;
	}
	printf("%d\n", ans);
}
void solve() {
	
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