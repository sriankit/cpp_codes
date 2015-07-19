#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef long long ll;
int main()
{
	char n[210], m[210];
	int k, t, len, i;
	ll pow2[17], temp;
	pow2[0] = 1;
	for(i=1; i<17; i++)
		pow2[i] = pow2[i-1] << 1;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%s%s%d",n,m,&k);
		len = strlen(n);
		if((n[len-1]-'0')&1) printf("1\n");
		else
		{
			i = (len<k)?len:k;
			sscanf(&n[len-i], "%lld", &temp);
            for( ; i>0; i--)
			{
				if(!(temp&(pow2[i]-1)))
				{
					printf("%lld\n", pow2[i]);
					break;
				}
			}
		}
	}
	return 0;
}
