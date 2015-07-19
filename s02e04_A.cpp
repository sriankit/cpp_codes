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
pair<int, pair<int, int> > arr[1000005];
pair<int, pair<int, int> > clone[1000005];
void precompute() {
	
}
void read() {
	s(n);
	for (int i = 0; i < n; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		arr[i] = make_pair(a, make_pair(b, c));
	}
	sort(arr, arr + n);
}
void preprocess() {
	
}
bool ok(ll cap) {
	for (int i = 0; i < n; ++i) {
		clone[i] = arr[i];
	}
	ll adone = 0;
	ll wdone = 0;
	ll incmax = 0;
	int ind = n - 1;
	for (int i = n - 1; i >= 0; --i) {
		int &cc = clone[i].SS.SS;
		int &a = clone[i].FF;
		int &b = clone[i].SS.FF;
		int avl = min(cc, a);		
		if(adone + avl >= cap) {
			int add = cap - adone;
			int bvl = min(cc - add, b);
			a -= add;
			cc -= add;
			adone += add;			
			b -= bvl;
			wdone += bvl;
			cc -= bvl;			
			incmax += min(add, b);	
			break;
		}
		else {
			int bvl = min(cc - avl, b);
			cc -= avl;
			a -= avl;
			adone += avl;
			incmax += min(avl, b);
			b -= bvl;
			wdone += bvl;
			cc -= bvl;	
		}
	}
	if(adone < cap) return false;
	if(adone == cap and wdone >= cap) return true;
	int ind2 = 0;
	
	for (int i = 0; i < n; ++i) {
		int &cc = clone[i].SS.SS;
		int &a = clone[i].FF;
		int &b = clone[i].SS.FF;
		int bvl = min(cc, b);	
		int inc = min(cc - bvl, a);
		if(wdone + bvl >= cap) {
			int add = cap - wdone;
			b -= add;
			cc -= add;
			wdone += add;
			ind2 = i;
			//cerr << wdone << " " << cap << " " << bvl <<'\n';	
			break;
		}
		else {
			cc -= bvl;
			b -= bvl;
			wdone += bvl;
		}
		inc = miN(inc, incmax);		
		wdone += inc;
		incmax -= inc;
		if(wdone >= cap) break;
	}
	if(wdone >= cap) return true;
	else return false;
}
void solve() {
	ll lo = 0, hi = (ll)1e10;
	ll ans = 0;
	//cerr << ok(4) << endl;
	while(lo <= hi) {
		ll mid = lo + hi >> 1;
		if(ok(mid)) {
			ans = mid;
			lo = mid + 1;
		} else hi = mid - 1;
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