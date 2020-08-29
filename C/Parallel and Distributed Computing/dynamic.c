#include <stdio.h>
int main()
{
#pragma omp parallel for schedule(dynamic, 1)
    for (int i = 0; i < 5; i++)
    {
        for (int i = 0; i < 6; i++)
        {
            printf("*");
        }
        printf("\n");
    }
}
