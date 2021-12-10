#include "stdio.h"
#include "stdlib.h"
#include "omp.h"

typedef long long ll;

ll sumOfDigits(ll n)
{
    ll sum = 0;
    while (n != 0)
    {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}

void parallelSum(ll *arr, int n, int x)
{
    ll sum = 0, prod = 1;
    ll i;

#pragma omp parallel for private(i) shared(arr, n) reduction(+                  \
                                                             : sum) reduction(* \
                                                                              : prod)
    for (i = 0; i < n; i++)
    {
        // printf("Thread %d: Array element at %lld is %lld\n", omp_get_thread_num(), i, *arr);
        sum += sumOfDigits(*arr);
        arr++;
    }

    if (sum != 0)
    {
        printf("Sum of digits of factors for %d is %lld\n", x, sum);
    }
}

int factorize(ll *arr, ll num)
{
    ll i;
    int count = 0;

    for (i = 2; i < num; ++i)
    {
        if (num % i == 0)
        {
            *(arr + count) = i;
            count++;
        }
    }

    return count;
}

int main()
{
    ll x;
#pragma omp parallel for schedule(dynamic, 1)
    for (x = 1; x <= 201; x++)
    {
        ll *arr, n, i;
        n = 10;

        arr = (ll *)malloc(sizeof(ll) * n);

        arr -= n;
        int count = factorize(arr, x);

        // for (i = 0; i < count; i++)
        // {
        //     printf("%d\n", *(arr + i));
        // }

        parallelSum(arr, count, x);
    }
}
