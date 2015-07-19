#include<stdio.h>
#include<string.h>
typedef long long ll;
const int MaxVal=100005;
ll tree[2][100005];
ll freqTo(int k,ll idx){
	ll sm=0;
	while(idx>0){
		sm+=tree[k][idx];
		idx-=(idx & -idx);
	}
	return sm;
}
void update(int k,int idx,ll val){
	while(idx<=MaxVal){
		tree[k][idx]+=val;
		idx+=(idx & -idx);
	}
}
/*inline int inp()
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
    };*/
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,q;
        //scanf("%d%d",&n,&q);
        n=inp();q=inp();
        memset(tree,0,sizeof(tree));
        while(q--){
            int a,c,b;
            ll v;
            //scanf("%d%d%d",&c,&a,&b);
            c=inp();a=inp();b=inp();
            if(c==0){
                scanf("%lld",&v);
                //v=inp();
                update(0,a,v);
                update(0,b+1,-v);
                update(1,a,v*(a-1));
                update(1,b+1,-v*b);
            }
            else{
                ll ans=0;
                ans=b*freqTo(0,b)-freqTo(1,b);
                ans-=(a-1)*freqTo(0,a-1)-freqTo(1,a-1);
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
