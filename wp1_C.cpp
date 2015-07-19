#include<stdio.h>
#include<math.h>
#define EPS 1e-9
int main()
{
	int t;
	scanf("%d",&t);
	int cnt=0;
	while(t)
	{
		cnt++;
		int i,ans=0;
		double d=10000000.0;
		for(i=0;i<t;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			double m=(b*100*4)/(1.0*a*a);
			if(d-m>=0)
			{
				d=m;
				ans=a;
			}
		}
		printf("Menu %d: %d\n",cnt,ans);
		scanf("%d",&t);
	}
}