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

int n, m, k;
int a[5005];
ll p[5005], dp[5005][5005];
void precompute() {
    
}
void read() {
    s(n);
    s(m);
    s(k);
    for (int i = 0; i < n; ++i) {
        s(a[i]);
    }
}
void preprocess() {
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] + a[i - 1];
    }
}
ll go(int i, int k) {
    if(k == 0 || i >= n + 1) return 0;
    if(dp[i][k] == -1) {
        dp[i][k] = maX(go(i + 1, k), p[i] - p[i - m] + go(i + m, k - 1)); 
    }
    return dp[i][k];
}
void solve() { 
    memset(dp, -1, sizeof dp);
    printf("%lld\n", go(m, k));
}
int main() 
{
    precompute();
    read();
    preprocess();
    solve();
    return 0;
}