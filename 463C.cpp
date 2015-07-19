#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[2001][2001];
ll d1[4009], d2[4009];
pair<int,int> p[2];
ll best[2];
inline void upd(int polarity, int i, int j, ll val) {
	if(best[polarity] <= val) {
		best[polarity] = val;
		p[polarity].first = i + 1;
		p[polarity].second = j + 1;
	}
}
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int v;
			scanf("%d", &v);
			d1[i + j] += v;
			d2[i - j + n - 1] += v;
			a[i][j] = v;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			upd((i + j) & 1, i, j, d1[i + j] + d2[i - j + n - 1] - a[i][j]);
		}	
	}
	printf("%lld\n", best[0] + best[1]);
	if(p[0] > p[1]) swap(p[0], p[1]);
	printf("%d %d %d %d\n", p[0].first, p[0].second, p[1].first, p[1].second);
	return 0;	 
}