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

int n, d;
int gain[30005];
map<PII, int> ma;

void precompute() {
    
}
void read() {
    s(n), s(d);
    for (int i = 0; i < n; ++i) {
    	int g;
    	s(g);
    	gain[g] = 1;
    }
}
void preprocess() {
    
}

int go(PII p) {
	cerr << p.FF << " " << p.SS << endl;
    if(p.FF > 30000) return 0;
    if(ma.count(p)) return ma[p];
    else {
        int i = p.FF, j = p.SS, cnt;
        cnt = ma[p] = gain[i] + max(max(go(make_pair(i + j - 1, j - 1)), go(make_pair(i + j, j))), go(make_pair(i + j + 1, j + 1)));        
        return cnt;
    }
}

void solve() {
    cout << go(make_pair(d, d));
}
int main() {
    precompute();
    read();
    preprocess();
    solve();
    return 0;
}