#include<stdio.h>
typedef long long int L;
#define MOD 1000000007
L Mod(L n){
    if(n<0) return Mod(n+MOD);
    else return n%MOD;
}

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
        scanf("%lld",&N);
	//N=scanInt();
    printf("%ld\n",luc(N));
    }
    return 0;
}
