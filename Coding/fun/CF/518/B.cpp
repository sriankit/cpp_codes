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
string a,b;
int f1[100], f2[100];
void precompute() {
	
}
void read() {
	cin >> a >> b;
}
void preprocess() {
	for (int i = 0; i < a.length(); ++i) {
		int c = a[i] - 'A';
		f1[c]++;
	}
	for (int i = 0; i < b.length(); ++i) {
		int c = b[i] - 'A';
		f2[c]++;	
	}
}
void solve() {
	int diff = 'a' - 'A';
	int yay = 0, wh = 0;
	for (int i = 0; i < 100; ++i) {
		int mn = min(f1[i], f2[i]);
		yay += mn;
		f1[i] -= mn;
		f2[i] -= mn;
	}
	for (int i = 0; i < 100; ++i) {
		int mir = i < diff ? (i + diff) : (i - diff);
		int mn = min(f1[i], f2[mir]);
		wh += mn;
		f1[i] -= mn;
		f2[mir] -= mn;
	}
	cout << yay << " " << wh ;
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}