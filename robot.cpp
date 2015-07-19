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
//special macro for reading a character of input
#define sc(n)                   {char temp[4]; ss(temp); n=temp[0];}
#define INF                     (int)1e9
#define LINF                    (long long)1e18
#define EPS                     1e-9
/*
Use these macros when comparing variables of different data types.
For e.g. comparing int and long long will give error when used with std::max, use maX instead.
*/
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
#define CODEJAM 0
#define MANY_CASES 0

/*Main code begins now*/
int n;
ll c[500005];
int e[500005];
ll dp[500005];
ll sum;
void precompute() {
    /*
    Code that is common to all test cases and should be run before solving for any case, like Prime-NUmber Generation :)    
    */
}
void read() {
    s(n);
    for (int i = 0; i < n; ++i) {
        s(c[i]);
        sum += c[i];
        s(e[i]);
    }
    /*
    Read Global variables here
    */
}
void solve() {
    c[n] = 0;
    int k = e[0];
    if(n == 1) {
        puts("0");
        return;
    }
    multiset<pair<ll, int> > pq;
    pq.insert(mp(c[0], e[0]));
    for (int i = 1; i < n; ++i) {
        while(!pq.empty() && pq.begin()->second < i) pq.erase(pq.begin());        
        int add = (pq.empty() ? 0 : *(pq.begin()));
        dp[i] = add + c[i];
        int fin = e[i] + i;
        pq.insert(mp(dp[i], fin)); 
    }
    cout << sum - dp[n] - c[0];
}
/*
This main function will remain same in all implementations.
Make sure that input file is present in same directory and if changing the filename(s), don't forget to include extensions(.in) as well.
*/
int main(){
    #if CODEJAM
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    precompute();
    int t;
    if(MANY_CASES) s(t);
    else t = 1;
    for(int T = 1; T <= t; T++) {
        read();
        #if CODEJAM
        printf("Case #%d: ",T);
        #endif
        solve();
    }
    return 0;
}