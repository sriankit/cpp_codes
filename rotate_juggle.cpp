/* Ankit Srivastava */
#include <bits/stdc++.h>
using namespace std;
void rotate(int *a, int l, int n) 
{
	for (int cy = 0; cy < __gcd(l, n); ++cy)
	{
		int i = cy;
		int temp = a[i];
		while(1)
		/*
		Loop Invariant: 
		cy is the index we started off with
		i is the index we need to fill
		next is index which will be referred for being filled
		hence, if some i requests cy for getting filled, it has to be the last one
		and we shall end the loop and assign the value previously stored in temp.
		*/	
		{
			int next = i + l >= n ? i + l - n : (i + l);
			if(next == cy) {
				a[i] = temp;
				break; 
			} else {
				a[i] = a[next];
				i = next;
			}
		}

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