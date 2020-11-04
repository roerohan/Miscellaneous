#include <stdio.h>
int n, nf;
int in[100];
int p[50];
int hit = 0;
int i, j, k;
int pgfaultcnt = 0;

void initialize()
{
    pgfaultcnt = 0;
    for (i = 0; i < nf; i++)
        p[i] = 9999;
}

int isHit(int data)
{
    hit = 0;
    for (j = 0; j < nf; j++)
    {
        if (p[j] == data)
        {
            hit = 1;
            break;
        }
    }

    return hit;
}

int getHitIndex(int data)
{
    int hitind;
    for (k = 0; k < nf; k++)
    {
        if (p[k] == data)
        {
            hitind = k;
            break;
        }
    }
    return hitind;
}

void dispPages()
{
    for (k = 0; k < nf; k++)
    {
        if (p[k] != 9999)
            printf(" %d", p[k]);
    }
}

void secondChance()
{
    int referencedbit[50];
    int modifybit[50];

    int victimptr = 0;

    initialize();

    for (i = 0; i < nf; i++)
    {
        referencedbit[i] = 0;
        modifybit[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        printf("\nFor %d: ", in[i]);
        if (isHit(in[i]))
        {
            printf("No page fault!");
            int hitindex = getHitIndex(in[i]);
            if (referencedbit[hitindex] == 0)
                referencedbit[hitindex] = 1;
        }
        else
        {
            pgfaultcnt++;
            int found = 0;
            for (j = 0; j < nf; j++)
            {
                if (referencedbit[victimptr] == 0 && modifybit[victimptr] == 0)
                {
                    found = 1;
                    p[victimptr] = in[i];
                    referencedbit[victimptr] = 1;
                    victimptr++;
                    break;
                }
            }

            if (found == 0)
            {
                for (j = 0; j < nf; j++)
                {
                    if (referencedbit[victimptr] == 0 && modifybit[victimptr] == 1)
                    {
                        found = 1;
                        p[victimptr] = in[i];
                        referencedbit[victimptr] = 1;
                        victimptr++;
                        break;
                    }
                }
            }

            if (found == 0)
            {
                for (j = 0; j < nf; j++)
                {
                    if (referencedbit[victimptr] == 1 && modifybit[victimptr] == 0)
                    {
                        found = 1;
                        p[victimptr] = in[i];
                        referencedbit[victimptr] = 1;
                        victimptr++;
                        break;
                    }
                }
            }

            if (found == 0)
            {
                for (j = 0; j < nf; j++)
                {
                    if (referencedbit[victimptr] == 1 && modifybit[victimptr] == 1)
                    {
                        found = 1;
                        p[victimptr] = in[i];
                        referencedbit[victimptr] = 1;
                        victimptr++;
                        break;
                    }
                }
            }
            dispPages();
        }
        if (victimptr == nf)
            victimptr = 0;
    }
    printf("\nTotal no of page faults:%d", pgfaultcnt);
}

int main()
{
    printf("\nLength of page reference sequence: ");
    scanf("%d", &n);

    printf("\nPage reference sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &in[i]);

    printf("\nNo of frames: ");
    scanf("%d", &nf);

    secondChance();
}
