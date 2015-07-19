#include<stdio.h>
/*
void print (long *a,long long max,int n,int k){
    int i;
    long long sum=a[n-1];
    int *flag=(int*)calloc(n,sizeof(int));
    for(i=n-1-1;i>=0;i--){
        if(sum+a[i]>max){
            sum=a[i];
            flag[i]=1;
            k--;
        }
        else sum+=a[i];
    }
    k--;
    if(k==0){
        for(i=0;i<n;i++){
            printf("%ld ",a[i]);
            if(flag[i]==1) printf("\ ");
        }
*/    
int p(long long max,long *a,long n,long k){
    int i;
    long long sum=a[n-1];
    for(i=n-1-1;i>=0&&k!=0;i--){
        if(a[i]>max) return 0;
        if(sum+a[i]>max){
            sum=a[i];
            k--;
        }
        else sum+=a[i];
    }
    if(i<0&&k==0) return 0; 
    return 1;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int bookn,writen,i;
        scanf("%d%d",&bookn,&writen);
        long arr[bookn];
        long long hi=0;
        for(i=0;i<bookn;i++){
            scanf("%ld",&arr[i]);
            hi+=arr[i];
        }
        long lo=0;
        while(1){
            if(lo>hi)
                break;
            long long mid=(lo+hi)/2;
            if(p(mid,arr,bookn,writen)==1) hi=mid-1;
            else lo=mid+1;
        }
        //print(arr,lo);
        printf("%ld\n",lo);
    }
    return 0;
}
            
