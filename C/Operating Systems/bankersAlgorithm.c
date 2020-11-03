#include <stdio.h>
int main()
{
	// Declare variables
	int n, m;
	int i, j, k;

	// Input the number of processes and resources
	printf("Enter the number of processes: ");
	scanf("%d", &n);

	printf("Enter the number of resources: ");
	scanf("%d", &m);

	// Declare the allocation matrix, maximum matrix, and available matrix
	int mat_allocation[n][m];
	int mat_maximum[n][m];
	int avail[m];

	// The allocation matrix stores the number of resources currently allocated to each process
	// Input the allocation matrix
	printf("\nEnter the values in the allocation matrix\n");
	for (i = 0; i < n; i++)
	{
		printf("Enter the number of resources allocated to process %d\n", (i + 1));
		for (j = 0; j < m; j++)
		{
			printf("Resource %d: ", (j + 1));
			scanf("%d", &mat_allocation[i][j]);
			printf("%d", mat_allocation[i][j]);
			printf("\n");
		}
	}

	// The maximum matrix stores the maximum number of resources required by each process
	// Input the maximum matrix
	printf("\nEnter the values in the maximum matrix\n");
	for (i = 0; i < n; i++)
	{
		printf("Enter the maximum number of resources required by process %d\n", (i + 1));
		for (j = 0; j < m; j++)
		{
			printf("Resource %d: ", (j + 1));
			scanf("%d", &mat_maximum[i][j]);
			printf("%d", mat_maximum[i][j]);
			printf("\n");
		}
	}

	// The available matrix stores the number of resources of each type currently available
	// Input the available matrix
	printf("\nEnter the number of resources available\n");
	for (i = 0; i < m; i++)
	{
		printf("Resource %d: ", (i + 1));
		scanf("%d", &avail[i]);
	}

	// sequence[n] -> Stores the safe sequence
	// f[n] -> Flag matrix to store the status of each process
	int f[n], sequence[n], ind = 0;
	for (k = 0; k < n; k++)
	{
		f[k] = 0;
	}

	// Need matrix stores the number of resources needed by each process
	int mat_need[n][m];

	// Calculation of need matrix
	// need matrix = max matrix - allocation matrix
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			mat_need[i][j] = mat_maximum[i][j] - mat_allocation[i][j];
	}

	// For every process, compare the values in the need matrix with the available matrix
	// If the values in the need matrix are greater, it is not possible to allocate resources,
	// so we move to the next iteration and check again later if it is possible to allocate
	// resources to this process.
	int y = 0;
	for (k = 0; k < 5; k++)
	{
		for (i = 0; i < n; i++)
		{
			if (f[i] == 0)
			{

				int flag = 0;

				// If resources can not be allocated to the current process,
				// flag is set to 1
				for (j = 0; j < m; j++)
				{
					if (mat_need[i][j] > avail[j])
					{
						flag = 1;
						break;
					}
				}

				// If flag is 1, the resources are not freed
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

	// The safe sequence has been generated and is stored in the array sequence
	// The following for loop prints the safe sequence
	printf("The 'SAFE SEQUENCE' is as follows:- \n");
	for (i = 0; i < n - 1; i++)
		printf(" P%d ->", sequence[i]);
	printf(" P%d", sequence[n - 1]);

	return 0;
}
