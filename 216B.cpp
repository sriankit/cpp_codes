/* Ankit Srivastava */
#include <bits/stdc++.h>
using namespace std;
int n, m;
std::vector<int> adj[101];
int vis[101];
int dfs(int u, int p, int l) {
	for (std::vector<int>::iterator it = adj[u].begin(); it != adj[u].end(); ++it)
	{
		int v = *it;
		if(u != p) {
			if(vis[v]) return l + 1;
			else
			{
				vis[v] = 1;
				return dfs(v, u, l + 1);
			}
		}
	}
	return l + 1;
}
int main() 
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		--a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int len = 0;
		if(!vis[i]) {
			vis[i] = 1;
			len = dfs(i, -1, 0);
			cout << i << " " << len << endl;
		}
		if(len > 1 and len % 2) ans++;
	}
	printf("%d\n", ans);
	return 0;
}