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

int n, pat;
char s[2002];
char p[502];
int a[2002];
int dp[2002][2002];
void precompute() {
}
void read() {
	ss(s);
	ss(p);
	n = strlen(s);
	pat = strlen(p);	
}

void dbgArr(int arr[], int len) {
	for (int i = 0; i < len; ++i) {
		if(i > 0) putchar(' ');
		printf("%d", arr[i]);
	}
	putchar('\n');
}

void dbgArr2D(int arr[][1002], int len) {
	for (int i = 0; i < len; ++i) {
		dbgArr(arr[i], n);
	}
}

void preprocess() {
	for (int i = 0; i < n; ++i) {
		int j = 0;
		int del = 0;
		while(i + j + del < n) {
			if(s[i + j + del] == p[j]) j++;
			else del ++;
			if(j == pat) break;
		}
		if(j == pat) a[i] = del;
		else a[i] = -1;
	}	
}
void solve() {
	for (int i = 0; i < n; ++i) {
		for (int del = 0; del <= i; ++del) {
			dp[i + 1][del] = max(dp[i + 1][del], dp[i][del]);
			//wasteful deletion
			dp[i + 1][del + 1] = max(dp[i + 1][del + 1], dp[i][del]);
			if(a[i] != -1 and del + a[i] <= n) {
				int &val = dp[i + a[i] + pat][del + a[i]];
				val = max(val, dp[i][del] + 1);
			}
		}
	}	
	//dbgArr2D(dp, n);
	for (int i = 0; i <= n; ++i) {
		if(i > 0) putchar(' ');
		printf("%d", dp[n][i]);
	}
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}