#include<stdio.h>
#include<stdlib.h>
#define swap(a,b) {int t=a;a=b;b=t;}
void quick(int *a,int p,int r){
    if(p<r){
        int q=split(a,p,r);
        quick(a,p,q-1);
        quick(a,q+1,r);
    }
}
int split(int *a,int p,int r){
    int x=a[r];
    int i=p-1;
    int j;
    for(j=p;j<=r-1;j++){
        if(a[j]<=x){
            i++;
            swap(a[i],a[j])
    	}
    }
    swap(a[i+1],a[r])
    return i+1;
}
int main(){
    int n;
    //printf("enter number of elements:");
    scanf("%d",&n);
    //printf("enter elements:\n");
    int *a=(int*)calloc(n+1,sizeof(int));
    int i;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    quick(a,1,n);
    //printf("Sorted array:");
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
    return 0;
}
    
