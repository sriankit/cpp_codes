#include<stdio.h>
#define MIN(x,y) (((x)<(y))?(x):(y))
int a[1001];
int arr[1001];
int map[1001];
int visited[1001];
int main(){
    int t=1,n,ans,s,i;
    //scanf("%d",&t);
    scanf("%d",&n);
    while(n){
        memset(a,0,sizeof(a));
        memset(arr,0,sizeof(arr));
        memset(map,0,sizeof(map));
        memset(visited,0,sizeof(visited));
        int gmin,min,cnt;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            arr[a[i]]=1;
        }
        int j=0;
        for(i=0;i<1001&&j<n;i++)
            if(arr[i])
                map[a[j++]]=i;
        gmin=map[a[0]];
        ans=0;
        for(i=0;i<n;i++){
            if(!visited[a[i]]){
                min=j=a[i];
                visited[j]=1;
                cnt=1;
                int s=j;
                while(!visited[map[j]]){
                    j=map[j];
                    s+=j;
                    if(j<min) min=j;
                    visited[j]=1;
                    cnt++;
                }
                if(cnt>1){
                    ans+=MIN(s+(cnt-2)*min,s-min+gmin+(cnt-2)*gmin+2*(gmin+min));
                }
            }
        }
        printf("Case %d: %d\n\n",t,ans);
        t++;
        scanf("%d",&n);
    }
    return 0;
}           
