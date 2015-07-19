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
string s;
int match[100005];
int br = 0;
vector<int> pts;
void precompute() {
    
}
void read() {
    cin >> s;
    n = s.size();
}
void preprocess() {
    for (int i = 0; i < n / 2; ++i) {
        if(s[i] != s[n - i - 1]) {
            match[i] = match[n - i - 1] = 1;
            pts.push_back(i);
            pts.push_back(n - i - 1);
            br += 2;
        }
    }
    if(n & 1) pts.push_back((n / 2));    
}
bool isPal(string s) {
    int len = s.size();
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] != s[len - i - 1]) return false;
    }
    return true;
}
void solve() {
    if(br > 4) {
        puts("0");
        return;
    }
    set<string> ans;
    if(isPal(s)) ans.insert(s);
    for (int i = 0; i < pts.size(); ++i) {
        for (int j = i + 1; j < pts.size(); ++j) {
            string ns = s;
            swap(ns[pts[i]], ns[pts[j]]);
            if(isPal(ns)) ans.insert(ns);
        }
    }
    printf("%d\n", ans.size());
    for (std::set<string>::iterator it = ans.begin(); it != ans.end(); ++it) {
        cout << *it << '\n';
    }
}
int main() {
    precompute();
    read();
    preprocess();
    solve();
    return 0;
}