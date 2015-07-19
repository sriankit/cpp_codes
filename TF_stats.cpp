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

int n, q;
int a[100005];
int dup[100005];
vector<PII> v;
multiset<int> m[2];
priority_queue<PII> maxq;
double sum;
map<int, int> frq;
priority_queue<PII> modeq;
void precompute() {
    
}
void read() {
    s(n);
    s(q);
    for (int i = 0; i < n; ++i) {
        int x;
        s(x);
        a[i] = x;
        dup[i] = x;
        frq[x]++;
        sum += x;
    }
}

inline void init_queues() {
    sort(dup, dup + n);
    for (int i = 0; i < n; ++i) {
        if(i <= n >> 1) m[0].insert(dup[i]);
        else m[1].insert(dup[i]);
    }
}
void preprocess() {
    for (std::map<int, int>::iterator it = frq.begin(); it != frq.end(); ++it) {
        modeq.push(make_pair(it->SS, it->FF));
    }
    init_queues();
}
int getMode() {
    while(1) {
        PII top = modeq.top();
        if(frq[top.SS] != top.FF) {
            modeq.pop();
        } else {
            return top.SS;
        }
    }
}
void solve() {
    while(q --) {
        int ind, val;
        s(ind), s(val);
        int prev = a[ind];
        
        a[ind] = val;
        frq[val]++;
        sum += val;

        frq[prev] --;
        sum -= prev;

        modeq.push(make_pair(frq[val], val));
        modeq.push(make_pair(frq[prev], prev));

        if(m[0].find(prev) != m[0].end()) {
            m[0].erase(m[0].find(prev));
            m[0].insert(val);
        } else {
            m[1].erase(m[1].find(prev));        
            m[1].insert(val);
        }
        while(1) {
            int maxl = *(m[0].rbegin()), minl = *(m[1].begin());
            if(maxl > minl) {
                m[0].erase(m[0].find(maxl));
                m[1].erase(m[1].begin());
                m[0].insert(minl);
                m[1].insert(maxl);
            } else break;
        }
        assert(m[0].size() - m[1].size() <= 1);

        printf("%.9lf %d %d\n", sum / n, *(m[0].rbegin()), getMode());
    }
}
int main() {
    precompute();
    read();
    preprocess();
    solve();
    return 0;
}