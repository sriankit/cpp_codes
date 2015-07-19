#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<int> adj[100005];
int d[100005],f[100005];
int color[100005];
int tym=0;
void dfs(int u){
	tym++;
	d[u]=tym;
	color[u]=1;
	for(vector<int>::iterator it=adj[u].begin();it!=adj[u].end();it++){
		if(color[*it]==0){
			dfs(*it);
		}
	}
	color[u]=2;
	tym++;
	f[u]=tym;	
}
int desc(int v,int u){
	//tru if a is desc of b
	if(d[u]<d[v] && d[v]<f[v] && f[v]<f[u]) return 1;
	return 0;
}
int main(){
	int n;
	scanf("%d",&n);
	int qs;
	scanf("%d",&qs);
	int root;
	scanf("%d",&root);
	for(int i=0;i<n-1;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(root);
	while(qs--){
		int x,y;
		scanf("%d%d",&x,&y);
		if(desc(x,y)) puts("1");
		else if(desc(y,x)) puts("-1");
		else puts("0");
	}
	return 0;
}
