#include<stdio.h>
#include<stdlib.h>
int intcmp(const void*x,const void*y){
    return *(long int*)x-*(long int*)y;
}
int p(long x,long *a,int n,int needed){
    int i;
    long k=a[0],cnt=1;
    for(i=1;i<n&&cnt!=needed;i++){
        if(a[i]>=k+x){
            cnt++;
            k=a[i];
        }
    }
    if(cnt!=needed) return 0;
    else return 1;
}
            
int main(){
    int t,n,c,i;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&c);
        long int arr[n];
        for(i=0;i<n;i++){
            scanf("%ld",&arr[i]);
        }
        qsort(arr,n,sizeof(int),intcmp);
        long int lo=0,hi=arr[n-1]-arr[0],mid;
        while(1){
            if(lo>hi)
                break;
            mid=(lo+hi)/2;
            if(p(mid,arr,n,c)==0) hi=mid-1;
            else lo=mid+1;
        }
        printf("%ld\n",hi);
    }
    return 0;
}
