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
 
#define FOR(i,a,b)					for(int i=a;i<b;i++)
#define REP(i,n)					FOR(i,0,n)
#define pb						 	push_back
#define s(n)						scanf("%d",&n)
#define sl(n) 						scanf("%lld",&n)
#define sf(n) 						scanf("%lf",&n)
#define fill(a,v) 					memset(a, v, sizeof a)
#define sz							size()
#define INF							(int)1e9
#define EPS							1e-9
#define bitcount					__builtin_popcount
#define all(x)						x.begin(), x.end()
#define gcd							__gcd
#define maX(a,b)					(a>b?a:b)
#define miN(a,b)					(a<b?a:b)
 
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long ll;
typedef pair<int, int > PII;

/*....main code begins now....*/

#define MAX 1000005
 
int t[2000020];
 
int update(int v,int tl,int tr,int val){
    if(val>t[v]) return -1;
    if(tl==tr){ 
        t[v]-=val;
        return tl;
    }
    else{
        int tm=(tl+tr)>>1;
        int ret=update(v<<1,tl,tm,val);
        if(ret==-1) ret=update(v<<1|1,tm+1,tr,val);
        t[v]=max(t[v<<1],t[v<<1|1]);
        return ret;
    }
}
 
int main(){
    int tt;
    scanf("%d",&tt);
    while(tt--){
        int k,n;
        scanf("%d%d",&k,&n);
        //memset(t,k,sizeof(t));
        FOR(_i,1,2*MAX) t[_i]=k;
        int ans=0;
        int rem=n;
        long long sub=0;
        while(rem){    
            char s[10]={'\0'};
            scanf("%s",s);
            int r,q;///repeats and quantity
            if(s[0]=='b'){
                scanf("%d%d",&r,&q);
                sub+=r*q;
                rem-=r;
                while(r--)
                    ans=max(ans,update(1,0,n-1,q));
            }
            else{
                q=atoi(s);
                sub+=q;
                ans=max(ans,update(1,0,n-1,q));
                rem-=1;
            }
        }
        printf("%d %lld\n",ans+1,k*(ans+1)-sub);
    }
    return 0;
}
