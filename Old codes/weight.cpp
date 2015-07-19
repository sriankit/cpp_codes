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
 
#define FOR(i,a,b)                              for(int i=a;i<b;i++)
#define REP(i,n)                                        FOR(i,0,n)
#define pb                                                      push_back
#define s(n)                                            scanf("%d",&n)
#define sl(n)                                           scanf("%lld",&n)
#define sf(n)                                           scanf("%lf",&n)
#define fill(a,v)                                       memset(a, v, sizeof a)
#define sz                                                      size()
#define INF                                                     (int)1e9
#define EPS                                                     1e-9
#define bitcount                                        __builtin_popcount
#define all(x)                                          x.begin(), x.end()
#define gcd                                                     __gcd
#define maX(a,b)                                        (a>b?a:b)
#define miN(a,b)                                        (a<b?a:b)
 
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long ll;
typedef pair<int, int > PII;
 
/*....main code begins now....*/

int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ll arr[n+5];
        FOR(i,1,n+1) scanf("%lld",&arr[i]);
        ll s=0,ans=0,v=0;
        for(int i=n;i>2;i--){
            s+=arr[i]*i;
            v+=arr[i];
            if(v<0) {
                s-=(i-2)*v;
                ans+=s;
                v=0;
                s=0;
            }
        }
        s+=arr[1]+2*arr[2];
        printf("%lld\n",ans+s);
    }
    return 0;
}
            
