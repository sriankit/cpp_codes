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

int a[200005];
vector<int> vals[100005];
vector<int> cst[100005];
int last[100005];
int lastv[100005];

int main(){
	int n,m,k;
	memset(lastv,-1,sizeof(lastv));
	memset(last,-1,sizeof(last));
	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++){
		s(a[i]);
	}
	int pre=a[0];
	
	last[a[0]]=0;
	vals[a[0]].pb(1);
	cst[a[0]].pb(0);
	lastv[a[0]]=0;
	
	for(int i=1;i<n;i++){
		if(a[i]==pre) {
			vals[a[i]][lastv[a[i]]]++;
			last[a[i]]=i;
		}
		else {
			vals[a[i]].pb(1);
			lastv[a[i]]++;
			if(lastv[a[i]]>0) cst[a[i]].pb(i-last[a[i]]-1);
			else cst[a[i]].pb(0); 
			last[a[i]]=i;
			pre=a[i];
		}
	}
	
	int ans=0;
	
	for(int i=1;i<=m;i++){
		vector<int> v=vals[i];
		vector<int> c=cst[i];
		//cout<<v<<endl;
		//cout<<c<<endl;
		int num=v.size();
		if(num==0) continue;
		int j=1;
		int sp=0;
		int sum=v[0];
		int fst=0;
		int mx=0;
		do{		
			for(j;j<num;j++){
				if(c[j]+sp <=k) {
					sp+=c[j];
					sum+=v[j];
				}
				else break;
			}				
			mx=max(mx,sum);
			sum-=v[fst];
			sp-=c[fst+1];
			fst++;
		}while(j<num);
		ans=max(mx,ans);
	}
	printf("%d\n",ans);
}











