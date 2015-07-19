#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k,l,j;
        scanf("%d",&n);
        int arr[20][3];
        int i;
        for(i=0;i<n;i++)
            scanf("%d%d%d",&arr[i][0],&arr[i][1],&arr[i][2]);
        int done=1;
        long min=999999;
        while(done<=3){
            k=done%3;
            l=(done+1)%3;
            long int cur=arr[0][k]+arr[1][l];
            for(i=2,j=(l+1)%3;i<n;i++,j=(j+1)%3){
                cur+=arr[i][j];
            }
            if (cur<min) {min=cur;printf("%ld ",min);}
            done++;
        }
        done=1;
        while(done<=3){
            k=(done+1)%3;
            l=(done)%3;
            int cur=arr[0][k]+arr[1][l];
            for(i=2,j=(l+2)%3;i<n;i++,j=(j+2)%3){
                cur+=arr[i][j];
            }
            if (cur<min) {min=cur;printf("%ld ",min);}
            done++;
        }
        printf("%ld\n",min);
    }
    return 0;
}
