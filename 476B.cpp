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
string s1, s2;
int sm1;
int q = 0;
int fav, tot;
void precompute() {
	
}
void read() {
	cin >> s1;
	cin >> s2;
}
void preprocess() {
	
}
int sumfind(string s1) { 
	int sum1 = 0;
	for (int i = 0; i < s1.size(); ++i) {
		if(s1[i] == '?') {
			q++;
			continue;
		}
		sum1 += s1[i] == '+' ? 1 : -1;
	}
	return sum1;
}
void go(int s, int i) {
	if(i == q) {		
		if(s == sm1) fav ++;
		tot++;
		return;
	}
	go(s + 1, i + 1);
	go(s - 1, i + 1);	
}

void solve() {
	sm1 = sumfind(s1);
	int sm2 = sumfind(s2);
	go(sm2, 0);
	double ans = (1.0 * fav) / tot;
	printf("%.9lf\n", ans);
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}