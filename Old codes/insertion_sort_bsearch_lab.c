#include<stdio.h>
#include<stdlib.h>
int search(int *a,int lo,int hi,int key){
    if(lo>hi)
        return hi;
    int mid=(lo+hi)/2;
    if(a[mid]==key) return mid;
    else if(a[mid]<key) return search(a,mid+1,hi,key);
    else return search(a,lo,mid-1,key);
}
int main(){
    int n,j,i,k;
    printf("enter the number of elements in the array:");
    scanf("%d",&n);
    if(n==0){
        printf("please insert atleast one element");
        exit(0);
    }
    int *arr=(int*)calloc(n,sizeof(int));
    printf("enter the elements:\n");
    scanf("%d",&arr[0]);
    for(i=1;i<n;i++){
        scanf("%d",&arr[i]);
        int loc=search(arr,0,i-1,arr[i]);
        int t=arr[i];
        for(j=i-1;j!=loc;j--)
            arr[j+1]=arr[j];
        arr[loc+1]=t;
    }
    printf("Sorted array is:\n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    getchar();
    getchar();
    return 0;
}
    
