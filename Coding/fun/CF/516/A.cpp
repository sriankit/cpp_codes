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
map<int, VI> ma;
int a[20];
int cnt[10];
void precompute() {
    
}
void read() {
    s(n);
    for (int i = 0; i < n; ++i) {
        scanf("%1d", &a[i]);
    }
}
void preprocess() {
    
}
void solve() {
    for (int i = 0; i < n; ++i) {
        if(a[i] == 4) {
            cnt[2] += 2;
            cnt[3] += 1;
        }
        else if (a[i] == 6) {
            cnt[3] += 1;
            cnt[5] += 1;
        } else if (a[i] == 8) {
            cnt[2] += 3;
            cnt[7] += 1;        
        } else if(a[i] == 9) {
            cnt[3] += 2;
            cnt[2] += 1;
            cnt[7] += 1;
        } else cnt[a[i]] += 1;

    }
    for (int i = 9; i > 1; --i) {
        while(cnt[i]) {
            printf("%d", i);
            cnt[i] --;
        }
    }
}
int main() {
    precompute();
    read();
    preprocess();
    solve();
    return 0;
}