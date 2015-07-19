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
int a[1001][1001];
int dwn[1001][1001];
int TEST_NO;
void precompute() {
	
}
void read() {
	s(n);
	for (int i = 0; i < n; ++i)
	{
		char s[1001];
		scanf("%s", s);
		for (int j = 0; j < n; ++j)
		{
			a[i][j] = s[j] == '.';
		}
	}
}
void preprocess() {
	memset(dwn, 0, sizeof dwn);
	for (int j = 0; j < n; ++j) {
		dwn[n - 1][j] = a[n - 1][j];
		for (int i = n - 2; i >= 0; --i) {
			if(dwn[i + 1][j] == 1 && a[i][j] == 1) 
				dwn[i][j] = 1;	
		}
	}
}
void solve() {
	int ans = 0;
	for (int i = 0; i < n; ++i) {	
		for (int j = n - 1; j >= 0; --j) {
			if(a[i][j] == 1 && dwn[i][j]) ans++;
			if(a[i][j] == 0) break;			
		}
	}
	printf("%d\n", ans);
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