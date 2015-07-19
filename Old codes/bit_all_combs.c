#include<stdio.h>
int n;
long cnt=0;
void find_ans(int*arr,int i){
    if(i<n){
            arr[i]=1;
            find_ans(arr,i+1);
            arr[i]=0;
            find_ans(arr,i+1);
        }
    else{
        int j;
        for(j=0;j<n;j++)
            printf("%d ",arr[j]);
        printf("\n");
        cnt++;
    }
}
int main(){
    scanf("%d",&n);
    int arr[n+4];
    memset(arr,0,sizeof(arr));
    find_ans(arr,0);
    printf("\ntotal %ld",cnt);
    system("pause");
    return 0;
}
        
