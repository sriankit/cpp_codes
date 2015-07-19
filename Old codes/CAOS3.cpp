#include<vector>
#include<stack>
#include<set>
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
//template<class A,class B> ostream& operator << (ostream& o,const map<A,B> &v) PRINT_CONTAINER(o,v)
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

char mat[20][20];
int map[20][20];
int table[20][20][20][20];
int n,m;

bool check_CPC(int i, int j){ // 1 = i = n, 1 = j = m
    if (mat[i][j] != '^')
        return false;
    if (i-2 < 0 or j-2 < 0 or i+2 > n-1 or j+2 > m-1) 
        return false;
    for (int x=-2; x<=2; x++)
        if (mat[i+x][j] != '^' or mat[i][j+x] != '^')
            return false;
    return true;
}

int go(int sx,int sy,int ex,int ey){
	if(sx>ex || sy>ey) return 0;
	int &res=table[sx][sy][ex][ey];
	if(res==-1){
		set<int> sg;
		for(int i=sx;i<=ex;i++)
			for(int j=sy;j<=ey;j++){
				if(map[i][j]==0) continue;
				int vals[]={go(sx,sy,i-1,j-1),go(sx,j+1,i-1,ey),go(i+1,sy,ex,j-1),go(i+1,j+1,ex,ey)};
				int x = vals[0] ^ vals[1] ^ vals[2] ^ vals[3];
				sg.insert(x);				
			}
		int val=0;
		foreach(v,sg){
			if(val!=*v) {
				res=val;
				break;				
			}val++;			
		}
		//debug(SZ(sg));
		if(res==-1){
			if(SZ(sg)==0) res=0;
			else res=SZ(sg);
		}
	}
	return res;	
}

int main(){
	int t;
	s(t);
	while(t--){
		memset(map,0,sizeof(map));
		memset(mat,0,sizeof(mat));
		memset(table,-1,sizeof(table));
		int r,c;
		s(r);
		s(c);		
		n=r;
		m=c;
		for(int i=0;i<r;i++){			
			scanf("%s",mat[i]);
			//for(int j=0;i<c;j++) 
			//	mat[i][j]=s[j];
		}
		for(int i=0;i<r;i++){
			//puts(mat[i]);
			for(int j=0;j<c;j++)
				if(check_CPC(i,j)){									
					map[i][j]=1;
					//debug(i,j);
				}
		}
		
		puts(go(0,0,r-1,c-1)?"Asuna":"Kirito");
	}
}




















