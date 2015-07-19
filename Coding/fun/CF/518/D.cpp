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

int n, tym;
long double dp[2003][2003];
bool done[2003][2003];

double p;

long double go(int togo, int t) {
	if(t == 0 or togo == 0) return 0;
	if(!done[togo][t]) {
		done[togo][t] = true;
		dp[togo][t] = p * (1 + go(togo - 1, t - 1)) + (1 - p) * go(togo, t - 1);
	}
	return dp[togo][t];
}

void precompute() {
	
}
void read() {
	cin >> n >> p >> tym;
}
void preprocess() {
	
}
void solve() {
	cout << go(n, tym);
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}