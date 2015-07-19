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
int d1[400][400], d2[400][400];
int a[400][400];
int TEST_NO;
void precompute() {
    
}
void read() {
    memset(d1, 0, sizeof d1);
    memset(d2, 0, sizeof d2);
    s(n), s(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            s(a[i][j]);
            d1[i + j][i] = a[i][j] + (i > 0 ? d1[i + j][i - 1] : 0);
            d2[i - j + m - 1][i] = a[i][j] + (i > 0 ? d2[i - j + m - 1][i - 1] : 0);
        }
    }
}
void preprocess() {
    
}
int go(int r1, int r2, int c, int w) {
    if(c + w >= m) return -INF;
    int dg2 = r1 - c + m - 1;
    int dg1 = r2 + c;
    int sum = d1[dg1][r2] - (r1 == 0 ? 0 : d1[dg1][r1 - 1]);
    sum += d2[dg2][r2] - (r1 == 0 ? 0 : d2[dg2][r1 - 1]);
    if(w % 2 == 0) sum -= a[r1 + w / 2][c + w / 2];
    return sum;
}
void solve() {
    int ans = -INF;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int w = 1; i + w < n; ++w) {
                int res = go(i, i + w, j, w);
                //cerr << i << " " << i + w << " " << j << " " << res << endl;
                ans = max(ans, res);    
            }
        }
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