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

int n, m, l;
char s[20004];
int dp[20004][505];
void precompute() {
    
}
void read() {
    s[0] = '$';
    scanf("%s", s + 1);
    n = strlen(s + 1);
}
void preprocess() {
    
}
void doit() {
    int ans = 0;
    dp[0][0] = 1;
    int num = 0;
    for(int i = 1; i <= n; i++) {
        int dig = s[i] - '0';
        num = (num * 10 + dig) % m;
        memset(dp[i], 0, sizeof dp[i]);

        for(int j = 0; j < m; j++) {
            int k = j * 10 % m;
            dp[i][k] = dp[i][k] + dp[i - 1][j];
        }
        int mod = (num - l + m) % m;        
        ans += dp[i][mod];
        dp[i][num]++;
    }
    printf("%d\n", ans);
}
void solve() {
    int q;
    s(q);
    while(q--) {
        s(m), s(l);
        doit();
    }
}
int main() {
    precompute();
    read();
    preprocess();
    solve();
    return 0;
}