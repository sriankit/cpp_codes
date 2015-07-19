#include<cstdio>
#include<iosteam>
#include<string>
#include<set>
using namespace std;
int a[100005];
int ok[100005];
int main(){
    int n,k,cnt=0,l,r;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(ok[a[i]]==0) cnt++;
        ok[a[i]]++;
        if(cnt==k){r=i;break;}
    }
    if(cnt<k) puts("-1 -1");
    else{
        for(int i=1;i<=n;i++)
            if(ok[a[i]]>1) ok[a[i]]--;
        else {l=i;break;}
        printf("%d%d\n",l,r);
    }
    return 0;
}
