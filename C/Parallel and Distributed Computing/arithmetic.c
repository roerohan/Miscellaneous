#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int calc_sum(int *nums, int n)
{
    int i, total = 0;
    for (i = 0; i < n; i++)
    {
        total += *(nums + i);
    }
    printf("Sum of the numbers is %d\n", total);
}
int calc_prod(int *nums, int n)
{
    int i, prod = 1;
    for (i = 0; i < n; i++)
    {
        prod *= *(nums + i);
    }
    printf("Product of the numbers is %d\n", prod);
}
int largest_num(int *nums, int n)
{
    int i, max = INT_MIN;
    for (i = 0; i < n; i++)
    {
        if (*(nums + i) > max)
        {
            max = *(nums + i);
        }
    }
    printf("Maximum of the numbers is %d\n", max);
}
int smallest_num(int *nums, int n)
{
    int i, min = INT_MAX;
    for (i = 0; i < n; i++)
    {
        if (*(nums + i) < min)
        {
            min = *(nums + i);
        }
    }
    printf("Minimum of the numbers is %d\n", min);
}
int main()
{
    int *nums;
    int n, i;
    printf("Enter the no of numbers: ");
    scanf("%d", &n);
    nums = malloc(sizeof(int) * n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", (nums + i));
    }
#pragma omp parallel sections
    {
#pragma omp section
        calc_sum(nums, n);
#pragma omp section
        calc_prod(nums, n);
#pragma omp section
        largest_num(nums, n);
#pragma omp section
        smallest_num(nums, n);
    }
    return 0;
}