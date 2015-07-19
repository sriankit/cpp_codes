#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define n 14 /* Then number of nodes */
int dist[n][n];

void printDist() {
    int i, j;
    printf("    ");
    for (i = 0; i < n; ++i)
        printf("%4c", 'A' + i);
    printf("\n");
    for (i = 0; i < n; ++i) {
        printf("%4c", 'A' + i);
        for (j = 0; j < n; ++j)
            printf("%4d", dist[i][j]);
        printf("\n");
    }
    printf("\n");
}

void floyd_warshall() {
    int i, j, k;

    for (k = 0; k < n; ++k)
        #pragma omp parallel for private(i,j)
        for (i = 0; i < n; ++i)
            for (j = 0; j < n; ++j)                
                if ((dist[i][k] * dist[k][j] != 0) && (i != j))                    
                    if ((dist[i][k] + dist[k][j] < dist[i][j]) || (dist[i][j] == 0))
                        dist[i][j] = dist[i][k] + dist[k][j];
}

int main(int argc, char *argv[]) {
    double start,stop;
    
    int i, j;
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            if (i==j)
                dist[i][j]=0;
            else
                dist[i][j] = 1 + (rand() % 10);

    printDist();

    //start = omp_get_wtime();
    floyd_warshall();
    //stop = omp_get_wtime();

    printDist();

    //printf("time %f\n",stop-start);

    return 0;
}
