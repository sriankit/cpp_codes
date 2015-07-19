#include "C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\lib\\gcc\\x86_64-w64-mingw32\\4.7.1\\include\\omp.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ITER 500000000

int main (int argc, char *argv[]) {
    omp_set_num_threads(100);
    int count = 0;
    #pragma omp parallel
    {
        srand(omp_get_thread_num());

        int count1 = 0;
        int i;
        for(i = 0;i < ITER / omp_get_num_threads();i++){
            double x = (double) rand() / RAND_MAX;
            double y = (double)rand() / RAND_MAX;
            if(x*x + y*y <= 1) count1++;
        }
        printf("Thread %d has count = %d\n", omp_get_thread_num(), count1);
        count+=count1;
    }
        printf("Total count = %d\n",count);
        double calc_pi = 4.0*count/ITER;
        printf("%0.15lf\n",4.0*count/ITER);
        double true_pi = 4.0 * atan(1.0);
        printf("Percentage Error = %lf\n", 100.0 * (true_pi - calc_pi) / true_pi);
	return 0;
}
