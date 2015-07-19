#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>

using namespace std;
typedef long long ll;
/*Main code begins now */
long long arr[100005];
long long pre[100005];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(pre,0,sizeof(pre));
		int n;
		scanf("%d",&n);
		ll sum=0;
		for(int i=0;i<n;i++){					
			scanf("%lld",&arr[i]);
			sum+=arr[i];
		}
		sort(arr,arr+n);
	
		pre[0]=0;
		for(int i=0;i<n;i++){
			pre[i+1]=pre[i]+arr[i];
		}	
		int ans=0;
		for(int i=n-1;i;i--){
			if(arr[i]<sum-arr[i]) {
				ans=i;				
				break;
			} 
			else sum-=arr[i];
		}
		if(ans>1) printf("%d\n",ans+1);
		else puts("-1");
	}
	return 0;
}
















