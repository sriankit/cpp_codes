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
/**************************fast input***************************/
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
**/
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
    *out++ = ' ';
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

const ll MOD = (1LL << 32);
int pow[10];
int primes[4] = {2,3,5,7}; 
int num_len,den_len;
ll table[20][64][64][64][64];
ll go(int len,int cnt2,int cnt3,int cnt5,int cnt7){
    if(len == 0 || cnt2 < 0 || cnt3 < 0 || cnt5 < 0 || cnt7 < 0) return 0;
    if(table[len][cnt2][cnt3][cnt5][cnt7] != -1) return table[len][cnt2][cnt3][cnt5][cnt7];
    int cnt[4] = {cnt2,cnt3,cnt5,cnt7};
    if(len == 1) {
        if(cnt2 == 0 && cnt3 == 0 && cnt5 == 0 && cnt7 == 0) return 1;//1
        if(cnt2 == 1 && cnt3 == 0 && cnt5 == 0 && cnt7 == 0) return 1;//2
        if(cnt2 == 0 && cnt3 == 1 && cnt5 == 0 && cnt7 == 0) return 1;//3 
        if(cnt2 == 2 && cnt3 == 0 && cnt5 == 0 && cnt7 == 0) return 1;//4
        if(cnt2 == 0 && cnt3 == 0 && cnt5 == 1 && cnt7 == 0) return 1;//5
        if(cnt2 == 1 && cnt3 == 1 && cnt5 == 0 && cnt7 == 0) return 1;//6 
        if(cnt2 == 0 && cnt3 == 0 && cnt5 == 0 && cnt7 == 1) return 1;//7
        if(cnt2 == 3 && cnt3 == 0 && cnt5 == 0 && cnt7 == 0) return 1;//8
        if(cnt2 == 0 && cnt3 == 2 && cnt5 == 0 && cnt7 == 0) return 1;//9
        return 0;
    }
    for(int i = 1;i < 10;i++){
        table[len][cnt2][cnt3][cnt5][cnt7]=
    
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll divpro;
        int l;
        scanf("%d%lld",&l,&divpro);
        ll ans = 0;
        den_len = l/2;
        num_len = l-den_len;
        for(int i = 0; i < 4; i++)
            while(divpro%primes[i]==0) pow[primes[i]]++,divpro/=primes[i];
        if(divpro > 1){
            puts("0");
        }
        memset(table,-1,sizeof(table));
        for(int cnt2 = 0;cnt2 < pow[2];cnt2++){
            for(int cnt3 = 0;cnt3 < pow[3];cnt3++){
                for(int cnt5 = 0;cnt5 < pow[5];cnt5++){
                    for(int cnt7 = 0;cnt7 < pow[7];cnt7++){
                         ll den = go(den_len,cnt2,cnt3,cnt5,cnt7);
                         ll num = go(num_len,cnt2,cnt3,cnt5,cnt7);
                         ans = (ans + (den*num)%MOD )%MOD;
                    }
               }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
            
        
        
        
