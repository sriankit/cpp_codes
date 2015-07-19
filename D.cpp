/* Code Jam Template */
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
#define DEBUG 0
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

/*Main code begins now*/
int n, k;
ll dp[201][201];
ll go(int open, int tot) {
    //cerr << open << " " << tot << endl;
    if(tot == 0) return open == 0; 
    if(dp[open][tot] == -1) {
        if(open == 0) dp[open][tot] = go(1, tot -1);
        else dp[open][tot] = go(open - 1, tot - 1) + go(open + 1, tot - 1);
    }
    return dp[open][tot];
}
void precompute() {
    memset(dp, -1, sizeof(dp));
    #if DEBUG
    for (int i = 0; i < 10; ++i)
    {
        printf("%lld ", dp[0][i]);
    }
    #endif
    /*
    Code that is common to all test cases and should be run before solving for any case, like Prime-NUmber Generation :)    
    */
}
void read() {
    s(n);
    s(k);
    n <<= 1;
    /*
    Read Global variables here
    */
}
void solve() {
    string ans(n, '(');
    int open = 0;
    int fail = 0;
    for (int i = 0; i < n; ++i)
    {   
        if(open < 0) {
            fail = 1;
            break;
        }
        ll cnt = go(open + 1, n - i - 1);
        if(k <= cnt || cnt < 0) {
            ans[i] = '(';            
            open ++;
        } else {
            k -= cnt;
            ans[i] = ')';
            open --;
        }
    }
    if(fail || open != 0) cout << "Doesn't Exist!\n"; 
    else cout << ans << endl;
    /*
    Main logic goes here
    */
}
/*
This main function will remain same in all implementations.
Make sure that input file is present in same directory and if changing the filename(s), don't forget to include extensions(.in) as well.
*/
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    precompute();
    int t;
    s(t);
    for(int T = 1; T <= t; T++) {
        read();
        printf("Case #%d: ",T);
        solve();
    }
    return 0;
}