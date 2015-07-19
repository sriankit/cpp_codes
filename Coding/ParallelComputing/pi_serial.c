#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ITER 50000000
int main(){
    int count = 0;
    int i;
    double start_time = clock();
    for(i=0;i<ITER;i++){
        double x = (double)rand()/RAND_MAX;
        double y = (double)rand()/RAND_MAX;
        if(x*x + y*y <= 1) count++;
    }
    double pi = 4*(double)count/ITER;
    printf("%0.15lf\nTime Taken = %lf seconds\n\n",pi, (clock() - start_time) / CLOCKS_PER_SEC);
    return 0;
}
