#include<cstdio>
#include<map>
using namespace std;
map<int,int>ma;
int main(){
    int n,c,i,cnt=0,a;
    scanf("%d%d",&n,&c);
    i=0;
    int s=0;
    while(i<n && cnt<c){
        scanf("%d",&a);
        if(ma[a]==0){
            cnt++;
            ma[a]=1;
        }
        else if(cnt==1)
            s=i;
    i++;
    }
    if(cnt==c) printf("%d %d",s,i);
    else puts("-1 -1");
    return 0;
}
