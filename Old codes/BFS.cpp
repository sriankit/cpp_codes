#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<queue>
using namespace std;
queue<int> q;
int adj[1000][1000],i,j,k,n,top,v,visited[1000];
int main()
{
cout <<"enter no. of vertices\n";
cin >> n;
cout<<"enter adjacency marix";
for(i=1;i<=n;i++)
{
    for(j=1;j<=n;j++)
    {
    cin>>adj[i][j];
    }
}

v=1;
cout <<"implementing BFS:\n";
cout << v <<" ";
visited[v]=1;
k=1;
while(k<n)
{
for(j=n;j>=1;j--)
if(adj[v][j]!=0 && visited[j]!=1)
{
q.push(j);
top++;
}
v=q.front();
q.pop();
cout<<v<<" ";
k++;
visited[v]=1;
}
system("pause");
return 0;
}
