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
char s[1000006];
ll cnt[1000006];

void precompute() {
	
}
void read() {
	s[0] = ' ';
	ss(s + 1);
	n = strlen(s);
	//cerr << n << endl;
}
void preprocess() {
	cnt[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cnt[i] = cnt[i - 1] + (s[i] == 'L');
	}
}
/*
ll go(int i, int state) {
	if(state == 3) return 1;
	if(i == n) return 0;
	ll &ret = dp[i][state];
	if(ret == -1) {
		int ns = 0;
		if(state == 0 and s[i] == 'L') ns = 1;
		else if(state == 1 and s[i] == 'O') ns = 2;
		else if(state == 1 and s[i] == 'L') ns = 1;
		else if(state == 1) ns = 0;
		else if(state == 2 and s[i] == 'L') ns = 3;
		else if(state == 2) ns = 0;
		else if(state == 3 and s[i] == 'L') ns = 1;
		else if(state == 3 and s[i] == 'O') ns = 2;
		else if(state == 3) ns = 0;
		ret = go(i + 1, state) + go(i + 1, ns);
	}
	return ret;
} 
*/
void solve() {
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {		
		if(s[i] == 'O') ans += cnt[i - 1] * (cnt[n] - cnt[i]);
	}
	printf("%lld\n", ans);
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