#include<stdio.h>
#include<string.h>
#include<map>
#define MaxVal 10005
typedef long long ll;
const ll MOD=5000000;
using namespace std;
map<ll,int>sort;
ll tree[52][10005];
ll Mod(ll x){
    if(x<0) return Mod(x+MOD);
    else return x%MOD;
}
ll freqTo(int i,int idx){
	ll sm=0;
	while(idx>0){
		sm=(sm+tree[i][idx])%MOD;
		idx-=(idx & -idx);
	}
	return sm;
}
void update(int i,int idx,ll val){
	while(idx<=MaxVal){
		tree[i][idx]+=val;
		tree[i][idx]%=MOD;
		idx+=(idx & -idx);
	}
}
ll freqAt(int i,int idx){
	ll sm=tree[i][idx],y;
	if(idx>0){
		int z=idx-(idx & -idx);
		y=idx-1;
		while(y!=z){
			sm-=tree[i][y];
			sm=Mod(sm);
			y-=(y & -y);
		}
	}
	return sm;
}
int main(){
    int n,k,l,i;
    scanf("%d%d",&n,&k);
    int arr[n];
    for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
            sort[arr[i]]=1;
        }
    int j=2;
    /*for(i=0;i<=100001&&j<=n+1;i++)
        if(sort[i]) sort[i]=j++;*/
    map<ll,int>::iterator it=sort.begin();
    for(it=sort.begin();it!=sort.end();it++)
        it->second=j++;
    int temp;
    for(i=0;i<n;i++){
        temp=sort[arr[i]];
        update(1,temp,1-freqAt(1,temp));
        for(j=2;j<=k;j++)
            update(j,temp,freqTo(j-1,temp-1)-freqAt(j,temp));
    }
    
    printf("%lld",Mod(freqTo(k,n+1)));
    return 0;
}
