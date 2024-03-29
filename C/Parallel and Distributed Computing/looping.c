#include "stdio.h"
#include "stdlib.h"
#include "omp.h"

typedef long long ll;
int main()
{
    ll *arr, n, i;
    printf("Enter the no of elements in the array: ");
    scanf("%lld", &n);

    arr = (ll *)malloc(sizeof(ll) * n);

    for (i = 0; i < n; i++)
    {
        scanf("%lld", arr++);
    }

    ll sum = 0, prod = 1;

    arr -= n;

    int crit = 0;

#pragma omp parallel for private(i) shared(arr, n, crit) reduction(+:sum) reduction(*:prod)
    for (i = 0; i < n; i++)
    {
        printf("Thread %d: Array element at %lld is %lld\n", omp_get_thread_num(), i, *arr);
        sum += *arr;
        prod *= *arr;
        arr++;

        #pragma omp critical (crit)
        {
            crit = i;
            printf("\n%d is in it's critical section - process %d.\n", crit, omp_get_thread_num());
        }
    }

    printf("Sum of elements is %lld\n", sum);
    printf("Product of elements is %lld\n", prod);
}
