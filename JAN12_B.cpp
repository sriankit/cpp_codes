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
int cnt = 0;
ll lucky[1024];
int LIM = (int)1e9;
int p10[10];
int fr[9];
int maxLen = 0;
ll dp[55][1024];
int a[55];
int curlen;

int get(int mask, int &j) {
	if(mask == 0) {
		j = 1;
		return 4;
	}
	int ret = 0;	
	while(mask) {
		if(mask & 1)  ret += p10[j] * 7;
		else ret += p10[j] * 4;
		j++;
		mask >>= 1;
	}
	return ret;
}
void precompute() {
	p10[0] = 1;
	for (int i = 1; i < 10; ++i) {
		p10[i] = 10 * p10[i - 1];
	}
	for (int i = 0; i < 1 << 9; ++i) {
		int j = 0;
		ll num = get(i, j);
		lucky[cnt++] = num;
		while(num + p10[j] * 4LL < LIM) {
			lucky[cnt++] = num + p10[j] * 4LL;
			num += p10[j] * 4LL;
			j++;
		}
	}
}
int frame(int number, int *fr) {
	int i = 0;
	memset(fr, 0, sizeof(int) * 9);
	while(number > 0) {
		fr[i] = number % 10;
		number /= 10;
		i++;
	}
	return i;
}
void read() {
	s(n);
	for (int i = 0; i < n; ++i) {
		s(a[i]);
		maxLen = max(maxLen, frame(a[i], fr));
	}
}
void preprocess() {
	memset(dp, -1, sizeof dp);
}

ll go(int i, int mask) {
	if(i == n) {
		if(mask + 1 == (1 << 9)) return 1;
		else return 0;
	}
	ll &ret = dp[i][mask];
	if(ret == -1) {
		ret = 0;
		int lcl[9];
		int thislen = frame(a[i], lcl);
		bool ok = true;
		for (int dig = 0; dig < 9; ++dig) {
			if(fr[dig] < lcl[dig]) 
				ok = false;
		}
		ret += go(i + 1, mask);
		if(ok) {
			int nmask = mask;
			for (int dig = 0; dig < 9; ++dig) {
				if(fr[dig] == lcl[dig]) nmask |= (1 << dig);
			}
			ret += go(i + 1, nmask);
		}
	}
	return ret;
}
ll solveInstance(int num) {
	int len = frame(num, fr);
	preprocess();
	curlen = len;
	return go(0, 0);	
}
void solve() {
	ll ans = 0;
	for (int i = 0; i < cnt; ++i) {
		ans += solveInstance(lucky[i]);
	}
	cout << ans << endl;
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