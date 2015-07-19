#include<stdio.h>
#include<string.h>
#define MOD(x) ((x)%1000000007)
long freq[10];
long long find_ans(int sum,int n){
    if(n==1)
        return freq[sum];
    if(n==2){
        int i;
        long long ret=0;
        for(i=0;i<5;i++){
            if(freq[i]*freq[sum-i]!=0) printf("%d %d\n",i,sum-i);
            ret+=freq[i]*freq[sum-i];
        }
        return MOD(ret);
    }
    int i,j;
    long long ret=0;
    for(i=0;i<=9;i++){
        if(freq[i]<=0) continue;
        freq[i]--;
        ret+=(freq[i]+1)*find_ans(sum-i,n-1);
        freq[i]++;
    }
    return MOD(ret);
}
int main(){
    int t;
    char s[]="0123456789";
    scanf("%d\n",&t);
    while(t--){
        memset(freq,0,sizeof(freq));
        char c;
        int k;
        while((c=getchar())!='\n'&&c!=EOF){
            freq[strchr(s,c)-s]++;
        }
        long long ans=0;
        for(k=1;k<=4;k++)
            ans+=find_ans(9,k);
        /*for(k=3;k<=4;k++){
            for(j=0;j<=9;j++){
                freq[j]--;
                ans+=find_ans(9-j,)*/
        printf("%ld\n",MOD(ans));
    }
    return 0;
}
