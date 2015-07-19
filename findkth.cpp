/*
Median of two sorted arrays
*/
#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1000], b[1000];
void read() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}	
}
int findKth(int a[], int b[], int k, int n, int m) {	
	int lo = 0, hi = n - 1;
	while(lo <= hi) {
		int i = (lo + hi) >> 1;
		int ele = a[i];
		int indb = k - i - 1;
		if(i >= k) hi = i - 1;
		else if(indb >= m) lo = i + 1;
		else if(ele > b[indb]) {
			hi = i - 1;
		} else if(indb == 0 || ele >= b[indb - 1]) 
			return i;
		else			
			lo = i + 1;	
	}
	return -1;
}
void solve(int k) {
	int res = findKth(a, b, k, n, m);
	if(res == -1) {
		res = findKth(b, a, k, m, n);
		printf("%d\n", b[res]);
	} else printf("%d\n", a[res]);
}
int main(){
	read();
	while(1) {
		int k;
		cin >> k;
		solve(k);
	}
	return 0;
}