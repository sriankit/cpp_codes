#include<stdio.h>
typedef long long ll;
ll arr[10005],n;
ll ok(ll b[10005],ll x){
    ll t=b[0]-x;
    ll i=1;
    while(i<n){
        if(b[i]+t>=x){
            t=b[i]+t-x;
            //b[i]=x;
            i++;
        }
        else break;
    }
    if(i<n) return 0;
    return 1;
}
int main(){
    ll t;
    scanf("%lld",&t);
    while(t--){
        ll i;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);
        ll lo=0,hi=arr[0];
        while(lo<=hi){
            ll mid=(lo+hi)/2;
            if(ok(arr,mid)) lo=mid+1;
            else hi=mid-1;
        }
        printf("%lld\n",hi);
    }
    return 0;
}
