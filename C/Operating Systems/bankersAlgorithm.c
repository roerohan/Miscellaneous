#include <stdio.h>
int main()
{
	int n, m;
	int i, j, k;
	n = 5;
	m = 3;

	int mat_allocation[5][3] = {{0, 1, 0},	// P1
								{2, 0, 0},	// P2
								{3, 0, 2},	// P3
								{2, 1, 1},	// P4
								{0, 0, 2}}; // P5

	int mat_maximum[5][3] = {{7, 5, 3},	 // P1
							 {3, 2, 2},	 // P2
							 {9, 0, 2},	 // P3
							 {2, 2, 2},	 // P4
							 {4, 3, 3}}; // P5

	int avail[3] = {3, 3, 2};

	int f[n], sequence[n], ind = 0;
	for (k = 0; k < n; k++)
	{
		f[k] = 0;
	}

	int mat_need[n][m];

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			mat_need[i][j] = mat_maximum[i][j] - mat_allocation[i][j];
	}

	int y = 0;
	for (k = 0; k < 5; k++)
	{
		for (i = 0; i < n; i++)
		{
			if (f[i] == 0)
			{

				int flag = 0;

				for (j = 0; j < m; j++)
				{
					if (mat_need[i][j] > avail[j])
					{
						flag = 1;
						break;
					}
				}

				if (flag == 0)
				{
					sequence[ind++] = i;
					for (y = 0; y < m; y++)
						avail[y] += mat_allocation[i][y];
					f[i] = 1;
				}
			}
		}
	}

	printf("The 'SAFE SEQUENCE' is as follows:- \n");
	for (i = 0; i < n - 1; i++)
		printf(" P%d ->", sequence[i]);
	printf(" P%d", sequence[n - 1]);

	return (0);
}
