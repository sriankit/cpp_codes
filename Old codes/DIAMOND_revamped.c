#include<stdio.h>
int arr[2009];
double table[2009][2009];
double val(int i,int j){
    if(i<0||j<0) return 0.0;
    return table[i][j];
}
void init(){
       int i,j;
       arr[0]=1;
       table[0][0]=1.0;
       table[1][0]=table[1][1]=.5;
       for(j=2;j<2005;j++)
                table[j][0]=(arr[0]+arr[j])/2.0+.25*table[j-2][0];
       arr[0]=0;
       for(i=1;i<2005;i++){
            arr[i]=1;
            for(j=i;j<2005;j++)
                table[j][i]=(arr[0]+arr[j])/2.0+.5*val(j-2,i-1)+.25*val(j-2,i-2)+.25*val(j-2,i);
            arr[i]=0;
        }
}
int main(){
    init();
    int t,n,a,i;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        double ans=0.0;
        for(i=0;i<n;i++){
            scanf("%d",&a);
            ans+=a*table[n-1][i];
        }
        printf("%.7lf\n",ans);
    }
    //system("pause");
    return 0;
}
    
