#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int num1[20];
int num2[20];
int a1[32000];
int a2[32000];
int max1,max2,n,N;
int cmp(const void*x,const void *y){
    return *(int*)x-*(int*)y;
}
void find_ans(int*arr,int i){
    if(i<n){
            arr[i]=1;
            find_ans(arr,i+1);
            arr[i]=0;
            find_ans(arr,i+1);
        }
    else{
        int j,s1=0,s2=0;
        for(j=0;j<n;j++){
            //printf("%d ",arr[j]);
            s1+=arr[j]*num1[j];
            s2+=arr[j]*num2[j];
        }
        if(k==1 )a1[max1++]=s1;
        else a2[max2++]=s2;
        //printf("\n");
        //cnt++;
    }
}
int main(){
    int l,r;
    int i;
    scanf("%d%d%d",&N,&l,&r);
    for(i=0;i<N/2;i++)
        scanf("%d",&num1[i]);
    for(;i<N;i++)
        scanf("%d",&num2[i-N/2]);
    n=N/2;
    int arr[n+4];
    memset(arr,0,sizeof(arr));
    find_ans(arr,0,1);
    puts("lucky");
    n=N-N/2;
    memset(arr,0,sizeof(arr));
    find_ans(arr,0,2);
    puts("lucky2");
    //qsort(a1,max1,sizeof(int),cmp);
    //qsort(a2,max2,sizeof(int),cmp);
    sort(a1,a1+max1);
    sort(a2,a2+max2);
	//int i=0,j=n-1;
    /*for(i=0;i<max1;i++) printf("%d ",a1[i]);
    printf("\n");
    for(i=0;i<max2;i++) printf("%d ",a2[i]);
    */
    long long ans=0,k;
    for(i=0;i<max1;i++){
        k=upper_bound(a2,a2+max2,r-a1[i])-lower_bound(a2,a2+max2,l-a1[i]);
        if(k>0) ans+=k;
    }
    printf("%lld ",ans);
    //system("pause");
    return 0;
}
