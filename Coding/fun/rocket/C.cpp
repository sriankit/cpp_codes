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
PII cp[5];
void precompute() {
	
}
void read() {
	s(n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		s(x), s(y);
		cp[i] = make_pair(x, y);
	}
}
void preprocess() {
	//sort(cp, cp + n);
}

/*
void solve() {
	double ans = 0;
	for (int sb = 1; sb < 10001; ++sb) {
		for (int bc = 0; bc < n; ++bc) {			
			if(cp[bc].SS < sb) continue;
			double p = (cp[bc].SS - max(sb, cp[bc].FF) + 1.0) / (cp[bc].SS - cp[bc].FF + 1);			
			bool ok = true;
			double mul = 1.0, sub = 1.0;
			for (int oc = 0; oc < n; ++oc) {
				if(bc == oc) continue;
				if(sb < cp[oc].FF) {
					mul = 0;										
				}
				else mul *= (min(sb, cp[oc].SS) - cp[oc].FF + 1.0) / (cp[oc].SS - cp[oc].FF + 1);
				if(sb - 1 < cp[oc].FF) sub = 0; 				
				else sub *= (min(sb - 1, cp[oc].SS) - cp[oc].FF + 1.0) / (cp[oc].SS - cp[oc].FF + 1);
			}
			if(ok) {
				cerr << mul << " " << sub << " " << sb << " " << bc <<  endl;
				ans += p * (mul - sub) * sb;
			}
		}				
	}
	cout << ans;
}
*/
void solve() {
	double ans = 0;
	for (int sb = 1; sb < 10001; ++sb) {				
		double add = 0;
		for (int mask = 1; mask < 1 << n; ++mask) {
			bool seenbc = false;
			for (int bc = 0; bc < n; ++bc) {			
				bool ok = true;
				bool seen = false;
				long double trm = 1.0;
				if(cp[bc].SS < sb) continue;	
				int res = mask;				
				for (int j = 0; j < n; ++j) {
					if((res & (1 << j)) == 0) {
						if(j == bc) trm *= (cp[bc].SS - max(sb + 1, cp[bc].FF) + 1.0) / (cp[bc].SS - cp[bc].FF + 1);
						else {
							if(sb - 1 < cp[j].FF) ok = false;
							trm *= (min(sb - 1, cp[j].SS) - cp[j].FF + 1.0) / (cp[j].SS - cp[j].FF + 1);
						}
					} else {							
						if(j != bc) seen = true;
						else {
							if(seenbc) ok = false;
							else seenbc = true;
						}
						if(cp[j].FF > sb or cp[j].SS < sb) ok = false;	
						trm /= (cp[j].SS - cp[j].FF + 1);
					}
				}
				if(ok and seen) add += trm;
			}
		}
		//cerr << sb << " " << " " << bc << " " << add << endl;
		ans += add * sb;					
	}
	printf("%.9lf\n", ans);
}

int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}