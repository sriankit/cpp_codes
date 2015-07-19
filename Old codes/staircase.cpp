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

#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define ss(n) 					scanf("%s",n)
#define INF						(int)1e9
#define LINF					(long long)1e18
#define EPS						1e-9
#define maX(a,b)				((a)>(b)?(a):(b))
#define miN(a,b)				((a)<(b)?(a):(b))
#define abS(x)					((x)<0?-(x):(x))
#define FOR(i,a,b)				for(int i=a;i<b;i++)
#define REP(i,n)				FOR(i,0,n)
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
#define debug(args...)			{dbg,args; cerr<<endl;}
#define dline					cerr<<endl	

void sc(char &c){
	char temp[4];	ss(temp);	
	c=temp[0];
}

struct debugger
{
	template<typename T> debugger& operator , (const T& v)
	{	
		cerr<<v<<" ";	
		return *this;	
	}
} dbg;

void debugarr(int * arr,int n)
{
	cout<<"[";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"]"<<endl;
}





typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> Pll;
typedef pair<int,PII> TRI;

typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VII;
typedef vector<Pll> Vll;
typedef vector<TRI> VT;

typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VII> VVII;
typedef vector<Vll> VVll;
typedef vector<VT> VVT;


/*Main code begins now */

ll BIT[100005];

ll max(ll a,ll b){
    return (a>b)?a:b;
}
 
void update(int idx,int val){
    while(idx <= 100005){
        BIT[idx] = max(BIT[idx] , val);
        idx += (idx&-idx);
    }
}
 
int query(int idx){
    ll mx = -1;
    while(idx ){
        mx = max(mx,BIT[idx]);
        idx -= (idx&-idx);
    }
    return mx;
}

int main(){
    memset(BIT,0,sizeof(BIT));
    int n;
    s(n);
    for(int i=1;i<=n;i++) {
        int a;
        s(a);
        update(i,a);
    }
    int m;
    s(m);
    while(m--){
        int w,h;
        s(w);s(h);
        printf("%I64d\n",query(w));
        update(w,h);
    }
    system("pause");
    return 0;
}
