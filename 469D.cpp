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

int n, s1, s2;
int a[100005];
map<int, int> ma;
int sw = 0;
int vis[100005];
void precompute() {
	
}
void read() {
	s(n);
	s(s1);
	s(s2);
	for (int i = 0; i < n; ++i) {
		int x;
		s(x);
		a[i] = x;
		ma[x] = i;
	}
}
void preprocess() {
	sort(a, a + n);
	if(s1 < s2) {
		swap(s1, s2);
		sw = 1;	
	}
	memset(vis, -1, sizeof vis);

}
void solve() {
	for (int i = 0; i < n; ++i) {
		if(vis[i] != -1) continue;
		int c1 = s1 - a[i];
		int c2 = s2 - a[i];
		if(ma.count(c1)) {
			vis[i] = 0;
			vis[ma[c1]] = 0;
		} else if(ma.count(c2)) {
			vis[i] = 1;
			vis[ma[c2]] = 1;
		} else {
			cout << "NO";
			return;
		}
	} 
	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		if(sw) vis[i] = 1 - vis[i];
		printf("%d ", vis[i]);
	}
}
int main() 
{
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}