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

ll n;
int c;
int a[20];
ll dp[20][3][201];
int len;

void precompute() {
	
}
void read() {
	sl(n);
	s(c);
}
void preprocess() {
	ll res = n;
	len = 0;
	while(res) {
		a[len] = res % 10;
		res /= 10;
		len++;
	}
}

ll go(int i, int mod, int rem) {
	//cerr << i << " " << mod << " " << rem << endl;	
	assert(rem >= 0);
	if(i == len) {
		if(mod == 0) return 1;
		else return 0;
	}
	if(dp[i][mod][rem] != -1) return dp[i][mod][rem];		
	ll ret = 0;	
	for (int ch = 1; ch <= rem and ch <= 10; ++ch) {
		for (int d = -1; d < 2; d += 2) {
			int dig = a[i] + d * ch;
			if(i == len - 1 and dig == 0) continue;					
			ret += go(i + 1, (mod + dig) % 3, rem - ch);					
		}
	}	
	ret += go(i + 1, (mod + a[i]) % 3, rem);
	return dp[i][mod][rem] = ret;
}

void solve() {
	memset(dp, -1, sizeof dp);
	//cerr << len << endl;
	cerr << " solve ";
	printf("%lld\n", go(0, 0, c));
}

int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}