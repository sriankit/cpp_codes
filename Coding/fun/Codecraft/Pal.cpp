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
int cnt[300006];

int isPal(int x) {
	if(x % 100 > 59) return 0;
	if((x / 100) %  100 > 59) return 0; 
	char tmp[6];
	for (int i = 0; i < 6; ++i) {
		tmp[i] = '0';
	}
	int j = 5;
	int res = x;
	while(x) {
		tmp[j] = (x % 10) + '0';
		x /= 10;
		j--;
	}
	for (int i = 0, j = 5; i < j; ++i, --j) {
		if(tmp[i] != tmp[j]) return 0;
	}
	//cerr << res << endl;
	return 1;
}

void precompute() {
	cnt[0] = 1;
	for (int num = 1; num < 300006; ++num) {
		cnt[num] = cnt[num - 1] + isPal(num);
	}
}
void read() {
	
}
void preprocess() {
	
}
void solve() {
	int q;
	s(q);
	while(q--) {
		int a[6];
		scanf("%d:%d:%d %d:%d:%d", a, a + 1, a + 2, a + 3, a + 4, a + 5);
		int t1 = a[0] * 10000 + a[1] * 100 + a[2];
		int t2 = a[3] * 10000 + a[4] * 100 + a[5];
		printf("%d\n", cnt[t2] - (t1 == 0 ? 0 : cnt[t1 - 1]));
	}
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}