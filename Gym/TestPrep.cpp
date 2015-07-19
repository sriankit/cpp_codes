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

int n, m;
ll fail[21];
void precompute() {
	
}
void read() {
	s(n), s(m);	
	for (int i = 0; i < n; ++i)
	{
		int num;
		s(num);
		for (int j = 0; j < num; ++j)
		{
			int x;
			s(x);
			--x;			
			fail[i] |= (1LL << x);
		}
	}
}
void preprocess() {
	
}
int cnt1(int n) {
	return __builtin_popcount(n);
}
void print_one(int mask) {
	int j = 0;
	while(mask) {
		if(mask & 1) printf("%d ",j + 1);
		mask >>= 1;
		j++;
	}	
}
int ok(int mask) {
	ll target = (1LL << m) - 1;
	ll res = 0;
	int j = 0;
	while(mask) {
		if(mask & 1) {
			res |= fail[j];
		}
		j++;
		mask >>= 1;
	}
	if(res == target) return 1;
	return 0;
}
void solve() {
	int ans = (1 << n) - 1;
	for (int mask = 0; mask < 1 << n; ++mask)
	{
		if(ok(mask) && cnt1(ans) > cnt1(mask)) {
			ans = mask;
		}
	}
	printf("%d\n", cnt1(ans));
	print_one(ans);
}
int main() 
{

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}