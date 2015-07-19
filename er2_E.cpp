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
int a[200005];
int ind[200005]; 	
int offline[200005];
priority_queue<int, vector<int>, greater<int> > pq;
bool vis[200005];
int ans[200005];
void precompute() {
	
}
void read() {
	s(n), s(q);
	for (int i = 0; i < n; ++i) {
		s(a[i]);
		--a[i];
		ind[a[i]] = i;		
	}
}
void preprocess() {
	
}
void solvePending() {
	memset(vis, false, sizeof vis);	
	int chunk = 0;
	int ptr = 0;
	while(!pq.empty()) {
		int x = pq.top();
		while(ptr <= x) {
			vis[ptr] = true;
			bool lf = ptr > 0 and vis[ptr - 1];
			bool rt = ptr < n and vis[ptr + 1];
			if(!lf and !rt) chunk ++;
			if(lf and rt) chunk --;
		}
		ans[x] = chunk;
		pq.pop();
	}
}
void solve() {
	int last = 0;
	int cur = 0;
	while(q --) {
		int ch;
		s(ch);
		if(ch == 1) {
			solvePending();
			while(last < cur) printf("%d\n", ans[offline[last++]]);
		} else {
			int x;
			s(x);
			--x;
			offline[cur++] = x;
			pq.push(x);
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