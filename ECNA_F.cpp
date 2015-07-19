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

int n, tt;
int TEST_NO;
int mov[52];
double dp[55][50];
bool ok[55][50];
void precompute() {
	
}
void read() {
	memset(mov, 0, sizeof mov);
	s(n);
	s(tt);
	for (int i = 1; i <= n; ++i) {
		string inp;
		cin >> inp;
		if(inp == "L") mov[i] = 2 * n;
		else mov[i] = atoi(inp.c_str());
		//printf("%d\n", mov[i]);;
	}
}
void preprocess() {
	memset(ok, false, sizeof ok);
}
double go(int i, int nt) {
	if(i > n) return 1.0;
	if(nt >= tt) return 0.0;
	double hp = .5, tp = .5;	
	if(!ok[i][nt]) {		
		int add = 0;
		if(mov[i + 1] == 2 * n) add = 1;
		int ni = i + 1 + (add ? 0 : mov[i + 1]);
		int nnt = nt + 1 + add;		
		dp[i][nt] = go(ni, nnt) * .5;	

		add = 0;
		if(mov[i + 2] == 2 * n) add = 1;
		ni = i + 2 + (add ? 0 : mov[i + 2]);
		nnt = nt + 1 + add;
		dp[i][nt] += go(ni, nnt) * .5;	

		ok[i][nt] = true;
	} 
	return dp[i][nt];
}
void solve() {
	double res = go(0, 0);
	if(abs(res - .5) <= EPS) puts("Push. 0.5000");
	else if(res > .5) printf("Bet for. %.4f\n", res);
	else printf("Bet against. %.4f\n", res);
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