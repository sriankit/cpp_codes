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
void precompute() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
bool endsWith(string s, string tail) {
	int i1 = s.length() - 1;
	int i2 = tail.length() - 1;
	while(i1 >= 0 and i2 >= 0) {
		if(s[i1] != tail[i2]) return false;
		i1--;
		i2--;
	}
	return true;
}
void read() {
	s(n);
	for (int i = 0; i < n; ++i) {
		bool dn = false;
		string s;
		cin >> s;
		int len = s.size();
		string end[] = {"ch", "x", "s", "o", "f", "fe", "y"};
		string rep[] = {"es", "es", "es", "es", "ves", "ves", "ies"};
		for (int i = 0; i < 4; ++i) {
			if(endsWith(s, end[i])) {
				cout << s + rep[i] << '\n';	
				dn = true;
				break;
			}
		}
		for (int i = 4; !dn and i < 6; ++i) {
			if(endsWith(s, end[i])) {
				int l = end[i].size();
				cout << s.substr(0, len - l) + rep[i] << '\n';
				dn = true;
			}
		}
		for (int i = 6; !dn and i < 7; ++i) {
			if(endsWith(s, end[i])) {
				int l = end[i].size();
				cout << s.substr(0, len - l) + rep[i] << '\n';
				dn = true;
			}
		}
		if(!dn) cout << s << "s" << '\n';
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