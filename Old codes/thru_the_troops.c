#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,arr[21][3],i,j,res;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            for(j=0;j<3;j++)
                scanf("%d",&arr[i][j]);
        int min=30000;
        for(res=0;res<3;res++){
            int sum=0;
            for(i=0,j=res;i<n-1;i++,j++,j%=3){
                    sum+=arr[i][j];
                }
                int temp=(arr[n-1][1]<arr[n-1][2])?arr[n-1][1]:arr[n-1][2];
                temp=(temp<arr[n-1][0])?temp:arr[n-1][0];
                sum+=temp;
                if(sum<min)
                    min=sum;
        }
        printf("%d\n",min);
    }
    return 0;
}
            
