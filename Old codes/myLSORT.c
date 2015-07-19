#include<stdio.h>
#define MIN(x,y) (((x)<(y))?(x):(y))
const long INF=394320443;
int n;
int ind[1001][1001][2];
int raw_ind[1001];
long long int table[1001][1001];
long long find_ans(int i,int j){
    if(table[i][j]!=-1) return table[i][j];
    //return table[i][j]=MIN((j-i+2)*ind[j][i][1]+find_ans(i,j+1),(j-i+2)*ind[j][i][0]+find_ans(i-1,j));
    long long int min=999999999,prob;
    int k;
    if(i-1>=1){
        /*ind=0;
        for(k=1;k<=n;k++){
            if(a[k]>0) ind++;
            if(a[k]==i-1) break;
        }
        a[k]=0;
        min=(j-i+2)*ind+find_ans(i-1,j);
        a[k]=i-1;*/
        min=ind[j][i][0]*(j-i+2)+find_ans(i-1,j);
    }
    if(j+1<=n){
        /*ind=0;
        for(k=1;k<=n;k++){
            if(a[k]>0) ind++;
            if(a[k]==j+1) break;
        }
        a[k]=0;
        prob=(j-i+2)*ind+find_ans(i,j+1);
        if(prob<min) min=prob;
        a[k]=j+1;*/
        prob=(j-i+2)* (ind[j][i][1])+find_ans(i,j+1);
        if(prob<min) min=prob;
    }
    if(min!=999999999) return table[i][j]=min;
    return 0;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int i,j,b;
        scanf("%d",&n);
        memset(ind,INF,sizeof(ind));
        memset(raw_ind,0,sizeof(raw_ind));
        memset(table,-1,sizeof(table));
        for(i=1;i<=n;i++){
            scanf("%d",&b);
            raw_ind[b]=i;
        }
        for(i=1;i<n;i++){
            ind[i][i][1]=raw_ind[i+1]-(raw_ind[i+1]>raw_ind[i]);
            for(j=i-1;j>0;j--){
                ind[i][j][1]=ind[i][j+1][1]-(raw_ind[i+1]>raw_ind[j]);
            }
        }
        for(j=2;j<=n;j++){
            ind[j][j][0]=raw_ind[j-1]-(raw_ind[j-1]>raw_ind[j]);
            for(i=j+1;i<=n;i++){
                ind[i][j][0]=ind[i-1][j][0]-(raw_ind[j-1]>raw_ind[i]);
            }
        }
        /*for(i=1;i<=n;i++){
            for(j=1;j<=n;j++)
                printf("%4d ",ind[i][j][1]);
            printf("\n");
        }
        printf("\n");
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++)
                printf("%4d ",ind[i][j][0]);
            printf("\n");
        }
        printf("\n");*/
        long long min=INF,k;
        for(i=1;i<=n;i++){
            if((k=raw_ind[i]+find_ans(i,i))<min) min=k;
            //printf("with %d min is %ld\n",i,k);
        }
        printf("%lld\n",min);
    }
    return 0;
}
