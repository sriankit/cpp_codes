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

int n, k;
int game[1001][1001];
int indeg[1001];
void precompute() {
	
}
void read() {
	s(n), s(k);
}
void preprocess() {
	
}
stringstream ss;
void solve() {
	if(k > (n - 1) / 2) {
		cout << -1;
		return;
	}
	ss << n * k << endl;
	bool ok = true;
	for (int i = 0; i < n; ++i) {
		vector<int> chose;
		int cnt = k;
		for (int j = (i + 1) % n; j != i and cnt; j = (j + 1) % n) {
			if(i != j and !game[i][j] and indeg[j] < k) {
				chose.push_back(j);
				cnt --;
			}
		}
		
			int j = 0;
			for (std::vector<int>::iterator it = chose.begin(); j < k and it != chose.end(); ++it) {
				int opp = *it;
				game[i][opp] = 1;
				game[opp][i] = 1;
				ss << i + 1 << " " << opp + 1 << "\n";
				indeg[opp] ++;
				j++;
			}
	}
	if(ok) cout << ss.str();
	else puts("-1");
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}