#include<stdio.h>
 
 
int main()
{
    int t;
    long n,ans;
    long mod=1000000007;
    scanf("%d",&t);
    while(t--)
    {
         long long a[2][2]={2,1,2,0};
         scanf("%ld",&n);
         if(n==1)
          ans=1;
         else if(n==2)
          ans=3;
 
        else
        {
         int stack[50];
         int top=0;
         n=n-2;
         while(n!=1)
         {
             stack[top++]=n;
             n/=2;
         }
         top--;
         while(top>=0)
         {
             long temp[2][2]={0};
             temp[0][0]=(a[0][0]*a[0][0]+a[0][1]*a[1][0])%mod;
             temp[0][1]=(a[0][0]*a[0][1]+a[0][1]*a[1][1])%mod;
             temp[1][0]=(a[1][0]*a[0][0]+a[1][1]*a[1][0])%mod;
             temp[1][1]=(a[1][0]*a[0][1]+a[1][1]*a[1][1])%mod;
 
             a[0][0]=temp[0][0];
             a[0][1]=temp[0][1];
             a[1][0]=temp[1][0];
             a[1][1]=temp[1][1];
 
             if(stack[top]%2)
             {
                long temp[2][2]={0};
                temp[0][0]=(a[0][0]*2+a[0][1]*2)%mod;
                temp[0][1]=a[0][0];
                temp[1][0]=(a[1][0]*2+a[1][1]*2)%mod;
                temp[1][1]=a[1][0];
 
                a[0][0]=temp[0][0];
                a[0][1]=temp[0][1];
                a[1][0]=temp[1][0];
                a[1][1]=temp[1][1];
             }
            top--;
          }
 
         ans=(3*a[0][0]+a[1][0])%mod;
        }
      printf("%ld\n",ans);
     }
return 0;
}
