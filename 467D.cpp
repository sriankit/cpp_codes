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

int nw, n;

string words[100005];
string inp[100005][2];
map<string, int> ma;
int a[100005];
vector<int> adj[100005];
bool vis[100005];
pair<int, int> dp[100005];
pair<int, int> sto[100005];

void precompute() {
	
}
void tolower_string(string &s) {
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
}
int count_r(string s) {
	int cnt = 0;
	for (int i = 0; i < s.size(); ++i) {
		if(s[i] == 'r') cnt ++;
	}
	return cnt;
}
void read() {
	s(nw);
	for (int i = 0; i < nw; ++i) {
		cin >> words[i];
		tolower_string(words[i]);
		ma[words[i]] = 0;
	}
	s(n);
	string w1, w2;
	for (int i = 0; i < n; ++i) {
		cin >> w1 >> w2;
		tolower_string(w1);
		tolower_string(w2);
		inp[i][0] = w1;
		inp[i][1] = w2;
		ma[w1] = ma[w2] = 0;
	}
}
void preprocess() {	
	int j = 0;
	for (std::map<string, int>::iterator it = ma.begin(); it != ma.end(); ++it) {
		it -> SS = j;
		string s = it -> FF;
		sto[j] = make_pair(count_r(s), s.size());
		j++;
	}
	for (int i = 0; i < nw; ++i) {
		a[i] = ma[words[i]];
	}
	for (int i = 0; i < n; ++i) {
		int u, v;
		u = ma[inp[i][0]];
		v = ma[inp[i][1]];
		adj[u].push_back(v);
	}
	for (int i = 0; i < 100005; ++i) {
		dp[i] = make_pair(1000000, 1000000);
	}
}
pair<int, int> go(int v) {
	if(vis[v]) return dp[v];
	vis[v] = true;
	pair<int, int> &ans = dp[v];
	ans = sto[v];
	for (std::vector<int>::iterator it = adj[v].begin(); it != adj[v].end(); ++it) {
		int next = *it;
		ans = min(ans, go(next));
	}
	return ans;
}
void solve() {
	pair<int, int> ans = make_pair(0, 0);
	for (int i = 0; i < nw; ++i) {
		pair<int, int> res = go(a[i]);
		ans.FF += res.FF;
		ans.SS += res.SS;	
	}
	printf("%d %d\n", ans.FF, ans.SS);
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}