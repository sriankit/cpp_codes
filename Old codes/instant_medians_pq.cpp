//Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
 
 
//Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
 
using namespace std;
/**************************fast input***************************
inline int inp()
    {
    int noRead=0;
    char p=getchar_unlocked();
    for(;p<33;){p=getchar_unlocked();};
    while(p>32)
    {
    noRead = (noRead << 3) + (noRead << 1) + (p - '0');
    p=getchar_unlocked();
    }
    return noRead;
    };
/************************fast input end***************************/
/**
BEGIN
FAST I/O
**
#define BUFSIZE 6000000
char inbuf[BUFSIZE],outbuf[BUFSIZE],c,*in,*out;
int nbuf[10],nbs,bi;
int neg,num;
 
void io_init(){
    fread_unlocked(inbuf,1,BUFSIZE,stdin);
    in = inbuf;
    out = outbuf;
}
 
int ni(){
    c = *in++;neg = num = 0;
    while(!(c >= '0' && c <= '9' || c == '-') ) c = *in++;
    if(c == '-') neg = 1, c = *in++;
    while(c >= '0' && c <= '9'){
        num = (num << 3) + (num << 1) + c - '0';
        c = *in++;
    }
    return neg ? -num : num;
}
 
void oi(int num){
    if(num < 0) *out++ = '-' , num = -num;
    nbs = bi = 0;
    if(num == 0) nbuf[nbs++] = 0;
    while(num) nbuf[nbs++] = num%10 , num /= 10;
    bi = nbs - 1;
    while(bi >= 0) *out++ = nbuf[bi--] + '0';
    *out++ = '\n';
}
 
void io_end(){
    *out = '\0';
    assert(out  - outbuf <= BUFSIZE && out - outbuf >= 0);
    fwrite_unlocked(outbuf,1,out - outbuf,stdout);
}
/**
END
FAST I/O
**/
 
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
#define fo(i,a,b)				for(int i=a;i<b;i++)
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
#define sz(v)					    ((int)(v.size()))
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





typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;

typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<PLL> VLL;
typedef vector<TRI> VT;

typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VII> VVII;
typedef vector<VLL> VVLL;
typedef vector<VT> VVT;


/*Main code begins now */

priority_queue<int>maxq;
priority_queue<int,vector<int>,greater<int> >minq;
             
int main(){
    //io_init();
    int n;
    s(n);
    //n=ni();
    int a,v;
    s(a);
    minq.push(a);
    printf("%d\n",a);
    for(int i = 2; i <= n; i++){
        s(a);
        if(i&1) {
            v = maxq.top();
            if(v>a) {
                maxq.pop();
                maxq.push(a);
                minq.push(v);
            }
            else minq.push(a);
            printf("%d\n",minq.top());
        }
        else {
            v = minq.top();
            if(v<a) {
                minq.pop();
                maxq.push(v);
                minq.push(a);
            }
            else maxq.push(a);
            printf("%d\n",maxq.top());
        }
        
    }
    //system("pause");                
    return 0;
}
