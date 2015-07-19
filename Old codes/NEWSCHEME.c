#include<stdio.h>
#define Mod(a) a%1000000007
typedef unsigned long long int L;
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
void multiply(L F[2][2], L M[2][2])
{
  L x = F[0][0]*M[0][0] + F[0][1]*M[1][0];
  L y = F[0][0]*M[0][1] + F[0][1]*M[1][1];
  L z = F[1][0]*M[0][0] + F[1][1]*M[1][0];
  L w = F[1][0]*M[0][1] + F[1][1]*M[1][1];
  F[0][0] = Mod(x);
  F[0][1] = Mod(y);
  F[1][0] = Mod(z);
  F[1][1] = Mod(w);
}
void power(L F[2][2], L n)
{
  if( n == 0 || n == 1)
      return;
  L M[2][2] = {{2,3},{1,0}};
  power(F, n/2);
  multiply(F, F);
  if( n%2 != 0 )
     multiply(F, M);
}
int main()
{
    L n,s;
    int t;
    //t=inp();
    scanf("%d",&t);
    while(t--)
    {
              //n=inp();
              scanf("%lld",&n);
              if(n==1)
              {printf("4\n");continue;}
              L F[2][2]={{2,3},{1,0}};
              power(F,n-1);
              s=12*F[1][0];
              s=Mod(s);
              printf("%lld\n",s);
    }
    return 0;
}
