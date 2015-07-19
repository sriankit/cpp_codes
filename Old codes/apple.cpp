#include<cstdio>
#include<algorithm>
#include<math.h>
typedef long long ll;
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	ll s=0;
	int arr[n];	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		s+=arr[i];
	}
	int avg=s/n;
	int ch[n];
	for(int i=0;i<n;i++)
		ch[i]=arr[i]-avg;
	ll zeros[n];
	zeros[0]=0;
	for(int i=1;i<n;i++)
		zeros[i]=zeros[i-1]+ch[i];
	sort(zeros,zeros+n);
	ll a=-zeros[n/2];
	ll ans=0;
	for(int i=0;i<n;i++){
		ans+=abs(a+zeros[i]);
	}
	printf("%lld",ans);
	return 0;
}
