/* Ankit Srivastava */
#include <bits/stdc++.h>
using namespace std;
void block_swap(int *a, int sz, int n)
{
	int st1 = 0, st2 = n - sz;
	for (int i = 0; i < sz; ++i)
	{
		swap(a[i + st1], a[i + st2]);
	}
}
void rotate(int *a, int l, int n)
{	
	if(n == 0 || l == n) return;
	if (l <= n / 2)
	{
		block_swap(a, l, n);
		rotate(a, l, n - l);
	}
	else if (l > n / 2)
	{
		block_swap(a, n - l, n);
		rotate(a + n - l, 2 * l - n, n - l);
	} else {
		block_swap(a, l, n);
	}
}
int main() 
{
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
	}
	int l;
	scanf("%d", &l);
	rotate(a, l, n);
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	return 0;
}