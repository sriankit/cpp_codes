#include<stdio.h>
long arr[501][2];
long int n,table[10001]={-1};
const long INF=99999999;
long find_ans(long c){
    if(c<0) return INF;
    if(c==0) return 0;
    if(table[c]!=-1) return table[c];
    long min=INF,i,k;
    for(i=0;i<n;i++){
             if((k=arr[i][0]+find_ans(c-arr[i][1]))<min)
                                min=k;
    }
    return table[c]=min;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long int i,j;
        scanf("%d%d",&i,&j);
        int c=j-i;
        scanf("%d",&n);
        memset(table,-1,sizeof(table));
        for(i=0;i<n;i++)
            scanf("%ld%ld",&arr[i][0],&arr[i][1]);
        j=find_ans(c);
        if(j>=INF){
            puts("This is impossible.");
        }
        else{
            printf("The minimum amount of money in the piggy-bank is %ld.\n",j);
        }
    }
    return 0;
}
