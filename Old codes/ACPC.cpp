#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<iterator>
using namespace std;
int main(){
    int t,n1,n2,i;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n1);
        int *a=new int[n1];
        for(i=0;i<n1;i++) scanf("%d",&a[i]);
        scanf("%d",&n2);
        int *b=new int[n2];
        for(i=0;i<n2;i++) scanf("%d",&b[i]);
        sort(a,a+n1);
        sort(b,b+n2);
        long long ans;
        k=upper_bound(b,b+n2,a[0]);
        ans=min(abs(a[0]-*k),abs(a[0]-*(k-1)));
    }
    return 0;
}
        
