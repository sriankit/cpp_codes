#include<stdio.h>
#include<string.h>
int arr[2005];
int done[2005][2005];
double table[2005][2005];
double find_ans(int i,int j){
    if(i==j) return arr[i];
    if(j==i+1) return (arr[i]+arr[j])/2.0;
    if(done[i][j]) return table[i][j];
    done[i][j]=1;
    return table[i][j]=.5*(arr[i]+.5*find_ans(i+1,j-1)+.5*find_ans(i+2,j))+.5*(arr[j]+.5*find_ans(i,j-2)+.5*find_ans(i+1,j-1));
}
int main(){
    int t,n,i,j;
    scanf("%d",&t);
    //t=inp();
    while(t--){
        scanf("%d",&n);
        //n=inp();
        memset(done,0,sizeof(done));
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
            //arr[i]=inp();
        printf("\n%.9lf\n",find_ans(0,n-1));
        /*for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                printf("%.9lf ",table[i][j]);
            putchar('\n');
        }*/
    }
    system("pause");
    return 0;
}
