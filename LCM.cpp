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
int TEST_NO;
int a[100005];
vector<int> pre[1000006];
int pr = 0;
void precompute() {
	for (int i = 2; i < 1000006; ++i) {
		if(pre[i].size() == 0) {		
			for (int j = i; j < 1000006; j += i) {
				pre[j].push_back(pr);
			}
			pr++;
		}	
	}
}
void read() {
	s(n);
	for (int i = 0; i < n; ++i) {
		s(a[i]);
	}
}
void preprocess() {
	
}
void solve() {
	int i = 0, j = -1;
	int frq[pr];
	memset(frq, 0, sizeof frq);
	int ans = 0;
	while(i < n and j + 1< n) {
		j = j + 1;
		int f = 0;
		do{
			int num = a[j];
			f = 0;
			for (std::vector<int>::iterator iterator = pre[num].begin(); iterator != pre[num].end(); ++iterator) {
				if(frq[*iterator] > 0) f = 1;
			}
			if(f == 1) {
				ans = max(ans, j - i);
				num = a[i];
				for (std::vector<int>::iterator iterator = pre[num].begin(); iterator != pre[num].end(); ++iterator) {
					frq[*iterator] --;
				}
				i++;
			} else {
				for (std::vector<int>::iterator iterator = pre[num].begin(); iterator != pre[num].end(); ++iterator) {
					frq[*iterator] ++;
				}	
			}
		}
		while(f == 1);
	}
	ans = max(ans, j - i + 1);
	if(ans == 1) {
		puts("-1");
		return;
	}
	printf("%d\n", ans);
}
int main() {
	precompute();
	int t;
	s(t);
	for(TEST_NO = 1; TEST_NO <= t; TEST_NO ++) {
		read();
		preprocess();
		solve();
	}
	return 0;
}