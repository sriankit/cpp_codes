#include<iostream>
#include<algorithm>
using namespace std;
struct edge{
    int w;
    int i;
    int j;
};
bool operator < (edge a,edge b){
    return (a.w<b.w)?1:0;
}
int a[100][100];
int chosen[100];
int v,e;
int main(){
    cout<<"enter the number of vertices and edges: ";
    cin>>v>>e;
    cout<<"enter edges in format v1 v2 weight\n";
    edge *arr=new edge[e];
    //int *chosen=new int[v+1];
    
    int i,j;
    for(i=0;i<=v;i++) chosen[i]=0;
    for(i=1;i<=e;i++){
        cin>>arr[i].i>>arr[i].j>>arr[i].w;
    }
    sort(arr+1,arr+e+1);
    cout<<"sort success";
    for(i=1;i<=e;i++) cout<<arr[i].w<<" ";
    for(i=1;i<=v;i++)
        for(j=1;j<=v;j++)
            a[i][j]=0;
    printf("gud enuf");
    i=1;
    int cnt=0,ans=0;
    while(i<=e&&cnt<v-1){
        if(chosen[arr[i].i]&&chosen[arr[i].j]) continue;
        a[arr[i].i][arr[i].j]=arr[i].w;
        chosen[arr[i].i]=chosen[arr[i].j]=1;
        ans+=arr[i].w;
        cnt++;
        i++;
    }
    for(i=1;i<=v;i++){
        for(j=1;j<=v;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    cout<<"mincost is "<<ans;
    system("pause");
    return 0;
}
        
