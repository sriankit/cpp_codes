#include<stdio.h>
typedef long long ll;
ll t3,tl3,s,i;
long long p(ll x){
    return (pow(x,6)*tl3-s*x*x*x+s*x*x-t3);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll t3,tl3,s,i;
        scanf("%lld%lld%lld",&t3,&tl3,&s);
        if(t3==tl3){
            if(t3==0){
                puts("6");
                printf("%lld ",s);
                for(i=1;i<6;i++)
                    printf("%d ",0);
            }
            else{
                int len=s/t3;
                printf("%lld\n",len);
                for(i=0;i<len;i++)
                    printf("%lld ",t3);
            }
        }
        else{
            ll r,mid,val;
            ll lo=2,hi=1;
            for(i=0;i<64;i++)
                hi*=2;
            while(lo<=hi){
                mid=(lo+hi)/2;
                val=p(mid);
                if(val==0) break;
                else if(val>0) hi=mid-1;
                else lo=mid+1;
            }
            r=mid;
            ll a=t3/(r*r);
            printf("%lld %lld",a,r);
        }
    }
    return 0;
}
                
