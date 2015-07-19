#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
pair<int,int> arr[1005];
int main(){
    int s,n,a,b,d=0,i;
    scanf("%d%d",&s,&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        arr[i]=make_pair(a,b);
    }
    sort(arr,arr+n);
    for(i=0;i<n;i++) printf("%d ",arr[i].first);
    for(i=0;i<n&&!d;i++){
        if(s>=arr[i].first)
            s+=arr[i].second;
        else break;
    }
    if(i==n) puts("NO");
    else puts("YES");
    return 0;
}
            
