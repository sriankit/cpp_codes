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
char a[3000006], b[1000001];
int TEST_NO;
void precompute() {

	
}
void read() {
	s(n);
	scanf("%s", a);
	scanf("%s", b);
	strcat(a, b);
	strcat(a, b);
	a[3 * n] = '\0';	
}
vector<int> getZfunc(char *s, int len) {
    int L = 0, R = 0;        
    vector<int> z(len, 0);
    z[0] = len;
    for (int i = 1; i < len; i++) {
        if (i > R) {
            L = R = i;
            while (R < len && s[R - L] == s[R]) R++;
            z[i] = R - L;
            R--;
        } else {
            int k = i - L;
            if (z[k] < R - i + 1) z[i] = z[k];
            else {
                L = i;
                while (R < len && s[R - L] == s[R]) R++;
                z[i] = R - L;
                R--;
            }
        }
    }
    return z;
}
void preprocess() {
	
}
void solve() {
	std::vector<int> pre = getZfunc(a, 3 * n);
	//puts("done!");
	int ind = n;
	for (int i = n; i < 2 * n; ++i) {
		if(pre[i] > pre[ind]) ind = i;		
	}
	printf("%d\n", ind - n);
}
int main() {
	precompute();
	int t;
	t = 1;
	for(TEST_NO = 1; TEST_NO <= t; TEST_NO ++) {
		read();
		preprocess();
		solve();
	}
	return 0;
}