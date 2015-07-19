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
int tree[200005],rev[200005];
bool occur[200005];
set<int> sets;
map<int,int> ma;
struct info{
    char c;
    int x;
};
info input[200005];

//fenwick tree code

int MaxVal;
int freqTo(int idx){
	int sm=0;
	while(idx>0){
		sm+=tree[idx];
		idx-=(idx & -idx);
	}
	return sm;
}
void update(int idx,int val){
	while(idx<=MaxVal){
		tree[idx]+=val;
		idx+=(idx & -idx);
	}
}
int freqAt(int idx){
	int sm=tree[idx],y;
	if(idx>0){
		int z=idx-(idx & -idx);
		y=idx-1;
		while(y!=z){
			sm-=tree[y];
			y-=(y & -y);
		}
	}
	return sm;
}
//fenwick tree ends


int find_ans(int k,int n){
    int lo=1,hi=n,mid;
    while(lo<hi){
        mid=(lo+hi)/2;
        int f=freqTo(mid);
        //if(f==k) return mid;
        if(f<k) lo=mid+1;
        else hi=mid;
    }
    return rev[lo];
}

int main(){
    int q,x;
    char s[10]={'\0'};
    scanf("%d",&q);
    int k=0;
    REP(i,q){
        scanf("%s %d",s,&x);
        if(s[0]!='K') sets.insert(x);
        input[i].c=s[0];
        input[i].x=x;
    }
    set<int>::iterator it;
    int j=2;
    for(it=sets.begin();it!=sets.end();it++){
        ma[*it]=j;
        rev[j]=*it;
        j++;
    }
    MaxVal=j;
    int ele=0;
    int maxsofar=0;
    REP(i,q){
        x=ma[input[i].x];
        switch(input[i].c){
            case 'I':
                if(occur[x]==0) {update(x,1);ele++;maxsofar=max(maxsofar,x);occur[x]=1;}
                break;
            case 'D':
                if(occur[x]==1) {update(x,-1);ele--;occur[x]=0;}
                break;
            case 'K':
                if(input[i].x>ele) puts("invalid");
                else printf("%d\n",find_ans(input[i].x,maxsofar));
                break;
            case 'C':
                printf("%d\n",freqTo(x-1));
                break;
        }
    }
    return 0;
}
