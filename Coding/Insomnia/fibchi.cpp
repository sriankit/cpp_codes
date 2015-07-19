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
int fib[50];
int tot = 0;
int dp[100005];

void precompute() {
	fib[0] = 1;
	fib[1] = 1;
	int i = 2;
	do{
		int next = fib[i - 1] + fib[i - 2];
		if(next > 1e5) break;
		fib[i] = next;
		i++;
	} while(1);
	tot = i + 1;
	memset(dp, 0, sizeof dp);	
	for (int i = 1; i <= 100005; ++i) {
		for (int j = 0; j < tot; ++j) {			
			if(i >= fib[j]) {
				if(dp[i] == 0 or dp[i] > 1 + dp[i - fib[j]]) dp[i] = 1 + dp[i - fib[j]];
			} else break;
		}
	}	
}

int TEST_NO;

void read() {
	s(n);	
}
void preprocess() {
	
}
void solve() {
	if(n == 0) puts("1");	
	else printf("%d\n", dp[n]);
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