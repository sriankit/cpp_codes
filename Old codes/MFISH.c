#include<stdio.h>
#include<stdlib.h>
long n,m;
const long INF=999999999;
int a[10001];
struct ship{
    int start;
    int len;
};
ship ships[10001];
long presum[10001];
int  cmp(const void *x1,const void *y1){
    struct ship *x=(struct ship*)x1,*y=(struct ship*)y1;
    return x->start-y->start;
}
long find_ans(int i,int st){
    if(i<m && st>=n) return -INF;
    if(i>=m) return 0;
    int j;
    long ans=0,cur;
    for(j=ships[i].start-ships[i].len-1;j<=ships[i].start;j++){
        if(j<=st && j<n)
            if((cur=presum[j+ships[i].len]-presum[j]+find_ans(i+1,j+ships[i].len))>ans) ans=cur;
    }
    return ans; 
}
int main(){
    scanf("%ld",&n);
    int i;
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        presum[i]=presum[i-1]+a[i];
    }
    scanf("%ld",&m);
    for(i=0;i<m;i++){
        scanf("%d%d",&ships[i].start,&ships[i].len);
    }
    qsort(ships,m,sizeof(ship),cmp);
    printf("%ld",find_ans(0,0));
    return 0;
}
