#include <stdio.h>
#include <mpi.h>

void main(int argc, char *argv[])
{
    int rank, size, i, j;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int root = 3;
    int b[] = {0, 0, 0, 0};
    
    MPI_Gather(&rank, 1, MPI_INT, b, 1, MPI_INT, root, MPI_COMM_WORLD);
    printf("rank %d: b[] = {%d, %d, %d, %d} \n", rank, b[0], b[1], b[2], b[3]);
    MPI_Finalize();
}
