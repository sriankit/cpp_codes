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
string s;
int TEST_NO;
void precompute() {
	
}
void read() {
	cin >> s;
}
void preprocess() {
	
}
void solve() {
	int ma[4];
	memset(ma, 0, sizeof ma);
	for (int i = 0; i < s.size(); ++i) {
		char c = s[i];
		switch (c) {
			case 'C':
				ma[0]++;
				break;
			case 'H':
				if(ma[0] > 0) {
					ma[0] --;
					ma[1] ++;
				}
				break;
			case 'E':
				if(ma[1] > 0) {
					ma[1] --;
					ma[2] ++;
				}
				break;
			case 'F':
				if(ma[2] > 0) {
					ma[2] --;
					ma[3] ++;					
				}
		}
	}
	printf("%d\n", ma[3]);
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