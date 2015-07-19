#include<cstdio>
#include<set>
using namespace std;
int tree[1000006];
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
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int *arr=new int[n];
        for(i=0;i<n;i++)
            scanf("%d",arr+i);
        set<int> mset;
        long long ans=0;
        for(j=n-1;j>=0;j--){
            update(arr[j],1);
            ans+=arr[j]*(n-j-freqTo(arr[j]));
        }
        printf("%lld\n",ans);
    }
    return 0;
}
