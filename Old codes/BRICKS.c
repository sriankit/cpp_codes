#include<stdio.h>
typedef long long ll;
int main(){
    int t;
    ll a1,a2,b1,b2;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld%lld%lld",&a1,&a2,&b1,&b2);
        ll np=(a1<b1)?a1:b1;
        ll ans=0;
        if(a2!=b2){
            if(np>=1){
                ans=(np-1)*3+2;
                ans+=(a1-np>0)+(b1-np>0)+1;
                printf("%lld\n",ans);
            }
            else printf("%d\n",(a1>0)+(b1>0));
        }
        else{
            if(np>=1){
                ans=(np-1)*2+1;
                ans+=(a1-np>0)+(b1-np>0)+1;
                printf("%lld\n",ans);
            }
        }
    }
    //system("pause");
    return 0;
}
            
