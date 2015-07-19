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
//FastIO begin
#define BUFFERSIZE 2000000
char *ipos, *opos, InpFile[BUFFERSIZE], OutFile[BUFFERSIZE], DIP[20];
inline int ni(int flag=0) {

	while(*ipos <= 32) ++ipos;
	if ( flag  ) return (*ipos++ - '0'); /* For getting Boolean Characters */
	int x=0, neg = 0;char c;
	while( true ) {
		c=*ipos++; if(c == '-') neg = 1;
		else {
			if (c<=32) return neg?-x:x;
			x=(x<<1)+(x<<3)+c-'0';
		}
	}
}
inline void pi(int x,int flag = 1) {
	int y,dig=0;
	while (x||!dig) { y=x/10;DIP[dig++]=x-((y << 3) + (y << 1))+'0';x=y;}
	while (dig--) *opos++=DIP[dig];
	*opos++= flag ? '\n' : ' ';
}
inline void InitFASTIO() {
	ipos = InpFile; opos = OutFile;
	fread(InpFile,20000000,1,stdin);
}
inline void FlushFASTIO() {
	fwrite(OutFile,opos-OutFile,1,stdout);
}
//FastIO end

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
typedef long long LL;
typedef pair<int, int > PII;

#define MAX 300005

struct node{
    int l,r;
};

node t[4*MAX];
char s[MAX];

node make_data(char c){
    node res;
    res.l=c=='(';
    res.r=c==')';
    return res;
}

node combine(node i,node j){
    node res;
    res.l=j.l;
    res.r=i.r;
    int m=min(i.l,j.r);
    res.l+=i.l-m;
    res.r+=j.r-m;
    return res;
}

void build(char a[],int v,int tl,int tr){
    if(tl==tr)
        t[v]=make_data(a[tl]);
    else{
        int tm=(tl+tr)>>1;
        build(a,v<<1,tl,tm);
        build(a,v<<1|1,tm+1,tr);
        t[v]=combine(t[v<<1],t[v<<1|1]);
    }
}

void update(int v,int tl,int tr,int pos){

    if(tl==tr)
        swap(t[v].l,t[v].r);
    else{
        int tm=(tl+tr)>>1;
        if(pos<=tm) update(v<<1,tl,tm,pos);
        else update(v<<1|1,tm+1,tr,pos);
        t[v]=combine(t[v<<1],t[v<<1|1]);
    }
}

int main(){
    FOR(_i,1,11){
        printf("Test %d:\n",_i);
        int n,i;
        scanf("%d",&n);
        scanf("%s",s);
        build(s,1,0,n-1);
        int q;
        scanf("%d",&q);
        while(q--){
            scanf("%d",&i);
            if(i) update(1,0,n-1,--i);
            else if(t[1].l==0 && t[1].r==0) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}

