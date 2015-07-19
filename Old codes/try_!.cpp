#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>

using namespace std;

#define REP(n)                  for(int i=0;i<n;i++)
#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define ss(n) 					scanf("%s",n)
#define sc(n)                   {char temp[4]; ss(temp); n=temp[0];}
#define INF						(int)1e9
#define LINF					(long long)1e18
#define EPS						1e-9
#define maX(a,b)				((a)>(b)?(a):(b))
#define miN(a,b)				((a)<(b)?(a):(b))
#define abS(x)					((x)<0?-(x):(x))
#define foreach(v,c)            for( typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define mp						make_pair
#define FF						first
#define SS						second
#define tri(a,b,c)				mp(a,mp(b,c))
#define XX						first
#define YY						second.first
#define ZZ						second.second
#define pb						push_back
#define fill(a,v) 				memset(a,v,sizeof a)
#define all(x)					x.begin(),x.end()
#define SZ(v)					((int)(v.size()))
#define DREP(a)					sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)			(lower_bound(all(arr),ind)-arr.begin())


#define debugger cerr
#define debug(args...)			{mdbg,args; debugger<<endl;}
#define PRINT_CONTAINER(o,v)    {if(v.size()==0) return o<<"{}"; o<<"{"; foreach(it,v) o<<*it<<" "; return o<<"\b}";}
struct multidebug {template<typename T> multidebug& operator , (const T &v) {debugger<<v<<" "; return *this;}} mdbg;
template<class T> ostream& operator << (ostream& o,const vector<T> &v) PRINT_CONTAINER(o,v)
template<class T> ostream& operator << (ostream& o,const set<T> &v) PRINT_CONTAINER(o,v)
template<class A,class B> ostream& operator << (ostream& o,const map<A,B> &v) PRINT_CONTAINER(o,v)
template<class A,class B> ostream& operator << (ostream& o,const pair<A,B> &p) {o<<"("<<p.first<<","<<p.second<<")"; return o;}
template<class T> void debugarr(T* v,int n) {debugger<<"{"; for(int i=0;i<n;i++) debugger<<v[i]<<" "; debugger<<"\b}"<<endl;}


typedef unsigned long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<ll> vl;
typedef vector<PII> VII;
typedef vector<TRI> VT;

/*Main code begins now */

LL risk[100005];
map<int,int> hash;
vector<pair<LL,LL> > adj[100005];
int src,dst;
pair<int,int> arr[100005];
bool flag[100005];
LL dist[100005];
int tym;

void dijkstra(LL s, vector< pair<LL,LL> > *graph, LL *dist, bool *flag) {
	priority_queue< pair<LL,LL>, vector< pair<LL,LL> >, greater< pair<LL,LL> > > Q;
	Q.push(pair<LL,LL>(0,s));
	LL u, v, w, i, sz;
	dist[s] = 0;
	while(!Q.empty()) {
		u = Q.top().second;
		Q.pop();
		if(flag[u] ) continue;
		sz = graph[u].size();
		for(i = 0; i < sz; i++) {
			v = graph[u][i].second;
			w = graph[u][i].first;
			if(!flag[v] && dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				Q.push(pair<LL,LL>(dist[v], v));
			}
		}
		flag[u] = true;
	}
}

int chk(int org,int finl,int rk,int n){
	for(int i=0;i<n;i++) {
		dist[i]=INF;
		//if(risk[i]>rk)
		//flag[i]=true;
		//else
		flag[i]=false;	
	}
	
	dijkstra(org-1,adj,dist,flag);
	LL cst=dist[finl-1];
	
	if(cst<tym) return 1;
	else return 0;		
}

int main(){
	int t;
	s(t);
	while(t--){
		int n;
		s(n);
		int k;
		s(k);
		for(int i=0;i<n;i++){
			sl(risk[i]);
			arr[i]=mp(risk[i],i);
		}
		
		sort(arr,arr+n);
		/*for(int i=0;i<n;i++){
			hash[p.SS]=i;
		}
		*/
		int m;
		scanf("%d%d%d",&m,&src,&dst);
		
		for(int i=0;i<m;i++){
			int u,v,c;
			scanf("%d%d%d",&u,&v,&c);
			--u,--v;
			adj[u].pb(make_pair(c,v));
			adj[v].pb(mp(c,u));			
		}
		
		int lo=0,hi=n-1;
		long long int ans=-1;
		while(lo <=hi){
			int mid=lo+hi>>1;
			if(chk(src,dst,arr[mid].first,n)) {
				//TODO										
				ans=arr[mid].first;	
				hi=mid-1;
			}
			else lo=mid+1;
		}
		printf("%lld\n",ans);
	}
}


















