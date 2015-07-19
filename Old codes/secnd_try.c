#include<stdio.h>
typedef long long int L;
#define MOD 1000000007
L Mod(L n){
    if(n<0) return Mod(n+MOD);
    else return n%MOD;
}
/*
inline L scanInt()
{
L noRead=0;
char p=getchar_unlocked();
for(;p<33;){p=getchar_unlocked();};
while(p>32)
{
noRead = (noRead << 3) + (noRead << 1) + (p - '0');
p=getchar_unlocked();
}
return noRead;
};
 */
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
  L M[2][2] = {{1,1},{1,0}};
  power(F, n/2);
  multiply(F, F);
  if( n%2 != 0 )
     multiply(F, M);
}
L fib(L n)
{
    L s;
    if(n==0) return 0;
    else if(n==1) return 1;
              L F[2][2]={{1,1},{1,0}};
              power(F,n);
              s=F[1][0];
              s=Mod(s);
    return s;
}
 
L luc(L n)
{
    L s;
    if(n==0) return 2;
    else if(n==1) return 1;
              L F[2][2]={{1,1},{1,0}};
              power(F,n);
              s=F[1][0]+2*F[1][1];
              s=Mod(s);
              return s;
}
 
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        L n,N;
        //N=scanInt();
	scanf("%lld",&N);
	if(N==0||N==1) {puts("0");continue;}
    n=N+5;
    //N=scanInt();
    //printf("%ld\n",luc(N));
    L ans=(Mod(Mod(n)*luc(n))-fib(n));
    ans=(ans*400000003)%MOD;
    //ans=Mod(ans-2*fib(n-1));
    //ans=Mod(ans-2*fib(n-2));
    //ans=Mod(ans-3*fib(n-3));
    ans=Mod(ans+2*fib(N)-4*fib(N+4)-fib(N+2));
    printf("%ld\n",ans);
    //printf("%ld\n",Mod(Mod((Mod(n)*luc(n)-fib(n))/5)-2*fib(n-1)-2*fib(n-2)-Mod(3*fib(n-3)+2*fib(N))));
    }
    return 0;
}
