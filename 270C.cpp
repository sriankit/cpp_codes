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
int p[100005];
int a[100005][2];
int rev[100005];
int dp[100005][2];
map<pair<string, int>, int> ma;
void precompute() {
    
}
void read() {
    s(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ma[make_pair(s, i)] = 1;
        cin >> s;
        ma[make_pair(s, i + n)] = 1;
    }
    for (int i = 0; i < n; ++i) {
        s(p[i]);
        p[i] --;
        rev[p[i]] = i;
    }
}
void preprocess() {
    int rank = 0;
    for (std::map<pair<string, int>, int>::iterator i = ma.begin(); i != ma.end(); ++i) {
        pair<string, int> p = i -> FF;
        int ind = (p.SS >= n) ? p.SS - n : p.SS;
        int sind = (p.SS >= n);
        a[ind][sind] = rank ++; 
        //printf("%d %d %d\n", ind, sind, rank - 1);
    }
    memset(dp, -1, sizeof dp);
}
int go(int i, int last) {
    //cout << "go "<< i << " " << last << " "<< dp[i][last] << endl;
    if(i == n) return 1;
    if(dp[i][last] == -1) {
        int mn = -1;    
        int now = p[i];
        int prev = -1;
        if(i > 0) {
            prev = p[i - 1];
            mn = a[prev][last];
        }
        int &ok = dp[i][last];
        ok = 0;
        //cout << now<< " " << mn << " " <<endl;
        for (int j = 0; j < 2; ++j) {
            if(a[now][j] > mn) ok |= go(i + 1, j);
        }
    }
    return dp[i][last];
}
void solve() {
    int res = go(0, 0);
    if(res) puts("YES");
    else puts("NO");
}
int main() {
    precompute();
    read();
    preprocess();
    solve();
    return 0;
}