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
int TEST_NO;
int cost[3], qty[3];
int a[20][3];

void precompute() {
	
}
void read() {	
	for (int i = 0; i < 3; ++i) {
		s(cost[i]);
	}
	s(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			s(a[i][j]);
		}
	}
}
void preprocess() {
	
}

int get(int mask) {
	int j = 0;
	memset(qty, 0, sizeof qty);
	while(mask) {
		if(mask & 1) {
			for (int i = 0; i < 3; ++i) {
				qty[i] += a[j][i];
			}
		}
		mask >>= 1;
		j++;
	}
	for (int i = 0; i < 3; ++i) {
		if(qty[i] != cost[i]) return 0;	
	}
	return 1;
}

void solve() {
	string ans[2] = {"no", "yes"};
	int res = 0;
	for (int mask = 0; mask < 1 << n; ++mask) {
		res = get(mask);
		if(res) break;
	}
	cout << "Case " << "#" << TEST_NO << ": " << ans[res] << endl;
}
int main() {
	freopen("input2.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
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