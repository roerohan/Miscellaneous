#include<stdio.h>
#define size 20

int worst()
{
    printf("\nWorst Fit");
    int frag[size], b[size], f[size];
    int i, j, nb, nf, var, highest = 0;
    int bf[size], ff[size];

    printf("\nEnter the number of blocks:");
    scanf("%d", & nb);
    printf("Enter the number of processes:");
    scanf("%d", & nf);
    printf("\nEnter the size of the blocks:-\n");

    for (i = 1; i <= nb; i++)
    {
        printf("Block %d:", i);
        scanf("%d", & b[i]);
    }

    printf("Enter the size of the processes:-\n");

    for (i = 1; i <= nf; i++)
    {
        printf("Process %d:", i);
        scanf("%d", & f[i]);

    }
    for (i = 1; i <= nf; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1)
            {
                var = b[j] - f[i];
                if (var >= 0)
                    if (highest < var) {

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

void first()
{
    int frag[size], b[size], f[size], i, j, nb, nf, var;
    int bf[size], ff[size];

    printf("\nFirst Fit");
    printf("\nEnter the number of blocks: ");
    scanf("%d", & nb);

    printf("Enter the number of processes: ");
    scanf("%d", & nf);

    printf("\nEnter the size of the blocks: -\n");

    for (i = 1; i <= nb; i++)
    {
        printf("Block %d: ", i);
        scanf("%d", & b[i]);
    }

    printf("Enter the size of the processes :-\n");

    for (i = 1; i <= nf; i++)
    {
        printf("Process %d:", i);
        scanf("%d", & f[i]);
    }

    for (i = 1; i <= nf; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1) {
                var = b[j] - f[i];
                if (var >= 0)
                {
                    ff[i] = j;
                    break;
                }
            }
        }

        frag[i] = var;
        bf[ff[i]] = 1;
    }

    printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment");
    for (i = 1; i <= nf; i++) printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
    printf("\n");
}

int best()
{
    int frag[size], b[size], f[size];
    int i, j, nb, nf, var, lowest = 10000;
    int bf[size], ff[size];
    printf("\nBest Fit");

    printf("\nEnter the number of blocks:");
    scanf("%d", & nb);


    printf("Enter the number of processes:");
    scanf("%d", & nf);


    printf("\nEnter the size of the blocks:-\n");
    for (i = 1; i <= nb; i++) {
        printf("Block %d:", i);
        scanf("%d", & b[i]);
    }

    printf("Enter the size of the processes :-\n");

    for (i = 1; i <= nf; i++)
    {
        printf("Process %d:", i);
        scanf("%d", & f[i]);
    }

    for (i = 1; i <= nf; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1)
            {
                var = b[j] - f[i];
                if (var >= 0)
                    if (lowest > var) {

                        ff[i] = j;
                        lowest = var;
                    }
            }
        }

        frag[i] = lowest;
        bf[ff[i]] = 1;
        lowest = 10000;
    }

    printf("\nProcess_No\tProcess_Size\tBlock_No\tBlock_Size\tFragment");

    for (i = 1; i <= nf && ff[i] != 0; i++) printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
    printf("\n");
}


int main() {
    int ch = 1;
    printf("Choose the type of fitting algorithm.");
    printf("\n1. First Fit");
    printf("\n2. Best Fit");
    printf("\n3. Worst Fit\n");
    scanf("%d", & ch);
    switch (ch) {
        case 1:
            first();
            break;
        case 2:
            best();
            break;
        case 3:
            worst();
            break;
        default:
            printf("\nChoose a number between 1 and 3.\n");

    }
    return 0;
}
