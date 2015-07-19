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

int n, sum;
int TEST_NO;
int a[1003];
#define MAXNUM 3000006
int lq[MAXNUM], cnt[MAXNUM], vis[MAXNUM];
void precompute() {
    
}
void read() {
    memset(lq, 0, sizeof lq);
    memset(cnt, 0, sizeof cnt);
    memset(vis, 0, sizeof vis);
    s(n), s(sum);
    for (int i = 0; i < n; ++i) {
        s(a[i]);
        cnt[a[i]] ++;
    }   
}
void preprocess() {
	sort(a, a + n);
    int last = 0;
    for (int i = 0; i < MAXNUM; ++i) {
    	lq[i] = last;
    	if(cnt[i]) last++;	
    }
}
int brute() {
    set<TRI> se;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {       
                if(a[i] + a[j] + a[k] > sum) continue;
                int sub[] = {a[i], a[j], a[k]};
                sort(sub, sub + 3);
                se.insert(make_pair(sub[0], make_pair(sub[1], sub[2])));
            }   
        }
    }
    return se.size();
}
void solve() {
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if(i > 0 and a[i] == a[i - 1]) continue;
        for (int j = 0; j < n; ++j) {
            if(i == j || a[j] < a[i] || vis[a[j]] == a[i]) continue;
            //cout << i << " " << j << endl;
            int f = a[i], s = a[j];
            vis[s] = f;
            int k = sum - f - s + 1;
            if(k <= s) continue;
            int add = lq[k] - lq[s];
            if(f == s) add -= (cnt[f] == 2);
            else add -= cnt[s] == 1;
            //cout << i << " " << f << " " << s << " " << add << " " << lq[k] << endl; 
            if(add > 0) ans += add;
        }
    }
    cout << ans << endl;
}
int main() {
    precompute();
    int t;
    s(t);
    for(TEST_NO = 1; TEST_NO <= t; TEST_NO ++) {
        read();
        preprocess();
        solve();
    }
    return 0;
}