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
ll k;
int a[100005];
int b[100005];
int bit[100005];

void upd(int x, int val) {
	while(x < 100005) {
		bit[x] += val;
		x += x & -x;		
	}
}

ll query(int x) {
	ll sum = 0;
	while(x) {
		sum += bit[x];
		x -= x & -x;		
	}
	return sum;
}

void precompute() {
	
}
void read() {
	s(n), sl(k);
	for (int i = 0; i < n; ++i) {
		s(a[i]);
		b[i] = a[i];
	}	
}
void preprocess() {
	sort(b, b + n);
	for (int i = 0; i < n; ++i) {
		a[i] = 1 + (upper_bound(b, b + n, a[i]) - b);
	}
}
void solve() {
	int i = 0, j = 0;
	ll ans = 0;
	ll inv = 0;
	while(i < n and j < n) {
		upd(a[j], 1);
		inv += j - i + 1 - (query(a[j]));
		while(inv >= k and i <= j) {
			//cerr << i << " " << j << inv << endl;
			ans += (n - j);
			inv -= query(a[i] - 1);
			upd(a[i], -1);
			i++;
		}
		j++;
	}
	printf("%lld\n", ans);
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}