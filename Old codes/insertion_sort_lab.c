//a program to implement insertion sort
#include<stdio.h>
#include<stdlib.h>
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
    int x=0;
    for(i=1;i<n;i++){
        scanf("%d",&k);
        for(j=x;j>=0;j--){
            if(arr[j]<k) break;
            arr[j+1]=arr[j];
        }
        arr[j+1]=k;
        x++;
    }
    printf("Sorted array is:\n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    getchar();
    getchar();
    return 0;
}
