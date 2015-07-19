#include<algorithm>
#include<cstdio>
using namespace std;
int binarySearch(int *arr,int x,int size){
    int low = 0,high = size-1;
    int ans = 0;
    while(low <= high){
        int mid = (low + high) >> 1;
        if(arr[mid] > x) {
            high = mid - 1;
            ans = size - mid ;
        }
        else low = mid + 1;
    }
    return ans;
}

int main(){
    int arr[7];
    int n = 7;
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    sort(arr,arr+7);
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    while(1) {
        int q;
        scanf("%d",&q);
        printf("%d\n",binarySearch(arr,q,7));
    }
    
    system("pause");
    return 0;
}
