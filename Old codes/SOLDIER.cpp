#include<cstdio>
#include<cstring>
#include<cstdlib>
int intcmp(const void*x,const void *y){
    return *((long int*)x)-*((long int*)y);
}
long arr[102][3];
int n;
long p(int x,int mon){
    int check[7];
    memset(check,-1,sizeof(check));
    int i;
    for(i=x;i<n;i++){
        if(arr[i][2]<=6 && arr[i][2]>=1)
        if(check[arr[i][2]]==-1){
            mon-=arr[i][1];
            check[arr[i][2]]=arr[i][1];
        }
        else{
            if(check[arr[i][2]]>arr[i][1]){
                mon+=check[arr[i][2]]-arr[i][1];
                check[arr[i][2]]=arr[i][1];
            }
        }
    }
    //printf("\nprinting check:  ");
    for(i=1;i<=6;i++){
        //printf("%d ",check[i]);
        if(check[i]==-1) return 0;
    }
    //printf("\n");
    if(mon<0) return 0;
    return 1;
}
int main(){
    scanf("%d",&n);
    long money;
    scanf("%ld",&money);
    int i;
    for(i=0;i<n;i++)
        scanf("%d%d%d",&arr[i][2],&arr[i][1],&arr[i][0]);
    //sort(arr,arr+n);
    qsort(arr,n,3*sizeof(int),intcmp);
    //for(i=0;i<n;i++)
      //  printf("%d %d %d\n",arr[i][2],arr[i][1],arr[i][0]);
    int lo=0,hi=n-1;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(p(mid,money)==1)
            lo=mid+1;
        else hi=mid-1;    
    }
    //printf("\t%d\n",hi);
    if (hi>=0 && hi<n)
        printf("%d",arr[hi][0]);
    else
        puts("0");
    //system("pause");
    return 0;
}
