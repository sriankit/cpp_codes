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
typedef pair<PII,int> TRI;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<ll> vl;
typedef vector<PII> VII;
typedef vector<TRI> VT;

int n, m, p;

vector<int> adj[4004];
vector<pair<int,int> > dis[4000];
pair<int,int> best[4004];
int vis[4004];
void precompute() {
	
}
void read() {
	s(n);s(m);s(p);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		char ch;		
		s(a), s(b), s(c);
		sc(ch);
		adj[a].push_back(b);
		adj[b].push_back(a);
		dis[a].push_back(make_pair(c, ch));
		dis[b].push_back(make_pair(c, ch));
	}
}
void preprocess() {
	for (int i = 0; i < n; ++i) {
		best[i] = make_pair(INF, INF);
	}
	memset(vis, 0, sizeof vis);
}
pair<int,int> dijkstra(int src, int tar) {
	best[src] = make_pair(0, 0);
	priority_queue<TRI, std::vector<TRI>, greater<TRI> > pq;
	for (int i = 0; i < n; ++i) {
		pq.push(make_pair(best[i], i));
	}
	while(!pq.empty()) {
		TRI top = pq.top();
		pq.pop();
		if(vis[top.SS]) continue;
		vis[top.SS] = 1;
		for (int i = 0; i < adj[top.SS].size(); ++i) {
			int ng = adj[top.SS][i];
			pair<int, int> ed = dis[top.SS][i];
			
			if (ed.SS=='I')
			{
				if(best[ng].FF>best[top.SS].FF)
				{
				

					best[ng].FF = best[top.SS].FF ;
					best[ng].SS =  best[top.SS].SS+ ed.FF;
				}
				else if(best[ng].FF==best[top.SS].FF)
				{
					best[ng].SS = min(best[ng].SS, best[top.SS].SS + ed.FF);
				}
				
			}
			else
			{
				if(best[ng].FF>best[top.SS].FF + ed.FF)
				{
					best[ng].FF = best[top.SS].FF + ed.FF;
					best[ng].SS =  best[top.SS].SS;
				}
				else if(best[ng].FF==best[top.SS].FF + ed.FF)
				{
					best[ng].SS = min(best[ng].SS, best[top.SS].SS);
				}

			}
			
			pq.push(make_pair(best[ng], ng));
		}
	}
	return best[tar];
}
void solve() {
	while(p--) {
		int a,b;
		s(a), s(b);
		preprocess();
		pair<int,int> ret=dijkstra(a,b);
		if(ret.FF==INF)
			ret.FF=0;
		if(ret.SS==INF)
			ret.SS=0;
		cout<<ret.FF<<" "<<ret.SS+ret.FF<<endl;
	}
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}