#include<cstdio>
#include<algorithm>
#include<utility>
#include<string.h>
typedef long long ll;
using namespace std;
int n;
ll table[100005],arr[100005];
ll go(int i,int pre,int tun){
    if(tun == 0 && table[i] != 0) return table[i];
    if(tun == 1) return go(i+pre,pre,0);
    else{
        ll ans = 0;
        int sm = 0;    
        if(i<n) {sm+=arr[i],ans = max(ans,sm + go(i+1,1,1));}
        if(i+1<n) {sm+=arr[i+1],ans = max(ans,sm + go(i+2,2,1));}
        if(i+2<n) {sm+=arr[i+2],ans = max(ans,sm + go(i+3,3,1));}
        return table[i]=ans;
    }
} 
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(table,0,sizeof(table));
        for(int i =0 ;i <n ;i++)
            scanf("%d",&arr[i]);
        printf("%lld\n",go(0,0,0));
    }
    return 0;
}
