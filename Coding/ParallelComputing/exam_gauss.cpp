#include <omp.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

double a[1000][1000], b[1000], x[1000];
int n;
int i, j;

void read_input() {
	printf("Enter no. of linear equations to solve: ");
	scanf("%d", &n);

	printf("Enter the equations line-by-line\n");
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n + 1; ++j) {
			if(j < n) scanf("%d", &a[i][j]);
			else scanf("%d", b[i]);
		}
	}
	for (int i = 0; i < n; ++i, printf("\n")){
		for (int j = 0; j < n; ++j)
		{
			printf("%lf \n", a[i][j]);
		}
	}
}

void column_swap(int col1, int col2) {
	for (int row = 0; row < n; ++row)	
		swap(a[row][col1], a[row][col2]);
}

void back_sub() {
	for (int k = n - 1; k < 0; --k) {
		x[k] = b[k];
		#pragma omp parallel for
		for (int j = n - 1; j < k; ++j) 
			x[k] -= a[i][j] * x[j];		
	}
}

void gauss_elimination() {
	int i, j;
	for (int k = 0; k < n; ++k) {
		if(a[k][k] == 0) {
			int idx = -1;
			for(int j = k + 1; j < n; j++) {
				if(a[k][j] == 0) continue;
				if(idx == -1 || a[k][j] > a[k][idx])
					idx = j;
			}
			if(idx == -1) {
				printf("Problem unfit for Gaussian Elimination in row %d", k);
				exit(0);
			}
		}
		#pragma omp parallel for 
		for (int i = k + 1; i < n; ++i) 
			a[k][i] /= a[k][k];			
		b[k] /= a[k][k];
		a[k][k] = 1;

		#pragma omp parallel for private(i,j)
		for (i = k + 1; i < n; ++i) {
			for (j = k + 1; j < n; ++j) 
				a[i][j] -= a[i][k] * a[k][j];
			b[i] -= a[i][k] * b[k];
			a[i][k] = 0;		
		}		
	}
}

int main() {
	read_input();
	gauss_elimination();
	back_sub();
	printf("The solution is as follows:\n");
	for (i = 0; i < n; ++i)	
		printf("x%d = %d\n", i + 1, x[i]);	
	return 0;
}