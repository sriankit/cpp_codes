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
void precompute() {
	
}
void read() {
	char s[65];	
	while(1) {
		memset(s, 0, sizeof s);
		gets(s);		
		if(strcmp(s, "END") == 0) break;
		int cnt[26];
		memset(cnt, 0, sizeof cnt);		
		int f = 1;
		int ln = strlen(s);
		for (int i = 0; i < ln; ++i) {
			if(s[i] == ' ') continue;
			cnt[s[i] - 'A'] ++;
			if(cnt[s[i] - 'A'] == 2) 
				f = 0;	
		}
		if(f) puts(s);
	}
}
void preprocess() {
	
}
void solve() {
	
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}