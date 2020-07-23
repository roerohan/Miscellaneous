#include <stdio.h>
#include <omp.h>
#define N 5
int main(void) { 
    int i;
    int nProc = omp_get_max_threads();
    printf("Number of processors available: %d\n", omp_get_num_procs());
    printf("Maximum number of threads: %d\n", nProc);
    omp_set_num_threads(nProc - 2);

    printf("Dynamic adjustment of threads enabled: %s\n", omp_get_dynamic() ? "true" : "false");
    printf("Nested parallelism enabled: %s\n", omp_get_nested() ? "true" : "false");
    #pragma omp parallel private(i)
    {    
        printf("Number of threads: %d\n", omp_get_num_threads());
	printf("Current thread ID: %d\n", omp_get_thread_num());
        #pragma omp for             
        for (i = 0; i < N; i++) {
            puts("Hello World!");
        }
    }
}
