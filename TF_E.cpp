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

#define BASE 1000000007

int n;
char s[10004];
LL hash[10004];
LL rev[10004];
LL p[10004];
void precompute() {
    
}
void read() {
    s[0] = '$';
    scanf("%s", s + 1);
    n = strlen(s) - 1;
}
void debugArr(LL *a, int len) {
    for (int i = 0; i < len; ++i) {
        cout << a[i] << " ";
    }
    cout << '\n';
}
void preprocess() {
    hash[0] = 0;
    for (int i = 1; i <= n; ++i) {
        hash[i] = hash[i - 1] * BASE + s[i] - 'a' + 1;
    }
    //debugArr(hash, n + 1);
    rev[n + 1] = 0;
    for (int i = n ; i > 0 ; --i) {
        rev[i] = rev[i + 1] * BASE + s[i] - 'a' + 1;
    }
    //debugArr(rev, n  + 1);
    p[0] = 1;
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] * BASE;
    }
}
LL subHash(int i, int j, bool rv = false) {
    if(i > j) return 0;
    int l = j - i + 1;
    if(rv) {
        return rev[i] - rev[j + 1] * p[l];
    } else {
        return hash[j] - hash[i - 1] * p[l];
    }
}
bool ok(int i, int j) {
    //cout << i << " " << j << endl;
    int l1 = i - 1, l2 = j - i + 1, l3 = n - j;
    LL fhash = subHash(1, i - 1);
    fhash = fhash * p[l2] + subHash(i, j, true);
    fhash = fhash * p[l3] + subHash(j + 1, n);   
    LL revHash = subHash(j + 1, n, true);
    revHash = revHash * p[l2] + subHash(i, j);
    revHash = revHash * p[l1] + subHash(1, i - 1, true);
    //cout << fhash << " " << revHash << '\n';
    return fhash == revHash; 
} 
bool go(int idx) {
    for (int i = idx; i <= n - idx; ++i) {
        if(s[n + 1 - idx] == s[i] and  ok(idx, i)) return true;
    }
    for (int i = n + 1 - idx; i > idx; --i) {
    	if(s[i] == s[idx] and ok(i, n + 1 - idx)) return true;
    }
    return false;
}
void solve() {
    bool res = true;
    for (int i = 1, j = n; i < j; ++i, --j) {
        if(s[i] != s[j]) {
            //cout << s[i] << " " << s[j] << '\n';
            res = go(i);
            break;
        }
    }
    if(res) puts("Yes");
    else puts("No");
}
int main() {
    precompute();
    read();
    preprocess();
    solve();
    return 0;
}