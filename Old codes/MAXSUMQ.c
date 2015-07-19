#include<stdio.h>
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int a[n];
        int i;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
            //a[i]=inp();
        int lmax=0,max=a[0],prev=0;
        long long int cnt=0,tr=0;
        for(i=0;i<n;i++){
            lmax+=a[i];
            if(lmax<a[i])
                lmax=a[i];
            if(lmax>max) max=lmax;
        }
        lmax=0;
        int flag=1;
        for(i=0;i<n;i++){
            lmax+=a[i];
            if(lmax<a[i]){
                flag=1;
                lmax=a[i];
                prev=i;
                tr=0;
            }
            if(flag) if(a[i]==0) tr++;
            else flag=0;
            if(lmax==max) {cnt++;cnt+=(a[i]==0 && tr>0)?(tr-1):tr;if(a[prev]!=a[i] && a[i]==max) cnt++;}
        }
        printf("%d %lld\n",max,cnt);
    }
    return 0;
}        
