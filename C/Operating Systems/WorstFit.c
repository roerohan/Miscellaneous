#include <stdio.h>

#define size 30

int main()
{
    printf("\nWorst Fit\n");
    int frag[size], b[size], f[size];
    int i, j, nb, nf, var, highest = 0;
    int bf[size], ff[size];

    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of processes: ");
    scanf("%d", &nf);
    printf("\nEnter the size of the blocks:-\n");

    for (i = 1; i <= nb; i++)
    {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }

    printf("Enter the size of the processes:-\n");

    for (i = 1; i <= nf; i++)
    {
        printf("Process %d: ", i);
        scanf("%d", &f[i]);
    }
    for (i = 1; i <= nf; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1)
            {
                var = b[j] - f[i];
                if (var >= 0)
                    if (highest < var)
                    {

                        ff[i] = j;
                        highest = var;
                    }
            }
        }

        frag[i] = highest;
        bf[ff[i]] = 1;
        highest = 0;
    }

    printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment");
    for (i = 1; i <= nf; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
    printf("\n");
}