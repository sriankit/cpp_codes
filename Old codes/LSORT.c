#include<stdio.h>
#include<string.h>
int n,i,t;
long long int table[1001][1001];
int a[1001],index[1001],taken[1001];
long long find_ans(int i,int j){
    if(table[i][j]!=0) return table[i][j];
    long long int min=999999999,prob;
    int k,ind;
    if(i-1>=1){
        ind=0;
        for(k=1;k<=n;k++){
            if(a[k]>0) ind++;
            if(a[k]==i-1) break;
        }
        a[k]=0;
        min=(j-i+2)*ind+find_ans(i-1,j);
        a[k]=i-1;
    }
    if(j+1<=n){
        ind=0;
        for(k=1;k<=n;k++){
            if(a[k]>0) ind++;
            if(a[k]==j+1) break;
        }
        a[k]=0;
        prob=(j-i+2)*ind+find_ans(i,j+1);
        if(prob<min) min=prob;
        a[k]=j+1;
    }
    if(min!=999999999) return table[i][j]=min;
    return 0;
}
int main(){
    scanf("%d",&t);
    while(t--){
        memset(table,0,sizeof(table));
	   scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            index[a[i]]=i;
        }
        int res=a[1];
        a[1]=0;
        long long min=1+find_ans(res,res),k;
        a[1]=res;
       // printf("%lld ",min);
	   for(i=2;i<=n;i++){
            res=a[i];
            a[i]=0;
            if((k=i+find_ans(res,res))<min) min=k;
            //printf("%lld ",k);
	    a[i]=res;
        }
        printf("%lld\n",min);
    }
    return 0;
}
        
