#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
int visited[100005];
const long long MOD=1000000007;
int dfs(vector<int> arr[],int u){
	int c=0;
	for(vector<int>::iterator it = arr[u].begin();it!=arr[u].end();it++){
		if(visited[*it]==0) {
			visited[*it]=1;
			c+= 1 + dfs(arr,*it);
		}
	}
	return c;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(visited,0,sizeof(visited));
		int n,m;
		scanf("%d%d",&n,&m);
		vector<int> arr[n];
		for(int i = 0;i < m; i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			u--,v--;
			arr[u].push_back(v);
			arr[v].push_back(u);
		}
		int cnt=0;
		long long ans=1;
		for(int i=0;i<n;i++){
			if(visited[i]==0) {
				visited[i]=1;
				int c = 1 + dfs(arr,i);
				cnt++;
				ans=(ans*c)%MOD;
			}
		}
		printf("%d %lld\n",cnt,ans);
	}
	return 0;
	
}
