#include <stdio.h>
#include <omp.h>

void backSubstitution(double a[20][20], double y[20], int n) {
	double x[20];
	printf("\nSolutions:\n");
	int i, k;
	for(k = n - 1; k >= 0; k--) {
		x[k] = y[k];
		for(i = k - 1; i >= 0; i--)
			y[i] -= x[k] * a[i][k];
		printf("x%d = %lf\n", k, x[k]);
	}
}

void gaussJordan(double a[][20], double b[20], int n) {
	int i, j, k;
	double y[20];
	for(k = 0; k < n; k++) {
		for(j = k + 1; j < n; j++)
			a[k][j] /= a[k][k];
		y[k] = b[k] / a[k][k];
		a[k][k] = 1;
		#pragma omp parallel for
		for(i = k + 1; i < n; i++) {
			for(j = k + 1; j < n; j++) {
				a[i][j] -= (a[i][k] * a[k][j]);
			}
			b[i] -= (a[i][k] * y[k]);
			a[i][k] = 0;
		}
	}
	backSubstitution(a, y, n);
}

int main(int argc, char const *argv[]) {
	double a[20][20], b[20];
	int n, i, j;
	printf("Enter number of variables: ");
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		printf("\nEnter coefficients of equation %d: ", i + 1);
		for(j = 0; j < n; j++)
			scanf("%lf", &a[i][j]);
		printf("Enter the constant: ");
		scanf("%lf", &b[i]);
	}
	gaussJordan(a, b, n);
	return 0;
}