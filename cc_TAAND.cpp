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
vector<int> sols;
int TEST_NO;
void precompute() {
	
}
void read() {
	s(n);
	for (int i = 0; i < n; ++i) {
		int x;
		s(x);
		sols.push_back(x);
	}
}
void preprocess() {
}
void dbg(vector<int> v) {
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}
int go(vector<int> vec, int bit) {
    if(bit == -1) return 0;
    std::vector<int> v1;
    std::vector<int> v0;
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        int num = *it;
        if((num & (1 << bit)) > 0) v1.push_back(num);
        else v0.push_back(num);
    }
    if(v1.size() >= 2) return (1 << bit) + go(v1, bit - 1);
    else return go(vec, bit - 1);
}
int brute() {
    int mx = sols[0] & sols[1];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i == j) continue;
            mx = max(sols[i] & sols[j], mx);
        }
    }
    return mx;
}
void solve() { 
    int my_sol =  go(sols, 30);
    printf("%d\n", my_sol);
}
int main() {
	precompute();
	int t;
	t = 1;
	for(TEST_NO = 1; TEST_NO <= t; TEST_NO ++) {
		read();
		preprocess();
		solve();
	}
	return 0;
}