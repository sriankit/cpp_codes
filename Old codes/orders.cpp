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
 
#define FOR(i,a,b)        			for(int i=a;i<b;i++)
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

#define MaxVal 200005

int tree[200005];

void update(int idx,int val){
	while(idx<=MaxVal){
		tree[idx]+=val;
		idx+=(idx & -idx);
	}
}
int freqTo(int idx){
	int sm=0;
	while(idx>0){
		sm+=tree[idx];
		idx-=(idx & -idx);
	}
	return sm;
}

int find_ans(int k,int n){
    int lo=1,hi=n,mid;
    while(lo<hi){
        mid=(lo+hi)/2;
        int f=freqTo(mid);
        //if(f==k) return mid;
        if(f<k) lo=mid+1;
        else hi=mid;
    }
    return lo;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(tree,0,sizeof(tree));
        int n;
        scanf("%d",&n);
        int arr[n],ans[n];
        FOR(_i,1,n+1) update(_i,1);
        //FOR(_i,1,n+1) printf("%d ",freqTo(_i));
        REP(i,n) scanf("%d",&arr[i]);
        int i=n;
        while(i){
            ans[i-1]=find_ans(i-arr[i-1],n);
            update(ans[i-1],-1);
            //printf("%d",ans[i-1]);
            //FOR(_i,1,n+1) printf("%d ",freqTo(_i));
            i--;
        }
        REP(_i,n) printf("%d ",ans[_i]);
        putchar('\n');
    }
    return 0;
}
