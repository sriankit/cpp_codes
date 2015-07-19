#include <stdio.h>
int n,i;
int arr[1000000][3];
int cur[1000000];
long long int mi(long long int a,long long int b)
{
	return a>b?b:a;
}
int chk(long long int mid)
{
	for(i=0;i<n;i++)
		cur[i]=arr[i][2];
	long long int ff=mid;
	for(i=0;i<n;i++)
	{
		if(mid==0)
			break;
		long long int cp=mi(arr[i][0],mi(mid,cur[i]));
		cur[i]-=cp;
		mid=mid-cp;
	}
	if(mid!=0)
		return 0;
	mid=ff;
	for(i=0;i<n;i++)
	{
		if(mid==0)
			break;
		long long int cp=mi(arr[i][1],mi(mid,cur[i]));
		cur[i]-=cp;
		mid=mid-cp;

	}
	if(mid!=0)
		return 0;
	else
		return 1;
}
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d%d",&arr[i][0],&arr[i][1],&arr[i][2]);
	long long int low=0,high=1000000000000L,mid,ans=-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(chk(mid))
		{
			low=mid+1;
			ans=mid;
		}
		else
			high=mid-1;
	}
	printf("%lld\n",ans);
	return 0;
}