#include<stdio.h>
#define MaxVal 100005
typedef long long ll;
ll tree[100005];
ll freqTo(int idx){
	ll sm=0;
	while(idx>0){
		sm+=tree[idx];
		idx-=(idx & -idx);
	}
	return sm;
}
void update(int idx,ll val){
	while(idx<=MaxVal){
		tree[idx]+=val;
		idx+=(idx & -idx);
	}
}
int main(){
    int t,n,i;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int arr[n];
        bool sort[1000006]={0};
        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
            sort[arr[i]]=1;
        }
        int j=1;
        ll ans=0;
        for(i=1;i<=1000001;i++)
            if(sort[i]) sort[i]=j++;
        for(i=0;i<n;i++){
            ans+=freqTo(sort[arr[i]]);
            update(sort[arr[i]],arr[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
