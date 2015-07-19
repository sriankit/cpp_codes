#include<iostream>
using namespace std;
int disc[100],visited[100],nv,adj[100][100];
void dfs(int st){
    if(visited[st]) return;
    int i;
    for(i=1;i<=nv;i++){
        if(adj[st][i]&&disc[i]==0){
            disc[i]=1;
            dfs(i);
        }
    }
    visited[st]=1;
    printf("%d ",st);
}
int main(){
    int i,j;
    cout<<"Enter the number of vertices:";
    cin>>nv;
    cout<<"Enter the adjacency matrix:";
    for(i=1;i<=nv;i++)
        for(j=1;j<=nv;j++)
            cin>>adj[i][j];
    cout<<"implementing DFS:\n";
    for(i=1;i<=nv;i++){
        if(visited[i]) continue;
        disc[i]=1;
        dfs(i);
    }
    system("pause");
    return 0;
}
