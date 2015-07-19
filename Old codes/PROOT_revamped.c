#include<stdio.h>
#include<string.h>
int nxt=0;
int primes[50000];
int fac[50000];
void init(){
    int i,j,n=(int)1e5+1;
    int *arr=(int*)calloc(n,sizeof(int));
    for(i=2;i<n;i++){
        if(arr[i]) continue;
        primes[nxt++]=i;
        for(j=2*i;j<n;j+=i)
            arr[j]=1;
    }
}
long long int power(int x, unsigned int y,int mod)
{
    // printf("%d\n",y);
    long long int temp=0;
    if( y == 0)
        return 1;
    else if(y==1)
        return x;
    else if (y%2 == 0)
    {
        temp=power(x,y/2,mod)%mod;
        return (temp*temp)%mod;
    }
 
    else
    {
        temp=power(x,y/2,mod)%mod;
        return (x*((temp*temp)%mod))%mod;
    }
 
}
int main(){
    init();
    int p,q,r;
    while(scanf("%d%d",&p,&q),p+q){
        int s=p-1;
        memset(fac,0,sizeof(fac));
        int cnt=0,x,j;
        for(j=0;j<nxt;j++){
            if(s==1) break;
            x=primes[j];
            if(s%x==0){
                fac[cnt++]=x;
                while(s%x==0) s/=x;
            }
        }
        if(s!=1) fac[cnt++]=s;
        while(q--){
            scanf("%d",&r);
            int ans=1;
            for(j=0;j<cnt;j++){
                if(ans==0) break;
                if(power(r,(p-1)/fac[j],p)==1) ans=0;
            }
            if(ans) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
