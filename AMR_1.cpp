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
char s[100005];
ll p[100005];
ll a[100005];
map<int, int> ma;
void precompute() {
    p[0] = 1;
    for (int i = 1; i < 100005; ++i) {
        p[i] = p[i - 1] * (m + 1);
        p[i] %= m;
    }
}
void read() {
    ss(s);  
    n = strlen(s);
}
void preprocess() {
    
}
void printArr(ll *a, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%lld ", a[i]);
    }
    putchar('\n');
}
void popu() {
    a[0] = s[0] - '0';
    for (int i = 1; i < n; ++i) {
        a[i] = a[i - 1] *(m + 1) + s[i] - '0';
        if(a[i] >= m) a[i] %= m;        
    }
}
void doit() {
    ll ans = a[0] == l;
    ma[(a[0] * p[n - 1]) % m] += 1;  
    for (int i = 1; i < n; ++i) {
        ans += a[i] == l;
        ll cur = (a[i] * p[n - i - 1]) % m;
        ll seek = (l * p[n - i - 1]) % m;
        if(cur - seek >= 0) ans += ma[cur - seek];
        else ans += ma[(cur - seek + m) % m];
                cout << cur << " " << seek << " " << ans << endl;
        ma[cur]++;
    }
    printf("%lld\n", ans);
}
void solve() {
    int q;
    s(q);
    while(q--) {
        ma.clear();
        s(m), s(l);
        precompute();
        popu();
        printArr(p, n);
        printArr(a, n);
        doit(); 
    }
}
int main() {
    read();
    preprocess();
    solve();
    return 0;
}